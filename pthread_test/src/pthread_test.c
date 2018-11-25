/*
 ============================================================================
 Name        : pthread_test.c
 Author      : zugelii
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>



int main(void)
{
	pid_t pc, pt;
	int delay_time = 0;
	srand(time(NULL));
	pc = fork();
	if(pc == 0)//子进程
	{
		delay_time = (int)(rand() * 10.0 /(RAND_MAX)) + 1;
		printf("1 father process:%d now process:%d wait time:%d\n", getppid(), getpid(), delay_time);
		sleep(delay_time);
		pt = fork();
		if(pt == 0)//孙子进程
		{
			delay_time = (int)(rand() * 10.0 /(RAND_MAX)) + 1;
			printf("2 father process:%d now thread:%d wait time:%d\n", getppid(), getpid(), delay_time);

			sleep(delay_time);
		}
		else
		{
			printf("pt:%d father:%d  now:%d \n", pt, getppid(), getpid());
			delay_time = (int)(rand() * 10.0 /(RAND_MAX)) + 1;
			sleep(delay_time);
			//wait();
		}
		exit(0);
	}else
	{
		printf("pc:%d  father:%d  now:%d\n", pc, getppid(), getpid());
		wait();
		printf("wait 1\n");
		//wait();
		//printf("wait 2\n");
	}



	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}























