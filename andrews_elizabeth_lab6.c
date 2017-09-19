//include statements
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//define size of string
#define SIZE 80

//function prototypes
void reverse_string(char*); //reverses the string sent to it
void get_input(char*); //gets input from the user

//main method
int main(int argc, char *argv[]) {
  //print an error message if wrong number of program arguments
  if(argc != 2) { //if anything other than 2 arguments are entered
    //print error message
    printf("ERROR: Please provide an integer greater than or equal to 0\n");
    return 0; //exit program
  } //end if statement

  //convert it to an integer (print error and quit if entered less than 0)
  int N = (int) strtol(argv[1], NULL, 10);
  if(N < 0) { //if N is less than zero print error message
    printf("ERROR: Please provide an integer greater than or equal to 0\n");
    return 0; //exit program
  } //end if statement

  char str[SIZE]; //declare string of set size
  int i;
  for(i = 0; i < N; i++) { //for loop to get the right number of inputs
    get_input(str); //get input from user
    reverse_string(str); //reverses string
    printf("%s\n", str); //prints out reversed string
  } //end for loop
} //end main method

//method to get input from user
void get_input(char* input) {
    fgets(input, SIZE, stdin); //fgets to get string from user
    char * replace = strchr(input, '\n');
    if(replace) {
      *replace = '\0'; //replace new line with string terminator character
    } //end if statement
} //end get_input method

//reverse string method to reverse the words in the line
void reverse_string(char* line) {
  //words appear in reverse order (still left to right)
  //punctuation and extra spaces omitted
  char temp[SIZE]; //temporary variable
  char word[SIZE]; //reversed word
  memset(temp, 0, SIZE);

  int index = strlen(line);
  int word_len = 0;
  int i;

  //for loop to go through the line
  for(i = index; i >= 0; --i) {
    if(line[i] == ' ' && word_len > 0) { //separate out by soaces
      memset(word, 0, SIZE);
      strncpy(word, line + i + 1, word_len); //copy the string
      strcat(temp, word); //concatenate
      strcat(temp, " "); //concatenate with spaces
      word_len = 0; //reset word length to 0
    } else if(isalnum(line[i]) || line[i] == '\'') { //is alphanumeric
      word_len++; //increase word lingth
    } //end if statement
  } //end for loop

  if(word_len > 0) { //if word length is still positive
    memset(word, 0, SIZE);
    strncpy(word, line, word_len); //copy the words over
    strcat(temp, word); //concatenate reversed word and temporary variable
  } //end if statement
  strcpy(line, temp); //copy over again
} //end reverse string method
