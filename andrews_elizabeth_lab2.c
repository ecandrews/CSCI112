/*
*CSCI112
*Elizabeth Andrews - Lab2
*February 8, 2016
*/
#include <math.h>
#include <stdio.h>
#include <float.h>

//function prototypes
int get_n();
double get_input();

//main function
void main() {
  //variables
  int n;
  double sum;
  double sum_of_squares;
  double lowest;
  double highest;
  sum = 0;
  lowest = DBL_MAX;
  highest = DBL_MIN;
  double current;
  int i;
  //get number of values (n) from user
  n = get_n();

  //gets n numbers from user
  for(i = 0; i < n; i++) {
    current = get_input();
    //sets lowest or highest if necessary
    if(current < lowest) {
      lowest = current;
    } else if(current > highest) {
      highest = current;
    }
    //updates sum and sum_of_squares variables
    sum += current;
    sum_of_squares = sum_of_squares + pow(current, 2);
    }

  //calculates range and average
  double range;
  range = highest - lowest;
  double average;
  double sd;
  if(n == 0) {
    average = 0;
    sd = 0;
  } else {
    //calculates standard deviation if n > 0
    double value;
    average = sum / n;
    value = ( (sum_of_squares / n) - (pow(average, 2)) );
    sd = sqrt(value);
  }

  //prints out values
  printf("The Highest is: %.3lf\n", highest);
  printf("The Lowest is: %.3lf\n", lowest);
  printf("The Average is: %.3lf\n", average);
  printf("The Range is: %.3lf\n", range);
  printf("The Standard deviation is %.3lf\n", sd);
}


//function that gets the number of values from the user
int get_n() {
 int n = -1;
  do {
    printf("Enter a value for N that is >= 0: ");
    scanf("%d", &n);
    if(n < 0) {
      //error statement if user enters a number that is < 0
      printf("Invalid value for N \n");
    } else { break; }
  } while (n < 0);
  return n;
}


//function that gets each value from the user
double get_input() {
  double m;
  printf("Enter a number: ");
  scanf("%lf", &m);
  return m;
}
