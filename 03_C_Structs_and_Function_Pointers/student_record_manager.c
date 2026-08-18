#include <stdio.h>

#define MAX_STUDENTS 3

typedef struct {
    int roll_no;
    char name[30];
    float cgpa;
} Student;

static void print_student(const Student *student)
{
    printf("Roll: %d, Name: %s, CGPA: %.2f\n",
           student->roll_no,
           student->name,
           student->cgpa);
}

static Student *find_student(Student students[], int count, int roll_no)
{
    for (int i = 0; i < count; ++i) {
        if (students[i].roll_no == roll_no)
            return &students[i];
    }

    return NULL;
}

int main(void)
{
    Student students[MAX_STUDENTS] = {
        {101, "Hameed", 8.50f},
        {102, "Arun", 7.90f},
        {103, "Fathima", 9.10f}
    };

    printf("Student records:\n");
    for (int i = 0; i < MAX_STUDENTS; ++i)
        print_student(&students[i]);

    Student *found = find_student(students, MAX_STUDENTS, 102);

    if (found != NULL) {
        printf("\nStudent found:\n");
        print_student(found);
    } else {
        printf("\nStudent not found\n");
    }

    return 0;
}
