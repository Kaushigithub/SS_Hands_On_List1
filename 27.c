#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
	int pid = fork();
	int wtstatus;
	if(pid == -1)
	{
		printf("Error in creating the child process.\n");
		return 0;
	}
	else if(pid == 0)
	{
		printf("execl execution: \n");
		execl("/bin/ls","ls","-Rl",NULL);
		perror("execl");
		exit(1);
	}
	sleep(1);

	int pid1  = fork();
	if(pid1 == -1)
        {       
                printf("Error in creating the child process.\n");
                return 0;
        }       
        else if(pid1 == 0)
        {       
		printf("execlp execution: \n");
                execlp("ls","ls","-Rl",NULL);
                perror("execl");
                exit(1);
        }       
        sleep(1);

        int pid2 = fork();
        if(pid2 == -1)
        {
                printf("Error in creating the child process.\n");
                return 0;
        }
        else if(pid2 == 0)
        {
		printf("execle execution: \n");
                execle("/bin/ls","ls","-Rl",NULL,NULL);
                perror("execl");
                exit(1);
        }
        sleep(1);

	char *args[] = {"ls","-Rl",NULL};
        int pid4  = fork();
        if(pid4 == -1)
        {
                printf("Error in creating the child process.\n");
                return 0;
        }
        else if(pid4 == 0)
        {
		printf("execv execution \n");
                execv("/bin/ls",args);
                perror("execl");
                exit(1);
        }
      	sleep(1);

        int pid5 = fork();
        if(pid5 == -1)
        {
                printf("Error in creating the child process.\n");
                return 0;
        }
        else if(pid5 == 0)
        {
		printf("execvp execution \n");
                execvp("ls",args);
                perror("execl");
                exit(1);
        }
	sleep(1);
	return 0;
}
