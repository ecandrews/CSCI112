/*
* Elizabeth Andrews
* Lab1 CSCI112
* 1/25/2016
*/
#include <stdio.h>

/*all function prototypes*/
double get_input();
double get_next(double, double);
void print_result(double);

void main(void) {
  /*call get_input function to get first two values*/
  double x1 = get_input();
  double x2 = get_input();
  /*call get_next and pass it the previous two values*/
  double x3 = get_next(x1, x2);
  double x4 = get_next(x2, x3);
  double x5 = get_next(x3, x4);
  /*call print_result to print the fifth calculated term in the sequence*/
  print_result(x5);
}

double get_input(void) {
  /*get input from user*/
  double value;
  printf("Enter a value: ");
  scanf("%lf", &value);
  return(value);
}

double get_next(double x1, double x2) {
  /*formula for calculating next term: (x1/2)+3*x2*/
  return (x1/2.0)+(3.0*x2);
}

void print_result(double x5) {
  /*print the fifth calculated term in the sequence*/
  printf("The fifth term in the sequence is: %.2lf \n", x5);
}
