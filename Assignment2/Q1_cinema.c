#include <stdio.h>

int main()
{
    int hall[50][50];
    int rows, seats, i, j, k;
    int total = 0, rowFree;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of seats per row: ");
    scanf("%d", &seats);

    printf("Enter seating status (0 = available, 1 = booked):\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < seats; j++)
        {
            scanf("%d", &hall[i][j]);
        }
    }

    printf("\nSeating arrangement:\n   ");
    for (j = 0; j < seats; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    for (i = 0; i < rows; i++)
    {
        printf("R%d ", i);
        for (j = 0; j < seats; j++)
        {
            if (hall[i][j] == 0)
                printf("_ ");
            else
                printf("X ");
        }
        printf("\n");
    }

    printf("\nFree seats per row: ");
    for (i = 0; i < rows; i++)
    {
        rowFree = 0;
        for (j = 0; j < seats; j++)
        {
            if (hall[i][j] == 0)
                rowFree++;
        }
        printf("%d ", rowFree);
        total = total + rowFree;
    }
    printf("  Total free: %d\n", total);

    printf("\nEnter number of customers in the group: ");
    scanf("%d", &k);

    if (k <= 0 || k > seats)
    {
        printf("Invalid group size. It must be between 1 and %d.\n", seats);
        return 0;
    }

    int mid = rows / 2;
    int found = 0, bookedRow = -1, startSeat = -1;
    int d, t, r, count, s;

    for (d = 0; d < rows && !found; d++)
    {
        for (t = 0; t < 2 && !found; t++)
        {
            if (t == 0)
                r = mid - d;
            else
                r = mid + d;

            if (t == 1 && d == 0)
                continue;
            if (r < 0 || r >= rows)
                continue;

            count = 0;
            for (s = 0; s < seats; s++)
            {
                if (hall[r][s] == 0)
                    count++;
                else
                    count = 0;

                if (count == k)
                {
                    found = 1;
                    bookedRow = r;
                    startSeat = s - k + 1;
                    break;
                }
            }
        }
    }

    if (found)
    {
        for (j = startSeat; j < startSeat + k; j++)
        {
            hall[bookedRow][j] = 1;
        }
        total = total - k;

        printf("\nGroup of %d seated in Row %d, Seats %d to %d\n", k, bookedRow, startSeat, startSeat + k - 1);

        printf("\n   ");
        for (j = 0; j < seats; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
        for (i = 0; i < rows; i++)
        {
            printf("R%d ", i);
            for (j = 0; j < seats; j++)
            {
                if (hall[i][j] == 0)
                    printf("_ ");
                else
                    printf("X ");
            }
            printf("\n");
        }
        printf("\nRemaining available seats: %d\n", total);
    }
    else
    {
        printf("\nSorry, no row has %d consecutive available seats.\n", k);
    }

    return 0;
}
