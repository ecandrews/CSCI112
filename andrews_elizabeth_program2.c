//include statements to import c libraries
#include <stdio.h>
#include<string.h>

//function prototypes
void pluralize(char*); //takes in a string and returns void

//main method
int main(int argc, char* argv[]) {
  int i;
  char word[200];
  for(i = 1; i < argc; i++) { //for loop to go through all the arguments
    strcpy(word, argv[i]); //strcpy the program parameter into word
    printf("noun: %s\n", word); //print the original word
    pluralize(word); //pluralize the word
    printf("plural: %s\n", word); //print the plural word
    printf("\n"); //new line
  } //end for loop
  return 0; //return 0
} //end main

//method to pluralize the entered word
void pluralize(char * word) {
  int length = strlen(word); //variable to keep track of the length of the string
  if(word[length - 1] == 'y') { //if the last letter is a y
    word[length - 1] = 'i';
    word[length] = 'e';
    word[length + 1] = 's';
    word[length + 2] = '\0'; //change ending to ies and add new line character
  } else if(word[length - 1] == 's' || (word[length - 2] == 'c'
            && word[length - 1] == 'h') || (word[length - 2] == 's'
            && word[length - 1] == 'h')) { //if it ends in an s, c, or sh
    strcat(word, "es"); //concatenate with an es
  } else { //anything else
    strcat(word, "s"); //concatenate with an s
  } //end if else statement
} //end pluralize
