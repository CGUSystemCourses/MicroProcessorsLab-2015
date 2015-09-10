/*******************************************************************************
 *
 * file: [glcd.h]
 *
 ******************************************************************************/

#ifndef glcd_h

#define glcd_h


/*******************************************************************************
 *
 * bit positions and control words
 *
 ******************************************************************************/

#define P2_CS1		0x01
#define P2_CS2		0x02
#define P2_RS		0x04
#define P2_RW		0x08
#define P2_E		0x10
#define P2_RST		0x20

#define P2_CWORD_TEMPLATE	0x21

#define P4_Busy				0x80
#define P4_Status_On		0x20
#define P4_Reset			0x10
#define P4_Display_On		0x01

#define P4_Set_Xaddr_TMPL	0xb8
#define P4_Set_Yaddr_TMPL	0x40
#define P4_Set_Zaddr_TMPL	0xc0
#define P4_Set_Display_TMPL	0x3e

/*******************************************************************************
 *
 * configuring the hardware
 *
 ******************************************************************************/

void set_GLCD_WriteMode ();
void set_GLCD_ReadMode ();
void system_init_config ();

/*******************************************************************************
 *
 * drive hardware signals
 *
 ******************************************************************************/

void GLCD_delay ();
void GLCD_Write (char P2_cword, char P4_cword);
char GLCD_Read (char P2_cword);

/*******************************************************************************
 *
 * GLCD read operations
 *
 ******************************************************************************/

///
/// raw hardware operations
///
char GLCD_ReadStatus ();
char GLCD_ReadData ();

///
/// checking status
///
int GLCD_IsBusy ();
int GLCD_IsReset ();
int GLCD_IsON ();
int GLCD_IsOFF ();

/*******************************************************************************
 *
 * send commands and data to GLCD
 *
 ******************************************************************************/

void Set_Xaddr (char x);
void Set_Yaddr (char y);
void Set_DisplayStartLine (char z);
void Send_Data (char pattern);
void Set_DisplayOn ();
void Set_DisplayOff ();
void GLCD_Reset ();

#endif






