#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char op[2], arg1[3], arg2[3], dest[3];
    FILE *fo;
    fp = fopen("input.dat", "r");
    fo = fopen("output.dat", "w");
    while (!feof(fp))
    {
        fscanf(fp, "%s%s%s%s", op, arg1, arg2, dest);
        if (strcmp(op, "+") == 0)
        {
            fprintf(fo, "MOV R0,%s\n", arg1);
            fprintf(fo, "ADD %s\n", arg2);
            fprintf(fo, "MOV %s,R0\n", dest);
        }
        else if (strcmp(op, "*") == 0)
        {
            fprintf(fo, "MOV R0,%s\n", arg1);
            fprintf(fo, "MUL %s\n", arg2);
            fprintf(fo, "MOV %s,R0\n", dest);
        }
        else if (strcmp(op, "/") == 0)
        {
            fprintf(fo, "MOV R0,%s\n", arg1);
            fprintf(fo, "DIV %s\n", arg2);
            fprintf(fo, "MOV %s,R0\n", dest);
        }
        else if (strcmp(op, "-") == 0)
        {
            fprintf(fo, "MOV R0,%s\n", arg1);
            fprintf(fo, "SUB %s\n", arg2);
            fprintf(fo, "MOV %s,R0\n", dest);
        }
        else
        {
            fprintf(fo, "MOV %s,%s\n", dest, arg1);
        }
    }
    fclose(fp);
    fclose(fo);
}