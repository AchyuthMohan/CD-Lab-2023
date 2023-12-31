#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char states[20][3], state[3], state1[3], state2[3], input[3], result[20][20], copy[3];

void display(int x)
{
    printf("Epsilon closure of %s: ", copy);
    for (int i = 0; i <= x; i++)
    {
        printf(" %s", result[i]);
    }
    printf("\n");
}

void addState(int i, char a[3])
{
    strcpy(result[i], a);
}
int main()
{
    FILE *fp;
    fp = fopen("input.dat", "r");
    printf("Enter the number of states: \n");
    scanf("%d", &n);
    printf("Enter the states: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", states[i]);
    }

    int x = 0;
    int end;
    for (int i = 0; i < n; i++)
    {
        strcpy(state, states[i]);
        strcpy(copy, state);
        addState(x++, state);

        while (1)
        {
            end = fscanf(fp, "%s%s%s", state1, input, state2);
            if (end == EOF)
            {
                break;
            }
            if (strcmp(state, state1) == 0)
            {
                if (strcmp(input, "e") == 0)
                {
                    strcpy(state, state2);
                    addState(x++, state2);
                }
            }
        }
        display(i);
        rewind(fp);
    }
    return 0;
}