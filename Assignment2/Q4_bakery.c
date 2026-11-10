











#include <stdio.h>

int getValidDays()
{
    int days;
    printf("Enter number of festival days (1-7): ");
    scanf("%d", &days);
    while (days < 1 || days > 7)
    {
        printf("Invalid input. Enter number of festival days (1-7): ");
        scanf("%d", &days);
    }
    return days;
}

float calculateDailySales(int dayNumber)
{
    int orders, i;
    float amount, total = 0, highest = 0;

    printf("\nDay %d - Number of orders: ", dayNumber);
    scanf("%d", &orders);

    for (i = 1; i <= orders; i++)
    {
        printf("Enter amount of order %d: ", i);
        scanf("%f", &amount);
        while (amount <= 0)
        {
            printf("Invalid amount. Enter amount of order %d again: ", i);
            scanf("%f", &amount);
        }
        total = total + amount;
        if (amount > highest)
            highest = amount;
    }

    printf("Total sales: Rs. %.2f\n", total);
    printf("Average order: Rs. %.2f\n", total / orders);
    printf("Highest order: Rs. %.2f\n", highest);

    return total;
}

int findHighestSalesDay(float dailySales[], int numberOfDays)
{
    int i, best = 0;
    for (i = 1; i < numberOfDays; i++)
    {
        if (dailySales[i] > dailySales[best])
            best = i;
    }
    return best + 1;
}

void displayBarChart(float dailySales[], int numberOfDays)
{
    int i, j, stars;
    printf("\n===== DAILY SALES BAR CHART =====\n");
    for (i = 0; i < numberOfDays; i++)
    {
        stars = (int)(dailySales[i] / 100);
        printf("Day %d: ", i + 1);
        for (j = 0; j < stars; j++)
        {
            printf("*");
        }
        printf(" (Rs. %.2f)\n", dailySales[i]);
    }
}

int main()
{
    float dailySales[7];
    float festivalTotal = 0;
    int days, i, bestDay;

    days = getValidDays();

    for (i = 0; i < days; i++)
    {
        dailySales[i] = calculateDailySales(i + 1);
        festivalTotal = festivalTotal + dailySales[i];
    }

    bestDay = findHighestSalesDay(dailySales, days);

    printf("\n===== FESTIVAL SUMMARY =====\n");
    printf("Total festival sales: Rs. %.2f\n", festivalTotal);
    printf("Day with highest sales: Day %d\n", bestDay);
    printf("Highest daily sales: Rs. %.2f\n", dailySales[bestDay - 1]);

    displayBarChart(dailySales, days);

    return 0;
}
