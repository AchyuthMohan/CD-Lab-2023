#include <stdio.h>
#include <stdlib.h>
#define MAX_STATES 100
#define MAX_SYMBOLS 100
struct Transition {
    int src;        // Source state
    char symbol;    // Transition symbol (epsilon is represented as '\0')
    int dest;       // Destination state
};
void epsilonClosure(int nfa[MAX_STATES][MAX_SYMBOLS], int n, int epsilonClosureSet[MAX_STATES][MAX_STATES]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            epsilonClosureSet[i][j] = nfa[i][j];
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                epsilonClosureSet[i][j] = epsilonClosureSet[i][j] || (epsilonClosureSet[i][k] && epsilonClosureSet[k][j]);
            }
        }
    }
}

int main() {
    int n; // Number of states
    int m; // Number of symbols
    int i, j, k;
    printf("Enter the number of states: ");
    scanf("%d", &n);
    printf("Enter the number of symbols: ");
    scanf("%d", &m);
    int nfa[MAX_STATES][MAX_SYMBOLS];
    printf("Enter the NFA transition table with epsilon transitions (use -1 for no transition):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Transition from state %d with symbol %d (-1 if no transition): ", i, j);
            scanf("%d", &nfa[i][j]);
        }
    }
    printf("\nOriginal NFA with epsilon transitions:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("(%d, %d, %d) ", i, j, nfa[i][j]);
        }
        printf("\n");
    }

    int epsilonClosureSet[MAX_STATES][MAX_STATES];
    epsilonClosure(nfa, n, epsilonClosureSet);
    int newNFA[MAX_STATES][MAX_SYMBOLS];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            newNFA[i][j] = epsilonClosureSet[i][nfa[i][j]];
        }
    }
    printf("\nNFA without epsilon transitions:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("(%d, %d, %d) ", i, j, newNFA[i][j]);
        }
        printf("\n");
    }

    return 0;
}
