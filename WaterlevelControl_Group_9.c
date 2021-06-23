#include<reg51.h>

sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;

sbit in0=P3^0;
sbit in1=P3^1;
sbit in2=P3^2;
sbit in3=P3^3;

sbit relay=P3^4;

void delay();
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void delayled();
void delay()
{
int i;
for(i=0;i<=1275;i++);
}
void delayled()
{
int i,j;for(i=0;i<=1275;i++)
for(j=0;j<=10;j++);
}
void lcdcmd(unsigned char val)
{
P2=val;
RS=0;
RW=0;
EN=1;
delay();
EN=0;
}
void lcddat(unsigned char val)
{
P2=val;
RS=1;
RW=0;
EN=1;
delay();
EN=0;
}
void main()
{
char i;
//char a[]={"WATER Level INDICATOR "};
char b[]={"Empty"};
char c[]={"Quarter"};
char d[]={"Half"};
char e[]={"3/4th"};
char f[]={"Full"};
relay=0;
P2=0x00;
lcdcmd(0x38);
lcdcmd(0x10);
lcdcmd(0x0c);
lcdcmd(0x80);

in0=0;
in1=0;
in2=0;
in3=0;
	while(1)
	{
		if(in0!=1 && in1!=1 && in2!=1 && in3!=1)
		{
			relay=1;
			
			for(i=0;c[i]!=0;i++)
			{
				lcddat(" ");
		
			}
			lcdcmd(0xc0);
			for(i=0;b[i]!=0;i++)
			{
				lcddat(b[i]);
		
			}
		}
		else if(in3==1)
		{
			relay=0;
		
			for(i=0;c[i]!=0;i++)
			{
				lcddat(" ");
		
			}
			lcdcmd(0xc0);
			for(i=0;f[i]!=0;i++)
			{
				lcddat(f[i]);
			
			}
		
		}
		else if(in2==1)
		{
			relay=1;
		
				for(i=0;c[i]!=0;i++)
			{
				lcddat(" ");
		
			}
			lcdcmd(0xc0);
			for(i=0;e[i]!=0;i++)
			{
				lcddat(e[i]);
				
			}
		}
		else if(in1==1)
		{
			relay=1;
			
				for(i=0;c[i]!=0;i++)
			{
				lcddat(" ");
		
			}
				lcdcmd(0xc0);
			for(i=0;d[i]!=0;i++)
			{
				lcddat(d[i]);
			}
		}
		else if(in0==1)
		{
				relay=1;
		

				for(i=0;c[i]!=0;i++)
			{
				lcddat(" ");
		
			}
			lcdcmd(0xc0);
			for(i=0;c[i]!=0;i++)
			{
				lcddat(c[i]);
			}
		}
	}
}