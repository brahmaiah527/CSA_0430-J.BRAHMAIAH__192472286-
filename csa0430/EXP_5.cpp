#include <stdio.h>

int main() {
    int n, i, j, bt[10], pr[10], wt[10], tat[10], t;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d %d", &bt[i], &pr[i]);

    // Sort by priority
    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(pr[i] > pr[j]) {
                t = pr[i]; pr[i] = pr[j]; pr[j] = t;
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
            }

    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], pr[i], wt[i], tat[i]);
    }

    return 0;
}

