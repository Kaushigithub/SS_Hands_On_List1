/*
============================================================================
Name : 1.c
Author : Kauhal Yogeshbhai Pancholi
Description : Create the following types of a files using (i) shell command (ii) system call
	      a. soft link (symlink system call)
	      b. hard link (link system call)
              c. FIFO (mkfifo Library Function or mknod system call)
Date: 25th Aug, 2023.
============================================================================
*/

/*
 i) using shell command
 	a) ln -s file_name softlink_file_name
	b) ln file_name hardlink_file_name
	c) mknod fifo_filename  
 */
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
        int v = symlink("slinkfile.txt","softlink");
        if(v<0)
        {
                perror("Softlink Failed ");
                return 1;
        }
        int f = link("hlinkfile.txt","hardlink");
        if(f<0)
        {
                perror("Hardlink Failed ");
                return 1;
        }
        int d = mknod("fifofile",S_IFIFO,0);
        if(d<0)
        {
                perror("Fifofile Failed ");

        }
        return 0;
}

