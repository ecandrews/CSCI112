/*
* Elizabeth Andrews
* CSCI 112 - Lab 3
* 2/21/16
*/

//include statements for standard io and math.h
#include <stdio.h>
#include <math.h>
//define constants PI and LOOP_LIMIT
#define PI 3.14159
#define LOOP_LIMIT 90

//define enum types for sine, cosine, tangent, and quit
typedef enum {
  sine,
  cosine,
  tangent,
  quit
} menu_t; //enum type name menu_t

//method to determine if choice from menu is a valid option
int is_valid(menu_t choice) {
  if(choice > 3 || choice < 0) { //if input is not between 0 and 3
    printf("%d is an invalid option. Please try again.\n", choice);
    return 0; //invalid input, return 0
  } else {
    return 1; //valid input, return 1
  }
} //end is_valid method

//method to get input from user
menu_t get_input() {
  menu_t choice;
  do { //print menu for user
    printf("Please choose an option: (0) Sine (1) Cosine (2) Tangent (3) QUIT\n");
    printf("Enter your choice > ");
    scanf("%u", &choice);
  } while (is_valid(choice) == 0);//while invalid choice, keep printing menu

  return choice;//when user enters valid option, return choice
} //end get_input method

//method called when sine is chosen to print out sine values
void sin_chosen() {
  //loop to calculate and print out sine values
  for(int i = 0; i <= LOOP_LIMIT; i += 15) {
    double radians = (PI / 180) * i; //convert i value to radians
    double sine_value = sin(radians); //new sine value in radians
    printf("\tsin(%d) = %.4lf\n", i, sine_value);
  }
} //end sin_chosen method

//method called when cosine is chosen to print out cosine values
void cos_chosen() {
  //loop to calculate and print out cosine values
  for(int i = 0; i <= LOOP_LIMIT; i += 15) {
    double radians = (PI / 180) * i; //convert i value to radians
    double cosine_value = cos(radians); //new cosine value in radians
    printf("\tcos(%d) = %.4lf\n", i, cosine_value);
  }
} //end cos_chosen method

//method called when tangent is chosen to print out tangent values
void tan_chosen() {
  //loop to calculate and print out tangent values
  for(int i = 0; i <= LOOP_LIMIT; i += 15) {
    if(i == 90) { //tangent is infinite at 90 degrees
      printf("\ttan(%d) is UNDEFINED\n", i); //tangent is undefined here
    } else {
      double radians = (PI / 180) * i; //convert i value to radians
      double tan_value = tan(radians); //new tangent value i radians
      printf("\ttan(%d) = %.4lf\n", i, tan_value);
    } //end if else statements
  }
} //end tan_chosen method


//main method, returns 0
int main(void) {
  menu_t choice;

  do { //do while loop to continue printing choice menu until user quits program
    choice = get_input(); //call get_input method to get user's choice
    switch(choice) { //switch statements to call appropriate methods for user's choice
      case sine: //if user chose sine
        //call sine method
        sin_chosen();
        break;
      case cosine: //if user chose cosine
        //call cosine method
        cos_chosen();
        break;
      case tangent: //if user chose tangent
        //call tangent method
        tan_chosen();
        break;
      case quit: //if user chose quit≈
        //user chose quit, break out of switch statements
        printf("You chose QUIT. Thank you, come again!\n");
        break;
    }//end of switch statements
  } while(choice != quit); //end of do while loop, user chose quit option

  return 0;
} //end of main method
