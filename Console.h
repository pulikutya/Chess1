#pragma once

namespace Console
{
	#include<stdio.h>


#define Reset						"\033[0m"/*supported*/
#define Bold						"\033[1m"/*supported*/
//#define Faint						"\033[2m"/*un*/
//#define Italic						"\033[3m"/*un*/
#define Underline					"\033[4m"/*supported*/
#define Slow_Blink					"\033[5m"
#define Rapid_Blink					"\033[6m"
#define Inverse_video				"\033[7m"/*supported*//*inverts back adn foreground colors*/
//#define Conceal						"\033[8m"//un
//#define Crossed_out					"\033[9m"//un
#define Default_font				"\033[10m"

//#define Fraktur						"\033[20m"//un
#define Bold_off					"\033[21m"/*or double underline*/
//#define Normal_Intensity			"\033[22m"//yes

#define Underline_off				"\033[24m"
#define Blink_off					"\033[25m"
#define Inverse_off					"\033[27m"
//#define Conceal_off					"\033[28m"
//#define Crossed_out_off				"\033[29m"
//#define Set_Foreground_Color(c)	{printf("\033[38;5;%c5m", c);}
//#define Set_Foreground_Color(r, g, b)"\033]38;" + r + ";" + g + ";" + b + "m";
#define Default_Foreground_Color	"\033[39m";

#define Default_Background_Color	"\033[49m";

//#define Framed "\033[51m"
//#define Encircled "\033[52m"
//#define Overlined "\033[53m"
//#define Framed_encircled_off "\033[54m"
//#define Overlined_off "\033[55m"

	#define clear() puts("\x1B[2J")
	#define cursor_move(X, Y) printf("\033[%d;%dH", Y, X)
#define beep() printf("\a")

	//#define enter_alt_screen() puts("\033[?1049h\033[H")
	//#define exit_alt_screen() puts("\033[?1049l")
};