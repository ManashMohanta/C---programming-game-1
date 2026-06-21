#include <stdio.h>
int main() {
    char player1, player2,player3;
    printf("Enter Player 1's choice (R for Rock, P for Paper, S for Scissors): ");
    scanf(" %c", &player1);

    printf("Enter Player 2's choice (R for Rock, P for Paper, S for Scissors): ");
    scanf(" %c", &player2);

  

    if (player1 == player2 && player2 == player3) {
        printf("It's a tie!\n");
    } else if ((player1 == 'R' && player2 == 'S') ||
               (player1 == 'P' && player2 == 'R') ||
               (player1 == 'S' && player2 == 'P')) {
        printf("Player 1 wins!\n");
    
        
    } else {
     printf("Player 2 wins!\n");
    }

    return 0;
  
}