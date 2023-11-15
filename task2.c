#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int number;
    pid_t p;

    printf("Enter an integer number:\n");
    scanf("%d", &number);

    p = fork();

    if (p == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (p == 0) {
        if (number % 2 == 0) {
            printf("Child process - %d is even.\n", number);
        } else {
            printf("Child process - %d is odd.\n", number);
        }
    } else {
        wait(NULL);
        printf("Parent process - Calculation completed\n");
    }

    return 0;
}
