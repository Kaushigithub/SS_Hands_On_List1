#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int pid = fork();
	if(pid == -1)
	{
		printf("Error in creating the child process.\n");
		return 0;
	}
	else if(pid == 0)
	{
		printf("Child process and Parent process id before sleep() call is: %d %d\n",getpid(),getppid());
		sleep(10);
		printf("Child process id after sleep() call is: %d\n",getpid());
		printf("Parent process id is: %d\n",getppid());
	}
	else
	{
		printf("Parent process id is: %d\n",getpid()); 
		exit(0);
	}
	return 0;
}
