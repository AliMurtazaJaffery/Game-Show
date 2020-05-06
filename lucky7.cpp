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

void lucky_7(int &round, int &money) {

    int number;
    char bet;
    srand(time(0));
    number = rand() % 15;

    cout << "Current round is "  << round << endl << endl;
    sleep(1);
    cout << "Your Current Score is " << money << endl;
    sleep(1);
    buffer();

    cout << "Welcome to the game of Lucky 7 !"<< endl << endl;
    usleep(500000);
    cout << "Instructions: " << endl << endl;
    usleep(2000000);
    cout << "Lucky Seven is a dice game." << endl;
    cout << "The main aim of the game is to bet game score on the dice roll to double your score." << endl;
    cout << "Enter your bet for any of the options, viz. Below Seven, Exact Seven, Above Seven." << endl;
    cout << "Roll The Dice, if the sum of the dice values matches your bet, score is doubled." << endl;
    cout << "If not, round is forfeited" << endl;
    sleep(1);
    buffer();

    do {
      printboard();
      cout << "To bet above 7 press [A], To bet below 7 press [B], To bet on 7 press [S]" << endl << endl;
      cout << "Enter your choice now : " << endl;
      cin >> bet ;
      bet = toupper(bet);
      usleep(500000);
      if(bet == 'A') {
        cout << endl << "YOU HAVE CHOSEN TO BET ABOVE 7! ARE YOU READY! " << endl;
      }
      else if(bet == 'B') {
        cout << endl << "YOU HAVE CHOSEN TO BET BELOW 7! ARE YOU READY! " << endl;
      }
      else if(bet == 'S') {
        cout << endl << "YOU HAVE CHOSEN TO BET ON 7! ARE YOU READY! " << endl;
      }
      else {
        cout << endl <<  "Invalid choice! Please try again!" << endl;
      }

    } while( ! (bet == 'A' || bet == 'B' || bet == 'S' ) );

    cout << endl << "DICE ROLL IS  ";
    usleep(1000000);
    cout << number << endl << endl;
    usleep(1000000);

    if(number > 7 && bet == 'A') {

      cout << "Congratulations!" << endl << endl;
      money *= 2;
      cout << "Money is " << money << endl;

    }
    else if(number < 7 && bet == 'B') {

      cout << "Congratulations!" << endl;
      money += 1000;
      cout << "Score is " << money << endl;

    }
    else if(number == 7 && bet == 'S') {

      cout << "Congratulations!" << endl;
      money += 1000;
      cout << "Score is " << money << endl;

    }
    else {
      cout << "Sorry! No luck! " << endl;
    }
    round +=1;
}

int main() {
  int round = 22, money = 1;
  lucky_7(round,money);
}
