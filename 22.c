#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc, char* argv[])
{
	int fd = open(argv[1], O_RDWR);
	if(fd<0)
	{
		perror("Error in opening the file!\n");
		return 0;
	}
	int pid = fork();
	if(pid == -1)
	{
		printf("Error in creating a child process!\n");
		return 0;
	}
	else if(pid == 0)
	{
		char *c = "This is the child process.\n";
		write(fd, c, strlen(c));
		close(fd);
		exit(0);
	}
	else
	{
		char *p = "This is the parent process.\n";
		write(fd,p,strlen(p));
		close(fd);

		wait(NULL);
	}
	return 0;
}


