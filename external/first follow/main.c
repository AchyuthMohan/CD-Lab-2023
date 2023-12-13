#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char a[20][20], f[20];
int n, m = 0;
void first(char c), follow(char c);

int main()
{
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        first(a[i][0]);
        printf("First of %c: ", a[i][0]);
        for (int j = 0; j < m; j++)
        {
            printf("%c ", f[j]);
        }
        printf("\n");
        m = 0;
        strcpy(f, "");
    }
    for (int i = 0; i < n; i++)
    {
        follow(a[i][0]);
        printf("Follow of %c: ", a[i][0]);
        for (int j = 0; j < m; j++)
        {
            printf("%c ", f[j]);
        }
        printf("\n");
        m = 0;
        strcpy(f, "");
    }
}

void first(char c)
{
    if (islower(c))
    {
        f[m++] = c;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i][0] == c)
            {
                first(a[i][2]);
            }
        }
    }
}
void follow(char c)
{
    if (a[0][0] == c)
        f[m++] = '$';
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < strlen(a[i]); j++)
        {
            if (a[i][j] == c)
            {
                if (a[i][j + 1] != '\0')
                    first(a[i][j + 1]);
                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}