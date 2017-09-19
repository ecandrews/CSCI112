//include statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constants MAZ_SIZE and MAX_WRONG_GUESSES
#define MAX_SIZE 25
#define MAX_WRONG_GUESSES 6

//function prototypes
void hangman_display(int); //displays the current status of the hanging man
char user_guess(int, int); //gets the user's guess from them
void game_over(int, int); //deals with the end of the game
int check_guess(char, int, char*, int, char*, int); //checks user's guess against the secret word
void check_game_over(int, char*); //checks to see if the game is over / user has guessed word

//main method
int main(int argc, char *argv[]) {
  //check input parameter against MAX_SIZE
  //if too big, print error message and terminate immediately
  if(strlen(argv[1]) >= MAX_SIZE) {
    printf("ERROR: Input argument is too long\n");
    exit(0); //program quits immediately
  } //end if statement

  char word[strlen(argv[1])]; //word to be guessed
  strcpy(word, argv[1]);
  char censored_word[strlen(argv[1])]; //censored copy of the word
  strcpy(censored_word, argv[1]);

  //int len1 = strlen(argv[1]);
  //int len2 = strlen(word);
  //int len3 = strlen(censored_word);

  //printf("argv length = %d\n", len1);
  //printf("word length = %d\n", len2);
  //printf("cens length = %d\n", len3);

  int i;
  for(i = 0; i < strlen(argv[1]); i++) { //for loop to fill censored word array
    censored_word[i] = '*';
  } //end for loop

  int guesses_left = 6; //number of wrong guesses left
  int guesses_made = 0; //number of guesses user has made
  char guess;
  do { //do while loop to continue until the game is over
    if(word == censored_word) {
      game_over(guesses_made, 1);
    }
    guess = user_guess(guesses_left, guesses_made); //get guess from user
    guesses_made++; //increment number of guesses made
    if(check_guess(guess, guesses_left, word, strlen(word), censored_word, strlen(censored_word)) == 0) { //guess not in word
      guesses_left--; //decrement wrong guesses left
    } //end if statement
    check_game_over(guesses_made, censored_word); //checks to see if user has guessed word
  } while(guesses_left > 0); //end do while loop

  game_over(guesses_made, 0);

  return 0;
} //end main method

//method to display hanging man's status
void hangman_display(int guesses_left) {
  //switch statement based on how many guesses are left
  switch (guesses_left) {
    case 0:
      //no guesses left (game over)
      printf("___\n");
      printf("|\\o/\n");
      printf("| | \n");
      printf("|/ \\");
      printf("\n");
      printf("-----\n");
      break;
    case 1:
      //1 guess left
      printf("___\n");
      printf("|\\o/\n");
      printf("| | \n");
      printf("|/  \n");
      printf("-----\n");
      break;
    case 2:
      //2 guesses left
      printf("___\n");
      printf("|\\o/\n");
      printf("| | \n");
      printf("|   \n");
      printf("-----\n");
      break;
    case 3:
      //3 guesses left
      printf("___\n");
      printf("|\\o/\n");
      printf("|   \n");
      printf("|   \n");
      printf("-----\n");
      break;
    case 4:
      //4 guesses left
      printf("___\n");
      printf("|\\o \n");
      printf("|   \n");
      printf("|   \n");
      printf("-----\n");
      break;
    case 5:
      //5 guesses left
      printf("___\n");
      printf("| o \n");
      printf("|   \n");
      printf("|   \n");
      printf("-----\n");
      break;
    case 6:
      //6 guesses left (default)
      printf("___\n");
      printf("|   \n");
      printf("|   \n");
      printf("|   \n");
      printf("-----\n");
      break;
    }//end switch statements
}//end hangman_display method

//method to get input from user
char user_guess(int guesses_left, int guesses_made) {
  char guess;
  printf("Guess a letter (%d attempts left) > ", guesses_left); //prompt user for guess
  printf("\n");
  if(guesses_made >= 1) { //if this isn't first guess, "flush the buffer" with a space in front of the %c
    scanf(" %c", &guess);
  } else { //if this is the first guess, flushing buffer unnecessary
    scanf("%c", &guess);
  }
  return guess;
}//end user_guess

//method to check if guess is in secret word
int check_guess(char guess, int guesses_left, char * word, int word_length, char * censored_word, int censored_word_length) {
  int i;
  int found = 0; //variable to keep track of how many of the guess are in the word
  for(i = 0; i < word_length; i++) { //for loop
    if(censored_word[i] == guess) { //if the censored word already contains letter, letter has already been guessed
      hangman_display(guesses_left); //display hangman
      printf("%s \n", censored_word); //print out censored word
      printf("You already guessed %c!\n", guess); //letter has already been guessed
      return 1;
    } //end if statement
    if(word[i] == guess) { //if secret word contains guess
      censored_word[i] = guess; //set corresponding index in censored word to guess
      found++; //increment found variable
    } //end if statement
  } //end for loop

  if(found == 0) { //if guess was not found in word
    guesses_left--; //decrement guesses left to display correct hangman
    hangman_display(guesses_left); //display hangman
    printf("%s \n", censored_word); //print out censored word
    printf("There are no %c's\n", guess); //guess was wrong, not found in secret word
    printf("\n");
    return 0;
  } else if(found == 1) { //one guess found in word
    hangman_display(guesses_left); //display hangman
    printf("%s \n", censored_word); //print out censored word
    printf("There is 1 %c\n", guess); //guess was found
    printf("\n");
    return 1;
  } else { //more than one guess found in word
    hangman_display(guesses_left); //display hangman
    printf("%s \n", censored_word); //print out censored word
    printf("There are %d %c's\n", found, guess); //guess was found
    printf("\n");
    return 1;
  } //end if else statement

} //end check guess method

//method to check if game is over by user guessing right word
void check_game_over(int guesses_made, char censored_word[]) {
  int i;
  for(i = 0; i < strlen(censored_word); i++) { //for loop to check censored word for characters
    if(censored_word[i] == '*') { //if censored word still contains any '*'s
      return; //exit function and return
    } //end if statement
  } //end for loop
  game_over(guesses_made, 1); //no asterisk's found, game is over and user has guessed word, call game over method
}

//method to handle print statements when game is over
void game_over(int guesses_made, int result) {
  //0 = game lost, 1 = game won
  printf("\n");
  printf("Game Over\n");
  printf("%d total guesses made.\n", guesses_made); //tells user how many guesses were made
  if(result == 0) { //if game was lost
    printf("Out of guesses.\n");
    printf("You lost.\n");
    exit(0); //exit program
  } else { //if game was won
    printf("You won!\n");
    exit(0); //exit program
  } //end if else statement
} //end game over method

