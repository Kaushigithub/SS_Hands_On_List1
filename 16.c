#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char*argv[])
{
	if(argc<2)
	{
		perror("Specify the file.\n");
		return 0;
	}

	struct flock fl;
	int fd = open(argv[1], O_RDWR);
	if(fd<0)
        {
                perror("File couldn't be opened successfully.\n");
                return 0;
        }
	
        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;
        fl.l_pid = getpid();
	char c;
        printf("Before entering the critical section..\n");
	printf("Enter the operation u want to perform - Read(R) or Write(W)\n");
	scanf("%c",&c);
	if(c=='R')
	{
		fl.l_type = F_RDLCK;
	}
	else if(c=='W')
	{
		fl.l_type = F_WRLCK;
	}
        int l = fcntl(fd,F_SETLKW,&fl);
        printf("Inside the critical section.\n");
        if(l<0)
        {
                perror("Lock not applied.\n");
                return 0;
        }
	else
	{
		printf("Lock is applied successfully.\n");
	}
	printf("Press Q to unlock.\n");
	scanf("%c",&c);
	while(c!='Q')
	{
		scanf("%c",&c);
	}
	
	l = fcntl(0,F_GETLK,&fl);
	if(l<0)
	{
		perror("Error in unlocking the file.\n");
		return 0;
	}
	printf("Critical Section exited.\n");
	close(fd);
	return 0;
}

