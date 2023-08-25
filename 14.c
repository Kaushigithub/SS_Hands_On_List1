#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

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
		perror("Error in opening the file.\n");
		return 0;
	}
	struct stat s;
	int x = lstat(argv[1],&s);
	if(x<0)
	{
		perror("Error in getting status of the file.\n");
		return 0;
	}
	printf("File type: ");
	switch (s.st_mode & S_IFMT) 
	{
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
        }
	int cf = close(fd);
	return 0;
}
