#include <stdio.h>

int main() {
    int n;
    int arrival[10], burst[10], pid[10];
    int completion[10], turnaround[10], waiting[10];
    int visited[10] = {0};

    float avg_tat = 0, avg_wt = 0;
    int current_time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nProcess P%d\n", pid[i]);
        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);
        printf("Burst Time: ");
        scanf("%d", &burst[i]);
    }

    // SJF Scheduling
    while (completed < n) {
        int idx = -1;
        int min_burst = 9999;

        // Find process with shortest burst time
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= current_time && !visited[i]) {
                if (burst[i] < min_burst) {
                    min_burst = burst[i];
                    idx = i;
                }
            }
        }

        // No process available, CPU idle
        if (idx == -1) {
            current_time++;
        } else {
            current_time += burst[idx];
            completion[idx] = current_time;
            turnaround[idx] = completion[idx] - arrival[idx];
            waiting[idx] = turnaround[idx] - burst[idx];

            avg_tat += turnaround[idx];
            avg_wt += waiting[idx];

            visited[idx] = 1;
            completed++;
        }
    }

    // Output
    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               pid[i], arrival[i], burst[i],
               completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}
