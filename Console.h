#pragma once

namespace Console
{
	#include<stdio.h>


	class Color
	{
		#define NRM		"\x1B[0m"
		#define GRY		"\x1B[1;30m"
		#define RED		"\x1B[1;31m"
		#define GRN		"\x1B[1;32m"
		#define YEL		"\x1B[1;33m"
		#define BLU		"\x1B[1;34m"
		#define MAG		"\x1B[1;35m"
		#define CYN		"\x1B[1;36m"
		#define WHT		"\x1B[1;37m"
		
		#define B_NRM	"\x1B[0m"
		#define B_GRY	"\x1B[0;30m"
		#define B_RED	"\x1B[0;31m"
		#define B_GRN	"\x1B[0;32m"
		#define B_YEL	"\x1B[0;33m"
		#define B_BLU	"\x1B[0;34m"
		#define B_MAG	"\x1B[0;35m"
		#define B_CYN	"\x1B[0;36m"
		#define B_WHT	"\x1B[0;37m"
		
		#define BG_NRM	"\x1B[40m"
		#define BG_RED	"\x1B[41m"
		#define BG_GRN	"\x1B[42m"
		#define BG_YEL	"\x1B[43m"
		#define BG_BLU	"\x1B[44m"
		#define BG_MAG	"\x1B[45m"
		#define BG_CYN	"\x1B[46m"
		#define BG_WHT	"\x1B[47m"
	};

	#define clear() puts("\x1B[2J")
	#define cursor_move(X, Y) printf("\033[%d;%dH", Y, X)
#define beep() printf("\a")

	#define enter_alt_screen() puts("\033[?1049h\033[H")
	#define exit_alt_screen() puts("\033[?1049l")
};