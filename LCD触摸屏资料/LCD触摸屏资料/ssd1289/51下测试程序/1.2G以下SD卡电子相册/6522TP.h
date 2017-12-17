/*-----------------------------------------------
  名称：写彩屏
  公司：
  网站：
  编写：
  日期：
  内容：320x240像素、16位BMP图片的HEX数据，依次写到屏上，还原图片
  注意事项：
------------------------------------------------*/
/*硕耀电子科技 http://hyao.taobao.com/ 
单片机工作电压3.3V
程序默认IO连接方式：

控制线：RS-P3^5;    WR-P3^6;   RD-P3^7;   CS-P1^0;   REST-P1^1;

数据线: DB0-DB7依次连接P0^0-P0^7;  DB8-DB15依次连接P2^0-P2^7;

触摸功能连接方式：(不使用触摸可不连接)
D_CLK-P1^2;  D_CS-P1^3;  D_DIN-P1^4;  D_OUT-P1^6;  D_PENIRQ-P1^7;

SD卡接线；(不使用触摸可不连接)
SD_MISO-P31;  SD_SCK-P32;  SD_MOSI-P33;  SD_CS-P34;
*/
#include"reg52.h"
//============================================================
//根据芯片资料定义
#define WINDOW_XADDR_START	0x0050 // 水平的开始地址组
#define WINDOW_XADDR_END	0x0051 // 水平的结束地址组
#define WINDOW_YADDR_START	0x0052 // 垂直的开始地址组
#define WINDOW_YADDR_END	0x0053 // 垂直的结束地址组
#define GRAM_XADDR		    0x0020 // GRAM 水平的地址组
#define GRAM_YADDR		    0x0021 // GRAM 垂直的地址组
#define GRAMWR 			    0x0022 // 记忆写

//=============================================================
//定义液晶屏接口
sbit CS=P1^0;		//片选
sbit RES=P1^1;		//复位
sbit RS=P3^5;		//数据/命令选择
sbit RW=P3^6;
                    //数据口使用P2 P0
//====================================================//
//函数声明
void LGDP6522_init(void);							   //LCD初始化
void Init_data(unsigned char x, unsigned int y);   //写命令数据
void Write_Cmd(unsigned char DH,unsigned char DL);	   //写命令
void Write_Data(unsigned char DH,unsigned char DL);	   //写数据
void delayms(unsigned int tt); //延时程序
void  Write_Data_U16(unsigned int y); //写16位数据
static void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1); //定义坐标
void ClearScreen(unsigned int bColor);	//清屏

//===============================================================
//清屏
void ClearScreen(unsigned int bColor)
{
 unsigned int i,j;
 LCD_SetPos(0,240,0,320);//320x240
 for (i=0;i<320;i++)
	{
	
	   for (j=0;j<240;j++)
	       Write_Data_U16(bColor);
	}
}


//===============================================================
//写命令数据

void Init_data(unsigned char x, unsigned int y)
{
	unsigned char m,n;
	m=y>>8;
	n=y;
	Write_Cmd(0x00,x);
	Write_Data(m,n);

}



//==============================================================
//写16位数据
void  Write_Data_U16(unsigned int y)
{
	unsigned char m,n;
	m=y>>8;
	n=y;
	Write_Data(m,n);

}
//=============================================================
//写命令

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

//===================================================================
//写数据

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





//============================================================
//延时程序
void delayms(unsigned int count)
{
    int i,j;                                                                                
    for(i=0;i<count;i++)                                                                    
       {
	     for(j=0;j<260;j++);
       }                                                                                     
}



//=============================================================
//液晶初始化

void LGDP6522_init(void)
{ 
  	CS=0;
delayms(50);//可以适当调整延时，保障稳定显示
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
	Write_Cmd(0x0022);


/*	Init_data(0x0001,0x0100); //源扫描设置SS=0, 输出的移动方向是从S1到S720
	//（源扫描设置SS=1, 输出的移动方向是从S720到S1）
	//SM=0，逐行扫描（SM=1，隔行扫描）

	Init_data(0x0002,0x0700); //B/C=1、EOR=1：行倒置（B/C=0：帧/场倒置）
	Init_data(0x0003,0x1030); //AM=0，地址在水平方向自动加1
	//I/D[1:0] = 11：水平垂直方向均增加
	//BGR=1:采用BGR格式
	//TRI=0、DFM=*：8位机、两次数据传送
	Init_data(0x0004,0x0000); //比例缩放设置：不缩放
	
	//显示控制
	Init_data(0x0008,0x0207); //设置后边沿和前沿 
	Init_data(0x0009,0x0000);//设置非显示区时间间隔ISC[3:0]
	Init_data(0x000A,0x0000); //帧标记功能

	Init_data(0x000C,0x0000);//RGB显示接口控制1
	Init_data(0x000D,0x0000);//帧标记位置
	Init_data(0x000F,0x0000);//RGB显示接口控制2
	
	//电源配置
	Init_data(0x0010,0x0000);   
	Init_data(0x0011,0x0007);  
	Init_data(0x0012,0x0000);  
	Init_data(0x0013,0x0000); 
	//vgh 
	Init_data(0x0010,0x1290);   
	Init_data(0x0011,0x0227);
	//delayms(100);
	//vregiout 
	Init_data(0x0012,0x001d); //0x001b
	//delayms(100); 
	//vom amplitude
	Init_data(0x0013,0x1500);
	//delayms(100); 
	//vom H
	Init_data(0x0029,0x0018); 
	Init_data(0x002B,0x000D); 
	
	//伽马校正
	Init_data(0x0030,0x0004);
	Init_data(0x0031,0x0307);
	Init_data(0x0032,0x0002);//0006
	Init_data(0x0035,0x0206);
	Init_data(0x0036,0x0408);
	Init_data(0x0037,0x0507); 
	Init_data(0x0038,0x0204);//0200
	Init_data(0x0039,0x0707); 
	Init_data(0x003C,0x0405);//0504
	Init_data(0x003D,0x0F02); 
	
	//窗口设置
	Init_data(0x0050,0x0000);//水平起始位置
	Init_data(0x0051,0x00EF);//水平终止位置
	Init_data(0x0052,0x0000);//垂直起始位置
	Init_data(0x0053,0x013F);//垂直终止位置

	Init_data(0x0060,0xA700);//门扫描设置，GS=1：从G320扫描到G1，320线
	Init_data(0x0061,0x0001); 
	Init_data(0x006A,0x0000);
	//
	Init_data(0x0080,0x0000); 
	Init_data(0x0081,0x0000); 
	Init_data(0x0082,0x0000); 
	Init_data(0x0083,0x0000); 
	Init_data(0x0084,0x0000); 
	Init_data(0x0085,0x0000); 
	//
	Init_data(0x0090,0x0010); 
	Init_data(0x0092,0x0600); 
	Init_data(0x0093,0x0003); 
	Init_data(0x0095,0x0110); 
	Init_data(0x0097,0x0000); 
	Init_data(0x0098,0x0000);
	Init_data(0x0007,0x0133);
	//write_cmd_data(0x0022);*/			
  	CS=1;
//	Write_Cmd_Data(0x0022);//		
}



//===============================================================

//===============================================================
//定义坐标
static void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1)
{ 
  Init_data(WINDOW_XADDR_START,x0);
  Init_data(WINDOW_XADDR_END,x1);
  Init_data(WINDOW_YADDR_START,y0);
  Init_data(WINDOW_YADDR_END,y1);
  Init_data(GRAM_XADDR,x0);
  Init_data(GRAM_YADDR,y0);
  Write_Cmd (0x00,0x22);//LCD_WriteCMD(GRAMWR);
}


