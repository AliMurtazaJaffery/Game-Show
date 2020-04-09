# ENGG1340: Computer Programming 2                                                 
# Group 142

## Team members:-
* NAME: Jaffery Syed Muhammad Ali Murtaza   
  UID: 3035718046
* NAME: Rajiv Arnav   
  UID:3035709057

## Description of the Text-Based Game -

* Our project is dedicated to emulate a gameshow. This game show would include several rounds bound by a sequential game pattern i.e. succession of rounds in an order.
* The project structure is based on our user earning points in the form of money by answering trivia questions. 
  Every right decision would lead to addition of points, in turn every error would lead to the reduction of points i.e. the money. 
  The currency of money earned can be entered by the user or using default value be set to game currency.
* The game show will consist of trivia based questions. These questions will be presented in the form of rounds. 
  In some rounds, the questions will be answered by manually by entering the answer, while in other rounds the user would have to select    an option.
* The topics would include but are not limited to science, sports, politics. 
* The game will include rapid fire rounds. One such example would be the game of lucky 7 that would allow the user to gamble with large   amounts of money.
  and rounds which would create chances to earn more money by gambling.
* At the end of the game, a player report will be generated and a score status of current player would be displayed.
  Additionally, a scoreboard will be updated after every round to track the game usage.

## Features we plan to Implement -

1. Generation of random events:
 * As our game is trivia based, we intend to use functions under random() to randomly select questions that the user will answer.
 * We intend to create rapif fire and bonus rounds which would both include the rolling of dice, which would also be implemented by the random function.

2. Dynamic structures for storing game sets or events:
 * The game is based on trivia questions. These questions will be stored in different data strucutures like arrays.
 * Some of the user data will be entered in basic data structures while other will use more high level data structures.

3. Dynamic memory management:
 * Using arrays and linked lists we will store data generated in the game.

4. File input/output:
 * All of the user data will be entered to different files. Each of these user files will be stored separately.
 * The game would also automatically generate a score board. This score board will be stored in a file.
 * Some of the game variables would be also written in files to maintain proper records of game choices and other implementation of game features.

5. Program code in multiple files:
 * Program code will be stored in multiple files to implement the game functionality without any errors.
 * These files would help to regulate the process used in the game.
 * We plan to use functions for our rapid fire round and store them in multiple files. In addition to this, we plan to use a Makefile to increase the efficiency of our program. 
