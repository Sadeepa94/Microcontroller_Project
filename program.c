/* 
 * File:   program.c
 * Author: Sadeepa
 *
 * Created on September 15, 2015, 8:50 PM
 */

#include <stdio.h>
#in
.
clude <stdlib.h>
#include "custom.h"

//LCD Control pins
#define _XTAL_FREQ 8000000
#define lcd_rs      LATCbits.LC0
#define lcd_rw      LATCbits.LC1
#define lcd_en      LATCbits.LC2


//LCD Data pins
#define lcdport LATD


#define SILK   PORTDbits.RD0
#define COTTON PORTDbits.RD1
#define DENIM  PORTDbits.RD2
#define SKIP   PORTDbits.RD3

#define BEEP LATCbits.LC3

#define FAN LATCbits.LC4
#define HEATER LATCbits.LC5
#define MOTOR LATCbits.LC6

#define ON 1
#define OFF 0



void lcd_ini();
void dis_cmd(unsigned char);
void dis_data(unsigned char);
void lcdcmd(unsigned char);
void lcddata(unsigned char);
void lcdmsg(unsigned char data0[20]);




void StartSignal();
void CheckResponse();
void ReadData();
void delay__(int i);
int get_humidity(void);
void time(int i);
void init_ADC(void);
float get_temp(void);
void check1();
void check2();
void check3();
void beep();

unsigned int result=0;
 float voltage;
 char *text;
 int  a = 0, b = 0,i = 0,t1 = 0,t2 = 0,
               rh1 = 0,rh2 = 0,sum = 0;
 char str[20];
 int j,k;




void main(void)
{
    OSCCON=0b01110000;
    TRISC=0b00000000;
    init_ADC();
    TRISD=0b00001111;
    LATDbits.LD4=0;
    LATDbits.LD5=0;
    LATDbits.LD6=0;
    LATDbits.LD7=0;
    MOTOR=OFF;
    FAN=OFF;
    HEATER=OFF;
    BEEP=OFF;
	lcd_ini();
        dis_cmd(0x82);
        lcdmsg("SELECT");
        while(1)
        {
            if(SILK==0)
            {
                beep();
                dis_cmd(0x01);
                dis_cmd(0x81);
                lcdmsg("SILK");
                dis_cmd(0xC1);
                lcdmsg("ROTATING...");
                MOTOR=ON;
                time(2);
                MOTOR=OFF;
                //dis_cmd(0x01);
                //dis_cmd(0x81);
                //lcdmsg("SILK");
                //dis_cmd(0xC1);
                //lcdmsg("DRYING...");
                dis_cmd(0x01);
                FAN=ON;
                HEATER=ON;

                while(1)
                {
                dis_cmd(0x81);
                lcdmsg("SILK");
                dis_cmd(0xC1);
                lcdmsg("DRYING...");
                    

                    get_humidity();
                    sprintf(str,"%d",rh1);
                    dis_cmd(0x8A);
                    lcdmsg(str);
                    lcdmsg("%");

                    get_temp();
                    sprintf(str,"%0.f",voltage);
                    dis_cmd(0xCA);
                    lcdmsg(str);
                    __delay_ms(50);
                    sprintf(str,"%c",223);
                    lcdmsg(str);
                    lcdmsg("C");
                    check1();
                    if(SKIP==0)
                    {
                        beep();
                        dis_cmd(0x01);
                        lcdmsg("END");
                        __delay_ms(50);
                        __delay_ms(50);
                        break;
                    }
                }
                FAN=OFF;
                HEATER=OFF;

            }
             if(COTTON==0)
            {
                beep();
                dis_cmd(0x01);
                dis_cmd(0x81);
                lcdmsg("COTTON");
                dis_cmd(0xC1);
                lcdmsg("ROTATING...");
                MOTOR=ON;
                time(2);
                MOTOR=OFF;
                //dis_cmd(0x01);
                //dis_cmd(0x81);
                //lcdmsg("SILK");
                //dis_cmd(0xC1);
                //lcdmsg("DRYING...");
                dis_cmd(0x01);
                FAN=ON;
                HEATER=ON;

                while(1)
                {
                dis_cmd(0x81);
                lcdmsg("COTTON");
                dis_cmd(0xC1);
                lcdmsg("DRYING...");


                    get_humidity();
                    sprintf(str,"%d",rh1);
                    dis_cmd(0x8A);
                    lcdmsg(str);
                    lcdmsg("%");

                    get_temp();
                    sprintf(str,"%0.f",voltage);
                    dis_cmd(0xCA);
                    lcdmsg(str);
                    __delay_ms(50);
                    sprintf(str,"%c",223);
                    lcdmsg(str);
                    lcdmsg("C");
                    check1();
                    if(SKIP==0)
                    {
                        beep();
                        dis_cmd(0x01);
                        lcdmsg("END");
                        __delay_ms(50);
                        __delay_ms(50);
                        break;
                    }
                }
                FAN=OFF;
                HEATER=OFF;

            }
            if(DENIM==0)
            {
                beep();
                dis_cmd(0x01);
                dis_cmd(0x81);
                lcdmsg("DENIM");
                dis_cmd(0xC1);
                lcdmsg("ROTATING...");
                MOTOR=ON;
                time(2);
                MOTOR=OFF;
                //dis_cmd(0x01);
                //dis_cmd(0x81);
                //lcdmsg("SILK");
                //dis_cmd(0xC1);
                //lcdmsg("DRYING...");
                dis_cmd(0x01);
                FAN=ON;
                HEATER=ON;

                while(1)
                {
                dis_cmd(0x81);
                lcdmsg("DENIM");
                dis_cmd(0xC1);
                lcdmsg("DRYING...");


                    get_humidity();
                    sprintf(str,"%d",rh1);
                    dis_cmd(0x8A);
                    lcdmsg(str);
                    lcdmsg("%");

                    get_temp();
                    sprintf(str,"%0.f",voltage);
                    dis_cmd(0xCA);
                    lcdmsg(str);
                    __delay_ms(50);
                    sprintf(str,"%c",223);
                    lcdmsg(str);
                    lcdmsg("C");
                    check1();
                    if(SKIP==0)
                    {
                        beep();
                        dis_cmd(0x01);
                        lcdmsg("END");
                        __delay_ms(50);
                        __delay_ms(50);
                        break;
                    }
                }
            }
                FAN=OFF;
                HEATER=OFF;

        }


        
     
        
	
}










void lcd_ini()
{
	dis_cmd(0x02);		// To initialize LCD in 4-bit mode.
	dis_cmd(0x28);
        dis_cmd(0x0C);              //----Cusor Blinking
        dis_cmd(0x01);              //----Clear LCD
        dis_cmd(0x06);              //----Increment Cusor
        dis_cmd(0x80);
}

void dis_cmd(unsigned char cmd_value)
{
	unsigned char cmd_value1;
	cmd_value1 = (cmd_value & 0xF0);	// Mask lower nibble because RB4-RB7 pins are being used
	lcdcmd(cmd_value1);			// Send to LCD
	cmd_value1 = ((cmd_value<<4) & 0xF0);	// Shift 4-bit and mask
	lcdcmd(cmd_value1);			// Send to LCD
}


void dis_data(unsigned char data_value)
{
	unsigned char data_value1;
	data_value1=(data_value&0xF0);
	lcddata(data_value1);
	data_value1=((data_value<<4)&0xF0);
	lcddata(data_value1);
}

void lcdcmd(unsigned char cmdout)
{
	lcdport=cmdout;		//Send command to lcdport=PORTB
	lcd_rs=0;
	lcd_rw=0;
	lcd_en=1;
	__delay_ms(10);
	lcd_en=0;
}

void lcddata(unsigned char dataout)
{
	lcdport=dataout;	//Send data to lcdport=PORTB
	lcd_rs = 1;
	lcd_rw = 0;
	lcd_en = 1;
	__delay_ms(10);
	lcd_en = 0;
}
void lcdmsg(unsigned char data0[20])
{
   int i=0;
   while(data0[i]!='\0')
	{
		dis_data(data0[i]);
		i++;
	}
}
void StartSignal()
 {
     TRISCbits.TRISC7 = 0;    //Configure RD2 as output
     PORTCbits.RC7 = 0;    //RD2 sends 0 to the sensor
     __delay_ms(18);
     PORTCbits.RC7 = 1;    //RD2 sends 1 to the sensor
     __delay_us(30);
     TRISCbits.TRISC7 = 1;    //Configure RD2 as input
  }
 void CheckResponse()
 {
     a = 0;
     __delay_us(40);
     if (PORTCbits.RC7 == 0)
     {
         __delay_us(80);
         if (PORTCbits.RC7 == 1)
             a = 1;
         __delay_us(40);
     }
 }
 void ReadData()
 {
     for(b=0;b<8;b++)
     {
         while(!PORTCbits.RC7); //Wait until PORTD.F2 goes HIGH
         __delay_us(30);
         if(PORTCbits.RC7 == 0)
             i&=~(1<<(7-b));  //Clear bit (7-b)
         else
         {
             i|= (1<<(7-b));               //Set bit (7-b)
             while(PORTCbits.RC7);
         }  //Wait until PORTD.F2 goes LOW
     }
 }
void delay(int i)
 {
    for(int k=0; k<i;k++)
        __delay_ms(50);
}
 int get_humidity(void)
 {
     while(1)
     {
          StartSignal();
          CheckResponse();
          if(a == 1)
          {
                  ReadData();
                  rh1 =i;
                  ReadData();
                  rh2 =i;
                  ReadData();
                  t1 =i;
                  ReadData();
                  t2 =i;
                  ReadData();
                  sum = i;
                  if(sum == rh1+rh2+t1+t2)
                      return rh1;
                  else
                  {
                      text = "Check sum error";
                      dis_cmd(0x81);
                      lcdmsg(text);
                  }
          }
          else
          {
            text="no response";
            dis_cmd(0x81);
            lcdmsg(text);
          }
          delay(80);
      }
  }
 void time(int i)
{
   // init_XLCD();
    char a[10];
    char b[10];
    for(int j=i-1;j>=0;j--)
        for(int k=59;k>0;k--)
        {
            __delay_ms(50);
            __delay_ms(50);
            __delay_ms(50);
            __delay_ms(50);
            __delay_ms(50);
            __delay_ms(50);
            __delay_ms(50);
            __delay_ms(50);
            __delay_ms(50);
            __delay_ms(50);
            sprintf(a,"%.2d",j);
            sprintf(b,"%.2d",k);
            dis_cmd(0x89);
            lcdmsg(a);
            lcdmsg("m");
            lcdmsg(b);
            lcdmsg("s");
        }
 }

 void init_ADC(void)
{
    OpenADC(ADC_FOSC_2 & ADC_RIGHT_JUST & ADC_2_TAD, ADC_CH0 & ADC_INT_ON &
    ADC_REF_VDD_VSS, ADC_1ANA);
}


float get_temp(void)
{
    ConvertADC();
    while(BusyADC());
    result=ReadADC();
    voltage=(result*5)/10.24;
    return voltage;
}

void beep(void)
{
    BEEP=1;
    for(int i=0;i<5;i++)
    __delay_ms(50);
    BEEP=0;
}

void check1()
{
    if(rh1>=90)
    {
        if(voltage<=32)
            HEATER=ON;
        if(voltage>=34)
            HEATER=OFF;
    }
    else if((rh1<=90)&&(rh1>=60))
    {
        if(voltage<=31)
            HEATER=ON;
        if(voltage>=33)
            HEATER=OFF;
    }
    else if((rh1<=59)&&(rh1>=30))
    {
        if(voltage<=31)
            HEATER=ON;
        if(voltage>=34)
            HEATER=OFF;
    }
    else
    {
        HEATER=OFF;
        FAN=OFF;
    }
}


void check2()
{
    if(rh1>=90)
    {
        if(voltage<140)
            HEATER=ON;
        if(voltage>145)
            HEATER=OFF;
    }
    else if((rh1<=90)&&(rh1>=60))
    {
        if(voltage<115)
            HEATER=ON;
        if(voltage>140)
            HEATER=OFF;
    }
    else if((rh1<=59)&&(rh1>=30))
    {
        if(voltage<100)
            HEATER=ON;
        if(voltage>115)
            HEATER=OFF;
    }
}


void check3()
{
    if(rh1>=90)
    {
        if(voltage<140)
            HEATER=ON;
        if(voltage>145)
            HEATER=OFF;
    }
    else if((rh1<=90)&&(rh1>=60))
    {
        if(voltage<115)
            HEATER=ON;
        if(voltage>140)
            HEATER=OFF;
    }
    else if((rh1<=59)&&(rh1>=30))
    {
        if(voltage<100)
            HEATER=ON;
        if(voltage>115)
            HEATER=OFF;
    }
}
