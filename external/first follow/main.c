#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 30

char a[max][max], f[max];
int n, m = 0;

void first(char c)
{
    if (islower(c))
    {
        f[m++] = c;
        return;
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
    {
        f[m++] = '$';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < strlen(a[i]); j++)
        {
            if (a[i][j + 1] != '\0')
            {
                first(a[i][j + 1]);
            }
            else if (a[i][j + 1] == '\0' && a[i][0] != c)
            {
                follow(a[i][0]);
            }
        }
    }
}
int main()
{
    char ch[2];
    printf("Enter the number of productions:");
    scanf("%d", &n);
    printf("Enter the grammar: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }
    printf("Enter the symbol whose first and follow to be found:");
    scanf(" %s",ch);
    first(ch[0]);
    printf("First: ");
    for (int i = 0; i < m; i++)
    {
        printf("%c ", f[i]);
    }
    strcpy(f, "");
    m = 0;
    follow(ch[0]);
    printf("Follow: ");
    for (int i = 0; i < m; i++)
    {
        printf("%c ", f[i]);
    }
}