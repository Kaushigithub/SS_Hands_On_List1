#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
        int fd = open("ticket_no.txt", O_RDWR, 00600);
        if(fd<0)
        {
                perror("File doesn't exist.\n");
                return 0;
        }
        
	char buff[5];
        printf("Enter ticket number: \n");
        scanf("%s", buff);
	int x = write(fd,buff,5);
	write(fd,"\n",1);
	if(x<0)
	{
		perror("File couldn't be created successfully.\n");
		return 0;
	}
	else
	{
		printf("Ticket created successfully.\n");
		printf("Ticket no. is: %s\n",buff);
	}
        return 0;
}

