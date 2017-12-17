
#include"reg52.h"
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


/* LCD color */
#define White          0xFFFF
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

sbit CS=P1^0;		//片选
sbit RES=P1^1;		//复位
sbit RS=P3^5;		//数据/命令选择
sbit RW= P3^6;
sbit LCD_RD =P3^7;                    //数据口使用P1
//====================================================//

void main (void);
void ILI9325_Initial(void);
void show_colour_bar (void);
void Init_data(unsigned char x, unsigned int y);
void Write_Cmd(unsigned char DH,unsigned char DL);
void Write_Data(unsigned char DH,unsigned char DL);
void delayms(unsigned int tt);
void show_photo(void);
void Show_RGB (unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1,unsigned int Color);
unsigned char code pic[];
void  Write_Data_U16(unsigned int y);
static void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1);
void ClearScreen(unsigned int bColor);
void LCD_PutChar8x16(unsigned short x, unsigned short y, char c, unsigned int fColor, unsigned int bColor);
void LCD_PutChar(unsigned short x, unsigned short y, char c, unsigned int fColor, unsigned int bColor);
void LCD_PutString(unsigned short x, unsigned short y, char *s, unsigned int fColor, unsigned int bColor);

void LCD_PutChar8x8(unsigned short x, unsigned short y, char c, unsigned int fColor, unsigned int bColor);
void PutGB1616(unsigned short x, unsigned short  y, unsigned char c[2], unsigned int fColor,unsigned int bColor);
void PutGB3232(unsigned short x, unsigned short  y, unsigned char c[2], unsigned int fColor,unsigned int bColor);
//================================================//

void  main(void)
{   
	CS=1;
	LCD_RD=1;
	delayms(5);
	RES=0;
	delayms(15);
	RES=1;
	delayms(5);
	ILI9325_Initial();
	while(1)
	{
	


ClearScreen(0x00);

//show_colour_bar();	


LCD_PutString(40,60,"I LOVE MY JOB ",Blue2,Yellow);

LCD_PutString(40,100,"专业技术支持论坛",0x07e0,0xf800);
LCD_PutString(40,120,"专业开发板工控板",0xF800,Yellow);
LCD_PutString(40,140,"1234567890",0xF800,Yellow);
LCD_PutString(20,160,"abcdefghijklmnopqistuvwxyz",0xF800,Yellow);
LCD_PutString(20,180,"`,./<>';:[]{}\|?)(-=+*&^%$",0xF800,Yellow);
PutGB3232(20,200,"我",Blue,Yellow);	//写入32x32汉字
PutGB3232(60,200,"爱",Blue,Red);
PutGB3232(100,200,"单",Blue,Magenta);
PutGB3232(140,200,"片",Blue,Green);
PutGB3232(180,200,"机",Blue,Cyan);	
PutGB3232(20,240,"硕",Blue,0X00);	
PutGB3232(60,240,"耀",Blue,0X00);	
PutGB3232(100,240,"电",Blue,0X00);	
PutGB3232(140,240,"子",Blue,0X00);	
PutGB3232(180,240,"科",Blue,0X00);
PutGB3232(20,280,"技",Blue,0X00);		
PutGB3232(60,280,"欢",Blue,0X00);	
PutGB3232(100,280,"迎",Blue,0X00);	
PutGB3232(140,280,"你",Blue,0X00);	
PutGB3232(180,280,"！",Blue,0X00);	

//	show_photo();

		while(1);	


	}
}


void ClearScreen(unsigned int bColor)
{
 unsigned int i,j;
 
 for (i=0;i<320;i++)
	{
	
	   for (j=0;j<240;j++)

	       Write_Data_U16(bColor);

	}
}

/////////////////////////////////////////////////////////////
#include "8X16.h"
void LCD_PutChar8x16(unsigned short x, unsigned short y, char c, unsigned int fColor, unsigned int bColor)
{
 unsigned int i,j;
 LCD_SetPos(x,x+8-1,y,y+16-1);
 for(i=0; i<16;i++) {
		unsigned char m=Font8x16[c*16+i];
		for(j=0;j<8;j++) {
			if((m&0x80)==0x80) {
				Write_Data_U16(fColor);
				}
			else {
				Write_Data_U16(bColor);
				}
			m<<=1;
			}
		}
}


void LCD_PutChar(unsigned short x, unsigned short y, char c, unsigned int fColor, unsigned int bColor) {

		LCD_PutChar8x16( x, y, c, fColor, bColor );
	}


#include "GB1616.h"	//16*16汉字字模

void PutGB1616(unsigned short x, unsigned short  y, unsigned char c[2], unsigned int fColor,unsigned int bColor){
	unsigned int i,j,k;

	LCD_SetPos(x,  x+16-1,y, y+16-1);

	for (k=0;k<64;k++) { //64标示自建汉字库中的个数，循环查询内码
	  if ((codeGB_16[k].Index[0]==c[0])&&(codeGB_16[k].Index[1]==c[1])){ 
    	for(i=0;i<32;i++) {
		  unsigned short m=codeGB_16[k].Msk[i];
		  for(j=0;j<8;j++) {
			if((m&0x80)==0x80) {
				Write_Data_U16(fColor);
				}
			else {
				Write_Data_U16(bColor);
				}
			m<<=1;
			} 
		  }
		}  
	  }	
	}

	#include "GB3232.h"	//32*32汉字字模

void PutGB3232(unsigned short x, unsigned short  y, unsigned char c[2], unsigned int fColor,unsigned int bColor){
	unsigned int i,j,k;

	LCD_SetPos(x,  x+32-1,y, y+32-1);

	for (k=0;k<15;k++) { //15标示自建汉字库中的个数，循环查询内码
	  if ((codeGB_32[k].Index[0]==c[0])&&(codeGB_32[k].Index[1]==c[1])){ 
    	for(i=0;i<128;i++) {
		  unsigned short m=codeGB_32[k].Msk[i];
		  for(j=0;j<8;j++) {
			if((m&0x80)==0x80) {
				Write_Data_U16(fColor);
				}
			else {
				Write_Data_U16(bColor);
				}
			m<<=1;
			} 
		  }
		}  
	  }	
	}

void LCD_PutString(unsigned short x, unsigned short y, unsigned char *s, unsigned int fColor, unsigned int bColor) {
	 unsigned char l=0;
	while(*s) {
		if( *s < 0x80) 
		    {
			LCD_PutChar(x+l*8,y,*s,fColor,bColor);
			s++;l++;
			}
		else
		    {
			PutGB1616(x+l*8,y,(unsigned char*)s,fColor,bColor);
			s+=2;l+=2;
			}
		}
	}
//==================== 显示R G B 顔色 ====================//



void Show_RGB (unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1,unsigned int Color)
{
	unsigned int i,j;
	//address_set();
	LCD_SetPos(x0,x1,y0,y1);
	for (i=y0;i<=y1;i++)
	{
	   for (j=x0;j<=x1;j++)
	       Write_Data_U16(Color);

	}


}

//====================== 显示彩条 ======================//
void show_colour_bar (void)

{
	int V,H;
	LCD_SetPos(0,240,0,320);//320x240

	for(H=0;H<240;H++)
	{
		for(V=0;V<40;V++)
		Write_Data(0xf8,0x00);
	}

	for(H=0;H<240;H++)
	{
		for(V=40;V<80;V++)
		Write_Data(0x07,0xe0);
	}

	for(H=0;H<240;H++)
	{
		for(V=80;V<120;V++)
		Write_Data(0x00,0x1f);
	}

	for(H=0;H<240;H++)
	{
		for(V=120;V<160;V++)
		Write_Data(0xff,0xe0);
	}

	for(H=0;H<240;H++)
	{
		for(V=160;V<200;V++)
		Write_Data(0xf8,0x1f);
	}

	for(H=0;H<240;H++)
	{
		for(V=200;V<240;V++)
		Write_Data(0x07,0xff);
	}

	for(H=0;H<240;H++)
	{
		for(V=240;V<280;V++)
		Write_Data(0xff,0xff);
	}

	for(H=0;H<240;H++)
	{
		for(V=280;V<320;V++)
		Write_Data(0x00,0x00);
	}

}

void show_photo(void)
{
	unsigned char j;
	unsigned int i;
	unsigned long s=0;

	LCD_SetPos(0,240,0,320);//320x240

	for (i=0;i<75;i++)
	{
	for (j=0;j<240;j++)
	Write_Data(0xff,0xff);
		
	}

	for (i=0;i<170;i++)
	{
	for (j=0;j<55;j++)
		Write_Data(0xff,0xff);

		for (j=0;j<130;j++)
		Write_Data(pic[s++],pic[s++]);
		
		for (j=0;j<55;j++)
		Write_Data(0xff,0xff);
	}

    for (i=0;i<75;i++)
	{
	for (j=0;j<240;j++)
	Write_Data(0xff,0xff);
		
	}

	}

//=======================================================//



void  Init_data (unsigned char x,unsigned int y)
{
	unsigned char m,n;
	m=y>>8;
	n=y;
	Write_Cmd(0x00,x);
	Write_Data(m,n);

}


void  Write_Data_U16(unsigned int y)
{
	unsigned char m,n;
	m=y>>8;
	n=y;
	Write_Data(m,n);

}
//====================== 写命令 ==========================//

void Write_Cmd(unsigned char DH,unsigned char DL)
{
  
 	

	CS=0;
	RS=0;

	P2=DH;


	P0=DL;
	
	RW=0;
	RW=1;
	CS=1;
}

//===================== 写数据 ===========================//

void Write_Data(unsigned char DH,unsigned char DL)
{
 
  
	
	CS=0;
	
	RS=1;
	P2=DH;

	P0=DL;	
	RW=0;
	RW=1;
	CS=1;
}





//=======================================================
void delayms(unsigned int count)
{
    int i,j;                                                                                
    for(i=0;i<count;i++)                                                                    
       {
	     for(j=0;j<260;j++);
       }                                                                                     
}



//===================== 初始化代码 =======================//



void ILI9325_Initial(void)
{ 

  //////////////////////////////////////////////////////////
 delayms(50);                     //根据不同晶振速度可以调整延时，保障稳定显示

	

Init_data(0x0000,0x0001);    delayms(1);  //打开晶振
    Init_data(0x0003,0xA8A4);    delayms(1);   //0xA8A4
    Init_data(0x000C,0x0000);    delayms(1);   
    Init_data(0x000D,0x080C);    delayms(1);   
    Init_data(0x000E,0x2B00);    delayms(1);   
    Init_data(0x001E,0x00B0);    delayms(1);   
    Init_data(0x0001,0x2B3F);    delayms(1);   //驱动输出控制320*240  0x6B3F
    Init_data(0x0002,0x0600);    delayms(1);
    Init_data(0x0010,0x0000);    delayms(1);
    Init_data(0x0011,0x6070);    delayms(1);        //0x4030           //定义数据格式  16位色 
    Init_data(0x0005,0x0000);    delayms(1);
    Init_data(0x0006,0x0000);    delayms(1);
    Init_data(0x0016,0xEF1C);    delayms(1);
    Init_data(0x0017,0x0003);    delayms(1);
    Init_data(0x0007,0x0233);    delayms(1);        //0x0233       
    Init_data(0x000B,0x0000);    delayms(1);
    Init_data(0x000F,0x0000);    delayms(1);        //扫描开始地址
    Init_data(0x0041,0x0000);    delayms(1);
    Init_data(0x0042,0x0000);    delayms(1);
    Init_data(0x0048,0x0000);    delayms(1);
    Init_data(0x0049,0x013F);    delayms(1);
    Init_data(0x004A,0x0000);    delayms(1);
    Init_data(0x004B,0x0000);    delayms(1);
    Init_data(0x0044,0xEF00);    delayms(1);
    Init_data(0x0045,0x0000);    delayms(1);
    Init_data(0x0046,0x013F);    delayms(1);
    Init_data(0x0030,0x0707);    delayms(1);
    Init_data(0x0031,0x0204);    delayms(1);
    Init_data(0x0032,0x0204);    delayms(1);
    Init_data(0x0033,0x0502);    delayms(1);
    Init_data(0x0034,0x0507);    delayms(1);
    Init_data(0x0035,0x0204);    delayms(1);
    Init_data(0x0036,0x0204);    delayms(1);
    Init_data(0x0037,0x0502);    delayms(1);
    Init_data(0x003A,0x0302);    delayms(1);
    Init_data(0x003B,0x0302);    delayms(1);
    Init_data(0x0023,0x0000);    delayms(1);
    Init_data(0x0024,0x0000);    delayms(1);
    Init_data(0x0025,0x8000);    delayms(1);
    Init_data(0x004f,0);        //行首址0
    Init_data(0x004e,0);        //列首址0


	
	
 Write_Cmd (0x00,0x22);//LCD_WriteCMD(GRAMWR);

}

 





/*===========================================================*/

/*************************************************************
函数名称:LCD_DefineDispWindow
功    能:定义显示窗体
参    数:x0:  窗体中X坐标中较小者
	 x1:  窗体中X坐标中较大者
	 y0:  窗体中Y坐标中较小者
	 y1:  窗体中Y坐标中较大者 
返 回 值:无
*************************************************************/
static void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1)
{
	Init_data(0x0044,(x1<<8)+x0);
	Init_data(0x0045,y0);
	Init_data(0x0046,y1);
	Init_data(0x004e,x0);
	Init_data(0x004f,y0);
     Write_Cmd (0x00,0x22);//LCD_WriteCMD(GRAMWR);  
}


