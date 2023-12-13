#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char ip[20], stack[20], shift[20], reduce[20];
int top = 0;
int i = 0, j = 0, z = 0, n;
void check()
{
    for (z = 0; z < n; z++)
    {
        if (stack[z] == 'i' && stack[z + 1] == 'd')
        {
            stack[z] = 'E';
            stack[z + 1] = '\0';
            printf("$%s\t\t%s\t\t%s\n", stack, ip, reduce);
            j++;
        }
    }
    for (z = 0; z < n; z++)
    {
        if (stack[z] == 'E' && stack[z + 1] == '+' && stack[z + 2] == 'E')
        {
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("$%s\t\t%s\t\t%s\n", stack, ip, reduce);
            i--;
        }
    }
    for (z = 0; z < n; z++)
    {
        if (stack[z] == 'E' && stack[z + 1] == '*' && stack[z + 2] == 'E')
        {
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("$%s\t\t%s\t\t%s\n", stack, ip, reduce);
            i--;
        }
    }
    for (z = 0; z < n; z++)
    {
        if (stack[z] == 'E' && stack[z + 1] == '/' && stack[z + 2] == 'E')
        {
            stack[z] = 'E';
            stack[z + 1] = '\0';
            stack[z + 2] = '\0';
            printf("$%s\t\t%s\t\t%s\n", stack, ip, reduce);
            i--;
        }
    }
}
int main()
{
    printf("Grammar: \nE->E+E | E*E | E/E | id\n");
    printf("Enter the input: ");
    scanf("%s", ip);
    strcpy(reduce, "Reduce to E");
    strcpy(shift, "Shift");
    n = strlen(ip);
    for (i = 0, j = 0; j < n; i++, j++)
    {
        if (ip[j] == 'i' && ip[j + 1] == 'd')
        {
            stack[i] = ip[j];
            stack[i + 1] = ip[j + 1];
            ip[j] = ip[j + 1] = ' ';
            stack[i + 2] = '\0';
            printf("$%s\t\t%s\t\t%s\n", stack, ip, shift);
            check();
        }
        else
        {
            stack[i] = ip[j];
            stack[i + 1] = '\0';
            ip[j] = ' ';
            printf("$%s\t\t%s\t\t%s\n", stack, ip, shift);
            check();
        }
    }
}