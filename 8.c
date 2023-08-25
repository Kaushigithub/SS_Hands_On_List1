#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
	char buff;
	int rdcount, wrcount;
	int i=0;
	char line[100];
	if(argc<2)
	{
		printf("No file is specified!");
		return 0;
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd<0)
	{
		perror("File doesn't exist\n");
		return 0;
	}
	rdcount = read(fd,&buff,1);
	while(rdcount != 0)
	{
		while(buff != '\n')
		{
			wrcount = write(1,&buff,1);
			rdcount = read(fd,&buff,1);
		}
		printf("\n");
		rdcount = read(fd,&buff,1);
	}
	int cf = close(fd);
	if(cf < 0)
	{
		perror("File couldn't be closed successfully\n");
	}

	return 0;
}
