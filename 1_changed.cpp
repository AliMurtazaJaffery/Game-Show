#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

using namespace std;

//global variable
//index will be used in the structured questions.
int index;
string player_1, currency;

// function printd endl, and then clears it
void buffer() {
  cout << endl;
  cout << "Press Enter to Continue!" << endl;
  cin.get();
  system("cls"); // change to clear for linux
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
//___________________________________________________________________

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
    round +=1;
}

void displayClock(int seconds) {
    // system call to clear the screen
    system("cls"); // change to clear for linux
    cout << endl;
    cout << setfill(' ') << setw(55) << "           TIMER         \n";
    cout << setfill(' ') << setw(55) << " ------------------\n";
    cout << endl;
    cout << "                                        | " << setfill('0') << setw(2) << seconds << " sec | " << endl << endl;
    cout << setfill(' ') << setw(55) << " ------------------\n";
}

void timer(int seconds) {
  int value = 1;
  int internal_s = 0;
   while (seconds >= internal_s) {
       // display the timer
       displayClock(internal_s);
       sleep(1);
       internal_s++;
       // if seconds reaches 60
       if (internal_s == 60) {
             value = 0;
           }
       }
}

void rapid_fire(int &round, int &money) {

  string file = "rapid_fire_questions.txt";
  char line[80];
  int n, seconds = 0;

  fstream fire(file, ios::in);
  if(fire.fail()) {
    typewriter("Rapid Fire has been Canceled! Sorry! ", 100000);
    cout << endl;
  }
  else {
    typewriter("Welcome to the rapid fire round!", 100000);
    cout << endl << endl;

    typewriter("How many questions can you answer? ",100000);
    typewriter("Remember, the number of questions should be more than 2 and less than 16!", 100000);
    cout << endl << endl;
    cin >> n;
    if(n < 2 || n > 16) {
      do {
        cout << endl;
        typewriter("Sorry! Please re-enter a VALID value", 100000);
        cout << endl;
        cin >> n;
      } while( n < 2 || n > 16);
  }

    buffer();
    typewriter("You have chosen to answer ", 100000);
    cout << n;
    typewriter(" questions!", 100000);
    cout << endl << endl;

    //while(fire.getline(line,80)){  }
    string *questions = new string[n];
    string *answers = new string[n];
    string *user_answers = new string[n];
    // for entering questions into dynamic array
    for(int i = 0; i < n; i++){
      fire.getline(line,80);
      questions[i] = line;
      fire.getline(line,80);
      answers[i] = line;
    }

    typewriter("Your questions will load after the instructions. Please enter your answer via your keyboard and press enter to save answer! ", 100000);
    cout << endl;
    typewriter("If you do not know the answer for a question, enter n and continue!", 100000);
    cout << endl;
    typewriter("Remember, each correct answer is worth 200 points while incorrect answer is worth 0 points!", 100000);
    cout << endl;
    typewriter("To prepare, you will be given time under 1 minute. This time can be set by you!", 100000);
    cout << endl;
    typewriter("How many seconds do you need to prepare for the questions? ", 100000);
    cout << endl;
    typewriter("Seconds : ", 100000);
    cin >> seconds;
    timer(seconds);
    typewriter("QUESTIONS: ", 100000);
    cout << endl << endl  ;
    // for printing the questions
    for(int i = 0; i < n; i++) {
      cout << questions[i] << endl;
    }
    cout << endl;

    // for entering user_answers
    for(int i = 0; i < n; i++) {
      cin >> user_answers[i];
    }
    cout << endl;
    // addition of points
    for(int i = 0; i < n; i++) {
      if( ( answers[i] )  ==  ( user_answers[i] )  ) {
        money += 200;
      }
    }
    typewriter("Your final score is : \a", 100000);
    sleep(1);

    cout << money << endl;

    delete [] questions;
    delete [] answers;
    delete [] user_answers;
  }
}

//___________________________________________________________________

// functions converts argument string to lowercase string
string ToLowerCase(string lower){
  for (int i = 0; i < lower.length(); i++){
    char x = lower[i];
    if (x <= 'Z' && x >= 'A') {
      lower[i] = ( x - ('A'-'a') );
    }
  }
  return lower;
}

void storing_data(int question, int money){

  fstream fout("output.txt", ios::out);

  fout << player_1 << endl;
  fout << question << endl;
  fout << money << endl;
  fout << currency << endl;
  fout << index;

  fout.close();
}

void extracting_data(int &question,int &money) {

  fstream fin("output.txt", ios::in);

  fin >> player_1 >> question >> money >> currency >> index;
  fin.close();

}

//___________________________________________________________________

void sports(int &question,int &money) {

  int random, variable_getline;
  string answer;

  variable_getline = index;

  if (index == 7){

    cout << "Welcome to the SPORTS ROUND!" << endl;
    cout << "Your current balance is " << money << currency << endl;
    buffer();

  }

  cout << "Question " << question << " is: " << endl << endl;

  struct questions{

    string question, option_A, option_B, option_C, option_D, correct_option, correct_letter;

  };

  questions game_program[5];
  game_program[0] = {"Which team has won the most cricket world cups?" ,"Australia", "India", "Pakistan", "England", "australia","a"};
  game_program[1] = {"Which Premiere League team is known as \"The Invincibles\"?", "Tottenham Hotspur", "Chelsea", "Arsenal", "Liverpool", "arsenal","c"};
  game_program[2] = {"Which is the most successful team in the Premiere League?", "Chelsea", "Arsenal", "Liverpool", "Manchester United", "manchester united", "d"};
  game_program[3] = {"Who has won the most number of Grand Slams?", "Rafael Nadal", "Novak Djokovic", "Roger Federer", "Andy Murray","roger federer","c"};
  game_program[4] = {"Who is the most decorated player in football? ", "Cristiano Ronaldo", "Dani Alves", "Lionel Messi", "Ronaldinho","dani alves","b"};

  random = ( rand() % 5 );

  if (random == index) {
    while(random == index) {
      random = ( rand() % 5 );
    }
  }

  index = random;
  cout << left;
  cout << game_program[index].question << endl << endl ;
  cout << "A) " << setw(25) << game_program[index].option_A << "B) " << game_program[index].option_B << endl;
  cout << "C) " << setw(25) << game_program[index].option_C << "D) " << game_program[index].option_D << endl;

  cout << endl << "Your Answer: ";

  if (variable_getline == 7) {
   cin.ignore( numeric_limits<streamsize>::max(), '\n' );
   getline(cin, answer);
  }
  else{
    getline(cin,answer);
  }

  if (ToLowerCase(answer) == game_program[index].correct_option || ToLowerCase(answer) == game_program[index].correct_letter) {

    cout << endl << "Your Answer is correct!" << endl;
    money = money * 2;
  }
  else {
    cout << endl << "Incorrect Answer!" << endl;
    money = money / 2;
  }
  cout<< endl << "Your new balance is " << currency << money << endl;
  question++;

  storing_data(question,money);
  sleep(1);
  buffer();
}

void technology(int &question, int &money) {

  int random;
  string answer;

  if (index == 7){
    cout << "Welcome to the TECHNOLOGY ROUND!" << endl;
    cout << "Your current balance is " << money << currency << endl;
    sleep(1);
    buffer();
  }
  cout << "Question " << question << " is: " << endl << endl;
  struct questions {

    string question, option_A, option_B, option_C, option_D, correct_option, correct_letter;

  };

  questions game_program[5];
  game_program[0] = {"\'OS\' computer abbreviation usually means ?", "Order of Significance", "Open software", "Operating system", "Optical Sensor", "operating system", "c"};
  game_program[1] = {"Who is largely responsible for breaking the German Enigma codes, created a test that provided a foundation for artificial intelligence?", "Alan Turing", "Jeff Bezos", "George Boole", "Charles Babbage", "alan turing", "a"};
  game_program[2] = {"Which consists of two plates separated by a dielectric and can store a charge?", "Inductor", "Capacitor", "Transistor", "Relay", "capacitor", "b"};
  game_program[3] = {"How many bits is a byte?", "4", "8", "16", "32", "8", "b"};
  game_program[4] = {"Who is the current CEO of Google?", "Steve Jobs", "Bill Gates", "Sundar Pichai", "Elon Musk", "sundar pichai", "c"};

  random=rand()%5;

  if (random == index) {
    while(random == index) {
      random=rand()%5;
    }
  }

  index = random;
  cout << left;
  cout << game_program[index].question << endl << endl;
  cout << "A) " << setw(25) << game_program[index].option_A << "B) " << game_program[index].option_B << endl;
  cout << "C) " << setw(25) << game_program[index].option_C << "D) " << game_program[index].option_D << endl;
  cout << endl << "Your Answer: ";

  getline(cin,answer);
  if (ToLowerCase(answer) == game_program[index].correct_option || ToLowerCase(answer) == game_program[index].correct_letter) {
    cout << endl << "Your Answer is correct!" << endl;
    money = money * 2;
  }
  else {
    cout << endl << "Incorrect Answer!" << endl;
    money = money / 2;
  }
  cout << endl << "Your new balance is " << currency << money << endl;
  question++;
  storing_data(question,money);
  sleep(1);
  buffer();
}

void world_history(int &question,int &money){
  int random;
  string answer;
  if (index==7){
    cout << "Welcome to the World History section!" << endl;
    cout << "Your current balance is " << money << currency << endl;
    buffer();
  }
  cout << "Question "<<question-1<<" is: " << endl;
  struct questions{
    string question, option_A, option_B, option_C, option_D, correct_option, correct_letter;
  }game_program[5];

  game_program[0] = {"Which is considered as oldest civilization of the world ?", " Mesopotamian Civilization", "Harappan Civilization", "Chinese Civilization", "Egyptain Civilization", "mesopotamian civilization", "a"};
  game_program[1] = {"The invasion of which of these countries in 1939 widely regarded to have started World War II ?", "Italy", "Germany", "Poland", "France", "poland", "c"};
  game_program[2] = {"When was the Opium war held between Britain and China ?", "1853", "1857", "1837", "1839", "1839", "d"};
  game_program[3] = {"In which year Hitler became the Chancellor of Germany ?", "1932", "1933", "1944", "1945", "1933", "b"};
  game_program[4] = {"Which of the following year is considered as the first year of the Muslim calender ? ", "AD 622", "AD 671", "AD 571", "AD 651", "ad 622", "a"};

  random = ( rand() % 5 );

  if (random == index) {
    while(random == index) {
      random = ( rand() % 5 );
    }
  }

  index = random;
  cout << left;
  cout << game_program[index].question << endl << endl;
  cout << "A) " << setw(25) << game_program[index].option_A << "B) " << game_program[index].option_B << endl;
  cout << "C) " << setw(25) << game_program[index].option_C << "D) " << game_program[index].option_D << endl;

  cout << endl << "Your Answer: ";

  getline(cin,answer);

  if (ToLowerCase(answer) == game_program[index].correct_option || ToLowerCase(answer) == game_program[index].correct_letter) {

    cout << endl << "Your Answer is correct!" << endl;
    money = money * 2;
  }
  else {
    cout << endl << "Incorrect Answer!" << endl;
    money = money / 2;
  }
  cout<< endl << "Your new balance is " << currency << money << endl;
  question++;

  storing_data(question,money);
  sleep(1);
  buffer();
}

void entertainment(int &question, int &money){

  int random;
  string answer;

  if (index == 7) {
    cout << "Welcome to the Entertainment round!" << endl;
    cout << "Your current balance is " << money << currency << endl;
    buffer();
  }
  cout << "Question " << question-1 << " is: " << endl << endl;
  struct questions{
    string question, option_A, option_B, option_C, option_D, correct_option, correct_letter;
  }game_program[5];

  game_program[0] = {"\'Cercei Lannister\' is a famous character from which TV show?", "Breaking Bad", "House of Cards", "Game of Thrones", "Westworld", "game of thrones", "c"};
  game_program[1] = {"What is the name of Ross Geller's second wife in the TV Show \'FRIENDS\'?", "Rachel", "Carol", "Janice", "Emily", "emily", "d"};
  game_program[2] = {"Which song has the most number of views on Youtube?", "See you again", "Despacito", "Shape of you", "Gangnam Style", "despacito", "b"};
  game_program[3] = {"Which TV show has the highest IMDB rating?", "Planet Earth 2", "Breaking Bad", "Chernobyl", "Sherlock", "planet earth 2", "a"};
  game_program[4]= {"Leonardo DiCaprio won Oscar for which movie? ", "Titanic", "The Revenant", "The Wolf of Wall Street", "The Great Gatsby", "the revenant", "b"};
  random = ( rand() % 5 );

  if (random == index) {
    while(random == index) {
      random = ( rand() % 5 );
    }
  }

  index = random;
  cout << left;
  cout << game_program[index].question << endl << endl;
  cout << "A) " << setw(25) << game_program[index].option_A << "B) " << game_program[index].option_B << endl;
  cout << "C) " << setw(25) << game_program[index].option_C << "D) " << game_program[index].option_D << endl;

  cout << endl << "Your Answer: ";

  getline(cin,answer);

  if (ToLowerCase(answer) == game_program[index].correct_option || ToLowerCase(answer) == game_program[index].correct_letter) {

    cout << endl << "Your Answer is correct!" << endl;
    money = money * 2;
  }
  else {
    cout << endl << "Incorrect Answer!" << endl;
    money = money / 2;
  }
  cout<< endl << "Your new balance is " << currency << money << endl;
  question++;

  storing_data(question,money);
  sleep(1);
  buffer();
}

void intelligence_quotient(int &question, int &money) {

  int random;
  string answer;

  if (index == 7) {
    cout << "Our last section will test your IQ" << endl;
    cout << "Your current balance is: " << money << currency << endl;
    buffer();
  }
  cout << "Question " << question-1 << " is: " << endl << endl;
  struct questions{
    string question, option_A, option_B, option_C, option_D, correct_option, correct_letter;
  }game_program[5];

  game_program[0] = {"If you rearrange the letters \'BARBIT\' you would have the name of a:", "Country", "Ocean", "Animal", "City", "animal", "c"};
  game_program[1] = {"Which one of the four is least like the other three?", "Tiger", "Dog", "Cow", "Snake", "snake", "d"};
  game_program[2] = {"Some months have 31 days; how many have 28?", "1", "3", "6", "12", "12", "d"};
  game_program[3] = {"Two people can make 2 bicycles in 2 hours. How many people are needed to make 12 bicycles in 6 hours?", "2", "4", "6", "12", "4", "b"};
  game_program[4] = {"The day after the day after tomorrow is four days before Monday. What day is it today?" ,"Monday", "Wednesday", "Thursday", "Sunday", "monday", "a"};
  random = ( rand() % 5 );

  if (random == index) {
    while(random == index) {
      random = ( rand() % 5 );
    }
  }

  index = random;
  cout << left;
  cout << game_program[index].question << endl << endl;
  cout << "A) " << setw(25) << game_program[index].option_A << "B) " << game_program[index].option_B << endl;
  cout << "C) " << setw(25) << game_program[index].option_C << "D) " << game_program[index].option_D << endl;

  cout << endl << "Your Answer: ";

  getline(cin,answer);

  if (ToLowerCase(answer) == game_program[index].correct_option || ToLowerCase(answer) == game_program[index].correct_letter) {

    cout << endl << "Your Answer is correct!" << endl;
    money = money * 2;
  }
  else {
    cout << endl << "Incorrect Answer!" << endl;
    money = money / 2;
  }
  cout<< endl << "Your new balance is " << currency << money << endl;
  question++;

  storing_data(question,money);
  sleep(1);
  buffer();
}

//___________________________________________________________________

int main(){

  int round, money;
  extracting_data(round, money);

  if (round == 1) {

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

  while (round < 3){
    sports(round,money);
  }
  index=7;
  storing_data(round,money);

  while (2<round && round<5){
    technology(round,money);
  }
  index=7;
  storing_data(round,money);
   if (round==5){
     lucky_7(round,money);
   }
  while (5<round && round<8){
    world_history(round,money);
  }
  index=7;
  storing_data(round,money);
   if (round==8){
     rapid_fire(round,money);
   }
  while (8<round && round<11){
    entertainment(round,money);
  }
   if (round==11){
     lucky_7(round,money);
   }
  index=7;
  storing_data(round,money);
  while (11<round && round<14){
    intelligence_quotient(round,money);
  }
  index=7;
  player_1="none";
  currency="none";
  round=1;
  money=1000;
  storing_data(round,money);




}
