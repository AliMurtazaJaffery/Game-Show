#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include <limits>
using namespace std;
//global variable
//index will be used in the structured questions.
int index;
string player_1;
string currency;
// function printd endl, and then clears it
void buffer() {
  cout << endl;
  cout << "Press Enter to Continue!" << endl;
  getch();
  system("clear");
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
  fout<<player_1<<endl;
  fout<<ques<<endl;
  fout<<cash<<endl;
  fout<<currency<<endl;
  fout<<index;
  fout.close();
}
void extracting_data(int &ques,int &cash){
  ifstream fin("output.txt");
  fin>>player_1>>ques>>cash>>currency>>index;
  fin.close();
}
void sports_section(int &ques,int &cash){
  int random,variable_getline;
  string answer;
  variable_getline=index;
  if (index==7){
    cout<<"Welcome to the sports round!"<<endl;
    cout<<"Your current balance is "<<currency<<cash<<endl;
    buffer();
  }
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
  question_structure game_program[5]={{"Which team has won the most cricket world cups?","Australia","India","Pakistan","England","australia","a"},{"Which Premiere League team is known as \"The Invincibles\"?","Tottenham Hotspur","Chelsea","Arsenal","Liverpool","arsenal","c"},{"Which is the most successful team in the Premiere League?","Chelsea","Arsenal","Liverpool","Manchester United","manchester united","d"},{"Who has won the most number of Grand Slams?","Rafael Nadal","Novak Djokovic","Roger Federer","Andy Murray","roger federer","c"},{"Who is the most decorated player in football? ","Cristiano Ronaldo","Dani Alves","Lionel Messi","Ronaldinho","dani alves","b"}};
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
  if (variable_getline==7){
   cin.ignore( numeric_limits<streamsize>::max(), '\n' );
   getline(cin,answer);
  }
  else{
    getline(cin,answer);
  }

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
void technology(int &ques,int &cash){
  int random;
  string answer;
  if (index==7){
    cout<<"Welcome to the round of technology!"<<endl;
    cout<<"Your current balance is "<<currency<<cash<<endl;
    buffer();
  }
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
  question_structure game_program[5]={{"\'OS\' computer abbreviation usually means ?","Order of Significance","Open software","Operating system","Optical Sensor","operating system","c"},{"Who is largely responsible for breaking the German Enigma codes, created a test that provided a foundation for artificial intelligence?","Alan Turing","Jeff Bezos","George Boole","Charles Babbage","alan turing","a"},{"Which consists of two plates separated by a dielectric and can store a charge?","Inductor","Capacitor","Transistor","Relay","capacitor","b"},{"How many bits is a byte?","4","8","16","32","8","b"},{"Who is the current CEO of Google?","Steve Jobs","Bill Gates","Sundar Pichai","Elon Musk","sundar pichai","c"}};
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
  getline(cin,answer);
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
void world_history(int &ques,int &cash){
  int random;
  string answer;
  if (index==7){
    cout<<"Welcome to the World History section!"<<endl;
    cout<<"Your current balance is "<<currency<<cash<<endl;
    buffer();
  }
  cout<<"Question "<<ques-1<<" is: "<<endl;
  struct question_structure{
    string question;
    string option_A;
    string option_B;
    string option_C;
    string option_D;
    string correct_option;
    string correct_letter;
  };
  question_structure game_program[5]={{"Which is considered as oldest civilization of the world ?"," Mesopotamian Civilization","Harappan Civilization","Chinese Civilization","Egyptain Civilization","mesopotamian civilization","a"},{"The invasion of which of these countries in 1939 widely regarded to have started World War II ?","Italy","Germany","Poland","France","poland","c"},{"When was the Opium war held between Britain and China ?","1853","1857","1837","1839","1839","d"},{"In which year Hitler became the Chancellor of Germany ?","1932","1933","1944","1945","1933","b"},{"Which of the following year is considered as the first year of the Muslim calender ? ","AD 622","AD 671","AD 571","AD 651","ad 622","a"}};
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
  getline(cin,answer);
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
void entertainment(int &ques,int &cash){
  int random;
  string answer;
  if (index==7){
    cout<<"Welcome to the Entertainment round!"<<endl;
    cout<<"Your current balance is "<<currency<<cash<<endl;
    buffer();
  }
  cout<<"Question "<<ques-1<<" is: "<<endl;
  struct question_structure{
    string question;
    string option_A;
    string option_B;
    string option_C;
    string option_D;
    string correct_option;
    string correct_letter;
  };
  question_structure game_program[5]={{"\'Cercei Lannister\' is a famous character from which TV show?","Breaking Bad","House of Cards","Game of Thrones","Westworld","game of thrones","c"},{"What is the name of Ross Geller's second wife in the TV Show \'FRIENDS\'?","Rachel","Carol","Janice","Emily","emily","d"},{"Which song has the most number of views on Youtube?","See you again","Despacito","Shape of you","Gangnam Style","despacito","b"},{"Which TV show has the highest IMDB rating?","Planet Earth 2","Breaking Bad","Chernobyl","Sherlock","planet earth 2","a"},{"Leonardo DiCaprio won Oscar for which movie? ","Titanic","The Revenant","The Wolf of Wall Street","The Great Gatsby","the revenant","b"}};
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
  getline(cin,answer);
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
void intelligence_quotient(int &ques,int &cash){
  int random;
  string answer;
  if (index==7){
    cout<<"Our last section will test your IQ"<<endl;
    cout<<"Your current balance is: "<<currency<<cash<<endl;
    buffer();
  }
  cout<<"Question "<<ques-1<<" is: "<<endl;
  struct question_structure{
    string question;
    string option_A;
    string option_B;
    string option_C;
    string option_D;
    string correct_option;
    string correct_letter;
  };
  question_structure game_program[5]={{"If you rearrange the letters \'BARBIT\' you would have the name of a:","Country","Ocean","Animal","City","animal","c"},{"Which one of the four is least like the other three?","Tiger","Dog","Cow","Snake","snake","d"},{"Some months have 31 days; how many have 28?",
"1","3","6","12","12","d"},{"Two people can make 2 bicycles in 2 hours. How many people are needed to make 12 bicycles in 6 hours?","2","4","6","12","4","b"},{"The day after the day after tomorrow is four days before Monday. What day is it today?","Monday","Wednesday","Thursday","Sunday","monday","a"}};
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
  getline(cin,answer);
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
  if (round==1){
    cout << "Welcome to Quiz 2020!" << endl;
    buffer();
    cout << "Enter first name of player : " ;
    cin >> player_1;
    buffer();

    introduction(player_1);
    select_currency();
    buffer();
  }
  else{
    cout<<"Welcome back "<<player_1<<endl;
    buffer();
  }


  srand(time(NULL));

  while (round<3){
    sports_section(round,money);
  }
  index=7;
  storing_data(round,money);

  while (2<round && round<5){
    technology(round,money);
  }
  index=7;
  storing_data(round,money);
  // if (round==5){
  //   lucky_7(round,money);
  // }
  while (5<round && round<8){
    world_history(round,money);
  }
  index=7;
  storing_data(round,money);
  // if (round==8){
  //   rapid_fire(round,money);
  // }
  while (8<round && round<11){
    entertainment(round,money);
  }
  // if (round==11){
  //   lucky_7(round,money);
  // }
  index=7;
  storing_data(round,money);
  while (11<round && round<14){
    intelligence_quotient(round,money);
  }
  index=7;
  player_1="none";
  round=1;
  money=1000;
  storing_data(round,money);




}
