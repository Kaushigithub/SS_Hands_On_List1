#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
	int rdcount, wrcount;
	char buff;
	if(argc<2)
	{
		printf("Error! Specify the file.\n");
		return 0;
	}
	int fd = open(argv[1], O_RDWR | O_CREAT, 0777);
	if(fd<0)
	{
		perror("File doesn't exist.\n");
		return 0;
	}
	char data[10];
	printf("Enter some data: \n");
	scanf("%s",data);
	wrcount = write(fd,data,10);
	int offset = lseek(fd,10,SEEK_CUR);
	if(offset<0)
	{
		perror("Error in seeking.\n");
	}
	printf("Enter data after moving by 10 bytes: \n");
	scanf("%s",data);
	wrcount = write(fd,data,10);
	offset = lseek(fd,0,SEEK_CUR);
	if(offset<0)
	{
		perror("Error in seeking the file.\n");
		return 0;
	}
	printf("Value of lseek returned: %d\n",offset);
	int cf = close(fd);

	if(cf<0)
	{
		perror("File couldn;t be closed successfully");
	}
	return 0;
}


