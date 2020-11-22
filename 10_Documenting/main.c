/** @file main.c
 * Main file
 */

#include <stdlib.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "."

char* ROMAN_NUMBERS[100] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", 
                            "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", 
                            "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX", 
                            "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL", 
                            "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L", 
                            "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX", 
                            "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX", 
                            "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX", 
                            "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC", 
                            "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"};

/**
 * Convert @p from int to roman number.
 * 
 * @param number is an int number, must be in range from 1 to 100.
 * 
 * @returns @p number converted to roman number or NULL.
 */
char* int_to_roman(int number) 
{
    if (number <= 0 || number > 100) 
    {
        printf(_("Number must be in range from 1 to 100\n"));
        return NULL;
    }
    return ROMAN_NUMBERS[number-1];
}

/**
 * Convert @p from roman to int number
 * 
 * @param number_s is a roman number, must be in range from I to C.
 * 
 * @returns @p number_s converted to int number or -1.
 */
int roman_to_int(char* number_s) 
{
    for (int i = 1; i <= 100; i++) 
    {
        if(!strcmp(number_s, ROMAN_NUMBERS[i-1]))
        {
            return i;
        }
    }
    printf(_("Roman number must be in range from I to C\n"));
    return -1;
}

/**
 * Find number x from l to r range
 * 
 * @param l is a left border of range.
 * @param r is a right border of range.
 * @param x is a number, that we have to find.
 * @param is_roman on a roman mode.
 * 
 * @returns x if we find a number else -1.
 * 
 */
int binary_search(int l, int r, int x, int is_roman) 
{
    char answer[8];
    int sc;
    if (r >= l) 
    { 
        int mid = l + (r - l) / 2;
        int is_l = -1;
        int is_g = -1;
        
        if (mid == x)
        {
            return mid;
        }

        if (is_roman)
        {
            printf(_("Is your number less or greater than %s?\n"), int_to_roman(mid));
        } 
        else 
        {
            printf(_("Is your number less or greater than %d?\n"), mid);
        }
        
        while (is_l && is_g)
        {
            printf(_("Answer %s or %s: "), _("l"), _("g"));
            sc = scanf("%s", answer);
            is_l = strcmp(answer, _("l"));
            is_g = strcmp(answer, _("g"));
        }
        
        if (!is_l) 
        {
            return binary_search(l, mid - 1, x, is_roman); 
        } 
        else if (!is_g) 
        {
            return binary_search(mid + 1, r, x, is_roman);
        }
        
    } 
    return -1; 
}

int main(int argc, char *argv[])
{
    int i, number, result, sc;
    char number_s[8];
    int is_roman = 0;

	setlocale (LC_ALL, "");
	bindtextdomain ("main", LOCALE_PATH);
	textdomain ("main");

    if (argc > 1 && !strcmp(argv[1], "--help")) {
    printf(_("\
        This program have to guess any number from 1 to 100.\n\
        \n\
        Usage: ./main [OPTION]...\n\
        \n\
        Options:\n\
        --help                  display this usage\n\
        -r                      on roman mode\n"));
        return 0;
    }

    if ( (argc == 2) && !(strcmp(argv[1], "-r")) ) 
    {
        is_roman = 1;
    }

    if (is_roman)
    {
        printf(_("Write a number from I to C\n"));
        sc = scanf("%s", number_s);
        number = roman_to_int(number_s);
    } else 
    {
        printf(_("Write a number from 1 to 100\n"));
        sc = scanf("%d", &number);
    }
    
	result = binary_search(1, 100, number, is_roman);
    if (is_roman)
    {
        printf(_("Your number is %s\n"), int_to_roman(result));
    } 
    else 
    {
        printf(_("Your number is %d\n"), result);
    }

	return 0;
}
