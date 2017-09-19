#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 20

typedef struct element {
  int atomic_num;
  char * name;
  char * chem_symbol;
  char * class_name;;
  double atomic_weight;
  int num_electrons[7];
} element_t;

void scan_element(/*element_t []*/element_t *, int);
void print_element(element_t *, char[], char[], int[]);

int main(int argc, char * argv[]) {
  if(argc < 2) {
    printf("ERROR: You must provide exactly one argument to this program\n");
    return 0;
  }

  int N = (int) strtol(argv[1], NULL, 10);
  if(N <= 0) {
    printf("ERROR: You must provide an integer greater than 0 and less than or equal to 20.\n");
    return 0;
  }

  element_t elements[MAX_ELEMENTS];
  element_t * elemp = elements;
  int i;
  for(i = 0; i < N; i++) {
    scan_element(elemp, i);
  }

  //printf("%s is the name after scanning\n", elements[0].name);
  //printf("%s is the sym after scanning\n", elements[0].chem_symbol); //literally what the actual fuck

  printf("%d total elements.\n", N);
  int iMax = 0;
  int iMin = 0;
  for(i = 0; i < N; i++) {
    if(elements[i].atomic_num > elements[iMax].atomic_num) {
      iMax = i;
    } else if(elements[i].atomic_num < elements[iMin].atomic_num) {
      iMin = i;
    }
  }
  printf("%s had the smallest atomic number.\n", elements[iMin].name);
  printf("%s had the largest atomic number.\n", elements[iMax].name);

  //printf("%s name before callign print", elements[0].name);

  for(i = 0; i < N; i++) {
    //printf("%s name right before print in for loop\n", elements[i].name);
    //element_t * to_send = elements[i];

    //printf("%s symbol\n", elements[i].chem_symbol);
    //printf("%s name\n", elements[i].name);

    print_element(&elements[i], elements[i].chem_symbol, elements[i].name,
                  elements[i].num_electrons);

    //printf("%s after calling print\n",elements[i].name);
  }

  return 0;
}

//function that scans in data from keyboard input to populate structure
void scan_element(element_t * elements /*elements[]*/, int i) {
  element_t element;
  int atomic_num;
  char name[20];
  char symbol[20];
  char class_name[20];
  double atomic_weight;
  int electrons[7];
  scanf("%d %s %s %s %lf %d %d %d %d %d %d %d", &atomic_num, name, symbol, class_name, &atomic_weight,
         &electrons[0], &electrons[1], &electrons[2], &electrons[3], &electrons[4], &electrons[5], &electrons[6]);
  element.atomic_num = atomic_num;
  element.name = name;
  element.chem_symbol = symbol;
  element.class_name = class_name;
  element.atomic_weight = atomic_weight;
  int j;
  for(j = 0; j < 7; j++) {
    element.num_electrons[i] = electrons[i];
  }
  elements[i] = element;
  //printf("%s this is inside scan func\n", elements[i].name);
  //printf("%s this is inside scan\n", elements[i].chem_symbol); //how the fuck do these work but nothing else prints it out
}

//prints out the information about the element
void print_element(element_t * element, char chem_symbol[], char name[],
                   int num_electrons[]) {

  //printf("%s here is the name\n", name);
  //printf("%s here is the sym\n", chem_symbol);

  printf("---------------\n");
  printf("| %d\t%.4f\n", element->atomic_num, element->atomic_weight); //prints fine
  printf("| %s\t%s\n", chem_symbol, name); //gets all screwy?
  int i;
  printf("|");
  for(i = 0; i < 7; i++) {
    if(num_electrons[i] != 0) {
      printf(" %d", num_electrons[i]); //also this is fucked up
    }
  }
  printf("\n");
  printf("---------------\n");
}
