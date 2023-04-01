# Conversion_chiffres_-criture

Welcome to the ReadMe for the C project that converts numbers to words in French.

This program allows you to convert integers into words in French. It can be used to convert written numbers into spoken numbers, for users with reading difficulties, or for applications that require the pronunciation of numbers in French.
How to use the program

The program can be used in two ways:

    By running the provided binary directly from the command line
    By integrating the conversion functions into your own C program.

Running the provided binary

    Clone the Git repository to your machine
    Compile the program using your preferred C compiler
    Run the binary by passing the number to be converted as an argument.

Integrating into your own program

    Copy the source files "convert.c" and "convert.h" into your C project
    Include the "convert.h" file in your source code
    Call the "convertNumberToWords" function with the integer to be converted as an argument. This function returns a string containing the conversion of the number into words. For example:


#include<stdio.h>
#include "chaine2.h"

char all[1000];

void menu()
    {
    char T[30],P1[15],P2[15];
		lecture_chaine(T);
		ent_reel(T,P1,P2);
		affichage_chaine(P1,P2);
		char_to_num(P1);
		char_to_num_v(P2);
    printf("\nLe nombre en lettres est : %s ",all);
	}

int main ()
    {
        menu();
    }

Limitations of the program

This program is capable of converting integers between -999,999,999,999 and 999,999,999,999. Numbers outside this range will not be correctly converted.

The program is written in French and does not support other languages.
