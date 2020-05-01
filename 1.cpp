#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>

/*
//to take in number of users
do {
cout << endl;
cout << "Enter Number of Players [1/2] : " ;
cin >> no_of_players;
if( !( no_of_players ==1 || no_of_players == 2) ) { cout << "Invalid Option, Please select again! " << endl;}
} while( !(no_of_players == 1 || no_of_players == 2) );
buffer();
*/
using namespace std;

// delcare all global variables here, score is the game score for the players and currency is the global currency value for the entire code
int score_1;
string currency;

// function printd endl, and then clears it
void buffer() {
  cout << endl;
  cout << "Press Enter to Continue!" << endl;
  getch();
  system("cls");
}

// function to print introduction for the game and instructions too, edit the last!!!
void introduction (string player_1) {

  cout << "HEllO " << player_1 << endl;
  cout << "This is how the game works" << endl;
  buffer();

}

// to select game currency as score
void select_currency(){
  int currency_options;
  do {

  cout << "Please select Game Score Currency to record your progress " << endl;
  cout << "1: Dollar [$]" << endl;
  cout << "2: Game Currency [|_|]" << endl;

  cin >> currency_options;

  if(currency_options == 1) {
    ::currency = "$";
  }
  else if (currency_options == 2) {
    ::currency = "|_|";
  }
  else { cout << "Sorry Option Not Recognized" << endl; }

} while( !( currency_options == 1 || currency_options == 2) );

cout << "Game Currency is : " << currency << endl;

}

int main() {
    // declare all variables here with either significant names or add comments explaning their use
    int no_of_players, no_of_questions;
    string player_1;
    cout << "Welcome to Quiz 2020!" << endl;
    buffer();

    cout << "Enter first name of player : " ; cin >> player_1;
    cout << endl;
    buffer();

    introduction(player_1);

    cout << "Enter Number of Trivia Questions [max(15)] : ";
    cin >> no_of_questions;
    buffer();

    select_currency();

    fstream score;
    score.open("score board.txt", ios::in);
    score.open("score board.txt", ios::out);




}
