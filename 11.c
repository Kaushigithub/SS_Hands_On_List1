#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	int wrcount,cf;
	char data[10];
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
	int dupfd = dup(fd);
	if(dupfd<0)
        {
                perror("Error in duplicating the file.\n");
        }
	printf("Enter data to be appended: \n");
	scanf("%s",data);
	wrcount = write(fd,data,10);
	printf("Enter data to be appended using duplicate file: \n");
	scanf("%s",data);
	wrcount = write(dupfd,data,10);
	printf("Now we will close the duplicated file.\n");
	cf = close(dupfd);
	int dup2fd = dup2(fd,8);
	if(dup2fd<0)
	{
		perror("File couldn't be duplicated using the dup2().\n");
		return 0;
	}	
	printf("Enter data to be appended using duplicate file: \n");
        scanf("%s",data);
        wrcount = write(dup2fd,data,10);
        printf("Now we will close the new duplicated file.\n");
        cf = close(dup2fd);

	int fd2 = fcntl(fd,F_DUPFD,9);
	if(fd2<0)
	{
		perror("File couldn't be created using fcntl.\n");
		return 0;
	}
	printf("Enter data to be appended - fcntl: \n");
        scanf("%s",data);
        wrcount = write(fd2,data,10);
        printf("Now we will close the new file.\n");
	printf("\n");
        cf = close(fd2);
	cf = close(fd);
	return 0;
}
