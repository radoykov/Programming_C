#include <stdio.h>

typedef unsigned int uint;

typedef struct
{
    char Firstname[16];
    char Secondname[16];
    char Lastname[16];
    char email[30];
    uint number;

} Student;

typedef enum
{
    false = 0,
    true = 1,
} Bool;

typedef struct
{
    Student student;
    Bool confirmed;

} Answer;

typedef struct
{
    char name[30];
    char description[100];
    struct
    {
        int day;
        int month;
        int year;
        struct
        {
            int hours;
            int minutes;
        } time;

    } date;

    Answer answers[100];

} Cause;

void printDate(Cause *cause)
{
    printf("\nDate %d.%d.%d", cause->date.day, cause->date.month, cause->date.year);

    printf("\nTime %d:%d", cause->date.time.hours, cause->date.time.minutes);
}

void printAnswer(Answer *answer)
{
    printf("\nStudent: %s %s %s", answer->student.Firstname, answer->student.Secondname, answer->student.Lastname);
    printf("\nEmail: %s", answer->student.email);
    printf("\nNumber: %d", answer->student.number);
    printf("\nConfirmed: %s", answer->confirmed == true ? "true" : "false");
}

void print(Cause *cause)
{
    printf("\nName:%s", cause->name);
    printf("\nDescription:%s", cause->description);

    printDate(cause);

    for (int i = 0; i < 100; i++)
    {
        if (cause->answers[i].student.Firstname[0] == '\0')
            break;
        printf("\n");
        printAnswer(&(cause->answers[i]));
    }
}

int main()
{
    Cause causes[2] = {
        {
            name : "Garbage collection",
            description : "77",
            date : {4, 8, 2008, {12, 30}},
            .answers[0] = {"alex", "vasilev", "radoykov", "alexvr@255", 258146545, true},
            .answers[1] = {"vasko", "pesho", "radoykov", "vaskop@255", 87569875, false},
        },
        {
            name : "Go to cinema",
            description : "Cool Movie",
            date : {11, 9, 2024, {23, 19}},
            .answers[0] = {"alex", "vasilev", "radoykov", "alexvr@255", 258146545, true},
            .answers[1] = {"vasko", "pesho", "radoykov", "vaskop@255", 87569875, true},
        }};

    print(&causes[0]);
    printf("\n");
    print(&causes[1]);

    return 0;
}