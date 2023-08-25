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

