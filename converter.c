#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int binToDec()
{
	int dec = 0;
	int cDec;
	char bin[20];
	int size;
	int base = 1;
	int i = 1;

	printf("\nEnter a number in binary to convert\n");
	scanf("%s", bin);

	size = strlen(bin);
	
	if (size == 0) {
		return 0;
	}

	while (i <= size) {
		 cDec = (bin[size - i] - '0') * base;
		 dec += cDec;
		 i++;
		 base *= 2;
	}

	return dec;
}

int decToBin() {
	int place = 1;
	int bin;
	int mod;
	int div = 1;
	int dec;
	int neg = 0;

	printf("\nEnter a number in decimal to convert\n");
	scanf("%d", &dec);

	if (dec < 0)
	{
		neg = 1;
		dec *= -1;
	}

	if (dec == 0)
	{
		return 0;
	}
	
	div = dec;

	while (div >= 1) {
		mod = div % 2;
		div = div / 2;
		bin += mod * place;

		place *= 10;

	}

	if (neg)
	{
		return bin *= -1;
	}
	else {
		return bin;
	}

}

int octToDec() {
	char bin[20];
	int size;
	int i = 1;
	int dec = 0;
	int cDec;
	int base = 1;
	
	printf("\nEnter a number in octal to convert\n");
	scanf("%s", bin);

	size = strlen(bin);

	if (size == 0) {
		return 0;
	}

	while (i <= size) {
		 cDec = (bin[size - i] - '0') * base;
		 dec += cDec;
		 i++;
		 base *= 8;
	}

	return dec;
}

int hexToDec() {
	char bin[20];
	int size;
	int i = 1;
	int dec = 0;
	int cDec;
	int base = 1;

	char digit;
	int realDigit;

	printf("\nEnter a number in hex to convert\n");
	scanf("%s", bin);

	size = strlen(bin);

	if (size == 0) {
		return 0;
	}

	while (i <= size) {
		digit = bin[size - i];

		if (isdigit(digit) == 0) {
			switch (digit) {
				case 'A' :
				case 'a' :
					realDigit = 10;
					break;	
				case 'B' :
				case 'b' :
					realDigit = 11;
					break;
				case 'C' :
				case 'c' :
					realDigit = 12;
					break;
				case 'D' :
				case 'd' :
					realDigit = 13;
					break;
				case 'E' : 
				case 'e' :
					realDigit = 14;
					break;
			}

			cDec = realDigit * base;
		}
		else {
			cDec = (digit - '0') * base;
		}

		dec += cDec;
		i++;
		base *= 16;
	}

	return dec;
}

int numberCollect()
{
	int dec;

	printf("\nEnter a number in decimal to convert\n");
	scanf("%d", &dec);

	if (dec < 0) {
		dec = dec * -1;
	}

	return dec;
}


int main()
{
	int choice;
	
	printf("Welcome to Base Converter\n\n");
	
	do {
		printf("Choose an option:\n");
		printf("1) Binary to Decimal\n");
		printf("2) Decimal to Binary\n");
		printf("3) Octal to Decimal\n");
		printf("4) Decimal to Octal\n");
		printf("5) Hex to Decimal\n");
		printf("6) Decimal to Hex\n");
		printf("7) Exit\n");

		scanf("%d", &choice);

		switch (choice) {
			case 1: printf("\nThe number in decimal is %d\n\n", binToDec()); break;
			case 2: printf("\nThe number in binary is %d\n\n", decToBin()); break;
			case 3: printf("\nThe number in decimal is %d\n\n", octToDec()); break;
			case 4: printf("\nThe number in octal is %o\n\n", numberCollect()); break;
			case 5: printf("\nThe number in decimal is %d\n\n", hexToDec()); break;
			case 6: printf("\nThe number in hex is %X\n\n", numberCollect()); break;
			case 7: return EXIT_SUCCESS;
			default: printf("\nInvalid choice\n\n");
		}
	}
	while (1);

	return EXIT_SUCCESS;
}

