#include "measurements.h"

int main()
{
    Date date = {.day = 5, .month = 6, .year = 2024};

    Sample arr[TESTCOUNT] = {
        {.temperature = 15, .chlorineAmount = 7},
        {.temperature = 21, .chlorineAmount = 8},
        {.temperature = 40, .chlorineAmount = 6}
    };

    FILE *file = fopen("waterStatus.bin", "wb");
    CHECK(file);
    int count = TESTCOUNT;

    fwrite(&count, sizeof(int), 1, file);
    fwrite(&date, sizeof(Date), 1, file);

    for (int i = 0; i < count; i++)
    {
        fwrite(&arr[i], sizeof(Sample), 1, file);
    }
    fclose(file);

    return 0;
}