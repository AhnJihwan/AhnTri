#include "../kernel.h"
#include "../init/api.h"

void acal(){
	os_print_color("                     Calendar - Year 2021                         \n", BLACK, GREY);
	printf("                            2021                                  \n");
	printf("      January               February               March          \n");
	printf("Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  \n");
	printf("                1  2      1  2  3  4  5  6      1  2  3  4  5  6  \n");
	printf(" 3  4  5  6  7  8  9   7  8  9 10 11 12 13   7  8  9 10 11 12 13  \n");
	printf("10 11 12 13 14 15 16  14 15 16 17 18 19 20  14 15 16 17 18 19 20  \n");
	printf("17 18 19 20 21 22 23  21 22 23 24 25 26 27  21 22 23 24 25 26 27  \n");
	printf("24 25 26 27 28 29 30  28                    28 29 30 31           \n\n");
	suspend(200);
	clscr();
	printf("       April                  May                   June          \n");
	printf("Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  \n");
	printf("             1  2  3                     1         1  2  3  4  5  \n");
	printf(" 4  5  6  7  8  9 10   2  3  4  5  6  7  8   6  7  8  9 10 11 12  \n");
	printf("11 12 13 14 15 16 17   9 10 11 12 13 14 15  13 14 15 16 17 18 19  \n");
	printf("18 19 20 21 22 23 24  16 17 18 19 20 21 22  20 21 22 23 24 25 26  \n");
	printf("25 26 27 28 29 30     23 24 25 26 27 28 29  27 28 29 30           \n");
	printf("                      30 31                                       \n");
	printf("\n");
	suspend(200);
	clscr();
	printf("        July                 August              September        \n");
	printf("Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  \n");
	printf("             1  2  3   1  2  3  4  5  6  7            1  2  3  4  \n");
	printf(" 4  5  6  7  8  9 10   8  9 10 11 12 13 14   5  6  7  8  9 10 11  \n");
	printf("11 12 13 14 15 16 17  15 16 17 18 19 20 21  12 13 14 15 16 17 18  \n");
	printf("18 19 20 21 22 23 24  22 23 24 25 26 27 28  19 20 21 22 23 24 25  \n");
	printf("25 26 27 28 29 30 31  29 30 31              26 27 28 29 30        \n");
	printf("                                                                  \n");
	printf("\n");
	printf("      October               November              December        \n");
	printf("Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  \n");
	printf("                1  2      1  2  3  4  5  6            1  2  3  4  \n");
	printf(" 3  4  5  6  7  8  9   7  8  9 10 11 12 13   5  6  7  8  9 10 11  \n");
	printf("10 11 12 13 14 15 16  14 15 16 17 18 19 20  12 13 14 15 16 17 18  \n");
	printf("17 18 19 20 21 22 23  21 22 23 24 25 26 27  19 20 21 22 23 24 25  \n");
	printf("24 25 26 27 28 29 30  28 29 30              26 27 28 29 30 31     \n");
	printf("31    ");
	suspend(200);
	clscr();
}
