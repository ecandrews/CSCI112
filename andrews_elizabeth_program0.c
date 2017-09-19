#include <stdio.h>
int is_valid(int);
void print_pattern(int);

int get_input() {
  int num;
  do {
    printf("Enter an odd number less than or equal to 9 and greater than 0 > ");
    scanf("%d", &num);
  } while(is_valid(num) == 0);
  return num;
}

int is_valid(int num) {
  if(num % 2 == 0) {
    printf("You have entered an even number. Please try again.\n");
    printf("\n");
    return 0;
  } else if(num > 9) {
    printf("You have entered a number greater than 9. Please try again.\n");
    printf("\n");
    return 0;
  } else if(num < 1) {
    printf("You have entered a number less than 1. Please try again.\n");
    printf("\n");
    return 0;
  } else {
    return 1;
  }
}

void print_pattern(int num) {
  for(int i = 1; i <= num; i+=2) {
    printf("%*s", num - i, " ");
    int j = 1;
    while(j <= i) {
      printf("%d ", j);
    }
    printf("\n");
  }
}

int
main(void) {
  int number = get_input();
  print_pattern(number);
  return 0;
}
