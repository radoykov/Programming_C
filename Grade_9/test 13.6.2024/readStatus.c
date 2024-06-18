#include "measurements.h"

int main()
{
    Date date;

    FILE *file = fopen("waterStatus.bin", "rb");
    CHECK(file);

    int count;
    fread(&count, sizeof(int), 1, file);
    fread(&date, sizeof(Date), 1, file);

    printf("%d/%d/%d", date.day, date.month, date.year);

    Sample sample;
    for (int i = 0; i < count; i++)
    {
        fread(&sample, sizeof(Sample), 1, file);

        printf("\n%d.temperature: %lf; chlorine: %lf", i + 1, sample.temperature, sample.chlorineAmount);
    }

    fclose(file);

    return 0;
}