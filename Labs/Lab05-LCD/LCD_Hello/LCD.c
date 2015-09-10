/*******************************************************************************
 *
 * the LCD infrastructure module
 *
 ******************************************************************************/

#include "C8051F040.h"
#include "LCD.h"

char LCD_status;

void
LCD_PortConfig ()
{
	//initialize SFR setup page
	SFRPAGE = CONFIG_PAGE;                 // Switch to configuration page

	//setup the cross-bar and configure the I/O ports
	XBR2 = 0xc0;
	P3MDOUT = 0x3f;

	//set to normal mode
	SFRPAGE = LEGACY_PAGE;
}//end of function LCD_PortConfig ()

void
LCD_Init ()
{
	LCD_SendCommand (0x01);		//clear display, cursor to home
	LCD_SendCommand (0x28);		//Display function: 2 rows for 4-bit data, small
	LCD_SendCommand (0x0e);		//display and curson ON, curson blink off
	LCD_SendCommand (0x10);		//cursor shift left
	LCD_SendCommand (0x06);		//cursor increment, shift off
}

void
LCD_Status_SetRS ()
{
	LCD_status = LCD_status | 1;
}

void
LCD_Status_ClearRS ()
{
	LCD_status = LCD_status & 0xfe;
}

void
LCD_Status_SetWord (char word)
{
	word = word & 0x0f;
	LCD_status = LCD_status & 0x03;
	LCD_status = LCD_status | (word<<2);
}

void
LCD_Status_SetEnable ()
{
	LCD_status = LCD_status | 0x02;
}


void
LCD_Status_ClearEnable ()
{
	LCD_status = LCD_status & 0xfb;
}

void
LCD_Delay ()
{
	int i;
	for (i=0;i<100;i++);
}

void
LCD_SendCommand (char cmd)
{
	LCD_Status_ClearRS ();

	///send the lower half
	LCD_Status_SetWord (cmd & 0x0f);
	LCD_Status_SetEnable ();
	P3 = LCD_status;
	LCD_Delay ();
	LCD_Status_ClearEnable ();
	P3 = LCD_status;
	LCD_Delay ();

	///send the lower half
	LCD_Status_SetWord ((cmd>>4)&0x0f);
	LCD_Status_SetEnable ();
	P3 = LCD_status;
	LCD_Delay ();
	LCD_Status_ClearEnable ();
	P3 = LCD_status;
	LCD_Delay ();
}

void
LCD_SendData (char dat)
{
	LCD_Status_SetRS ();

	///send the lower half
	LCD_Status_SetWord (dat & 0x0f);
	LCD_Status_SetEnable ();
	P3 = LCD_status;
	LCD_Delay ();
	LCD_Status_ClearEnable ();
	P3 = LCD_status;
	LCD_Delay ();

	///send the lower half
	LCD_Status_SetWord ((dat>>4)&0x0f);
	LCD_Status_SetEnable ();
	P3 = LCD_status;
	LCD_Delay ();
	LCD_Status_ClearEnable ();
	P3 = LCD_status;
	LCD_Delay ();
}

void
LCD_PrintString (char* str)
{
	int i;

	for (i=0; str[i]!=0; i++) {
		LCD_SendData (str[i]);
		LCD_SendCommand (0x14);		//cursor shift right
	}//for i
}

void
LCD_ClearScreen ()
{
	LCD_SendCommand (0x01);
}






