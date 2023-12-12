#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ip[30], stk[30], act[30], ac[30];
int i = 0, j = 0, n, z = 0;

void check()
{
    for (z = 0; z < n; z++)
    {
        if (stk[z] == 'i' && stk[z + 1] == 'd')
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            j++;
            printf("$%s\t\t\t%s\t\t\t%s\n", stk, ip, ac);
        }
    }

    for (z = 0; z < n; z++)
    {
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E')
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 1] = '\0';
            printf("$%s\t\t\t%s\t\t\t%s\n", stk, ip, ac);
            i = i - 2;
        }
    }
    for (z = 0; z < n; z++)
    {
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E')
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 1] = '\0';
            printf("$%s\t\t\t%s\t\t\t%s\n", stk, ip, ac);
            i = i - 2;
        }
    }
    for (z = 0; z < n; z++)
    {
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')')
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 1] = '\0';
            printf("$%s\t\t\t%s\t\t\t%s\n", stk, ip, ac);
            i = i - 2;
        }
    }
}
int main()
{
    printf("Gramar\n E->E+E\nE->E*E\nE->(E)\nE->id\n");
    printf("Enter the string input: ");
    scanf("%s", ip);
    strcpy(act, "SHIFT");
    strcpy(ac, "REDUCE to E");
    printf("\nstck\t\t\tinput\t\t\taction\n");
    n = strlen(ip);
    for (i = 0, j = 0; j < n; i++, j++)
    {
        if (ip[j] == 'i' && ip[i + 1] == 'd')
        {
            stk[i] = ip[j];
            stk[i + 1] = ip[j + 1];
            stk[i + 2] = '\0';
            ip[i] = ip[i + 1] = ' ';
            printf("$%s\t\t\t%s\t\t\t%s\n", stk, ip, act);
            check();
        }
        else
        {
            stk[i] = ip[j];
            stk[i + 1] = '\0';
            ip[j] = ' ';
            printf("$%s\t\t\t%s\t\t\t%s\n", stk, ip, act);
            check();
        }
    }
}
