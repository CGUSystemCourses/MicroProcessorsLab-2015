#include "C8051F040.h"

void
Port_Configuration ()
{
	//initialize SFR setup page
	SFRPAGE = CONFIG_PAGE;                 // Switch to configuration page

	//setup the cross-bar and configure the I/O ports
	XBR2 = 0xc0;
	P2MDOUT = 0xff;

	//set to normal mode
	SFRPAGE = LEGACY_PAGE;
}//end of function Port_Configuration

void
Timer_Configuration ()
{
	TMOD = 0x01;
	TCON = 0x10;
	CKCON = 0x10;

	IE = 0x82;
	TL0 = 0;
	TH0 = 0;
}//end of function Timer_Configuration

void
Config ()
{
	//turn-off watch-dog timer
	WDTCN = 0xde;
	WDTCN = 0xad;

	OSCICN = 0x83;
	CLKSEL = 0x00;

	Port_Configuration ();

	Timer_Configuration ();
}//end of function Default_Config

unsigned status;
int count;

void Timer0_ISR ();

int
main ()
{
	Config ();
	status = 0x80;
	count = 0;

	while (1) {
		P2 = status;

		/*
		if (TCON & 0x20) {
			Timer0_ISR ();
			TCON = 0x10;
		}
		*/
	}//end while (1)
}//end of function main

void
Timer0_ISR () interrupt 1
{
	count++;

	if (count==4) {
		count = 0;
		status = status>>1;
		if (status==0) status=0x80;
	}

	TH0 = 0;
	TL0 = 0;
}//end of function Timer0_ISR




