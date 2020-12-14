#include <stdlib.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "."

int binarySearch(int l, int r, int x) 
{
    char answer[8];
    int sc;
    if (r >= l) { 
        int mid = l + (r - l) / 2;
        int is_l = -1;
        int is_g = -1;
        
        if (mid == x) 
            return mid;

        printf(_("Is your number less or greater than %d?\n"), mid);
        
        while (is_l && is_g)
        {
            printf(_("Answer %s or %s: "), _("l"), _("g"));
            sc = scanf("%s", answer);
            is_l = strcmp(answer, _("l"));
            is_g = strcmp(answer, _("g"));
        }
        
        if (!is_l) 
        {
            return binarySearch(l, mid - 1, x); 
        } 
        else if (!is_g) 
        {
            return binarySearch(mid + 1, r, x);
        }
        
    } 
    return -1; 
}

int main(int argc, char *argv[])
{
    int i, number, result, sc;

	setlocale (LC_ALL, "");
	bindtextdomain ("main", LOCALE_PATH);
	textdomain ("main");

	/* Simple text */
	printf(_("Write a number from 1 to 100\n"));
    sc = scanf("%d", &number);

	result = binarySearch(1, 100, number);
    printf(_("Your number is %d\n"), result);

	return 0;
}
