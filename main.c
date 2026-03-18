#include <stdio.h>

struct Process
{
    int id, bt, wt, tat, pr, rt;
};

void printGantt(int order[], int n, int time[]);
void fcfs();
void sjf();
void priorityScheduling();
void roundRobin();

/* ================= MAIN ================= */
int main()
{
    int choice;

    printf("\nCPU Scheduling Simulator\n");
    printf("1. FCFS Scheduling\n");
    printf("2. SJF Scheduling\n");
    printf("3. Priority Scheduling\n");
    printf("4. Round Robin Scheduling\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        fcfs();
        break;
    case 2:
        sjf();
        break;
    case 3:
        priorityScheduling();
        break;
    case 4:
        roundRobin();
        break;
    default:
        printf("Invalid Choice");
    }

    return 0;
}

/* ================= GANTT ================= */
void printGantt(int order[], int n, int time[])
{
    int i;

    printf("\nGantt Chart:\n");

    for (i = 0; i < n; i++)
        printf("--------");
    printf("\n|");

    for (i = 0; i < n; i++)
        printf("  P%d   |", order[i]);

    printf("\n");

    for (i = 0; i < n; i++)
        printf("--------");

    printf("\n%d", time[0]);
    for (i = 1; i <= n; i++)
        printf("      %d", time[i]);

    printf("\n");
}

/* ================= FCFS ================= */
void fcfs()
{
    int n, i;
    struct Process p[20];
    int order[20], time[21];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &p[i].bt);
    }

    p[0].wt = 0;
    for (i = 1; i < n; i++)
        p[i].wt = p[i - 1].wt + p[i - 1].bt;

    for (i = 0; i < n; i++)
        p[i].tat = p[i].wt + p[i].bt;

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", p[i].id, p[i].bt, p[i].wt, p[i].tat);

    time[0] = 0;
    for (i = 0; i < n; i++)
    {
        order[i] = p[i].id;
        time[i + 1] = time[i] + p[i].bt;
    }

    printGantt(order, n, time);
}

/* ================= SJF ================= */
void sjf()
{
    int n, i, j;
    struct Process p[20], temp;
    int order[20], time[21];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &p[i].bt);
    }

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (p[i].bt > p[j].bt)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }

    p[0].wt = 0;
    for (i = 1; i < n; i++)
        p[i].wt = p[i - 1].wt + p[i - 1].bt;

    for (i = 0; i < n; i++)
        p[i].tat = p[i].wt + p[i].bt;

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", p[i].id, p[i].bt, p[i].wt, p[i].tat);

    time[0] = 0;
    for (i = 0; i < n; i++)
    {
        order[i] = p[i].id;
        time[i + 1] = time[i] + p[i].bt;
    }

    printGantt(order, n, time);
}

/* ================= PRIORITY ================= */
void priorityScheduling()
{
    int n, i, j;
    struct Process p[20], temp;
    int order[20], time[21];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i].id = i + 1;

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &p[i].bt);

        printf("P%d Priority: ", i + 1);
        scanf("%d", &p[i].pr);
    }

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (p[i].pr > p[j].pr)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }

    p[0].wt = 0;
    for (i = 1; i < n; i++)
        p[i].wt = p[i - 1].wt + p[i - 1].bt;

    for (i = 0; i < n; i++)
        p[i].tat = p[i].wt + p[i].bt;

    printf("\nProcess\tBT\tPR\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].bt, p[i].pr, p[i].wt, p[i].tat);

    time[0] = 0;
    for (i = 0; i < n; i++)
    {
        order[i] = p[i].id;
        time[i + 1] = time[i] + p[i].bt;
    }

    printGantt(order, n, time);
}

/* ================= ROUND ROBIN ================= */
void roundRobin()
{
    int n, tq, i, time = 0, done;
    struct Process p[20];
    int order[100], t[101], k = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt; // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    t[0] = 0;

    do
    {
        done = 1;

        for (i = 0; i < n; i++)
        {
            if (p[i].rt > 0)
            {
                done = 0;

                order[k++] = p[i].id;

                if (p[i].rt > tq)
                {
                    time += tq;
                    p[i].rt -= tq;
                }
                else
                {
                    time += p[i].rt;
                    p[i].wt = time - p[i].bt;
                    p[i].rt = 0;
                }

                t[k] = time;
            }
        }
    } while (!done);

    for (i = 0; i < n; i++)
        p[i].tat = p[i].wt + p[i].bt;

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n",
               p[i].id, p[i].bt, p[i].wt, p[i].tat);

    printGantt(order, k, t);
}