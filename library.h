#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>		// for using roundf()		
#include <windows.h>  // for using Sleep()

void f_redundant(char s[])	// used to remove redundant blank of the string Bui minh chau
{
    size_t length = strlen(s), i, j;
    for (i = 0; i < length; i++)
    {
        if (s[0] == ' ')	// if blank is in the beginning, remove all
        {
            for (i = 0; i < (length - 1); i++)
                s[i] = s[i + 1];	//if having blank, shift the string to the left 
            s[i] = '\0';
            length--;// everytime shifting,decrease the length 
            i = -1; // set i to return for the loop "for", after that i=0 then start again
            continue;
        }
        if (s[i] == ' ' && s[i + 1] == ' ')// check if  2 consecutive blank or more 
        {
            for (j = i; j < (length - 1); j++)
            {
                s[j] = s[j + 1];
            }
            s[j] = '\0';	//shift and decrease the length of string
            length--;
            i--;	// decrease for match with the string when shifting
        }
    }
    if (s[strlen(s) - 1] == ' ')
    {
        s[strlen(s) - 1] = '\0'; // clear the space at the end of the string
    }
}

void f_firstupper(char s[])
{					// make the right format for all the words
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')	// character is not a blank, then lower all character
        {
            s[i] = tolower(s[i]);
            if (s[i - 1] == ' ' || i == 0)
            {
                s[i] = toupper(s[i]); // if before this character is a blank, then upper the character
            }
        }
    }
}

void f_delEnter(char s[])
{
    size_t len = strlen(s);
    if (s[len - 1] == '\n')
        s[len - 1] = '\0';
}

void f_font(char s[])
{
    f_redundant(s);
    f_firstupper(s);
}

void f_scrollingtext(const char* s)
{   					// this function makes the text scrolling on the console   
    int i;
    size_t size = strlen(s);		// here we don't print all the string, we print each character in the string
    for (i = 0; i < size; i++)
    {
        Sleep(5); 			// set delay time for everytime printing a character, here is 5 miliseconds delay
        printf("%c", s[i]);
    }
}

