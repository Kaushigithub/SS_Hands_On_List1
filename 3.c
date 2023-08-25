#include<stdio.h>
#include<fcntl.h>
int main()
{
        int fd = creat("newfilecreated.txt",O_CREAT);
        if(fd<0)
        {
                perror("File not created!");
        }
        else
        {
                printf("File is created successfully \nFile descriptor: %d\n",fd);
        }
        return 0;
}

