/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int comp(char *, char *);
char ** commonWords(char *str1, char *str2) 
{
	if (str1 != NULL && str2 != NULL)
	{
		int sp1 = 0, sp2 = 0, len1=0, len2=0,i=0,j=0;
		while (str1[len1] != '\0')
		{
			if (str1[len1] == ' ')
				sp1++;
			len1++;
		}
		while (str2[len2] != '\0')
		{
			if (str2[len2] == ' ')
				sp2++;
			len2++;
		}
		len1++; 
		len2++; 
		sp1++; 
		sp2++;
		if (len1 == sp1 || len2 == sp2)
			return NULL;
		char **s1 = (char **)calloc(sp1,sizeof(char *));
		char **s2 = (char **)calloc(sp2,sizeof(char *));
		
		j = 0;
		int k = 0;
		for (i = 0; i < sp1; i++)
		{
			s1[i] = (char*)malloc(10 * sizeof(char));
			for (j=0; k < len1; k++,j++)
			{
				if (str1[k] == ' ' || str1[k] == '\0')
				{
					s1[i][j] = '\0';
					break;
				}
				s1[i][j] = str1[k];
			}
			k++;
		}
		k= 0;
		for (i = 0; i < sp2; i++)
		{
			s2[i] = (char *)malloc(10 * sizeof(char));
			for (j = 0; k < len2; k++, j++)
			{
				if (str2[k] == ' ' || str2[k] == '\0')
				{
					s2[i][j] = '\0';
					break;
				}
				s2[i][j] = str2[k];
			}
			k++;
		}
		k = 0;
		int yes = 0;
		char** s = (char**)calloc(10, sizeof(char *));
		for (i = 0; i < sp1; i++)
		{
			for (j = 0; j < sp2; j++)
			{
				if (comp(s1[i], s2[j]))
				{
					yes = 1;
					int l = 0;
					s[k] = (char *)calloc(10, sizeof(char));
					while (s1[i][l] != '\0')
					{
						s[k][l] = s1[i][l];
						l++;
					}
					s[k][l] = '\0';
					k++;
				}
			}
		}
		if (yes == 1)
			return s;
		else
			return NULL;
	}
	else
		return NULL;
}
int comp(char *s1, char *s2)
{
	int i = 0;
	while ((s1[i] != '\0') || (s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return 0;
		i++;
	}
	return 1;
}