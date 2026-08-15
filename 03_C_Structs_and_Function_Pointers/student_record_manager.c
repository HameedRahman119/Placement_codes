#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define NAME_LEN 40

typedef struct {
    int roll_no;
    char name[NAME_LEN];
    float cgpa;
} Student;

typedef int (*StudentCompare)(const Student *, const Student *);

static void print_student(const Student *student)
{
    printf("%-6d %-20s %.2f\n",
           student->roll_no,
           student->name,
           student->cgpa);
}

static int compare_cgpa_desc(const Student *a, const Student *b)
{
    if (a->cgpa < b->cgpa)
        return 1;
    if (a->cgpa > b->cgpa)
        return -1;
    return 0;
}

static int compare_roll_no(const Student *a, const Student *b)
{
    return (a->roll_no > b->roll_no) - (a->roll_no < b->roll_no);
}

static void sort_students(Student students[], size_t count,
                          StudentCompare compare)
{
    for (size_t i = 0; i < count; ++i) {
        for (size_t j = 0; j + 1 < count - i; ++j) {
            if (compare(&students[j], &students[j + 1]) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

static Student *find_by_roll(Student students[], size_t count, int roll_no)
{
    for (size_t i = 0; i < count; ++i) {
        if (students[i].roll_no == roll_no)
            return &students[i];
    }
    return NULL;
}

static void print_table(const Student students[], size_t count)
{
    printf("\n%-6s %-20s %s\n", "Roll", "Name", "CGPA");
    printf("----------------------------------------------\n");

    for (size_t i = 0; i < count; ++i)
        print_student(&students[i]);
}

int main(void)
{
    Student students[MAX_STUDENTS] = {
        {103, "Arun", 8.10f},
        {101, "Meena", 9.05f},
        {105, "Rahul", 7.85f},
        {102, "Fathima", 8.72f},
        {104, "Kavin", 8.40f}
    };

    const size_t count = sizeof(students) / sizeof(students[0]);

    printf("Initial records:");
    print_table(students, count);

    sort_students(students, count, compare_cgpa_desc);
    printf("\nSorted by CGPA (highest first):");
    print_table(students, count);

    Student *found = find_by_roll(students, count, 102);
    if (found != NULL) {
        printf("\nFound roll 102: ");
        print_student(found);
    }

    sort_students(students, count, compare_roll_no);
    printf("\nSorted by roll number:");
    print_table(students, count);

    return 0;
}
