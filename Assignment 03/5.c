#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeInventory(char*** speciesSupplies, int numSpecies, int** numSupplies) {
    *speciesSupplies = (char**)malloc(numSpecies * sizeof(char*));
    *numSupplies = (int*)calloc(numSpecies, sizeof(int));
}

void addSupplies(char** speciesSupplies, int* numSupplies, int speciesIndex) {
    printf("Enter the number of supplies for species %d: ", speciesIndex + 1);
    scanf("%d", &numSupplies[speciesIndex]);

    speciesSupplies[speciesIndex] = (char*)malloc(numSupplies[speciesIndex] * sizeof(char*));

    for (int i = 0; i < numSupplies[speciesIndex]; i++) {
        speciesSupplies[speciesIndex][i] = (char*)malloc(50 * sizeof(char));
        printf("Enter supply %d: ", i + 1);
        scanf(" %[^\n]s", speciesSupplies[speciesIndex][i]);
    }
}

void updateSupply(char** speciesSupplies, int* numSupplies, int speciesIndex) {
    int supplyIndex;
    printf("Enter the index of the supply to update (1-%d): ", numSupplies[speciesIndex]);
    scanf("%d", &supplyIndex);
    supplyIndex--;

    if (supplyIndex < 0 || supplyIndex >= numSupplies[speciesIndex]) {
        printf("Invalid supply index.\n");
        return;
    }

    printf("Enter the new name for supply %d: ", supplyIndex + 1);
    scanf(" %[^\n]s", speciesSupplies[speciesIndex][supplyIndex]);
}

void removeSpecies(char*** speciesSupplies, int* numSupplies, int* numSpecies, int speciesIndex) {
    if (speciesIndex < 0 || speciesIndex >= *numSpecies) {
        printf("Invalid species index.\n");
        return;
    }

    for (int i = 0; i < numSupplies[speciesIndex]; i++) {
        free((*speciesSupplies)[speciesIndex][i]);
    }
    free((*speciesSupplies)[speciesIndex]);

    for (int i = speciesIndex; i < *numSpecies - 1; i++) {
        (*speciesSupplies)[i] = (*speciesSupplies)[i + 1];
        numSupplies[i] = numSupplies[i + 1];
    }

    (*speciesSupplies) = (char**)realloc(*speciesSupplies, (*numSpecies - 1) * sizeof(char*));
    *numSpecies -= 1;
}

void displayInventory(char** speciesSupplies, int* numSupplies, int numSpecies) {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < numSpecies; i++) {
        printf("Species %d:\n", i + 1);
        for (int j = 0; j < numSupplies[i]; j++) {
            printf("  - %s\n", speciesSupplies[i][j]);
        }
    }
}

int main() {
    char** speciesSupplies;
    int* numSupplies;
    int numSpecies;

    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    initializeInventory(&speciesSupplies, numSpecies, &numSupplies);

    for (int i = 0; i < numSpecies; i++) {
        printf("\nAdding supplies for species %d...\n", i + 1);
        addSupplies(speciesSupplies, numSupplies, i);
    }

    displayInventory(speciesSupplies, numSupplies, numSpecies);

    printf("\nUpdate supplies for a species:\n");
    int speciesIndex;
    printf("Enter species index (1-%d): ", numSpecies);
    scanf("%d", &speciesIndex);
    updateSupply(speciesSupplies, numSupplies, speciesIndex - 1);

    displayInventory(speciesSupplies, numSupplies, numSpecies);

    printf("\nRemove a species:\n");
    printf("Enter species index to remove (1-%d): ", numSpecies);
    scanf("%d", &speciesIndex);
    removeSpecies(&speciesSupplies, numSupplies, &numSpecies, speciesIndex - 1);

    displayInventory(speciesSupplies, numSupplies, numSpecies);

    for (int i = 0; i < numSpecies; i++) {
        for (int j = 0; j < numSupplies[i]; j++) {
            free(speciesSupplies[i][j]);
        }
        free(speciesSupplies[i]);
    }
    free(speciesSupplies);
    free(numSupplies);

    return 0;
}
