#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 50
#define MAX_ALPHABET 26

int numStates, numAlphabet;
int transition[MAX_STATES][MAX_ALPHABET];
bool isFinal[MAX_STATES];

// Function to minimize the DFA
void minimizeDFA() {
    int equivalenceClasses[MAX_STATES]; // Equivalence classes for states
    int newEquivalenceClasses[MAX_STATES];
    int numEquivalenceClasses = numStates;
    bool changed = true;

    // Initialize equivalence classes
    for (int i = 0; i < numStates; i++) {
        equivalenceClasses[i] = (isFinal[i]) ? 0 : 1;
    }

    while (changed) {
        changed = false;

        // Iterate over each pair of states
        for (int i = 0; i < numStates; i++) {
            for (int j = i + 1; j < numStates; j++) {
                if (equivalenceClasses[i] != equivalenceClasses[j]) {
                    bool equivalent = true;

                    // Check for equivalence using all alphabet symbols
                    for (int k = 0; k < numAlphabet; k++) {
                        int nextState1 = transition[i][k];
                        int nextState2 = transition[j][k];

                        if (equivalenceClasses[nextState1] != equivalenceClasses[nextState2]) {
                            equivalent = false;
                            break;
                        }
                    }

                    // If equivalent, merge the equivalence classes
                    if (equivalent) {
                        newEquivalenceClasses[i] = newEquivalenceClasses[j] = numEquivalenceClasses;
                        numEquivalenceClasses++;
                        changed = true;
                    }
                }
            }
        }

        // Update equivalence classes
        for (int i = 0; i < numStates; i++) {
            if (newEquivalenceClasses[i] != 0) {
                equivalenceClasses[i] = newEquivalenceClasses[i];
            }
        }
    }

    // Print minimized DFA
    printf("Minimized DFA:\n");
    for (int i = 0; i < numStates; i++) {
        if (equivalenceClasses[i] == 0) {
            printf("State %d (Final State)\n", i);
        } else {
            printf("State %d\n", i);
        }
    }
}

int main() {
    printf("Enter the number of states: ");
    scanf("%d", &numStates);
    printf("Enter the number of alphabet symbols: ");
    scanf("%d", &numAlphabet);

    printf("Enter transition table:\n");
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numAlphabet; j++) {
            printf("Delta(q%d, %c) = ", i, 'a' + j);
            scanf("%d", &transition[i][j]);
        }
    }

    printf("Enter the final states (0-based indices, separated by spaces): ");
    for (int i = 0; i < numStates; i++) {
        int finalState;
        scanf("%d", &finalState);
        isFinal[finalState] = true;
    }

    minimizeDFA();

    return 0;
}
