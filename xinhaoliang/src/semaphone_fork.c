/*
 * semaphone_fork.c
 *
 *  Created on: Nov 20, 2018
 *      Author: cisl
 */

#include "sem_com.h"


int main(int argc, char *argv[])
{
	pid_t result;
	int sem_id;
	sem_id = semget(ftok(".", 'a'), 1, 0666 | IPC_CREAT);
	init_sem(sem_id, 0);


	result = fork();
	if(result == -1)
	{
		perror("fork");
	}else if(result == 0)
	{
		printf("child process will wait for some second...\n");
		sleep(5);
		printf("child process pid is %d\n ", getpid());
		sem_v(sem_id);
	}else
	{
		sem_p(sem_id);
		printf("father process pid is %d  the return value is %d\n", getpid(), result);
		sem_v(sem_id);
		del_sem(sem_id);
	}
	exit(0);

}

