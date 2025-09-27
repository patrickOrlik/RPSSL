#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

enum { SPOCK = 0, SCISSORS = 1, PAPER = 2, ROCK = 3, LIZARD = 4 } PLAYER;
int user_input;
int PlayerScore = 0;
int PcScore = 0;
int PlayerChoice;
int Diff;

int main() {
  srand(time(NULL)); // Generer en seed baseret på tidspunktet
  while (1) {
    puts("welcome to to the RPSSL game!\n [s]- start \n [e]-exit");
    user_input = getchar();
    while ((getchar()) != '\n')
      ;

    if (user_input == 'e')
      return 0;
    else if (user_input == 's') {
      puts("Game is starting...");
      sleep(1);
      while (PcScore < 5 && PlayerScore < 5) {
        do {
          puts("Pick a hand!\n [0]🖖\n [1]✂️\n [2]🗒️\n [3]🪨\n [4]🦎");
          scanf("%d", &PlayerChoice);
          if (PlayerChoice != 1)
            while (getchar() != '\n')
              ;

          if (PlayerChoice < 0 || PlayerChoice > 4)
            puts("Sorry! Wrong input try again!");
        } while (PlayerChoice < 0 || PlayerChoice > 4);

        switch (PlayerChoice) {
        case SPOCK:
          puts("You Chose spock🖖!");
          break;
        case SCISSORS:
          puts("you chose Scissors✂️!");
          break;
        case PAPER:
          puts("you chose PAPER🗒️!");
          break;
        case ROCK:
          puts("you chose rock🪨!");
          break;
        case LIZARD:
          puts("you chose lizard🦎!");
          break;
        }
        sleep(1);
        int PcChoice = rand() % 5;
        switch (PcChoice) {
        case SPOCK:
          puts("🤖 Chose spock🖖!");
          break;
        case SCISSORS:
          puts("🤖 chose Scissors✂️!");
          break;
        case PAPER:
          puts("🤖 chose PAPER🗒️!");
          break;
        case ROCK:
          puts("🤖 chose rock🪨!");
          break;
        case LIZARD:
          puts("🤖 chose lizard🦎!");
          break;
        }
        int Diff = PcChoice - PlayerChoice;
        if (Diff == 0)
          puts("its a tie!");
        else if (Diff == -4 || Diff == -2 || Diff == 1 || Diff == 3) {
          puts("You WON this round!😄");
          ++PlayerScore;
        } else {
          puts("you LOST this round!🥴");
          ++PcScore;
        }
        {
        }
        printf("👫your score is:  %d ", PlayerScore);
        printf("🤖Agents Score is:  %d \n", PcScore);
        sleep(3);
      }
      if (PlayerScore == 5)
        puts("You won the game congratulations!!🤩🤩🤩");
      else
        puts("You lost the game sorry!🤮🤮🤮🤮");
      return 0;

    } else
      puts("error wrong input try again!");
  }
}