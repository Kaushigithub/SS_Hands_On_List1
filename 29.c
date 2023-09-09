#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int pid = getpid();
	int policy;
	struct sched_param p;
	int get_scheduler_policy = sched_getscheduler(pid);
        if(get_scheduler_policy < 0)
	{
		perror("Error in getting policy.\n");
		return 0;
	}
	printf("Scheduling policy is: \n");
	switch(get_scheduler_policy)
	{
		case SCHED_FIFO:
			printf("SCHED_FIFO\n");
			break;
		case SCHED_RR:
			printf("SCHED_RR\n");
			break;
		case SCHED_OTHER:
			printf("SCHED_OTHER\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}

	printf("Current priority is: %d\n",p.sched_priority);
	policy = SCHED_FIFO;
	p.sched_priority = 56;
	int set_scheduler_policy = sched_setscheduler(pid,policy,&p); 
	if(set_scheduler_policy < 0)
	{
		perror("Error in changing the policy.\n");
		return 0;
	}
	get_scheduler_policy = sched_getscheduler(pid);
	if(get_scheduler_policy < 0)
        {
                perror("Error in getting policy.\n");
                return 0;
        }
	printf("New Scheduling policy is: \n");
        switch(get_scheduler_policy)
        {
                case SCHED_FIFO:
                        printf("SCHED_FIFO\n");
                        break;
                case SCHED_RR:
                        printf("SCHED_RR\n");
                        break;
                case SCHED_OTHER:
                        printf("SCHED_OTHER\n");
                        break;
                default:
                        printf("Unknown\n");
                        break;
        }
	printf("New priority is: %d\n",p.sched_priority);
	return 0;
}
