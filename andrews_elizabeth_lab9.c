/*
* The grading program keeps saying that I need to have a '^M' at the end of my
* year discovered when I print it out, but I have no idea what that means, or
* how to fix it.
*/

//include statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constant for the name of the file
#define ELEMENT_FILENAME "element_db.csv"

//create a type struct for each element
typedef struct {
  int atomic_num;
  char chem_sym[4];
  char name[25];
  float atomic_weight;
  char state[25];
  char bond_type[25];
  char year[25];
} element_t;

//function prototypes
element_t * find_element(element_t  * list, char * symbol, int array_size);

//main method
int main(int argc, char * argv[]) {
  if(argc < 2) { //no program arguments provided
    printf("ERROR: Please provide at least one program argument.\n");
    return 0;
  }
  int array_size = 0;
  element_t * elements = (element_t *)calloc(118, sizeof(element_t));
  FILE *element_file = fopen(ELEMENT_FILENAME, "r"); //open the file with all the element information in it
  if(element_file != NULL) {
    char line[100];
    while(fgets(line, 100, element_file) != NULL) { //use fgets instead of scanf
      char * nl = strchr(line, '\n');
      if(nl) {
        *nl = '\0'; //convert new line characters to null characters
      }
      element_t e; //create new element
      char * str = strtok( line, ",");
      int col = 0; //keep track of which column you're on
      while(str != NULL) {
        switch(col) {
          case 0:
            e.atomic_num = atoi(str); //assign atomic number
            break;
          case 1:
            strcpy(e.chem_sym, str); //assign chemical symbold
            break;
          case 2:
            strcpy(e.name, str); //assign name
            break;
          case 3:
            e.atomic_weight = atof(str); //assign atomic weight
            break;
          case 4:
            strcpy(e.state, str); //assign state at room temp
            break;
          case 5:
            strcpy(e.bond_type, str); //assign bond type
            break;
          case 6:
            //str[strlen(str) - 1] = '\0';
            strcpy(e.year, str); //assign year discovered
            col = 0;
            break;
        } //end switch statements
        str = strtok(NULL, ",");
        col++; //move to next col
      }
      elements[e.atomic_num - 1] = e; //add element to array of elements
      array_size++;
    }
    fclose(element_file); //close file
  }

  //process program arguments
  FILE * output_f = NULL;
  int i;
  for(i = 1; i < argc; i++) {
    if( i == 1 ) {
      char * dot = strchr(argv[i], '.');
      if(dot) { //file name found
        output_f = fopen(argv[i], "w");
        continue;
      } //end dot
    } //end if i == 1

    //look up this element, chemical symbol found
    element_t * ele = find_element(elements, argv[i], array_size);
    if( ele ) { //if the chemical symbol is found
      //print out information
      printf("---------------\n");
      printf("| %d\t%.4f\n", ele->atomic_num, ele->atomic_weight);
      printf("| %s\t%s\n", ele->chem_sym, ele->name);
      printf("| %s\n", ele->state);
      printf("| %s\n", ele->bond_type);
      printf("| Found: %s\n", ele->year);
      printf("---------------\n");
    } else { //element not found
      printf("WARNING: No such element: %s\n", argv[i]);
    }
  } //end for loop

  return 0;
} //end main method

//function to find the element entered by user
element_t * find_element(element_t * list, char * symbol, int array_size) {
  int i;
  for(i = 0; i < 118; i++) {
    if(strcmp(list[i].chem_sym, symbol) == 0) {
      element_t * result = &list[i]; //return a pointer to an element in the list
      return result;
    } //end if
  } //end for
  return NULL; //return null if not found
} //end find_element function
