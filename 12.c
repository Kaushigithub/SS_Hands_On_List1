#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{ 
	if(argc<2)
	{
		printf("Error! Specify the file.\n");
		return 0;
	}
	int fd = open(argv[1],O_RDWR);
	if(fd<0)
	{
		perror("File doesn't exist.\n");
		return 0;
	}
	printf("File opening mode: %d\n",fcntl(fd,F_GETFL));
	int cf = close(fd);
	return 0;
}



