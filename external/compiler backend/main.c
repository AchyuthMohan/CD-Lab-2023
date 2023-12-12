#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char dest[20], assign[20], arg1[20], op[20], arg2[20];
    FILE *fp;
    FILE *fo;
    fp = fopen("input.dat", "r");
    fo = fopen("output.dat", "w");
    while (!feof(fp))
    {
        fscanf(fp, "%s%s%s%s%s", dest, assign, arg1, op, arg2);

        if (strcmp(op, "+") == 0)
        {
            fprintf(fo, "\nMOV R0,%s", arg1);
            fprintf(fo, "\nADD %s", arg2);
            fprintf(fo, "\nMOV %s,R0", dest);
            
        }
        else if (strcmp(op, "-") == 0)
        {
            fprintf(fo, "\nMOV R0,%s", arg1);
            fprintf(fo, "\nSUB %s", arg2);
            fprintf(fo, "\nMOV %s,R0", dest);
            
        }
        else if (strcmp(op, "*") == 0)
        {
            fprintf(fo, "\nMOV R0,%s", arg1);
            fprintf(fo, "\nMUL %s", arg2);
            fprintf(fo, "\nMOV %s,R0", dest);
            
        }
    }
}
