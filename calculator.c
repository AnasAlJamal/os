#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int num1, num2;
    pid_t p;

    printf("Enter two integer numbers:\n");
    scanf("%d %d", &num1, &num2);

    p = fork();

    if (p == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (p == 0) {
        int sum = num1 + num2;
        printf("Child process - Sum = %d\n", sum);
    } else {
        wait(NULL);
        printf("Parent process - Calculation completed\n");
    }

    return 0;
}
