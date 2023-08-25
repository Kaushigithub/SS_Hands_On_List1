#include<stdio.h>
#include<sys/select.h>
#include<stdlib.h>

int main()
{
	int timeout_val;
	fd_set f;
	struct timeval t;
	FD_ZERO(&f);
	FD_SET(0,&f);
	t.tv_sec = 10;
	t.tv_usec = 0;
	timeout_val = select(1,&f,NULL,NULL,&t);
	if(timeout_val)
	{
		printf("Data is available within 10 seconds.\n");
	}
	else
	{
		printf("No data is available within 10 seconds.\n");
	}
	return 0;
}

