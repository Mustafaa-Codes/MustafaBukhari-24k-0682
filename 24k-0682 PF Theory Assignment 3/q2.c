/*
Name:- Syed Mustafa Bukhari
Roll#:- 24k-0682
Question 2
Pf Assignment 3
*/
#include <stdio.h>
#include <string.h>

#define BALLS 12


typedef struct {
    char playerName[50];
    int ballScores[BALLS];
    int totalScore;
} Player;
int validateScore(int score) {
    return (score >= 0 && score <= 6);
}

void playGame(Player *player) {
    player->totalScore = 0;
    printf("\n%s, it's your turn!\n", player->playerName);

    for (int i = 0; i < BALLS; i++) {
        printf("Enter score for ball %d: ", i + 1);
        int score;
        scanf("%d", &score);

        if (validateScore(score)) {
            player->ballScores[i] = score;
            player->totalScore += score;
        } else {
            printf("Invalid score! Score must be between 0 and 6. Ball is still marked.\n");
            player->ballScores[i] = 0;
        }
    }
}
void findWinner(Player player1, Player player2) {
    printf("\nMatch Result:\n");
    if (player1.totalScore > player2.totalScore) {
        printf("Winner: %s with %d runs!\n", player1.playerName, player1.totalScore);
    } else if (player1.totalScore < player2.totalScore) {
        printf("Winner: %s with %d runs!\n", player2.playerName, player2.totalScore);
    } else {
        printf("It's a tie! Both players scored %d runs.\n", player1.totalScore);
    }
}
void displayMatchScoreboard(Player player1, Player player2) {
    printf("\nMatch Scoreboard:\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < 2; i++) {
        Player player = (i == 0) ? player1 : player2;
        printf("Player: %s\n", player.playerName);
        printf("Scores per ball: ");
        for (int j = 0; j < BALLS; j++) {
            printf("%d ", player.ballScores[j]);
        }
        printf("\nTotal Score: %d\n", player.totalScore);
        printf("Average Score: %.2f\n", player.totalScore / (float)BALLS);
        printf("----------------------------------------------------\n");
    }
}

int main() {
    Player player1, player2;
    printf("Enter Player 1's name: ");
    scanf(" %[^\n]%*c", player1.playerName);
    printf("Enter Player 2's name: ");
    scanf(" %[^\n]%*c", player2.playerName);
    playGame(&player1);
    playGame(&player2);

    displayMatchScoreboard(player1, player2);

    findWinner(player1, player2);

    return 0;
}
