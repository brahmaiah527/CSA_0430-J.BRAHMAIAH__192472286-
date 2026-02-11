#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, time = 0, done = 0, min, idx;
    int at[10], bt[10], rt[10], pr[10];
    int wt[10] = {0}, tat[10] = {0};

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    while(done < n) {
        min = INT_MAX; idx = -1;

        for(i = 0; i < n; i++)
            if(at[i] <= time && rt[i] > 0 && pr[i] < min) {
                min = pr[i];
                idx = i;
            }

        if(idx == -1) { time++; continue; }

        rt[idx]--;
        time++;

        if(rt[idx] == 0) {
            done++;
            tat[idx] = time - at[idx];
            wt[idx] = tat[idx] - bt[idx];
        }
    }

    for(i = 0; i < n; i++)
        printf("%d %d\n", wt[i], tat[i]);

    return 0;
}

