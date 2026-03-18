#include <stdio.h>

int main()
{
    int n, bt[20], wt[20], tat[20], i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    FILE *fp = fopen("output.txt", "w");

    printf("\nProcess\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        fprintf(fp, "P%d %d %d\n", i + 1, wt[i], wt[i] + bt[i]);
    }

    fclose(fp);
    return 0;
}