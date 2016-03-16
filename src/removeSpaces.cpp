/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

#include<stdio.h>
char removeSpaces(char *str)
{
	if (str != NULL && str != "")
	{
		int i = 0, len = 0, j = 0;
		while (str[len] != '\0')
			len++;
		len++;
		for (i = 0; i <len; i++)
		{
			if (str[i] != ' ')
			{
				str[j] = str[i];
				j++;
			}
		}
	}
	else
		return '\0';
	return '\0';
}