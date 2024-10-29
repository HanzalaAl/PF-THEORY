/*
A popular beverage company is looking to optimize their marketing campaigns by understanding the
frequency of characters used in their promotional slogans. They believe that analyzing these patterns
can help them tailor their messaging to specific demographics and improve brand recall. You've been
tasked with creating a C code function to analyze the character frequency in a list of slogans provided
by the marketing team. This analysis will help identify the most common letters used in their slogans,
which can inform future marketing strategies.
Input:
slogans = ["buy now", "save big", "limited offer"]
Expected Output:
● For "buy now": {'b': 1, 'u': 1, 'y': 1, ' ': 1, 'n': 1, 'o': 1, 'w': 1}
● For "save big": {'s': 1, 'a': 1, 'v': 1, 'e': 1, ' ': 1, 'b': 1, 'i': 1, 'g': 1}
● For "limited offer": {'l': 1, 'i': 1, 'm': 1, 't': 1, 'e': 2, 'd': 1, ' ': 1, 'o': 1, 'f': 1, 'r': 1}
*/

#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 128

void analyzeFrequency(char slogan[]) {
    int frequency[ASCII_SIZE] = {0};

    for (int i = 0; slogan[i] != '\0'; i++) {
        frequency[(int)slogan[i]]++;
    }

    printf("For \"%s\": {", slogan);
    int first = 1;

    for (int i = 0; i < ASCII_SIZE; i++) {
        if (frequency[i] > 0) {
            if (!first) {
                printf(", ");
            }
            printf("'%c': %d", i, frequency[i]);
            first = 0;
        }
    }
    printf("}\n");
}

int main() {
    char *slogans[] = {"buy now", "save big", "limited offer"};
    int num_slogans = sizeof(slogans) / sizeof(slogans[0]);

    for (int i = 0; i < num_slogans; i++) {
        analyzeFrequency(slogans[i]);
    }

    return 0;
}
