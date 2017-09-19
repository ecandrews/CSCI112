/*
* Elizabeth Andrews
* Lab 0, CSCI 112
* 1/24/2016
*/
#include <stdio.h>

int main(void) {
  
  /*declare required variables */
  double celsius = 0, fahrenheit = 0;

  /*get temperature in Celsius from user*/
  printf("Enter a temperature in degrees Celsius: ");
  scanf("%d", &celsius);

  /*convert to fahrenheit*/
  fahrenheit = ((9.0/5.0) * celsius) + 32;

  /*print out temperature in fahrenheit*/
  printf("That is %.2f degrees Fahrenheit \n", fahrenheit);

  /*get the temperature in fahrenheit*/
  printf("Enter a temperature in degrees Fahrenheit: ");
  scanf("%d", &fahrenheit);

  /*convert to celsius*/
  celsius = ((fahrenheit - 32) * (5.0/9.0));

  /*print out the temperature in celsius*/
  printf("That is %.2f degrees Celsius \n", celsius);

  /*exit with no errors*/
  return(0);

}
