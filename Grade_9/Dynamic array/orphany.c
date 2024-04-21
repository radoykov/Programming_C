#include <stdio.h>
#include <stdlib.h>
#include "dynarr.h"

int main()
{
    int command;
    DynamicArray array = init(0);

    printf("Add new donor: 1\n");
    printf("Delete donor: 2\n");
    printf("Print all donors: 3\n");
    printf("Exit: 4\n");

    while (1)
    {
        printf("Input command:");
        scanf("%d", &command);

        switch (command)
        {
        case 1:
            float idAdd;
            printf("ID to add:");
            scanf("%f", &idAdd);

            pushBack(&array, idAdd);

            break;
        case 2:

            float idDel;
            printf("ID to delete:");
            scanf("%f", &idDel);
            int index = getIndexOf(&array, idDel);
            if (index == -1)
            {
                printf("This user not found.\n");
                break;
            }
            removeElement(&array, index);

            printf("ID was deleted.\n");
            break;

        case 3:
            if (array.size == 0)
            {
                printf("No donors\n");
                break;
            }
            for (int i = 0; i < array.size; i++)
            {
                printf("Id(%d): %f\n", i + 1, array.buffer[i]);
            }
            break;

        case 4:
            release(&array);
            printf("Program have finished.\n");
            exit(0);
            break;

        default:
            printf("You have inputed a wrong command. Please try again.\n");
            break;
        }
    }

    return 0;
}