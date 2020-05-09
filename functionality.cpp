#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

#include "func.h"

using namespace std;

// to diaplay text like a typewriter
void typewriter(string line, int speed){
  int i = 0;
  while(i < line.length()) {
    cout << line[i++];
    cout.flush();
    usleep(speed);
  }
}

// to print lucky 7 board
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

// functions converts argument string to lowercase string for a uniform answer
string ToLowerCase(string lower){
  for (int i = 0; i < lower.length(); i++){
    char x = lower[i];
    if (x <= 'Z' && x >= 'A') {
      lower[i] = ( x - ('A'-'a') );
    }
  }
  return lower;
}
