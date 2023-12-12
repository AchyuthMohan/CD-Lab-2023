#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    FILE *fo;
    char op[20], arg1[20], arg2[20], result[20];
    fp = fopen("input.dat", "r");
    fo = fopen("output.dat", "w");
    while (!feof(fp))
    {
        fscanf(fp, "%s%s%s%s", op, arg1, arg2, result);
        if (strcmp(op, "+") == 0)
        {
            fprintf(fo, "\nMOV R0, %s", arg1);
            fprintf(fo, "\nADD R0, %s", arg2);
            fprintf(fo, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "*") == 0)
        {
            fprintf(fo, "\nMOV R0, %s", arg1);
            fprintf(fo, "\nMUL R0, %s", arg2);
            fprintf(fo, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "-") == 0)
        {
            fprintf(fo, "\nMOV R0, %s", arg1);
            fprintf(fo, "\nSUB R0, %s", arg2);
            fprintf(fo, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "=") == 0)
        {
            fprintf(fo,"\nMOV R0, %s",arg1);
            fprintf(fo,"\nMOV %s, R0",result);
        }
    }
}