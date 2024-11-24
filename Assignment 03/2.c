#include <stdio.h>
#include <string.h>

struct Player {
    int ballScores[12];
    char playerName[50];
    int totalScore;
};

int validateScore(int score) {
    return (score >= 0 && score <= 6) ? 1 : 0;
}

void playGame(struct Player *player) {
    printf("Enter scores for %s:\n", player->playerName);
    player->totalScore = 0;
    for (int i = 0; i < 12; i++) {
        printf("Ball %d: ", i + 1);
        int score;
        scanf("%d", &score);
        if (validateScore(score)) {
            player->ballScores[i] = score;
            player->totalScore += score;
        } else {
            player->ballScores[i] = 0;
        }
    }
}

void findWinner(struct Player player1, struct Player player2) {
    if (player1.totalScore > player2.totalScore) {
        printf("\nWinner: %s with %d runs\n", player1.playerName, player1.totalScore);
    } else if (player2.totalScore > player1.totalScore) {
        printf("\nWinner: %s with %d runs\n", player2.playerName, player2.totalScore);
    } else {
        printf("\nMatch Drawn! Both players scored %d runs\n", player1.totalScore);
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) {
    printf("\nMatch Scoreboard:\n");
    printf("%s's Performance:\n", player1.playerName);
    for (int i = 0; i < 12; i++) {
        printf("Ball %d: %d\n", i + 1, player1.ballScores[i]);
    }
    printf("Total Score: %d\n", player1.totalScore);
    printf("Average Score: %.2f\n", player1.totalScore / 12.0);

    printf("\n%s's Performance:\n", player2.playerName);
    for (int i = 0; i < 12; i++) {
        printf("Ball %d: %d\n", i + 1, player2.ballScores[i]);
    }
    printf("Total Score: %d\n", player2.totalScore);
    printf("Average Score: %.2f\n", player2.totalScore / 12.0);
}

int main() {
    struct Player player1, player2;
    printf("Enter Player 1 Name: ");
    scanf(" %[^\n]s", player1.playerName);
    printf("Enter Player 2 Name: ");
    scanf(" %[^\n]s", player2.playerName);

    playGame(&player1);
    playGame(&player2);

    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);

    return 0;
}
