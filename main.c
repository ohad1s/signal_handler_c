#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int signum) {
    int i = 5;
    int j = 0;
    int k;
    int first;
    switch (signum) {
        case SIGCHLD:
            printf("signal 1\n");
            fflush(stdout);
            raise(SIGUSR1);
        case SIGUSR1:
            printf("signal 2\n");
            fflush(stdout);
            k = i / j;
        case SIGFPE:
            printf("signal 3\n");
            fflush(stdout);
            abort();
        case SIGABRT:
            printf("signal 4\n");
            fflush(stdout);
            char *cptr = malloc(sizeof(int) + 1);
            int *iptr = (int *) ++cptr;
            *iptr = 42;
        case SIGBUS:
            printf("signal 5\n");
            fflush(stdout);
            kill(0, signum);
        case SIGSEGV:
            printf("signal 6\n");
            fflush(stdout);
            0;
        case SIGILL:
            printf("signal 7\n");
            fflush(stdout);
            alarm(2);  // Scheduled alarm after 2 seconds
            for (int i = 1;; i++)
                sleep(1);  // Delay for 1 second
        case SIGALRM:
            printf("signal 8\n");
            fflush(stdout);
            while (1) {
                break;
            }
        case SIGWINCH:
            printf("signal 9\n");
            fflush(stdout);
            printf("enter a number to get signal number 10 ");
            scanf("%c", &first);
        case SIGXFSZ:
            printf("signal 10\n");
            fflush(stdout);
            system("ohad");
        case SIGSYS:
            printf("signal 11\n");
            fflush(stdout);
            int main = 6;
        case SIGKILL:
            printf("signal 12\nenter ctrl+c to get signal 13\n");
            fflush(stdout);
            while (1);
        case SIGINT:
            printf("\nsignal 13\n");
            fflush(stdout);
            exit(1);
    }
}

int main() {
    int status;
    signal(SIGCHLD, sig_handler);
    signal(SIGUSR1, sig_handler);
    signal(SIGFPE, sig_handler);
    signal(SIGABRT, sig_handler);
    signal(SIGINT, sig_handler);
    signal(SIGKILL, sig_handler);
    signal(SIGBUS, sig_handler);
    signal(SIGSEGV, sig_handler);
    signal(SIGILL, sig_handler);
    signal(SIGALRM, sig_handler);
    signal(SIGWINCH, sig_handler);
    signal(SIGXFSZ, sig_handler);
    signal(SIGSYS, sig_handler);


    if (!(fork())) {
        exit(1);
    }
    wait(&status);

}
