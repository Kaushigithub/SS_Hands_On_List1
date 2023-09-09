#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
        int fd = creat(argv[1],O_CREAT);
        if(fd<0)
        {
                perror("File not created!");
        }
        else
        {
                printf("File is created successfully \nFile descriptor: %d\n",fd);
        }
	close(fd);
        return 0;
}

