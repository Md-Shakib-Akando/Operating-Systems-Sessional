#include <stdio.h>

int main() {
    int n;
    int arrival[10], burst[10];
    int completion[10], turnaround[10], waiting[10];

    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Arrival Time and Burst Time
    for (int i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);
        printf("Burst Time: ");
        scanf("%d", &burst[i]);
    }

    // Completion Time calculation (FCFS)
    completion[0] = arrival[0] + burst[0];

    for (int i = 1; i < n; i++) {
        if (completion[i - 1] < arrival[i])
            completion[i] = arrival[i] + burst[i];
        else
            completion[i] = completion[i - 1] + burst[i];
    }

    // Turnaround Time & Waiting Time
    for (int i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];

        avg_tat += turnaround[i];
        avg_wt += waiting[i];
    }

    // Output Table
    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               i + 1, arrival[i], burst[i],
               completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}
