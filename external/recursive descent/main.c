#include <stdio.h>
#include <stdlib.h>

char string[64];
const char *cursor;

int E(), EDash(), T(), TDash(), F();

int main()
{
    printf("Enter the input string: ");
    scanf("%s", string);
    cursor = string;
    if (E() && *cursor == '\0')
    {
        printf("Accepted...");
        return 0;
    }
    else
    {
        printf("String not accepted..\n");
        exit(0);
    }
}
int E()
{
    printf("%s E->TE'\n", cursor);
    if (T())
    {
        if (EDash())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
int EDash()
{
    if (*cursor == '+')
    {
        printf("%-16s E' -> + T E'\n", cursor);
        cursor++;
        if (T())
        {
            if (EDash())
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
    {
        printf("%-16s E' -> $\n", cursor);
        return 1;
    }
}
int T()
{
    printf("%-16s T -> F T'\n", cursor);  
    if (F())
    {
        if (TDash())
        {
            return 1;
        }
        return 0;
    }
    return 0;
}
int TDash()
{
    if (*cursor == '*')
    {
        printf("%s T'->*FT'\n", cursor);
        cursor++;
        if (F())
        {
            if (TDash())
            {
                return 1;
            }
            return 0;
        }
        return 0;
    }
    else {  
        printf("%-16s T' -> $\n", cursor);  
        return 1;  
    }  
    
}
int F()
{
     if (*cursor == '(') {  
        printf("%-16s F -> ( E )\n", cursor);  
        cursor++;  
        if (E()) {  
            if (*cursor == ')') {  
                cursor++;  
                return 1;  
            } else  
                return 0;  
        } else  
            return 0;  
    } else if (*cursor == 'i') {  
        cursor++;  
        printf("%-16s F ->i\n", cursor);  
        return 1;  
    } else  
        return 0;  
}