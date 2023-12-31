#include <stdio.h>
#include <limits.h>
#define PRI_ONE "|%-13s| %-13s| %-13s| %-20s| %-20s| %-13s| %-20s| \n"
#define PRINT_TABLE  printf("------------------------------------------------------------------------------------------------------------------------------\n")

int main() 
{
    PRINT_TABLE;
    printf(PRI_ONE, "Name", "It's si print", "Size", "Max si type", "Min si type", "It's un print", "Max un type");
    PRINT_TABLE;
    printf("|%13s| %13s| %13zu| %20d| %20d| %13s| %20d| \n", "char", "%c", sizeof(char), CHAR_MAX, CHAR_MIN, "%d",  UCHAR_MAX);
    printf("|%13s| %13s| %13zu| %20hd| %20hd| %13s| %20hu| \n", "short", "%hd", sizeof(short), SHRT_MAX, SHRT_MIN, "%hu",  USHRT_MAX);
    printf("|%13s| %13s| %13zu| %20d| %20d| %13s| %20u| \n", "int", "%d", sizeof(int), INT_MAX, INT_MIN, "%u",  UINT_MAX);
    printf("|%13s| %13s| %13zu| %20ld| %20ld| %13s| %20lu| \n", "long", "%ld", sizeof(long), LONG_MAX, LONG_MIN, "%lu",  ULONG_MAX);
    printf("|%13s| %13s| %13zu| %20lld| %20lld| %13s| %20llu| \n", "long long", "%lld", sizeof(long long), LONG_LONG_MAX, LONG_LONG_MIN, "%llu",  ULONG_LONG_MAX);
    PRINT_TABLE;
    return 0;
}