/******************************************************************
This is to certify that this project is my own work, based on my
personal efforts in studying and applying the concepts learned. I
have constructed the functions and their respective algorithms
and corresponding code by myself. The program was run, tested, and
debugged by my own efforts. I further certify that I have not copied
in part or whole or otherwise plagiarized the work of other students
and/or persons.
Garcia, Brian Alexander M., DLSU ID# 12409626
******************************************************************/

/*
	Description: 	Calculates the resistance value, tolerance and temperature 
					coefficient of and displays a resistor using the color 
					bands of a 4-to-6-band resistor.
	Programmed by: Garcia, Brian Alexander, M. S27B
	Last modified: November 24, 2024
	Version: 1.4
	[ Acknowledgements: Wikipedia. ANSI Escape Codes. 
						https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
	user142019. (2010, July 10). stdlib and colored output in C. 
		Stack Overflow. https://stackoverflow.com/questions/3219393/
		stdlib-and-colored-output-in-c 
	goldenmean. (2011, September 14). How can I use ANSI Escape Codes for 
		outputting colored text in C and C++?. 
		Stack Overflow. https://stackoverflow.com/questions/7414983/
		how-can-i-use-ansi-escape-codes-for-outputting-colored-text-in-c-and-c
	George. (2014, May 23). How to handle exception when scanf of integer gets
	a character. Stack Overflow. https://stackoverflow.com/questions/23825754/
	how-to-handle-exception-when-scanf-of-integer-gets-a-character]
*/

#include <stdio.h>
#include <math.h>

/* 
Resistor Color Band Numerical Assignment // (valid input values)
*/
#define BLACK 	0			// B,b
#define BROWN 	1			// N,n
#define RED 	2			// R,r
#define ORANGE 	3			// O,o	
#define YELLOW 	4			// Y,y
#define GREEN 	5			// G,g
#define BLUE 	6			// E,e
#define VIOLET 	7			// V,v
#define GREY	8			// A,a
#define WHITE 	9			// W,w
#define GOLD 	0.1			// D,d
#define SILVER	0.01		// S,s

/* None/Unused Color Band Z,z */

/* 
	\x1b control sequence initiator 
	[3n foreground, [4n background | color
	ansi color code
*/

#define CLR_BLACK 	"\x1b[38:5:235;40m"							// B,b ;
#define CLR_BROWN 	"\x1b[38;2;150;75;0;48;2;150;75;0m"			// N,n; RGB
#define CLR_RED 	"\x1b[31;41m"								// R,r
#define CLR_ORANGE 	"\x1b[38:5:208;48:5:208m"					// O,o	
#define CLR_YELLOW 	"\x1b[38:5:226;48:5:226m"					// Y,y
#define CLR_GREEN 	"\x1b[32;42m"								// G,g
#define CLR_BLUE 	"\x1b[34;44m"								// E,e
#define CLR_VIOLET 	"\x1b[95;105m"								// V,v
#define CLR_GREY 	"\x1b[90;100m"								// A,a
#define CLR_WHITE 	"\x1b[97;107m"								// W,w
#define CLR_GOLD 	"\x1b[33;43m"								// D,d
#define CLR_SILVER 	"\x1b[37;47m"								// S,s
#define CLR_END 	"\x1b[m"		// ends/resets escape code sequence


/* 	This function displays a greeting and a color code table
	Precondition: is called
	@param none
	@return none
*/
void 
displayGreeting ()
{
	printf("Welcome to the Resistor Color Code Calculator!\n");

	/* Prints out table of resistor color code*/
	printf(	"%7s %10s %15s %15s %12s %20s\n", "Band", "Input", "Digit", 
			"Multiplier", "Tolerance", "Temp Coefficient");
	printf(	"%s%6s%s%s%s\n",  "--------------------", " ", 
			"--------------------", 
			"--------------------", "--------------------");
	
	printf("%s%7s%10s%s   ", CLR_BLACK, "Black", "B,b", CLR_END);
	printf(	"%s%s%6s%16s%14s%18s%s\n", CLR_BLACK, "= == =", "0", "1 ohm", " ",
			"250 ppm/K", CLR_END);
	
	printf("%s%7s%10s%s   ", "\x1b[38;2;150;75;0m", "Brown", "N,n", CLR_END);
	printf("%s%s%s", CLR_BROWN, "= == =", CLR_END);
	printf(	"%s%6s%16s%13s%19s%s\n", "\x1b[38;2;150;75;0m",  "1", "10 ohm", 
			"+-1%", "100 ppm/K", CLR_END);

	printf("%s%7s%10s%s   ", "\x1b[31m", "Red", "R,r", CLR_END);
	printf("%s%s%s", CLR_RED, "= == =", CLR_END);	
	printf(	"%s%6s%16s%13s%19s%s\n", "\x1b[31m",  "2", "100 ohm", "+-2%", 
			"50 ppm/K", CLR_END);
	
	printf("%s%7s%10s%s   ", "\x1b[38:5:208m", "Orange", "O,o", CLR_END);
	printf("%s%s%s", CLR_ORANGE, "= == =", CLR_END);
	printf(	"%s%6s%16s%14s%18s%s\n", "\x1b[38:5:208m",  "3", "1K ohm", " ", 
			"15 ppm/K", CLR_END);
	
	printf("%s%7s%10s%s   ", "\x1b[38:5:226m", "Yellow", "Y,y", CLR_END);
	printf("%s%s%s", CLR_YELLOW, "= == =", CLR_END);
	printf(	"%s%6s%16s%14s%18s%s\n", "\x1b[38:5:226m",  "4", "10K ohm", " ", 
			"25 ppm/K", CLR_END);
	
	printf("%s%7s%10s%s   ", "\x1b[32m", "Green", "G,g", CLR_END);
	printf("%s%s%s", CLR_GREEN, "= == =", CLR_END);
	printf(	"%s%6s%16s%13s%19s%s\n", "\x1b[32m",  "5", "100K ohm", "+-0.5%", 
			"20 ppm/K", CLR_END);

	printf("%s%7s%10s%s   ", "\x1b[34m", "Blue", "E,e", CLR_END);
	printf("%s%s%s", CLR_BLUE, "= == =", CLR_END);
	printf(	"%s%6s%16s%13s%19s%s\n", "\x1b[34m",  "6", "1M ohm", "+-0.25%", 
			"10 ppm/K", CLR_END);
	
	printf("%s%7s%10s%s   ", "\x1b[95m", "Violet", "V,v", CLR_END);
	printf("%s%s%s", CLR_VIOLET, "= == =", CLR_END);
	printf(	"%s%6s%16s%13s%19s%s\n", "\x1b[95m",  "7", " ", "+-0.1%", 
			"5 ppm/K", CLR_END);

	printf("%s%7s%10s%s   ", "\x1b[90m", "Grey", "A,a", CLR_END);
	printf("%s%s%s", CLR_GREY, "= == =", CLR_END);
	printf(	"%s%6s%16s%13s%19s%s\n", "\x1b[90m",  "8", " ", " ", "1 ppm/K",
			CLR_END);

	printf("%s%7s%10s%s   ", "\x1b[97m", "White", "W,w", CLR_END);
	printf("%s%s%s", CLR_WHITE, "= == =", CLR_END);
	printf("%s%6s%16s%13s%19s%s\n", "\x1b[97m",  "9", " ", " ", " ", CLR_END);
	
	printf("%s%7s%10s%s   ", "\x1b[33m", "Gold", "D,d", CLR_END);
	printf("%s%s%s", CLR_GOLD, "= == =", CLR_END);
	printf(	"%s%6s%16s%13s%19s%s\n", "\x1b[33m",  " ", "0.1 ohm", "+-5%",
			" ", CLR_END);
	
	printf("%s%7s%10s%s   ","\x1b[37m", "Silver", "S,s", CLR_END);
	printf("%s%s%s", CLR_SILVER, "= == =", CLR_END);
	printf(	"%s%6s%16s%13s%19s%s\n", "\x1b[37m",  " ", "0.01 ohm", "+-10%", 
			" ", CLR_END);
	
	printf("\n");
}

/* 	This function gets number of color bands on resistor
	Precondition: is called; expects integer input
	@param nBandNum stores number of color bands
	@param nBandNum stores unexpected char input
	@return nBandNum (4, 5, or 6)
*/
int 
getBandNum () 
{
	int nBandNum;
	char cTemp;
	
	do 
	{
	printf("4, 5 or 6 bands: ");
	scanf("%d", &nBandNum);
		
	do 
	{
	scanf("%c", &cTemp);		// get rid of char input
	} while (cTemp != '\n');

	if (nBandNum != 4 && nBandNum != 5 && nBandNum != 6)
	{
		printf("Invalid Input\n");
	}
	} while (nBandNum != 4 && nBandNum != 5 && nBandNum != 6);
	
	return nBandNum;
}

/* 	This function determines input type
	Precondition: is called; expects integer input
	@param nSelectType stores input type
	@param cTemp stores unexpected char input
	@return nSelectType (either 1 or 0)
*/
int 
chooseInput () 
{
	int nSelectType = 2;
	char cTemp;
	
	do 
	{
	printf("Input Mode: per-line [0] or one-line [1]: ");
	scanf("%d", &nSelectType);	// only accepts integer input
	
	if (nSelectType == 1 || nSelectType == 0) 
	{
		printf("Success\n");
	}
	else 
	{
		do 
		{
		scanf("%c", &cTemp);		// get rid of char input
		} while (cTemp != '\n'); 
	}

	if (nSelectType != 1 && nSelectType != 0)
	{
		printf("Invalid input\n");
	}
	} while (nSelectType != 1 && nSelectType != 0);
	
	return nSelectType;
}

/* 	This function gets the band colors of the resistor via one-line or 
	per-line input
	Precondition: char variables to store values; expects correct input
	@param nBandNum is the number of bands on the given resistor 
	@param *cBand1 stores char value of first color band 
	@param *cBand2 stores char value of second color band
	@param *cBand3 stores char value of third color band
	@param *cBand4 stores char value of fourth color band
	@param *cBand5 stores char value of fifth color band
	@param *cBand6 stores char value of sixth color band
	@param nSelectType stores 1 for one-line input or 0 for per-line input
	@param 	cTemp stores placeholder char value to enable one-line scanf and
			char input
	@return none
*/
void 
getBands (	int nSelectType, char *cBand1, char *cBand2, char *cBand3, 
			char *cBand4, char *cBand5, char *cBand6)
{
	char cTemp;
	
	printf("input 'Z' or 'z' if band is inapplicable or unused.\n");
	printf(	"%s%s", "Example: If 4 or 5 band resistor,", 
			"input 'Z' or 'z' for unused bands.\n");
	
	switch (nSelectType)
	{
		case 0:
			printf("First Band: ");
			scanf("%c%c", &cTemp, cBand1);
			printf("Second Band: ");
			scanf("%c%c", &cTemp, cBand2);
			printf("Third Band: ");
			scanf("%c%c", &cTemp, cBand3);
			printf("Fourth Band: ");
			scanf("%c%c", &cTemp, cBand4);
			printf("Fifth Band: ");
			scanf("%c%c", &cTemp, cBand5);
			printf("Sixth Band: ");
			scanf("%c%c", &cTemp, cBand6);
			break;
		case 1:
			printf(	"%s%s", 
					"Sample Input: 4 band r r r r z z; 5 band r r r r r z 6",
					" band r r r r r r\n");
			printf("input 6 color bands separated by spaces: ");
			scanf("%c%c%c%c%c%c%c%c%c%c%c%c", &cTemp, cBand1, &cTemp, cBand2,
										&cTemp, cBand3, &cTemp, cBand4, 
										&cTemp, cBand5, &cTemp, cBand6);
			break;
	}
	
}

/*
	prints equivalent band color from inputted band color
	Precondition: band value is given is a character
	@param cBand is the char color code
	@return none
*/
void 
printBandColor (char cBand)
{
	switch (cBand)
	{
		case 'B':
		case 'b':
			printf("%s#%s", CLR_BLACK, CLR_END);
			break;
		case 'N':
		case 'n':
			printf("%s#%s", CLR_BROWN, CLR_END);
			break;
		case 'R':
		case 'r':
			printf("%s#%s", CLR_RED, CLR_END);
			break;
		case 'O':
		case 'o':
			printf("%s#%s", CLR_ORANGE, CLR_END);
			break;
		case 'Y':
		case 'y':
			printf("%s#%s", CLR_YELLOW, CLR_END);
			break;
		case 'G':
		case 'g':
			printf("%s#%s", CLR_GREEN, CLR_END);
			break;
		case 'E':
		case 'e':
			printf("%s#%s", CLR_BLUE, CLR_END);
			break;
		case 'V':
		case 'v':
			printf("%s#%s", CLR_VIOLET, CLR_END);
			break;
		case 'A':
		case 'a':
			printf("%s#%s", CLR_GREY, CLR_END);
			break;
		case 'W':
		case 'w':
			printf("%s#%s", CLR_WHITE, CLR_END);
			break;
		case 'D':
		case 'd':
			printf("%s#%s", CLR_GOLD, CLR_END);
			break;
		case 'S':
		case 's':
			printf("%s#%s", CLR_SILVER, CLR_END);
			break;
		case 'Z':
		case 'z':
			printf("%s#%s", CLR_END, CLR_END);
			break;	
	}
}

/*
	displays color band
	Precondition: band value is given is a character; positive int band length
	@param cBand is the char color band code
	@param nBandlength determines character length of band displayed
	@return none
*/
void 
displayBandColor (char cBand, int nBandLength)
{
	if (nBandLength == 6)
		printf(" ");
	for (int i = 1; i <= nBandLength; i++) 
	{
		printBandColor (cBand);
	}
	printf("\n");
}

/* 	
	This function gets the integer band value of the resistor color band 
	inputted
	Precondition: color band in char is given
	@param cBand contains char equivalent of band color
	@param cTemp contains char of new band input for invalid band colors 
	@param *nBand stores value of band
	@return none
*/
void 
getBandValue (char cBand, int *nBand)
{
	switch (cBand)
	{
		case 'B':
		case 'b':
			*nBand = BLACK;
			break;
		case 'N':
		case 'n':
			*nBand = BROWN;
			break;
		case 'R':
		case 'r':
			*nBand = RED;
			break;
		case 'O':
		case 'o':
			*nBand = ORANGE;
			break;
		case 'Y':
		case 'y':
			*nBand = YELLOW;
			break;
		case 'G':
		case 'g':
			*nBand = GREEN;
			break;
		case 'E':
		case 'e':
			*nBand = BLUE;
			break;
		case 'V':
		case 'v':
			*nBand = VIOLET;
			break;
		case 'A':
		case 'a':
			*nBand = GREY;
			break;
		case 'W':
		case 'w':
			*nBand = WHITE;
			break;
		case 'Z':
		case 'z':
			*nBand = 0;
			break;
	}
}

/*
	Display resistor with correct color bands inputted
	Precondition: color bands are characters and correct
	@param cBand1-6 inputted color code
	@return none
*/
void 
displayResistor (	int nBandNum, char cBand1, char cBand2, char cBand3,
					char cBand4, char cBand5, char cBand6) 
{
	
	for (int i = 1; i <= 3; i++) 
	{
		if (i == 1) 
		{
			printf("1 23");
			if (nBandNum == 4)
				printf(" 4");
			else 
			{
				printf("4 5");
				if (nBandNum == 6)
					printf(" 6");
			}
			printf("\n");
		}
		else 
		{
			printBandColor(cBand1);
			printf(" ");
			printBandColor(cBand2);
			printBandColor(cBand3);
			if (nBandNum == 4)
				printf(" ");
			printBandColor(cBand4);
			if (nBandNum >= 5)
				printf(" ");
				printBandColor(cBand5);
			if(nBandNum == 6)
				printf(" ");
				printBandColor(cBand6);
			printf("\n");
		}
	}
	
	printf(" ______ \n");
	printf("/      \\\n");
	displayBandColor (cBand1, 8);
	printf("\\      /\n");
	displayBandColor (cBand2, 6);
	displayBandColor (cBand3, 6);
	displayBandColor (cBand4, 6);
	printf(" |    |\n");
	displayBandColor (cBand5, 6);
	printf("/      \\\n");
	displayBandColor (cBand6, 8);
	printf("\\______/\n");
}

/* 	
	This function gets the combined integer value of the resistor's first 2-3 bands
	Precondition: first 3 band values are found
	@param nFirstBand is the value of first color band
	@param nSecondBand is the value of second color band
	@param nThirdBand is the value of third color band
	@return the 1-3 digit value of first 2-3 color bands
*/
int 
getBandDigit (int nFirstBand, int nSecondBand, int nThirdBand)
{
	return nFirstBand * 100 + nSecondBand * 10 + nThirdBand;
}

/* 	
	This function gets the final resistance value of the resistor given the 
	multipler color band value and combined value of digit color bands
	Precondition: multiplier color band and combined value of digit bands found
	@param cBand is the character value of multiplier color band
	@param nBand is the integer value of digit color bands
	@return the float base resistance value of resistor
*/
float 
getMultiplier (char cBand, int nBand)
{
	float fBand;
	switch (cBand)
	{
		case 'B':
		case 'b':
			fBand = nBand * pow(10, 0);
			break;
		case 'N':
		case 'n':
			fBand = nBand * pow(10, 1);
			break;
		case 'R':
		case 'r':
			fBand = nBand * pow(10, 2);
			break;
		case 'O':
		case 'o':
			fBand = nBand * pow(10, 3);
			break;
		case 'Y':
		case 'y':	
			fBand = nBand * pow(10, 4);
			break;
		case 'G':
		case 'g':
			fBand = nBand * pow(10, 5);
			break;
		case 'E':
		case 'e':
			fBand = nBand * pow(10, 6);
			break;
		/* 
		violet to white multiplier is not in the resistor color code table in 
		the specs so it is not displayed in the greeting table however it is 
		in the code anyway as it is in sample runs
		*/
		case 'V':
		case 'v':
			fBand = nBand * pow(10, 7);
			break;
		case 'A':
		case 'a':
			fBand = nBand * pow(10, 8);
			break;
		case 'W':
		case 'w':
			fBand = nBand * pow(10, 9);
			break;
		case 'D':
		case 'd':
			fBand = nBand * 0.1;
			break;
		case 'S':
		case 's':	
			fBand = nBand * 0.01;
			break;
	}
	return fBand;
}

/* 	
	This function gets the tolerance level given the fifth color band, and 
	gets the possible min (lower) and max (upper) resistance value of the given
	base resistance value
	Precondition: fifth color band and base resistance
	@param cBand is the character value of fifth color band
	@param fResistor is the deviation value of tolerance
	@param fResistorValue is the float value of resistor
	@param *fLower stores float value of min possible resistance
	@param *fUpper stores float value of max possible resistance
	@return none
*/
void
getTolerance (char cBand, float fResistorValue, float *fLower, float *fUpper)
{
	float fTolerance;
	float fResistor;
	switch (cBand)
	{
		case 'N':
		case 'n':
			fResistor = fResistorValue * .01;
			fTolerance = 1;
			break;
		case 'R':
		case 'r':
			fResistor = fResistorValue * .02;
			fTolerance = 2;
			break;
		case 'G':
		case 'g':
			fResistor = fResistorValue * .005;
			fTolerance = 0.5;
			break;
		case 'E':
		case 'e':
			fResistor = fResistorValue * .0025;
			fTolerance = 0.25;
			break;
		case 'V':
		case 'v':
			fResistor = fResistorValue * .001;
			fTolerance = 0.1;
			break;
		/* 
		grey tolerance ('A' is not in the resistor color code table in the 
		specs so it is not displayed in the greeting table however it is in
		the code anyway
		*/
		case 'A':
		case 'a':
			fResistor = fResistorValue * .0005;
			fTolerance = 0.05;
			break;
		case 'D':
		case 'd':
			fResistor = fResistorValue * .05;
			fTolerance = 5;
			break;
		case 'S':
		case 's':
			fResistor = fResistorValue * .1;
			fTolerance = 10;
			break;
		case 'Z':
		case 'z':
			fResistor = fResistorValue * .2;
			fTolerance = 20; // no band is +-20% tolerance
			break;
	}
	
	*fUpper = fResistorValue + fResistor;
	*fLower = fResistorValue - fResistor;
	
	printf(	"%.2f%%.\nResistance Range Value: %.2f ohms to %.2f ohms.\n", 
			fTolerance, *fLower, *fUpper);
}

/* 	
	This function displays temperature coefficient of resistor
	Precondition: sixth color band given
	@param cBand is the character value of sixth color band
	@param nTempCoefficient is the temp coefficient of the resistor
	according to the color band
	@return none
*/
void 
displayTempCoefficient(char cBand)
{
	int nTempCoefficient;
	switch (cBand)
	{
		case 'B':
		case 'b':
			nTempCoefficient = 250;
			break;
		case 'N':
		case 'n':
			nTempCoefficient = 100;
			break;
		case 'R':
		case 'r':
			nTempCoefficient = 50;
			break;
		case 'O':
		case 'o':	
			nTempCoefficient = 15;
			break;
		case 'Y':
		case 'y':	
			nTempCoefficient = 25;
			break;
		case 'G':
		case 'g':
			nTempCoefficient = 20;
			break;
		case 'E':
		case 'e':	
			nTempCoefficient = 10;
			break;
		case 'V':
		case 'v':
			nTempCoefficient = 5;
			break;
		case 'A':
		case 'a':
			nTempCoefficient = 1;
			break;
		default:
			cBand = 'Z';
	} 
	
	if (cBand == 'Z' || cBand == 'z')
	{
		printf("\n");
	}
	else
	{
		printf("The temperature coefficient is %d ppm/K.\n", nTempCoefficient);
	}
}

/* 	
	This function checks if resistor value exceeds 100 mega ohms and displays 
	a warning message if true
	Precondition: base resistance and max resistance
	@param fBaseResistance is the float value of base resistance
	@param fUpperResistance is the float value of max possible resistance
	@return none
*/
void 
checkIfImpractical (float fBaseResistance, float fUpperResistance)
{
	if (fBaseResistance > 10000000 || fUpperResistance > 100000000)
	{
		printf("Warning! This value is above 100 Mega-ohms. No Practical Application!\n");
	}
}

/* 	This function does the entire resistor calculation, operations, and 
	displays needed info
	@param nFirstBand to nSixthBand are the variables for the first to sixth
	color band
	@param nBandDigit is the resistance before multiplier is applied
	@param nBandNum is the number of bands of the given resistor
	@param fBandMult is the resistance after multiplier is applied
	@param fLower is the minimum possible resistance of the given resistor
	@param fUpper is the maximum possible resistance of the given resistor
	@param cBand1 to cBand6 are the color letter equivalents for the first 
	to sixth color band
	@return none
*/
void 
calculateResistance () 
{
	int nFirstBand, nSecondBand, nThirdBand;
	int nBandDigit, nBandNum;
	int nSelectType;
	
	float fBandMult;
	
	float fLower, fUpper;
	char cBand1, cBand2, cBand3, cBand4, cBand5, cBand6;
	
	nBandNum = getBandNum();
	nSelectType = chooseInput();
	getBands(	nSelectType, &cBand1, &cBand2, &cBand3, &cBand4, &cBand5,
				&cBand6);
	
	if (nBandNum == 4) 
	{
		getBandValue(cBand1, &nFirstBand);
		getBandValue(cBand2, &nSecondBand);
		nThirdBand = 0;
		nBandDigit = getBandDigit(nThirdBand, nFirstBand, nSecondBand);
	}
	else if (nBandNum == 5 || nBandNum == 6) 
	{
		getBandValue(cBand1, &nFirstBand);
		getBandValue(cBand2, &nSecondBand);
		getBandValue(cBand3, &nThirdBand);
		nBandDigit = getBandDigit(nFirstBand, nSecondBand, nThirdBand);
	}
	
	if (nBandNum == 4) 
	{
		displayResistor(nBandNum, cBand1, cBand2, cBand3, cBand4, 'z', 'z');
	}
	else if (nBandNum == 5) 
	{
		displayResistor(	nBandNum, cBand1, cBand2, cBand3, cBand4, cBand5,
							'z');
	}
	else if (nBandNum == 6) 
	{
		displayResistor(nBandNum, cBand1, cBand2, cBand3, cBand4, cBand5, 
						cBand6);
	}
	
	if (nBandNum == 4) 
	{
		fBandMult = getMultiplier(cBand3, nBandDigit);
	}
	else if (nBandNum == 5 || nBandNum == 6) 
	{
		fBandMult = getMultiplier(cBand4, nBandDigit);
	}
	
	printf("Your resistor value is %.2f ohms, %s", fBandMult,
			"with a tolerance of ");
	
	if (nBandNum == 4) 
	{
		getTolerance(cBand4, fBandMult, &fLower, &fUpper);
	}
	else if (nBandNum == 5 || nBandNum == 6) 
	{
		getTolerance(cBand5, fBandMult, &fLower, &fUpper);
	}
	
	if (nBandNum == 6) 
	{
		displayTempCoefficient(cBand6);
	}

	checkIfImpractical (fBandMult, fUpper);
}

int 
main ()
{
	char cTemp, cState;
	do
	{
		displayGreeting();
		calculateResistance();
		
		printf("Calculate again? (y/n): ");
		scanf("%c%c", &cTemp, &cState);
		
	} while (cState == 'y' || cState == 'Y');
}
