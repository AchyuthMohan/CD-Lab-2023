#include <stdio.h>
#include <stdlib.h>
#define max 20
int nfa[max][max];
void epsilonConvert(int nfa[][], int n, int nfaWithEpsilonTrans[][])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            nfaWithEpsilonTrans[i][j] = nfa[i][j];
        }
    }
    for (int k = 0; k < nk++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nfaWithEpsilonTrans[i][j] = nfaWithEpsilonTrans[i][j] || (nfaWithEpsilonTrans[i][k] && nfaWithEpsilonTrans[k][j])
            }
        }
    }
}
int main()
{
    int n, m;
    printf("Enter the number of states: \n");
    scanf("%d", &n);
    printf("Enter the number of inputs: \n");
    scanf("%d", &m) for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Enter the destination state from state %d during input %d: \n", i, j);
            scanf("%d", &nfa[i][j])
        }
    }
    int nfaWithEpsilonTrans[max][max];
    epsilonConvert(nfa,n,nfaWithEpsilonTrans);
    int resNfa[max][max];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            resNfa[i][j]=nfaWithEpsilonTrans[i][nfa[i][j]];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("(%d,%d,%d)\n",i,j,resNfa[i][j])
        }
    }
}