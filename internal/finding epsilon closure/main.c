#include <stdio.h>
#include <stdlib.h>
struct node
{
    int st;
    struct node *link;
};

static int states, alpha, trans, r, s, count;
char alphabets[20], c;
int buffer[20];
struct node *transitions[20][20] = {NULL};
static int e_closure[20][20] = {0};

void findclosure(int x, int sta)
{
    struct node *temp;
    int i;
    if (buffer[x])
    {
        return;
    }
    e_closure[sta][count++] = x;
    buffer[x] = 1;
    if (alphabets[alpha - 1] == 'e' && transitions[x][alpha - 1] != NULL)
    {
        temp = transitions[x][alpha - 1];
        while (temp != NULL)
        {
            findclosure(temp->st, sta);
            temp = temp->link;
        }
    }
}
int findalpha(char ch)
{
    for (int i = 0; i < alpha; i++)
    {
        if (alphabets[i] == ch)
        {
            return i;
        }
    }
    return 999;
}
void insertIntoTable(int r, char c, int s)
{
    int j = findalpha(c);
    struct node *temp;

    if (j == 999)
    {
        printf("Error");
        exit(0);
    }
    temp = (struct node *)malloc(sizeof(struct node));
    temp->st = s;
    temp->link = transitions[r][j];
    transitions[r][j] = temp;
}
void printclosure(int i)
{
    int j;
    printf("{");
    for (j = 0; e_closure[i][j] != 0; j++)
        printf("q%d,", e_closure[i][j]);
    printf("}");
}
int main()
{
    printf("Enter the number of states: ");
    scanf("%d", &states);
    printf("Enter the number of alphabets: ");
    scanf("%d", &alpha);
    printf("Enter the alphabets: \n");
    for (int i = 0; i < alpha; i++)
    {
        scanf("%c", &alphabets[i]);
    }
    printf("Enter the number of transitions: \n");
    scanf("%d", &trans);
    printf("Enter the transitions:\n");
    for (int i = 0; i < trans; i++)
    {
        scanf("%d%c%d", &r, &c, &s);
        insertIntoTable(r, c, s);
    }
    for (int i = 1; i <= states; i++)
    {
        count = 0;
        for (int j = 0; j < 20; j++)
        {
            buffer[j] = 0;
            e_closure[i][j] = 0;
        }
        findclosure(i, i);
        printclosure(i);
    }
}