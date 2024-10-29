/*
You are working for a text-processing company that optimizes storage for large amounts of written
data. The company has identified a recurring issue: words in documents are often unnecessarily
lengthy due to repeated consecutive characters. Your task is to minimize these words by reducing
consecutive duplicate characters to a single instance of the character.

Operations:
Compress a Word: Write a function that takes a string (a word) as input and returns a minimized
version of the word, where all consecutive duplicate letters are reduced to one.
Multiple Word Compression: You will then apply this function to a list of words and return the
minimized version for each word.
Add a feature to calculate how many characters were removed during the compression process.

Input: words = ["booooook", "coooool", "heeeey"]
Output: ["bok", "col", "hey"]
*/

#include <stdio.h>
#include <string.h>

void compressWord(char *word, char *compressed, int *removed_count) {
    int length = strlen(word);
    int j = 0;
    *removed_count = 0;

    for (int i = 0; i < length; i++) {
        if (i == 0 || word[i] != word[i - 1]) {
            compressed[j++] = word[i];
        } else {
            (*removed_count)++;
        }
    }
    compressed[j] = '\0';
}

int main() {
    char *words[] = {"booooook", "coooool", "heeeey"};
    int num_words = sizeof(words) / sizeof(words[0]);
    char compressed[100];
    int total_removed = 0;

    printf("Compressed words:\n");
    for (int i = 0; i < num_words; i++) {
        int removed_count = 0;
        compressWord(words[i], compressed, &removed_count);
        total_removed += removed_count;
        printf("%s -> %s (Characters removed: %d)\n", words[i], compressed, removed_count);
    }

    printf("\nTotal characters removed: %d\n", total_removed);
    return 0;
}
