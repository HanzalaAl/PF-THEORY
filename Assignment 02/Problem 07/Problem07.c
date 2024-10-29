/*
One of the master coders designed a subscript block that stores random characters in a multidimensional array. 
You are asked to design a program that will find a given string in a multidimensional array of characters. 
The search for characters can be present and operational from left to right and top to down only. 
The program should create a 6 x 5 2D array and populate it with random alphabet characters. 
After that, the program should print it in a tabular form. 
Search the user-entered string in the 2D array, if it is present then add a point to the score, if it is not 
available then subtract one. Print the score at every input. The program stops asking and re-populates 
the 2D array with new random characters when the user enters "END" as the string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 6
#define COLS 5

void populateArray(char arr[ROWS][COLS], int lastRowID[COLS]) {
    srand(time(0));
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = 'A' + rand() % 26; // Generate random uppercase letters
        }
    }
    // Fill the last row with specific ID values
    for (int j = 0; j < COLS; j++) {
        arr[ROWS - 1][j] = '0' + lastRowID[j]; // Convert int ID to char
    }
}

void printArray(char arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int searchString(char arr[ROWS][COLS], const char *str) {
    int len = strlen(str);
    
    // Check left to right
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - len; j++) {
            int k;
            for (k = 0; k < len; k++) {
                if (arr[i][j + k] != str[k]) {
                    break;
                }
            }
            if (k == len) {
                return 1; // String found
            }
        }
    }

    // Check top to bottom
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i <= ROWS - len; i++) {
            int k;
            for (k = 0; k < len; k++) {
                if (arr[i + k][j] != str[k]) {
                    break;
                }
            }
            if (k == len) {
                return 1; // String found
            }
        }
    }

    return 0; // String not found
}

int main() {
    char arr[ROWS][COLS];
    int lastRowID[COLS] = {1, 2, 3, 4, 5}; // Replace with your student ID's last four digits as needed
    int score = 0;
    char str[50];

    populateArray(arr, lastRowID);

    while (1) {
        printArray(arr);
        printf("Enter the search string (type 'END' to stop): ");
        scanf("%s", str);

        if (strcmp(str, "END") == 0) {
            printf("Re-populating array with new random characters...\n");
            populateArray(arr, lastRowID);
            continue;
        }

        if (searchString(arr, str)) {
            score++;
            printf("%s is present. Score: %d\n", str, score);
        } else {
            score--;
            printf("%s is not present. Score: %d\n", str, score);
        }
    }

    return 0;
}
