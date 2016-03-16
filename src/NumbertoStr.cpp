/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str, int afterdecimal)
{
	int k = 0;
	while (k != afterdecimal)
	{
		number = number * 10;
		k++;
	}
	int num = number;
	int i = 0;
	if (num < 0)
		num = -num;
	while (k>0)
	{
		str[i] = num % 10 + '0';
		num /= 10;
		i++;
		k--;
	}
	if (afterdecimal)
	{
		str[i] = '.';
		i++;
	}

	while (num != 0)
	{
		str[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	if (number < 0)
	{
		str[i] = '-';
		i++;
	}
	int j;
	char c;
	for (j = 0; j<i / 2; j++)
	{
		c = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = c;
	}
	str[i] = '\0';
	return;
}
