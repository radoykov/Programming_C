#include <stdio.h>

typedef struct node
{
    char Firstname[16];
    struct node *father;
    struct node *mother;
    struct node *merriedto;
} Node;

int main()
{
    Node stefan = {.Firstname = "Stefan", .father = NULL, .mother = NULL, .merriedto = NULL};
    Node deqna = {.Firstname = "Deqna", .father = NULL, .mother = NULL, .merriedto = &stefan};
    Node ivan = {.Firstname = "Ivan", .father = &stefan, .mother = &deqna, .merriedto = NULL};
    Node hristo = {.Firstname = "Hristo", .father = NULL, .mother = NULL, .merriedto = NULL};
    Node nikol = {.Firstname = "Nikol", .father = NULL, .mother = NULL, .merriedto = &hristo};
    Node maria = {.Firstname = "Maria", .father = &hristo, .mother = &nikol, .merriedto = &ivan};
    Node pesho = {.Firstname = "Pesho", .father = &ivan, .mother = &maria, .merriedto = NULL};
    Node peshosister = {.Firstname = "Elena", .father = &ivan, .mother = &maria, .merriedto = NULL};

    stefan.merriedto = &deqna;
    ivan.merriedto = &maria;
    hristo.merriedto = &nikol;

    return 0;
}
