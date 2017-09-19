//include statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constants
#define NAME_SIZE 25

//define structure to store student records
typedef struct {
  int sid;
  char last_name[NAME_SIZE];
  char first_name[NAME_SIZE];
  float * list_grades;
  float gpa;
} student_t;

//function prototypes
student_t get_input(int); //gets input from the user
float calc_gpa(student_t, int); //calculates the gpa for a student
void print_records(student_t, int, int); //displays the information in each student's record

//main method
int main(void) {
  int total_students;
  int total_grades;
  scanf("%d %d", &total_students, &total_grades); //get total number of students and grades each

  student_t * records;
  records = (student_t *) calloc(total_students, sizeof(student_t)); //allocate memory for an array of type student_t

  int i;
  for(i = 0; i < total_students; i++) { //loop through to get all grades
    records[i] = get_input(total_grades);
  }

  printf("Number of students: %d\n", total_students);
  printf("Number of grades (each): %d\n", total_grades);

  for(i = 0; i < total_students; i++) {
    print_records(records[i], total_students, total_grades); //print each record individually
  }

  free(records); //free up memory used in calloc

  return 0;
} //end main method

//method to get input from user
student_t get_input(int num_grades) {

  student_t new_student;
  float * grades;
  grades = (float *) calloc(num_grades, sizeof(num_grades)); //assign memory for an array of grades for a student
  new_student.list_grades = grades;
  scanf("%d %s %s", &new_student.sid, &*(new_student.last_name), &*(new_student.first_name));

  int i;
  for(i = 0; i < num_grades; i++) { //assign values to student's grades
    scanf("%f", &new_student.list_grades[i]);
  }

  new_student.gpa = calc_gpa(new_student, num_grades);

  return new_student; //return new student created
} //end get_input method

//method to calculate a student's gpa
float calc_gpa(student_t student, int num_grades) {
  int i;
  float gpa = 0;
  for(i = 0; i < num_grades; i++) {
    gpa = gpa + student.list_grades[i];
  }
  return gpa / num_grades;
} //end calc_gpa

//method to print a record of each student
void print_records(student_t student, int num_students, int num_grades) {

  printf("ID: %d, Name: %s %s, GPA: %.2f\n", student.sid, student.first_name, student.last_name, student.gpa);
  printf("Grades:");
  int i;
  for(i = 0; i < num_grades; i++) { //loop through to print out grades
    printf(" %.1f", student.list_grades[i]);
  }

  printf("\n"); //end with a new line
} //end print_records method

