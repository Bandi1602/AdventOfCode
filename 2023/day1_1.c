#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char calibration_values(char *string, int comp)
{   
    char c;

    if (comp == 1)
    {
        for (int i = 0; string[i] != '\0'; i++)
        {
            if (isdigit(string[i]))
            {
                c = string[i];
                return c;
            }
            
        }
        
    }
    else
    {
        for (int i = strlen(string) - 1; string[i] != '\0'; i--)
        {
            if (isdigit(string[i]))
            {
                c = string[i];
                return c;
            }
            
        }
    }

    return c;
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
            
            char elso = calibration_values(sor, 1) - '0';
            char masodik = calibration_values(sor, 0) - '0';

            int res = (int)elso * 10 + (int)masodik;
            
            sum = sum + res;
            printf("sum: %s %d %d \n",sor, res, sum);

        }

    }
    fclose(pt);

    printf("\nSum: %d\n", sum);

    return 0;
}