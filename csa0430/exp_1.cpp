#include <stdio.h>
#include <unistd.h>

int main() {
    int fork();
        printf("Child PID=%d Parent PID=%d\n", getpid(), getppid());
    else
        printf("Parent PID=%d\n", getpid());

    return 0;
}

