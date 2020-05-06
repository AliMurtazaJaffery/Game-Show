#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
using namespace std;
//global variable
//index will be used in the structured questions.
int index;
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
void storing_data(int ques,int cash){
  ofstream fout("output.txt");
  fout<<ques<<endl;
  fout<<cash;
  fout.close();
}
void extracting_data(int &ques,int &cash){
  ifstream fin("output.txt");
  fin>>ques>>cash;
  fin.close();
}
sample_question_structure_1(int &ques,int &cash){
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
  question_structure game_program[5]={{"what","a","b","c","d","c","d"},{"why","a","b","c","d","a","g"},{"what","1","2","4","5","6","4"},{"when","1","3","5","5","t","5"},{"where","r","t","y","t","t","5"}};
  random=rand()%5;
  if (random==index){
    while(random==index){
      random=rand()%5;
    }
  }
  index=random;
  cout<<left;
  cout<<game_program[index].question<<endl;
  cout<<"A) "<<setw(25)<<game_program[index].option_A<<"B) "<<game_program[index].option_B<<endl;
  cout<<"C) "<<setw(25)<<game_program[index].option_C<<"D) "<<game_program[index].option_D<<endl;
  cout<<"Your Answer: ";
  cin>>answer;
  if (ToLowerCase(answer)==game_program[index].correct_option || ToLowerCase(answer)==game_program[index].correct_letter){
    cout<<"Your Answer is correct"<<endl;
    cash=cash*2;
  }
  else{
    cout<<"Incorrect Answer"<<endl;
    cash=cash/2;
  }
  cout<<"Your new balance is "<<currency<<" "<<cash<<endl;
  ques++;
  storing_data(ques,cash);
  buffer();
}

int main(){

  int round,money;
  extracting_data(round,money);
  if (round=1){
    string player_1;
    cout << "Welcome to Quiz 2020!" << endl;
    buffer();
    cout << "Enter first name of player : " ;
    cin >> player_1;
    buffer();

    introduction(player_1);
    select_currency();
  }


  srand(time(NULL));

  while (round<3){
    sample_question_structure_1(round,money);
  }
  // while (2<round<5){
  //   sample_question_structure_2(round,money);
  // }
  // if (round==5){
  //   lucky_7(round,money);
  // }
  // while (5<round<8){
  //   sample_question_structure_3(round,money);
  // }
  // if (round==8){
  //   rapid_fire(round,money);
  // }
  // while (8<round<11){
  //   sample_question_structure_4(round,money);
  // }
  // if (round==11){
  //   lucky_7(round,money);
  // }
  // while (11<round<14){
  //   sample_question_structure_5(round,money);
  // }





}
