#include <stdio.h>

#define MAX_ARRAY_SIZE 50

//method prototypes
int populate_array(int array[]); //fill array with values from user
void print_array(int array[], int n); //print out the array values
void swap(int array[], int index1, int index2); //swap two array elements
void quicksort(int array[], int low, int high); //sorting algorithm
int partition(int array[], int low, int high); //find the partition point

//main method
int main() {
  //declare an array of size MAX_ARRAY_SIZE
  int array[MAX_ARRAY_SIZE];
  //call populate_array and save result as variable n
  int n = populate_array(array);
  //print out values in the array by calling print_array
  printf("The initial array contains:\n");
  print_array(array, n);
  //call sorting algorithm with quicksort(array, 0, n);
  quicksort(array, 0, n);
  //verify that list is sorted by calling print_array
  printf("The array is now sorted:\n");
  print_array(array, n);
  return 0;
}//end of main method

//method to fill array with values from user
int populate_array(int array[]) {
  int n;
  do { //do while loop
    printf("Enter the value of n > "); //get value of n from user
    scanf("%d", &n);
    if(n < 0) { //if n is less than 0 prompt user again
      printf("%d is less than zero. Please try again.\n", n);
      printf("\n");
    }//end if statement
    if(n > 50) { //if n is greater than 50 prompt user again
      printf("%d exceeds the maximum array size. Please try again.\n", n);
      printf("\n");
    }//end if statement
  } while(n < 0 || n > 50); //end do while statement
  printf("Enter %d integers (positive, negative, or zero) >\n", n);
  for(int i = 0; i < n; i++) { //get integers from user
    scanf("%d", &array[i]); //save integers in array
  }//end for loop
  return n;
}//end method

//method to print out the array values
void print_array(int array[], int n) {
  //print the values in the array, one value per line, using for loop
  for(int i = 0; i < n; i++) { //for loop to print values from array
    printf("%+5d\n", array[i]);
  }//end for loop
  //use formatting code %+5d to print back each digit
}//end print array method

//method to swap two values, i think this is the method that's causing problem
void swap(int array[], int index1, int index2) {
  //helper function which is called by partition
  //swaps the values located in index1 and index2 of array
  int temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
} //end swap method

//method to sort values
void quicksort(int array[], int low, int high) {
  if(low < high) { //if low < high then
    int pivot = partition(array, low, high);//pivot <- partition(A, low, high)
    quicksort(array, low, pivot - 1);//quicksort(A, low, pivot -1)
    quicksort(array, pivot + 1, high);//quicksort(A, pivot + 1, high)
  } //end if
}//end quicksort method

//partition method to set the partition for quicksort
int partition(int array[], int low, int high) {
  int pivot = array[high]; //pivot <- A[high]
  int i = low; //i <- low
  for(int j = low; j <= high - 1; j++) { //for j=low to high-1 do
    if(array[j] <= pivot) { //if A[j] <= pivot then
      swap(array, i, j); //swap(A, i, j)
      i = i + 1; //i <- i + 1
    } //end if
  } //end for
  swap(array, i, high); //swap(A, i, high)
  return i; //return i
}//end partition method
