#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int calibration_values(char *string, int comp)
{   
    //on tw thr fou fiv six seven eight nine

    if (comp == 1)
    {   
        for(int i = 0; i < strlen(string); i++)
        {       
            if (isdigit(string[i]))
            {   
                return string[i] - '0';
            }

            //one
            if (strlen(string) >= 3 && string[i] == 'o' && string[i+1] == 'n' && string[i+2] == 'e')
            {   
                return 1;
            }
            //two
            if (strlen(string) >= 3 && string[i] == 't' && string[i+1] == 'w' && string[i+2] == 'o')
            {
                return 2;
            }
            //three
            if (strlen(string) >= 5 && string[i] == 't' && string[i+1] == 'h' && string[i+2] == 'r' && string[i+3] == 'e' && string[i+4] == 'e')
            {
                return 3;
            }
            //four
            if (strlen(string) >= 4 && string[i] == 'f' && string[i+1] == 'o' && string[i+2] == 'u' && string[i+3] == 'r')
            {
                return 4;
            }
            //five
            if (strlen(string) >= 4 && string[i] == 'f' && string[i+1] == 'i' && string[i+2] == 'v' && string[i+3] == 'e')
            {
                return 5;
            }
            //six
            if (strlen(string) >= 3 && string[i] == 's' && string[i+1] == 'i' && string[i+2] == 'x')
            {
                return 6;
            }
            //seven
            if (strlen(string) >= 5 && string[i] == 's' && string[i+1] == 'e' && string[i+2] == 'v' && string[i+3] == 'e' && string[i+4] == 'n')
            {
                return 7;
            }
            //eight
            if (strlen(string) >= 5 && string[i] == 'e' && string[i+1] == 'i' && string[i+2] == 'g' && string[i+3] == 'h' && string[i+4] == 't')
            {
                return 8;
            }
            //nine
            if (strlen(string) >= 4 && string[i] == 'n' && string[i+1] == 'i' && string[i+2] == 'n' && string[i+3] == 'e')
            {
                return 9;
            }
        }
    }
    else
    {
        for(int i = strlen(string) - 1; i >= 0 ; i--)
        {   
            if (isdigit(string[i]))
            {
                return string[i] - '0';
            }
            
            //one
            if (strlen(string) >= 3 && string[i-2] == 'o' && string[i-1] == 'n' && string[i] == 'e')
            {   
                return 1;
            }
            //two
            if (strlen(string) >= 3 && string[i-2] == 't' && string[i-1] == 'w' && string[i] == 'o')
            {
                return 2;
            }
            //three
            if (strlen(string) >= 5 && string[i-4] == 't' && string[i-3] == 'h' && string[i-2] == 'r' && string[i-1] == 'e' && string[i] == 'e')
            {
                return 3;
            }
            //four
            if (strlen(string) >= 4 && string[i-3] == 'f' && string[i-2] == 'o' && string[i-1] == 'u' && string[i] == 'r')
            {
                return 4;
            }
            //five
            if (strlen(string) >= 4 && string[i-3] == 'f' && string[i-2] == 'i' && string[i-1] == 'v' && string[i] == 'e')
            {
                return 5;
            }
            //six
            if (strlen(string) >= 3 && string[i-2] == 's' && string[i-1] == 'i' && string[i] == 'x')
            {
                return 6;
            }
            //seven
            if (strlen(string) >= 5 && string[i-4] == 's' && string[i-3] == 'e' && string[i-2] == 'v' && string[i-1] == 'e' && string[i] == 'n')
            {
                return 7;
            }
            //eight
            if (strlen(string) >= 5 && string[i-4] == 'e' && string[i-3] == 'i' && string[i-2] == 'g' && string[i-1] == 'h' && string[i] == 't')
            {
                return 8;
            }
            //nine
            if (strlen(string) >= 4 && string[i-3] == 'n' && string[i-2] == 'i' && string[i-1] == 'n' && string[i] == 'e')
            {
                return 9;
            }
        }
    }
}

int main()
{   
    FILE *pt = fopen("input.txt", "r");

    char sor[100];
    int sum = 0;

    if (pt == NULL)
    {
        printf("Nem sikerult megnyitni a fajl-t");
        exit(1);
    }
    else
    {
        while (fgets(sor, 100, pt) != NULL)
        {   
            sor[strlen(sor) - 1] = '\0';
            
            int elso = calibration_values(sor, 1);
            int masodik = calibration_values(sor, 0);

            int res = elso*10 + masodik;
            
            sum = sum + res;
            printf("Adott sor: %s %d %d %d\n", sor, elso, masodik, res);
        }

    }
    fclose(pt);

    printf("\nSum: %d\n", sum);

    return 0;
}