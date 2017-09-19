/*
*Elizabeth Andrews
*Lab4 submission
* 2/29/16
*/

#include <stdio.h>
#include <math.h>
//List of all function prototypes

//display user menu, read input, and validate input
int user_menu();

//Equation functions that are passed by reference
void equation1(float *); //calculate motion equation 1
void equation2(float *); //calculate motion equation 2
void equation3(float *); //calculate motion equation 3
void equation4(float *); //calculate motion equation 4

//user input functions that return a value from the user
float get_position_initial(void); //prompts user for x0
float get_position_final(void); //prompts user for xf
float get_velocity_initial(void); //prompts user for v0
float get_velocity_final(void); //prompts user for vf
float get_acceleration(void); //prompts user for a
float get_time(void); //prompts user for t


int main(void) {
  //print welcome message
  printf("Welcome to the MOTION EQUATION CALCULATOR\n\n");
  //Variable for the user choice menu
  int user_choice;

  do {
    user_choice = user_menu(); //print menu, validate choice is between 1&5
    //pass the address of this variable to your equation functions
    float result; //variable to hold calculated result

    //Handle menu choice selected by user
    switch(user_choice) {
      case 1: //equation 1 chosen
        //call equation 1
        equation1(&result);
        break;
      case 2: //equation 2 chosen
        //call equation 2
        equation2(&result);
        break;
      case 3: //equation 3 chosen
        //call equation 3
        equation3(&result);
        break;
      case 4: //equation 4 chosen
        //call equation 4
        equation4(&result);
        break;
      case 5:
        //exit program if user selected QUIT
        printf("Thank you for using the MOTION EQUATION CALCULATOR. Goodbye.\n");
        return 0;
        break;
      }

      //Print out the calculated result with four digits after the decimal place
      printf("Your result is %.4f.\n\n", result);

    } while(user_choice != 5);

  return 0; //exit with no error

}

//function to display user menu and return user's choice
int user_menu() {
  int choice;
  do { //print menu while user hasn't entered valid choice
    printf("Choose a motion equation 1-4 or choose 5 to QUIT > ");
    scanf("%d", &choice);
    if(choice < 1 || choice > 5) { //if choice is outside range of values
      printf("Invalid Option. Please try again.\n");//invalid choice
      printf("\n");
    }
  } while(choice < 1 || choice > 5); //continue to do while choice invalid

 //return user's choice
  return choice;
}

//function to get initial position from uwer
float get_position_initial() {
  float init_pos;
  printf("\tEnter initial position > ");
  scanf("%f", &init_pos);
  //return initial position
  return init_pos;
}

//function to get final position from user
float get_position_final() {
  float final_pos;
  printf("\tEnter final position > ");
  scanf("%f", &final_pos);
  //return final position
  return final_pos;
}

//function to get initial velocity from user
float get_velocity_initial() {
  float init_velocity;
  printf("\tEnter initial velocity > ");
  scanf("%f", &init_velocity);
  //return initial velocity
  return init_velocity;
}

//function to get final velocity from user
float get_velocity_final() {
  float final_velocity;
  printf("\tEnter final velocity > ");
  scanf("%f", &final_velocity);
  //return final velocity
  return final_velocity;
}

//function to get acceleration from user
float get_acceleration() {
  float accel;
  printf("\tEnter acceleration > ");
  scanf("%f", &accel);
  //return acceleration
  return accel;
}

//function to get time from user
float get_time() {
  float time;
  printf("\tEnter time > ");
  scanf("%f", &time);
  //returns time
  return time;
}

//equation 1 function
void equation1(float * result) {
  //get all values needed for equation
  //v0, a, t
  float v0 = get_velocity_initial();
  float a = get_acceleration();
  float t = get_time();
  //result is set to calculated value from equation
  *result = v0 + (a * t);
}

//equation 2 function
void equation2(float * result) {
  //get all values needed for equation
  //x0, v0, t, a
  float x0 = get_position_initial();
  float v0 = get_velocity_initial();
  float t = get_time();
  float a = get_acceleration();
  //result is set to calculated value from equation
  *result = x0 + v0 * t + 1/2 * a * powf(t, 2);
}

//equation3 function
void equation3(float * result) {
  //get all needed values for equation
  //v0, a, xf, x0
  float v0 = get_velocity_initial();
  float a = get_acceleration();
  float xf = get_position_final();
  float x0 = get_position_initial();
  //result is set to calculated value
  *result = sqrt((v0 * v0) + 2 * (a*(xf - x0)));
}

//equation 4 function
void equation4(float * result) {
  //get all values needed for equation
  //x0, vf, v0, t
  float x0 = get_position_initial();
  float vf = get_velocity_final();
  float v0 = get_velocity_initial();
  float t = get_time();
  //result is set to the calculated equation
  *result = x0 + 1/2 * (vf + v0) * t;
  /*I can't make this equation she gave us return the right values no matter
  *what I try. I think the equation we were given in the lab was either wrong
  *or missing parentheses somewhere. Same with equation 2. I have tried
  *every combination of parentheses and changing things that I can with no
  *luck whatsoever, and I have no idea why it's not returning the right
  * values.
  */
}
