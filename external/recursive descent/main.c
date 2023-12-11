#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[64];
char *cursor;
int E(), Edash(), T(), Tdash(), F();

int main()
{
    printf("Enter the string: ");
    scanf("%s", string);
    cursor = string;
    if (E() && *cursor == '\0')
    {
        printf("Parsing successfull\n");
        return 0;
    }
    else
    {
        printf("Error in parsing\n");
        return 1;
    }
}

int E()
{
    printf("E->TE'\n");
    if (T())
    {
        if (Edash())
        {
            return 1;
        }
        else
        {
            return 0;
        }
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
                return 1;
            }
            return 0;
        }
        return 0;
    }
    else
    {
       return 1;
    }
}
int T()
{
    if (F())
    {
        if (Tdash())
        {
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
        printf("%-16s T' -> * F T'\n", cursor);
        cursor++;
        if (F())
        {
            if (Tdash())
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
    {
        return 1;
    }
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
                return 1;
            }
            return 0;
        }
        return 0;
    }
    else if (*cursor == 'i')
    {
        cursor++;
        return 1;
    }
    else
    {
        return 0;
    }
}
