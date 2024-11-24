#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    if (email == NULL || strlen(email) == 0) return 0;
    char* atPtr = strchr(email, '@');
    if (atPtr == NULL) return 0;
    if (strchr(atPtr + 1, '.') == NULL) return 0;
    if (strchr(atPtr + 1, '@') != NULL) return 0;
    return 1;
}

int main() {
    char *email;
    int length;
    printf("Enter the length of the email address: ");
    scanf("%d", &length);
    email = (char *)malloc((length + 1) * sizeof(char));
    if (email == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter the email address: ");
    scanf(" %[^\n]s", email);
    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }
    free(email);
    return 0;
}
