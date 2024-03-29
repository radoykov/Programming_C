#include <stdio.h>

void printfLegend(void)
{
    printf("\n1 = Monday");
    printf("\n2 = Tuesday");
    printf("\n3 = Wednesday");
    printf("\n4 = Thursday");
    printf("\n5 = Friday");
    printf("\n6 = Saturday");
    printf("\n7 = Sunday");
}
enum Weekdays
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main()
{
    enum Weekdays num = 0;
    printfLegend();

    printf("\nInput number of day = ");
    scanf("%d", &num);

    switch (num)
    {
    case Monday:
        printf("\nMonday");
        break;
    case Tuesday:
        printf("\nTuesday");
        break;
    case Wednesday:
        printf("\nWednesday");

        break;
    case Thursday:
        printf("\nThursday");

        break;
    case Friday:
        printf("\nFriday");

        break;
    case Saturday:
        printf("\nSaturday");

        break;
    case Sunday:
        printf("\nSunday");
        break;

    default:
        printf("\nYou have been inputed a wrong number");
        break;
    }

    return 0;
}