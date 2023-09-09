#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
	int wrcount,cf;
	if(argc<2)
	{
		printf("Specify the file.\n");
		return 0;
	}

	int fd = open(argv[1], O_RDWR | O_APPEND);
	if(fd<0)
	{
		perror("Error in opening the file.\n");
		return 0;
	}
	char str[] = "This is original file. \n";
	int dupfd = dup(fd);
	if(dupfd<0)
        {
                perror("Error in duplicating the file.\n");
        }
	char dup_str[] = "This is duplicated file using dup(). \n"; 
	wrcount = write(fd,str,strlen(str));
	wrcount = write(dupfd,dup_str,strlen(dup_str));
	printf("Now we will close the duplicated file.\n");
	cf = close(dupfd);
	char dup2_str[] = "This is duplicated file using dup2().\n";
	int dup2fd = dup2(fd,8);
	if(dup2fd<0)
	{
		perror("File couldn't be duplicated using the dup2().\n");
		return 0;
	}	
        wrcount = write(dup2fd,dup2_str,strlen(dup2_str));
        printf("Now we will close the new duplicated file.\n");
        cf = close(dup2fd);

	char fcntl_str[] = "This duplicated file using fcntl().\n";
	int fd2 = fcntl(fd,F_DUPFD,9);
	if(fd2<0)
	{
		perror("File couldn't be created using fcntl.\n");
		return 0;
	}
        wrcount = write(fd2,fcntl_str,strlen(fcntl_str));
        printf("Now we will close the new file.\n");
	printf("\n");
        cf = close(fd2);
	cf = close(fd);
	return 0;
}
