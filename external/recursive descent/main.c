#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ip[20];
char *cursor;
int E(), Edash(), T(), Tdash(), F();
int main()
{
    printf("Grammar: E->E+T | T\nT->T*F|F\nF->(E)|i\n");
    printf("Enter the expression: ");
    scanf("%s", ip);
    cursor = ip;
    if (E() && *cursor == '\0')
    {
        printf("Accept\n");
        return 0;
    }
    else
    {
        printf("Rejected\n");
        return 1;
    }
}

int E()
{
    if (T())
    {
        if (Edash())
        {
            printf("E->TE'\n");
            return 1;
        }
        return 0;
    }
    return 0;
}
int Edash()
{
    if (*cursor == '+')
    {
        cursor++;
        if (T())
        {
            if (Edash())
            {
                printf("E'->+TE'\n");
                return 1;
            }
            return 0;
        }
        return 0;
    }
    printf("E'->e\n");
    return 1;
}
int T()
{
    if (F())
    {
        if (Tdash())
        {
            printf("T->FT'\n");
            return 1;
        }
        return 0;
    }
    return 0;
}
int Tdash()
{
    if (*cursor == '*')
    {
        cursor++;
        if (F())
        {
            if (Tdash())
            {
                printf("T'->*FT'\n");
                return 1;
            }
            return 0;
        }
        return 0;
    }
    printf("T'->e\n");
    return 1;
}
int F()
{
    if (*cursor == '(')
    {
        cursor++;
        if (E())
        {
            if (*cursor == ')')
            {
                cursor++;
                printf("F->(E)\n");
                return 1;
            }
            return 0;
        }
        return 0;
    }
    else if (*cursor == 'i')
    {
        printf("F->i\n");
        cursor++;
        return 1;
    }
    return 0;
}