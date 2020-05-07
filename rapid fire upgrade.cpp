#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
// Additions ___________________________________________________________________
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




// Additions ___________________________________________________________________

void buffer() {
  cout << endl;
  cout << "Press Enter to Continue!" << endl;
  cin.get();
  system("cls"); // change to clear for linux
}

void typewriter(string line, int speed){
  int i = 0;
  while(i < line.length()) {
    cout << line[i++];
    cout.flush();
    usleep(speed);
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

int main() {
  int round = 22, money = 100;
  rapid_fire(round,money);
}
