#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>


int main()
{
	int pid =  fork();
	if(pid == -1)
	{
		printf("Error in creating a child process.\n");
		return 0;
	}
	else if(pid==0)
	{
		printf("Child process does nothing.\n");
		exit(0);
	}
	else
	{
		sleep(10);
	}
	return 0;
}


