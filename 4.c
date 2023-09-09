#include<stdio.h>
#include<fcntl.h>
int main()
{
        int fl = open("new1.txt",O_CREAT | O_EXCL | O_RDWR, 0644); // O_EXCL with O_CREAT is used to check if the file already exists or not - if exists it will give error otherwise
								   // will create the new file. O_EXCL is used for safe file creation and to prevent race conditions.
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

