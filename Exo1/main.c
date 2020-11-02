#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void handler(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("signal %d\n", signum);
        fflush(stdout);
        pause();
    }
    else if (signum == SIGUSR2)
    {
        printf("signal %d\n", signum);
        fflush(stdout);
        exit(0);
    }
}

int main(int argc, char* argv[])
{
    pid_t child_pid;
    child_pid = fork();

    if (child_pid == 0)
    {
        struct sigaction sa;
        sa.sa_handler = handler;
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);

        pause();
    }
    else
    {
        sleep(5);
        printf("sending SIGUSR1\n");
        kill(child_pid, SIGUSR1);

        sleep(5);
        printf("sending SIGUSR2\n");

        kill(child_pid, SIGUSR2);
        wait(NULL);
    }

    return 0;
