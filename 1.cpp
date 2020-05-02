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
string ToLowerCase(string v){
  for (int i=0; i<v.length(); i++){
    char x=v[i];
    if (x<='Z' && x>='A'){
      v[i]=x-('A'-'a');
    }
  }
  return v;
}
storing_data(int ques,int cash){
  ofstream fout("output.txt");
  fout<<ques<<" "<<cash;
  fout.close();
}
extractng_data(int &ques,int &cash){
  ofstream fin("output.txt");
  fin<<ques<<cash;
  cout<<ques<<" "<<cash;
  fin.close();
}
sample_question_structure(int ques,int &index,int &cash){
  int random;
  string answer;
  cout<<"Question "<<ques<<" is: "<<endl;
  struct question_structure{
    string question;
    string option_A;
    string option_B;
    string option_C;
    string option_D;
    string correct_option;
    string correct_letter;
  };
  question_structure game_program[5]={{"what","a","b","c","d","c"},{"why","a","b","c","d","a"}};
  random=rand()%5;
  if (random==index){
    while(random==index){
      random=rand()%5;
    }
  }
  index=random;
  cout<<left;
  cout<<game_program[index].question<<endl;
  cout<<"A) "<<game_program[index].option_A<<setw(25)<<"B) "<<game_program[index].option_B<<endl;
  cout<<"C) "<<game_program[index].option_C<<setw(25)<<"D) "<<game_program[index].option_D<<endl;
  cout<<"Your Answer: ";
  cin<<answer;
  if (ToLowerCase(answer)==game_program[index].correct_option || ToLowerCase(answer)==game_program[index].correct_letter){
    cout<<"Your Answer is correct"<<endl;
    cash=cash*2;
  }
  else{
    cout<<"Incorrect Answer"<<endl;
    cash=cash/2;
  }
  cout<<"Your new balance is "<<currency<<" "<<cash<<endl;
}

int main() {
    // declare all variables here with either significant names or add comments explaning their use
    srand(time(NULL));
    int no_of_players, no_of_questions;
    string player_1;
    cout << "Welcome to Quiz 2020!" << endl;
    buffer();

    cout << "Enter first name of player : " ; cin >> player_1;
    cout << endl;
    buffer();

    introduction(player_1);

    buffer();

    select_currency();

  



}
