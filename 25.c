#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int wtstatus;
        int pid1 = fork();
        if(pid1 == -1)
        {
                printf("Error in creating first child process.\n");
                return 0;
        }
	else if(pid1 == 0)
	{
		printf("First child process id is: %d\n",getpid());
		printf("First child process parent id is: %d\n",getppid());
		exit(0);
	}
	else
	{
		waitpid(pid1, &wtstatus, 0);
		int pid2 = fork();
		if(pid2 == -1)
        	{
                	printf("Error in creating second child process.\n");
                	return 0;
        	}
        	else if(pid2 == 0)
        	{       
                	printf("Second child process id is: %d\n",getpid());
                	printf("Second child process parent id is: %d\n",getppid());
			exit(0);
        	}
		else
		{
			waitpid(pid2, &wtstatus, 0);
                	int pid3 = fork();
                	if(pid3 == -1)
                	{
                        	printf("Error in creating third child process.\n");
                        	return 0;
                	}
                	else if(pid3 == 0)
                	{
                        	printf("Third child process id is: %d\n",getpid());
                        	printf("Third child process parent id is: %d\n",getppid());
				exit(0);
                	}
			else
			{
				waitpid(pid3, &wtstatus, 0);
				printf("Parent process id of all process is: %d\n", getpid());
			}
		}
	}
}
