#include<stdio.h>
#include<fcntl.h>
int main()
{
        int fl = open("newfilecreated.txt",O_EXCL | O_RDWR, 00644);
        if(fl<0)
        {
                perror("Error in opening the file");
        }
        else
        {
                printf("File is opening successfully \nFile descriptor: %d\n",fl);
        }
        return 0;
}

