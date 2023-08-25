#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
	int fd = open("ticket_no.txt", O_RDWR);
	if(fd<0)
	{
		perror("File couldn't be opened successfully.\n");
		return 0;
	}
	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();
	printf("Before entering the critical section..\n");
	int l = fcntl(fd, F_SETLKW, &fl);
	printf("Inside the critical section.\n");
	if(l<0)
	{
		perror("Lock not applied.\n");
		return 0;
	}
	char buff[5];
	int rdcount = read(fd,buff,5);
	buff[0]+=1;
	int ls = lseek(fd,0,SEEK_SET);
	if(ls<0)
	{
		perror("Error occurred while seeking.\n");
		return 0;
	}
	int wrcount = write(fd,buff,5);
	char c;

	printf("Press Enter to release lock.\n");
	scanf("%c",&c);

	while(c != '\n')
	{
		scanf("%c",&c);
	}

	l = fcntl(fd, F_GETLK, &fl);
	printf("Ticket number is: %s\n",buff);

	printf("Exited Critical section.\n");
	
	return 0;
}

