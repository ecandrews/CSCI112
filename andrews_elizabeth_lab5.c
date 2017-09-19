/*
*STEP 1: SUM ODDS
*STEP 2: SUM EVENS
*STEP 3: TOTAL SUM
*STEP 4: CHECK DIGIT
*STEP 5: COMPARE
*/

#include <stdio.h>
#define ARRAY_SIZE 12

void get_input(int[]); //gets input from user
void print_barcode(int[]); //prints barcode
int sum_odds(int[]); //takes barcode
int sum_evens(int[]); //takes barcodE
int total_sum(int, int); //takes the two sums
int check_digit(int); //takes total sum
void barcode_is_valid(int, int[]); //takes check digit and barcode

//main method, returns 0
int main() {
  int barcode [ARRAY_SIZE]; //declare integer array of size ARRAY_SIZE
  get_input(barcode); //get input from user
  print_barcode(barcode); //display the barcode entered
  int sum_of_odds = sum_odds(barcode); //STEP 1
  int sum_of_evens = sum_evens(barcode); //STEP 2
  int total = total_sum(sum_of_odds, sum_of_evens); //STEP 3
  int digit = check_digit(total); //STEP 4
  barcode_is_valid(digit, barcode); //STEP 5
  return 0;
} //end of main method

//method to get input from user and insert it into the array
void get_input(int barcode[]) {
  //gets input from user
  printf("Enter a bar code to check. Separate digits with a space >\n");
  scanf("%d %d %d %d %d %d %d %d %d %d %d %d",
        &barcode[0], &barcode[1], &barcode[2], &barcode[3], &barcode[4],
        &barcode[5], &barcode[6], &barcode[7], &barcode[8], &barcode[9],
        &barcode[10], &barcode[11]); //assign all values to indices in barcode
} //end get_input method

//method to display barcode for user
void print_barcode(int barcode[]) {
  printf("\n");
  printf("You entered the code: %d %d %d %d %d %d %d %d %d %d %d %d\n",
        barcode[0], barcode[1], barcode[2], barcode[3], barcode[4],
        barcode[5], barcode[6], barcode[7], barcode[8], barcode[9],
        barcode[10], barcode[11]);
} //end print_barcode method

//method to sum all values in odd slots of barcode array
int sum_odds(int barcode[]) {
  //takes barcode
  int sum_of_odds = 0;
  for(int i = 0; i <= 10; i+=2) { //for loop that stops before reaching checksum
    sum_of_odds = sum_of_odds + barcode[i]; //increases sum_of_odds value
  }
  printf("STEP 1: Sum of odds times 3 is %d\n", sum_of_odds * 3);//print value
  return sum_of_odds * 3;
} //end of sum_odds method

//method to sum all values in even slots of barcode array
int sum_evens(int barcode[]) {
  //takes barcode
  int sum_of_evens = 0;
  for(int i = 1; i <= 9; i+=2) { //for loop that stops before reaching checksum
    sum_of_evens = sum_of_evens + barcode[i]; //increases sum_of_evens value
  }
  printf("STEP 2: Sum of the even digits is %d\n", sum_of_evens); //print value
  return sum_of_evens;
} //end of sum_evens method

//method to calculate total sum of both odd and even sums
int total_sum(int odd_sum, int even_sum) {
  //takes the two sums
  printf("STEP 3: Total sum is %d\n", odd_sum + even_sum); //print value
  return odd_sum + even_sum;
}

//method to find the digit to compare to final digit of barcode
int check_digit(int total_of_sums) {
  //takes total of two sums
  int digit = total_of_sums % 10; //modulus operator to extract final digit
  if(digit == 0) { //if final digit is 0
    printf("STEP 4: Calculated check digit is %d\n", digit); //checksum is 0
    return digit;
  } else { //else if final digit is > 0
    printf("STEP 4: Calculated check digit is %d\n", 10 - digit); //checksum
    return 10 - digit;
  } //end of if-else statements
} //end of check_digit method

//method to determine whether the barcode entered is valid or not
void barcode_is_valid(int digit, int barcode[]) {
  //takes check digit and barcode
  if(digit == barcode[ARRAY_SIZE - 1]) { //digit == last number in the array
    //barcode is valid
    printf("STEP 5: Check digit and last digit match\n");
    printf("Barcode is VALID.\n"); //barcode is valid, end of program
  } else { //digit != last number in the array
    //barcode is invalid
    printf("STEP 5: Check digit and last digit do not match\n");
    printf("Barcode is INVALID.\n"); //barcode is invalid, end of program
  } //end of if-else statements
} //end of barcode_is_valid method
