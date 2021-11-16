/**
  * comp2022 - assignment 1 - task 4
  * justin harding
  * 450221916 jhar5338
  *
  * In my report I used different names for the states to show that the states
  * originated from the previous NFA and DFA. Here is what the state names are
  * changed to in this program:
  *
  * A,B,C,H,I,B,C,F,J,I --> q0
  * D,J,I               --> q1
  * G,I,J,I             --> q2
  * I                   --> q3
  * E,I                 --> q4
  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static int strLength,indexInt=0,currState,destState;
static char inputStr[100],currChar='c';

void accepted();
void rejected();
void print();
void check();
void q0();
void q1();
void q2();
void q3();
void q4();

struct State {
	
	char name[100];
	bool isStart;
	bool isFinal;
	
}

int main(int argc,char **argv) {

  strLength = strlen(argv[1]);
  strncpy(inputStr,argv[1],strLength);

  // for empty string ""
  if (strLength==0)
    accepted();

  // check to see if all chars in input str are in this DFA's alphabet
  for (int i=0;i<strLength;i++) {
    if (inputStr[i]!='a'&&inputStr[i]!='b')
      rejected();
  }

  q0();

  return 0;
}

// used when string is accepted
void accepted(void) {
  printf("accepted\n");
  exit(0);
}

// used when string is rejected
void rejected(void) {
  printf("rejected\n");
  exit(0);
}

// used to print trace of execution, state by state
void print(void) {

  for (int i = 0;i<indexInt-1;i++)
	putchar(inputStr[i]);

  printf(" q%d -- %c --> q%d ",currState,currChar,destState);

  for (int j = indexInt;j<strLength;j++)
    putchar(inputStr[j]);

  printf("\n");
}

// used to check if at end of string and accept or reject depending on state
void check(void) {

  if (indexInt==strLength) {
    if (destState==3||destState==4)
      rejected();

    else
      accepted();
  }
}

// methods for each of the states
void q0(void) {

  indexInt++;

  currChar = inputStr[indexInt-1];
  currState = 0;

  if (currChar=='a') {
    destState = 1;
    print();
    check();
    q1();
  }
  else {
    destState = 2;
    print();
    check();
    q2();
  }
}

void q1(void) {

  indexInt++;

  currChar = inputStr[indexInt-1];
  currState = 1;

  if (currChar=='a') {
    destState = 2;
    print();
    check();
    q2();
  }
  else {
   destState = 4;
   print();
   check();
   q4();
  }
}


void q2(void) {

  indexInt++;

  currChar = inputStr[indexInt-1];
  currState = 2;

  if (currChar=='a') {
    destState = 2;
    print();
    check();
    q2();
  }
  else {
    destState = 3;
    print();
    check();
    q3();
  }
}


void q3(void) {

  indexInt++;

  currChar = inputStr[indexInt-1];
  currState = 3;

  if (currChar=='a') {
    destState = 2;
    print();
    check();
    q2();
  }
  else {
    destState = 3;
    print();
    check();
    q3();
  }
}


void q4(void) {

  indexInt++;

  currChar = inputStr[indexInt-1];
  currState = 4;

  if (currChar=='a') {
    destState = 0;
    print();
    check();
    q0();
  }
  else {
    destState = 3;
    print();
    check();
    q3();
  }
}
