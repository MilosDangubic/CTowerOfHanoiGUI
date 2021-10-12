/*
 * kbgi_lib.h
 *
 *  Created on: Jan 3, 2015
 *      Author: kalman
 */

#ifndef KBGI_LIB_H_
#define KBGI_LIB_H_

// NUMERIC CONSTRAINTS
#define WINDOW_MAX (10)
#define KBD_BUF_LEN (10)

// CONSTANTS
#define KBGI_SUCCESS (0)
#define KBGI_ERROR (-1)
#define KBGI_KBUF_EMPTY (-2)
#define KBGI_EXISTS (1)
#define KBGI_DOES_NOT_EXIST (0)

// COLORS
#define KBGI_BLACK (0)
#define KBGI_RED (1)
#define KBGI_YELLOW (2)
#define KBGI_GREEN (3)
#define KBGI_CYAN (4)
#define KBGI_MAGENTA (5)
#define KBGI_BLUE (6)
#define KBGI_WHITE (7)
#define KBGI_GREY (8)
#define KBGI_DARK_GREY (9)
#define KBGI_LIGHT_GREY (10)
#define KBGI_DARK_BLUE (11)
#define KBGI_DARK_GREEN (12)
#define KBGI_DARK_RED (13)
#define KBGI_DARK_YELLOW (14)
#define KBGI_ORANGE (15)

#define DIR_UP (1)
#define DIR_RIGHT (2)
#define DIR_DOWN (4)
#define DIR_LEFT (8)

// USER FUNCTIONS
// INITIALIZATION
int K_kbgi(void);
// SYSTEM
void K_Wait(unsigned int msec);
int K_WindowExists(unsigned int WinN);
// WINDOW MANAGEMENT
int K_OpenWindow(unsigned int WinN, char *WindowTitle);
int K_EndWindow(unsigned int WinN);
int K_WaitForClose(unsigned int WinN);
int K_WaitAllClose(void);
int K_MoveWindow(unsigned int WinN, int x, int y);
int K_Refresh(unsigned int WinN);
int K_SetAutorefresh(unsigned int WinN, unsigned char x);
// DRAWING
int K_Clear(unsigned int WinN, unsigned int color);
int K_Line(unsigned int WinN, int x0, int y0, int x1, int y1);
int K_MoveTo(unsigned int WinN, int x, int y);
int K_LineTo(unsigned int WinN, int x, int y);
int K_Rectangle(unsigned int WinN, int x0, int y0, int x1, int y1);
int K_Box(unsigned int WinN, int x0, int y0, int x1, int y1);
int K_FilledEllipse(unsigned int WinN, int x, int y, int R1, int R2);
int K_Ellipse(unsigned int WinN, int x, int y, int R1, int R2);
// COLOR SELECTION
int K_SetDrawColor(unsigned int WinN, unsigned int color);
int K_SetFillColor(unsigned int WinN, unsigned int color);
int K_SetTextColor(unsigned int WinN, unsigned int color);
// TEXT OUTPUT
int K_Text(unsigned int WinN, int x, int y, char *text, int len);
// KEYBOARD INPUT
int K_ReadKey(unsigned int WinN);
int K_ClearKeys(unsigned int WinN);
int K_KbdDir(unsigned int WinN);

#endif /* KBGI_LIB_H_ */
