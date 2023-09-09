#include<stdio.h>
#include<unistd.h>


int main()
{
	int pid = fork();
	if(pid == -1)
	{
		perror("Error in creating child process.\n");
		
	}
	else if(pid)
	{
		printf("Parent process id is: %d\n",getpid());
		printf("Child process id is: %d\n",pid);
	}
	//printf("Parent process id is: %d\n",getpid());
        //printf("Child process id is: %d\n",pid);

	return 0;
}

