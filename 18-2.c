#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd = open("records.txt", O_RDWR);
	if(fd<0)
	{
		perror("File doesn't exist\n");
		return 0;
	}
	int n;
	struct{
                int flight_no;
                int flight_tno;
        } f[3];

	printf("Enter flight number: 1,2,3\n");
	scanf("%d",&n);
	struct flock fl;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = (n-1)*sizeof(f);
	fl.l_len = sizeof(f);
	fl.l_pid = getpid();
	fcntl(fd,F_SETLKW,&fl);

	int l = lseek(fd,(n-1)*sizeof(f),SEEK_SET);
	read(fd,&f,sizeof(f));
	printf("Before entering critical section\n");
	/*fcntl(fd,F_SETLKW,&f);*/
	printf("Current ticket number: %d\n", f->flight_tno);
	f->flight_tno++;
	lseek(fd,(n-1)*sizeof(f),SEEK_SET);
	write(fd,&f,sizeof(f));
	printf("Ticket number after: %d\n",f->flight_tno);
 	char c;
	printf("Press Q to book ticket:\n");
	scanf("%c",&c);
	while(c!='Q')
	{
		scanf("%c",&c);
	}

	/*fl.l_type = F_UNLCK;*/
	fcntl(fd,F_GETLK,&fl);
	printf("Ticket number: %d\n",f->flight_tno);
	return 0;
}

