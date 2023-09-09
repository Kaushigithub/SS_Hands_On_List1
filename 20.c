#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<errno.h>

int main()
{
	int pid = getpid();
	int priority = getpriority(PRIO_PROCESS, 0);
	printf("Process priority is: %d\n",priority);
	errno = 0;
	priority = nice(2);
	if(errno==1)
	{
		printf("Error in setting the priority!\n");
		return 0;
	}
        printf("Process priority after updating nice value is: %d\n",priority);
	//sleep(10000);
	return 0;
}

