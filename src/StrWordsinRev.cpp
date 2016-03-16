/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len)
{
	if (len > 0 && input != NULL && input[0] != '\0')
	{
		int i;
		int space = 0;
		for (i = 0; i < len; i++)
			if (input[i] == ' ')
				space = 1;
		if (space == 0)
			return;

		for (i = 0; i < len / 2; i++)
		{
			char t = input[i];
			input[i] = input[len - i - 1];
			input[len - i - 1] = t;
		}
		int high = 0, low = 0;
		while (high <len)
		{
			if (input[low] == ' ')
				low++;
			while (input[high] != ' '&&high<len)
				high++;
			for (i = 0; i < (high - low + 1) / 2; i++)
			{
				char c;
				c = input[i + low];
				input[i + low] = input[high - i - 1];
				input[high - i - 1] = c;
			}
			low = ++high;
			high++;

		}

	}
	return;

}