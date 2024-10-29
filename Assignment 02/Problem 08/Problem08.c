/*
Write a C program that contains the following functions for different numerical conversions:
1. int BinaryToDecimal(int number); Converts a binary number to its decimal equivalent.
2. int DecimalToBinary(int number); Converts a decimal number to its binary equivalent.
3. void DecimalToHexadecimal(int number); Converts a decimal number to its hexadecimal equivalent and prints it.
4. void HexadecimalToDecimal(char hexNumber[]); Converts a hexadecimal number to its decimal equivalent and prints it.
5. void BinaryToHexadecimal(int number); Converts a binary number to its hexadecimal equivalent and prints it.
6. void HexadecimalToBinary(char hexNumber[]); Converts a hexadecimal number to its binary equivalent and prints it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int BinaryToDecimal(int number) {
    int decimal = 0, base = 1, rem;
    while (number > 0) {
        rem = number % 10;
        if (rem > 1) {
            printf("Invalid binary input.\n");
            return -1;
        }
        decimal += rem * base;
        number /= 10;
        base *= 2;
    }
    return decimal;
}

int DecimalToBinary(int number) {
    int binary = 0, base = 1;
    while (number > 0) {
        binary += (number % 2) * base;
        number /= 2;
        base *= 10;
    }
    return binary;
}

void DecimalToHexadecimal(int number) {
    if (number < 0) {
        printf("Invalid decimal input.\n");
        return;
    }
    printf("Hexadecimal: %X\n", number);
}

void HexadecimalToDecimal(char hexNumber[]) {
    int decimal = 0;
    for (int i = 0; hexNumber[i] != '\0'; i++) {
        if (!isxdigit(hexNumber[i])) {
            printf("Invalid hexadecimal input.\n");
            return;
        }
    }
    sscanf(hexNumber, "%x", &decimal);
    printf("Decimal: %d\n", decimal);
}

void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    if (decimal != -1) {
        DecimalToHexadecimal(decimal);
    }
}

void HexadecimalToBinary(char hexNumber[]) {
    int decimal = 0;
    for (int i = 0; hexNumber[i] != '\0'; i++) {
        if (!isxdigit(hexNumber[i])) {
            printf("Invalid hexadecimal input.\n");
            return;
        }
    }
    sscanf(hexNumber, "%x", &decimal);
    printf("Binary: %d\n", DecimalToBinary(decimal));
}

void displayMenu() {
    printf("\nChoose a conversion option:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");
    printf("0. Exit\n");
}

int main() {
    int choice, number;
    char hexNumber[20];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                int binaryToDec = BinaryToDecimal(number);
                if (binaryToDec != -1) {
                    printf("Decimal: %d\n", binaryToDec);
                }
                break;

            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Binary: %d\n", DecimalToBinary(number));
                break;

            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                DecimalToHexadecimal(number);
                break;

            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToDecimal(hexNumber);
                break;

            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                BinaryToHexadecimal(number);
                break;

            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToBinary(hexNumber);
                break;

            case 0:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
