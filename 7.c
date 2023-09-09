#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
	if(argc<3)
	{
		printf("Error occurred! Specify both the file names.\n");
		return 0;
	}
	else
	{
		int fd1 = open(argv[1], O_RDONLY);
		if(fd1<0)
		{
			perror("file1 (source file) doesn't exist.\n");
			return 0;
		}
		int fd2 = open(argv[2], O_RDWR|O_CREAT,0777);
		if(fd2<0)
		{
                        perror("file2 (destination file) doesn't exist.\n");
                        return 0;
                }
		char buff[100];
		int rdcount, wrcount;
		rdcount = read(fd1, &buff, sizeof(buff));
		//while(rdcount!=0)
		/*{
			wrcount = write(fd2, &buff, 1);
			rdcount = read(fd1, &buff, 1);
		}*/
		wrcount = write(fd2, &buff, rdcount);
		int fd1_close = close(fd1);
		int fd2_close = close(fd2);
		if(fd1_close<0 || fd2_close<0)
		{
			perror("Error occurring while closing the files.\n");
		}
		else
		{
			printf("File1 is copied to File2 successfully.\n");
		}
	}
	return 0;
}

