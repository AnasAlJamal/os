#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

    int x = 3;
    pid_t p;
    x++;

    p = fork();

    if (p == -1) {
        // Error handling for fork failure
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (p == 0) {
        // This is the child process
        printf("Child x=%d\n", x);
    } else {
        // This is the parent process
        wait(NULL); // Wait for the child to finish
        printf("Parent x=%d\n", x);
    }

    printf("Hello World\n");

    return 0;
}
}

