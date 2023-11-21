#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKwd(char buffer[])
{
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                         "do", "double", "else", "enum", "extern", "float", "for", "goto",
                         "if", "int", "long", "register", "return", "short", "signed",
                         "sizeof", "static", "struct", "switch", "typedef", "union",
                         "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(buffer, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    char ch, buffer[15];
    int j = 0;
    if (fp == NULL)
    {
        printf("Error in readin the file...\n");
        exit(0);
    }
    else
    {
        printf("File opened successfully\n");
    }
    char operators[] = "+-*/%()=,;";
    while ((ch = fgetc(fp)) != EOF)
    {
        for (int i = 0; i < 10; i++)
        {
            if (ch == operators[i] && isKwd(buffer) == 0)
            {
                printf("id");
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (operators[i] == ch)
            {
                if (operators[i] == '+')
                {
                    printf("op-add");
                }
                else if (operators[i] == '-')
                {
                    printf("op-min");
                }
                else if (operators[i] == '*')
                {
                    printf("op-mul");
                }
                else if (operators[i] == '/')
                {
                    printf("op-div");
                }
                else if (operators[i] == '=')
                {
                    printf("op-equ");
                }
                else if (operators[i] == '%')
                {
                    printf("op-mod");
                }
                else if (operators[i] == ',')
                {
                    printf(",");
                }
                else if (operators[i] == ';')
                {
                    printf(";");
                }
                else if (operators[i] == '(')
                {
                    printf(".");
                }
            }
        }
        if (isalnum(ch))
        {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && j != 0)
        {
            buffer[j++] = '\0';
            j = 0;
            if (isKwd(buffer) == 1)
            {
                printf("kwd ");
            }
        }
    }
    fclose(fp);
    return 0;
}