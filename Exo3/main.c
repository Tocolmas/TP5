#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

void chaine (int n)
{
    int i;
    printf ("Lance %d processus en chaine\n\n",n);
    printf ("proc %d fils de %d (shell)\n", getpid(), getppid());

    for (i=0; i<n; i++)
    {
        if (fork() == 0)
        {
            printf ("proc %d fils de %d\n", getpid(), getppid());
            sleep(3)
            exit(0);
        }
        else
        {
            wait(NULL);
        }
    }
}


int main (int argc, char *argv[])
{
    if (argc<2)
    {
        printf ("Usage:\n%s 1 <n> pour lancer <n> processus en chaine\n",argv[0])
        exit(1);
    }

    signal(SIGINT, hand)
    return 0
}




