#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    FILE *fo;
    char dest[3], eq[2], arg1[3], op[2], arg2[3];
    fp = fopen("input.dat", "r");
    fo = fopen("output.dat", "w");
    while (!feof(fp))
    {
        fscanf(fp, "%s%s%s%s%s", dest, eq, arg1, op, arg2);
        if (strcmp(op, "+") == 0)
        {
            fprintf(fo, "MOV R0,%s\n", arg1);
            fprintf(fo, "ADD %s\n", arg2);
            fprintf(fo, "MOV %s,R0\n", dest);
        }
        else if (strcmp(op, "-") == 0)
        {
            fprintf(fo, "MOV R0,%s\n", arg1);
            fprintf(fo, "SUB %s\n", arg2);
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
    }
}