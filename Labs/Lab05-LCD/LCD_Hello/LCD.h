/*******************************************************************************
 *
 * the LCD infrastructure module
 *
 ******************************************************************************/

#ifndef LCD_h

#define LCD_h

extern char LCD_status;

///
/// hardware initialization
///
void LCD_PortConfig ();
void LCD_Init ();

///
/// setting LCD status
///
void LCD_Status_SetRS ();
void LCD_Status_ClearRS ();
void LCD_Status_SetWord (char word);
void LCD_Status_SetEnable ();
void LCD_Status_ClearEnable ();

///
/// LCD actions
///
void LCD_Delay ();
void LCD_SendCommand (char cmd);
void LCD_SendData (char dat);

///
/// high-level APIs
///
void LCD_PrintString (char* str);
void LCD_ClearScreen ();

#endif




