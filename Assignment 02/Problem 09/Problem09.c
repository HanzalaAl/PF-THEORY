/*
Simple Grid-Based Adventure Game

Game Description:
- The game consists of a 5x5 grid.
- Each cell can contain:
    - An empty space (' ').
    - An item ('I') that the player can collect.
    - An obstacle ('X') that the player cannot pass through.
    - The player's position, represented by 'P'.
Requirements:
1. Display the grid and prompt the player for a move (W: up, S: down, A: left, D: right, Q: quit).
2. Update the player's position based on valid moves.
3. Collect items when the player moves to a cell containing an item (remove item from grid).
4. Prevent movement into obstacles ('X').
5. Continue until the player chooses to quit.
6. The grid is fixed at 5x5.
7. Only valid moves are allowed.
8. Handle invalid input gracefully.
*/

#include <stdio.h>
#include <conio.h>

#define SIZE 5

void displayGrid(char grid[SIZE][SIZE]) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char grid[SIZE][SIZE], int *playerRow, int *playerCol, int dRow, int dCol, int *itemsCollected) {
    int newRow = *playerRow + dRow;
    int newCol = *playerCol + dCol;

    if (newRow < 0 || newRow >= SIZE || newCol < 0 || newCol >= SIZE) {
        printf("Move out of bounds! Try again.\n");
        return;
    }

    if (grid[newRow][newCol] == 'X') {
        printf("Obstacle encountered! Move not allowed.\n");
        return;
    }

    if (grid[newRow][newCol] == 'I') {
        printf("Item collected!\n");
        (*itemsCollected)++;
    }

    grid[*playerRow][*playerCol] = ' ';
    *playerRow = newRow;
    *playerCol = newCol;
    grid[*playerRow][*playerCol] = 'P';
}

int main() {
    char grid[SIZE][SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playerRow = 4, playerCol = 4;
    int itemsCollected = 0;
    char move;

    while (1) {
        displayGrid(grid);
        printf("Items Collected: %d\n", itemsCollected);
        printf("Enter move (W: up, S: down, A: left, D: right, Q: quit): ");
        move = getch();
        move = toupper(move);

        switch (move) {
            case 'W':
                movePlayer(grid, &playerRow, &playerCol, -1, 0, &itemsCollected);
                break;
            case 'S':
                movePlayer(grid, &playerRow, &playerCol, 1, 0, &itemsCollected);
                break;
            case 'A':
                movePlayer(grid, &playerRow, &playerCol, 0, -1, &itemsCollected);
                break;
            case 'D':
                movePlayer(grid, &playerRow, &playerCol, 0, 1, &itemsCollected);
                break;
            case 'Q':
                printf("Thanks for playing!\n");
                printf("Total Items Collected: %d\n", itemsCollected);
                return 0;
            default:
                printf("Invalid move! Please enter W, S, A, D, or Q.\n");
                break;
        }
    }

    return 0;
}
