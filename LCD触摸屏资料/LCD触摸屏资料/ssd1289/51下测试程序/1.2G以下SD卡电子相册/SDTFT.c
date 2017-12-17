		  /*-----------------------------------------------
  名称：读SD卡写彩屏
 
  日期：
  内容：通过读出SD卡中320x240像素、16位BMP图片的HEX数据，依次写到屏上，还原图片
  注意事项：由于SD卡使用SPI模式，并且是块读取(512Byte),所以需要单片机提供大于512的可用RAM，以供缓冲使用
            这里可以选择STC89c52RD+、STC89C58RD+、STC89C516RD+，后缀RD+表明扩展RAM是1024字节，RC表明扩展RAM256字节
------------------------------------------------*/
#include <reg52.h>
#include <stdio.h>
#include<6522TP.h>
/*
单片机工作电压3.3V
程序默认IO连接方式：

控制线：RS-P3^5;    WR-P3^6;   RD-P3^7;   CS-P1^0;   REST-P1^1;

数据线: DB0-DB7依次连接P0^0-P0^7;  DB8-DB15依次连接P2^0-P2^7;

触摸功能连接方式：(不使用触摸可不连接)
D_CLK-P1^2;  D_CS-P1^3;  D_DIN-P1^4;  D_OUT-P1^6;  D_PENIRQ-P1^7;

SD卡接线；(不使用触摸可不连接)
SD_MISO-P31;  SD_SCK-P32;  SD_MOSI-P33;  SD_CS-P34;
*/


//=============================================================
//定义SD卡需要的4根信号线
sbit SD_CLK = P3^2;
sbit SD_DI  = P3^3;
sbit SD_DO  = P3^1;
sbit SD_CS  = P3^4;
//===========================================================
//定义512字节缓冲区，注意需要使用 xdata关键字
unsigned char xdata DATA[512];

//===========================================================
//写一字节到SD卡,模拟SPI总线方式
void SdWrite(unsigned char n)
{

unsigned char i;

for(i=8;i;i--)
{
SD_CLK=0;
SD_DI=(n&0x80);
n<<=1;
SD_CLK=1;
}
SD_DI=1; 
} 
//===========================================================
//从SD卡读一字节,模拟SPI总线方式
unsigned char SdRead()
{
unsigned char n,i;
for(i=8;i;i--)
{
SD_CLK=0;
SD_CLK=1;
n<<=1;
if(SD_DO) n|=1;

}
return n;
}
//============================================================
//检测SD卡的响应
unsigned char SdResponse()
{
unsigned char i=0,response;

while(i<=8)
{
response = SdRead();
if(response==0x00)
break;
if(response==0x01)
break;
i++;
}
return response;
} 
//================================================================
//发命令到SD卡
void SdCommand(unsigned char command, unsigned long argument, unsigned char CRC)
{

SdWrite(command|0x40);
SdWrite(((unsigned char *)&argument)[0]);
SdWrite(((unsigned char *)&argument)[1]);
SdWrite(((unsigned char *)&argument)[2]);
SdWrite(((unsigned char *)&argument)[3]);
SdWrite(CRC);
}
//================================================================
//初始化SD卡
unsigned char SdInit(void)
{
int delay=0, trials=0;
unsigned char i;
unsigned char response=0x01;

SD_CS=1;
for(i=0;i<=9;i++)
SdWrite(0xff);
SD_CS=0;

//Send Command 0 to put MMC in SPI mode
SdCommand(0x00,0,0x95);


response=SdResponse();

if(response!=0x01)
{
return 0;
} 

while(response==0x01)
{
SD_CS=1;
SdWrite(0xff);
SD_CS=0;
SdCommand(0x01,0x00ffc000,0xff);
response=SdResponse();
} 

SD_CS=1;
SdWrite(0xff);
return 1; 
}
//================================================================
//往SD卡指定地址写数据,一次最多512字节
unsigned char SdWriteBlock(unsigned char *Block, unsigned long address,int len)
{
unsigned int count;
unsigned char dataResp;
//Block size is 512 bytes exactly
//First Lower SS

SD_CS=0;
//Then send write command
SdCommand(0x18,address,0xff);

if(SdResponse()==00)
{
SdWrite(0xff);
SdWrite(0xff);
SdWrite(0xff);
//command was a success - now send data
//start with DATA TOKEN = 0xFE
SdWrite(0xfe);
//now send data
for(count=0;count<len;count++) SdWrite(*Block++);

for(;count<512;count++) SdWrite(0);
//data block sent - now send checksum
SdWrite(0xff); //两字节CRC校验, 为0XFFFF 表示不考虑CRC
SdWrite(0xff);
dataResp=SdRead();

while(SdRead()==0);

dataResp=dataResp&0x0f; //mask the high byte of the DATA RESPONSE token
SD_CS=1;
SdWrite(0xff);
if(dataResp==0x0b)
{
return 0;
}
if(dataResp==0x05)
return 1;

return 0;
}
return 0;
}

//=======================================================================
//从SD卡指定地址读取数据,一次最多512字节
unsigned char SdReadBlock(unsigned char *Block, unsigned long address,int len)
{
unsigned int count;
//Block size is 512 bytes exactly
//First Lower SS

 //printf("MMC_read_block\n");

SD_CS=0;
//Then send write command
SdCommand(0x11,address,0xff);

if(SdResponse()==00)
{
//command was a success - now send data
//start with DATA TOKEN = 0xFE
while(SdRead()!=0xfe);

for(count=0;count<len;count++) *Block++=SdRead(); 

for(;count<512;count++) SdRead();

//data block sent - now send checksum
SdRead();
SdRead();
//Now read in the DATA RESPONSE token
SD_CS=1;
SdRead();
return 1;
}
 //printf("Command 0x11 (Read) was not received by the MMC.\n");
return 0;
}

//============================================================
//主程序	
main()
{
 unsigned int x,y; //定义液晶屏坐标
 unsigned long j;  //执行循环需要的临时变量
  unsigned int i;
  unsigned long AddTemp=270336;//393728;//SD卡地址第一个数据物理地址初始值，可以用winhex查看，这里是512扇区，512x512=262144，根据实际SD卡内容更改
  	CS=1;
	delayms(25);
	RES=0;
	delayms(150);
	RES=1;
	delayms(25);
	LGDP6522_init();//液晶屏初始化
	SdInit();         //SD卡初始化
 while(1)
 {

 for(j=0;j<300;j++)   //300表示一幅图片含有300x512字节的信息
    {
    SdReadBlock(DATA,AddTemp+(j*512),512);//每次读出512字节放到缓冲区
    for(i=0;i<256;i++)                    //然后写到液晶屏，可以显示256个像素，每个像素16位即2个字节
	   {   
   	   LCD_SetPos(x,x,y,y);
   	   Write_Data(DATA[2*i+1],DATA[2*i]);	 
	   x++;
	   if(x==240)                         //检测是否写到屏的边缘 240x320
	     {
	     y++;
	     x=0;
	     if(y==320)
	       y=0;
	     }
       }
     } 
     AddTemp = AddTemp+((j+0)*512);          //写完一幅图片后把SD地址加300x512到下一个图片地址
delayms(1500);//等待继续执行循环显示下一幅图片
	 
 } 
}