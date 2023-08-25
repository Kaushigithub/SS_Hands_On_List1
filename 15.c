#include<stdio.h>
#include<stdlib.h>

int main()
{
	char* usr_var = getenv("USER");
	if(usr_var == NULL)
	{
		perror("Error occurred!");
	}
	else
	{
		printf("Environmental variable of the user is: %s\n",usr_var);
	}
	return 0;
}

