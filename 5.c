#include<stdio.h>
#include<fcntl.h>
int main()
{
        int fd1 = creat("newfilecreated1.txt",O_CREAT);
        int fd2 = creat("newfilecreated2.txt",O_CREAT);
        int fd3 = creat("newfilecreated3.txt",O_CREAT);
        int fd4 = creat("newfilecreated4.txt",O_CREAT);
        int fd5 = creat("newfilecreated5.txt",O_CREAT);
        if(fd1<0)
        {
                perror("Error in creating File 1");
        }
        else
        {
                printf("File 1 created successfully !\n");
                printf("File descriptor: %d\n",fd1);
        }
        if(fd2<0)
        {
                perror("Error in creating File 2");
        }
        else
	{
                printf("File 2 created successfully !\n");
                printf("File descriptor: %d\n",fd2);

        }

        if(fd3<0)
        {
                perror("Error in creating File 3");
        }
        else
        {
                printf("File 3 created successfully !\n");
                printf("File descriptor: %d\n",fd3);

        }

        if(fd4<0)
        {
                perror("Error in creating File 4");
        }
        else
        {
                printf("File 4 created successfully !\n");
                printf("File descriptor: %d\n",fd4);

        }

        if(fd5<0)
        {
                perror("Error in creating File 5");
        }
        else
        {
                printf("File 5 created successfully !\n");
                printf("File descriptor: %d\n",fd5);

        }

        while(1)
        {
        }
        return 0;
}

