#include "C8051F040.h"

void
Port_Configuration ()
{
	XBR2 = 0xc0;
	P1MDIN = 0xff;
	P2MDOUT = 0xff;
}//end of function Port_Configuration

void
Default_Config ()
{
	//turn-off watch-dog timer
	// disable watchdog timer
	WDTCN = 0xde;
	WDTCN = 0xad;

	//initialize SFR setup page
	SFRPAGE = CONFIG_PAGE;                 // Switch to configuration page

	Port_Configuration ();

	//set to normal mode
	SFRPAGE = LEGACY_PAGE;
}//end of function Default_Config

int
main ()
{
	int status;
	int i;

	Default_Config ();

	while (1) {
		status = P1;
		for (i=0;i<100;i++);	//delay
		P2 = status;
	}//end while (1)
}//end of function main




