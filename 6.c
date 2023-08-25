#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	char buff[100];
	int rcount, wcount;
	printf("Input: \n");
	rcount = read(0,&buff,100);
	wcount = write(1,&buff,rcount);
	return 0;
}

