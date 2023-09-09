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
	int f = fcntl(fd,F_GETFL);
	printf("File opening mode: %d\n",f);
	if (f & O_RDONLY) 
	{
		printf("File is open for reading.\n");
	}
    	if (f & O_WRONLY) {
        	printf("File is open for writing.\n");
    	}
    	if (f & O_RDWR) {
        	printf("File is open for both reading and writing.\n");
    	}
    	if (f & O_APPEND) {
        	printf("File is open in append mode.\n");
    	}
	int cf = close(fd);
	return 0;
}



