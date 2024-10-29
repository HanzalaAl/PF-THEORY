/*
You are working as a software engineer at a company that manages a large database of customer
transactions. Each transaction is stored as a string that contains encoded information about the
customer. However, some transactions may have been duplicated due to system errors, and these
duplicates appear in scrambled order. Your task is to identify and group these "scrambled"
transactions together, as they represent the same customer activity. Two transactions are considered
scrambled if they contain the same letters but in a different order (anagrams). You are provided with
a list of transaction strings. You need to write a program that groups these scrambled transactions
into separate categories, returning each group of related transactions together.

Example
Input transactions = ["eat", "tea", "tan", "ate", "nat", "bat"]
Expected Output: [['bat'], ['nat', 'tan'], ['ate', 'eat', 'tea']]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

typedef struct {
    char original[MAX_LENGTH];
    char sorted[MAX_LENGTH];
} Transaction;

int compareStrings(const void *a, const void *b) {
    return strcmp((*(Transaction *)a).sorted, (*(Transaction *)b).sorted);
}

void sortString(char *str) {
    int len = strlen(str);
    qsort(str, len, sizeof(char), (int (*)(const void *, const void *))strcmp);
}

void groupTransactions(char transactions[][MAX_LENGTH], int n) {
    Transaction transArr[MAX_WORDS];
    for (int i = 0; i < n; i++) {
        strcpy(transArr[i].original, transactions[i]);
        strcpy(transArr[i].sorted, transactions[i]);
        sortString(transArr[i].sorted);
    }

    qsort(transArr, n, sizeof(Transaction), compareStrings);

    printf("Grouped Transactions:\n");
    for (int i = 0; i < n; i++) {
        if (i == 0 || strcmp(transArr[i].sorted, transArr[i - 1].sorted) != 0) {
            if (i != 0) printf("]\n");
            printf("[\'%s\'", transArr[i].original);
        } else {
            printf(", \'%s\'", transArr[i].original);
        }
    }
    printf("]\n");
}

int main() {
    char transactions[][MAX_LENGTH] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = sizeof(transactions) / sizeof(transactions[0]);
    groupTransactions(transactions, n);
    return 0;
}
