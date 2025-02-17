#include <stdio.h>

void display(char board[]) {

     for(int i = 0; i < 9; i+=3) {
         printf("%c | %c | %c\n", board[i], board[i+1],board[i+2]);
         if(i < 6) printf("----------\n");
     }
     printf("\n");
}

char check_winner(char board[]) {
      //check lines

      for( int i = 0; i < 9; i+=3 ) {
          if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i] != ' ') return board[i];
      }

      //check cols
      for(int i = 0; i < 3; ++i) {
          if(board[i] == board[i+3] && board[i+3] == board[i+6] && board[i] != ' ') return board[i];
      }


      //check diagonals
      if((board[0] == board[4]) && (board[4] == board[8]) && board[0] != ' ') return board[0];

      if((board[2] == board[4]) && (board[4] == board[6]) && board[2] != ' ') return board[2];

      return '_';

}

int checkFullBoard(char board[]) {
     int cnt = 0;
     for(int i = 0; i < 9; ++i) if(board[i] != ' ') cnt++;
     return cnt == 9;
}

int main(int argc, char const *argv[]) {

  char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  int pos;
  char current_player = 'X';

  display( board );

  while(1) {
        printf("Current Player: %c, enter position (1-9): ", current_player) ;
        scanf("%d",&pos);

        if(pos < 0 || pos >9) {
          printf("Enter a number between 0 and 9\n");
          continue;
        }

        if(board[pos-1] != ' ') {
          printf("The Position is already taken.\n");
          continue;
        }

        board[pos-1] = current_player;

        display( board );

        char winner = check_winner( board );


        if(winner != '_') {

          printf("The winner is %c\n", winner);

          break;

        }

        if(checkFullBoard(board)) { printf("The Game is draw!\n"); break; }

        if(current_player == 'X') current_player = '0'; else current_player = 'X';
  }

  return 0;
}
