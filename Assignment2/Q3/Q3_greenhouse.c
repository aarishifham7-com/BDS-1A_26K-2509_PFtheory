#include <stdio.h>

void inputReadings(int temp[][50], int sensors, int hours)
{
    int i, j;
    for (i = 0; i < sensors; i++)
    {
        printf("Sensor %d readings:\n", i + 1);
        for (j = 0; j < hours; j++)
        {
            printf("  Hour %d: ", j + 1);
            scanf("%d", &temp[i][j]);
        }
    }
}

void analyzeSensor(int readings[], int hours, int *total, float *avg, int *max, int *min, int *critical, int *warning, int *streak)
{
    int i, current = 0;

    *total = 0;
    *max = readings[0];
    *min = readings[0];
    *critical = 0;
    *warning = 0;
    *streak = 0;

    for (i = 0; i < hours; i++)
    {
        *total = *total + readings[i];

        if (readings[i] > *max)
            *max = readings[i];
        if (readings[i] < *min)
            *min = readings[i];

        if (readings[i] >= 40)
            (*critical)++;
        else if (readings[i] >= 35 && readings[i] <= 39)
            (*warning)++;

        if (readings[i] >= 35)
        {
            current++;
            if (current > *streak)
                *streak = current;
        }
        else
        {
            current = 0;
        }
    }

    *avg = (float)(*total) / hours;
}

int highestAverageSensor(float averages[], int sensors)
{
    int i, best = 0;
    for (i = 1; i < sensors; i++)
    {
        if (averages[i] > averages[best])
            best = i;
    }
    return best + 1;
}

int main()
{
    int temp[50][50];
    float averages[50];
    int sensors, hours, i;
    int total, max, min, critical, warning, streak;
    float avg;
    int best;

    printf("Enter number of sensors: ");
    scanf("%d", &sensors);
    printf("Enter number of hourly readings: ");
    scanf("%d", &hours);

    inputReadings(temp, sensors, hours);

    printf("\n");
    for (i = 0; i < sensors; i++)
    {
        analyzeSensor(temp[i], hours, &total, &avg, &max, &min, &critical, &warning, &streak);
        averages[i] = avg;

        printf("Sensor %d: Total=%d Avg=%.2f Max=%d Min=%d\n", i + 1, total, avg, max, min);
        printf("          Critical=%d Warning=%d Longest hot streak=%d\n", critical, warning, streak);
    }

    best = highestAverageSensor(averages, sensors);
    printf("\nHighest average: Sensor %d (%.2f)\n", best, averages[best - 1]);

    return 0;
}
