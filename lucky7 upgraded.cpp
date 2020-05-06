#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <string>

using namespace std;

void buffer() {
  cout << endl;
  cout << "Press Enter to Continue!" << endl;
  cin.get();
  system("cls"); // change to clear for linux
}

void printboard() {
  cout << " ";
  for(int i = 0; i < 30; i++) {
    cout << "_";
  }
  cout << endl << endl;
  cout << " | ";
  for(int i = 1; i < 13; i++){
    cout << i << " ";
  }
  cout << "|";
  cout << endl;
  cout << " ";
  for(int i = 0; i < 30; i++) {
    cout << "_";
  }
  cout << endl << endl;

}

void typewriter(string line, int speed){
  int i = 0;
  while(i < line.length()) {
    cout << line[i++];
    cout.flush();
    usleep(speed);
  }
}

void lucky_7(int &round, int &money) {
    
    system("cls"); // change to clear for linux
    int number;
    char bet;
    srand(time(0));
    number = (rand() % 15) + 1;

    typewriter("Current round is ", 150000);
    cout << round << endl << endl;
    usleep(500000);
    typewriter("Current Score is ", 150000);
    cout << money << endl;
    usleep(500000);
    buffer();
    typewriter("Welcome to the game of Lucky 7 !", 100000);
    cout << endl << endl;
    usleep(500000);
    typewriter("Instructions: ", 100000);
    cout << endl << endl;
    usleep(200000);
    typewriter("Lucky Seven is a dice game.", 100000);
    cout << endl;
    typewriter("The main aim of the game is to bet game score on the dice roll to double your score.", 100000);
    cout << endl;
    typewriter("Enter your bet for any of the options, viz. Below Seven, Exact Seven, Above Seven.", 100000);
    cout << endl;
    typewriter("Roll The Dice, if the sum of the dice values matches your bet, score is doubled.", 100000);
    cout << endl;
    typewriter("If not, round is forfeited!", 100000);
    cout << endl;

    sleep(1);
    buffer();

    do {
      printboard();
      typewriter("To bet above 7 press [A], To bet below 7 press [B], To bet on 7 press [S]", 100000);
      cout << endl << endl;
      typewriter("Enter your choice now : ", 100000);
      cout << endl;
      cin >> bet;
      bet = toupper(bet);
      usleep(500000);
      if(bet == 'A') {
        cout << endl ;
        typewriter("YOU HAVE CHOSEN TO BET ABOVE 7!", 100000);
        usleep(500000);
        typewriter("ARE YOU READY!", 100000);
        cout << endl;
      }
      else if(bet == 'B') {
        cout << endl ;
        typewriter("YOU HAVE CHOSEN TO BET BELOW 7! ARE YOU READY! ", 100000);
        cout << endl;
      }
      else if(bet == 'S') {
        cout << endl ;
        typewriter("YOU HAVE CHOSEN TO BET ON 7! ARE YOU READY! ", 100000);
        cout << endl;
      }
      else {
        cout << endl <<  "Invalid choice! Please try again!" << endl;
      }

    } while( ! (bet == 'A' || bet == 'B' || bet == 'S' ) );
    cout << endl;
    typewriter("5! 4! 3! 2! 1!",350000);
    cout << endl << endl ;
    typewriter("DICE ROLL IS \a", 100000);
    usleep(1000000);
    cout <<  number << endl << endl;
    usleep(1000000);

    if(number > 7 && bet == 'A') {

      typewriter("CONGRATULATIONS! ",100000);
      cout << endl << endl;
      money *= 2;
      cout << "Money is " << money << endl;

    }
    else if(number < 7 && bet == 'B') {

      typewriter("Congratulations! ",100000);
      cout << endl << endl;
      money *= 2;
      cout << "Money is " << money << endl;

    }
    else if(number == 7 && bet == 'S') {

      typewriter("Congratulations! ",100000);
      cout << endl << endl;
      money *= 2;
      cout << "Money is " << money << endl;

    }
    else {
      typewriter("Sorry! No luck! ",100000);
      cout << endl << endl;
    }
    round += 1;
}

