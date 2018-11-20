/*
 ============================================================================
 Name        : xinhaoliang.c
 Author      : yulu
 Version     :
 Copyright   : cis
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "sem_com.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/sem.h>
union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};

int init_sem(int sem_id, int init_value)
{
	union semun sem_union;
	struct semid_ds mysemds;
	unsigned short a;
	sem_union.buf = &mysemds;
	//sem_union.array = &a;
	sem_union.val = init_value;
	if(semctl(sem_id, 0, SETVAL, sem_union) == -1)
	{
		perror("initialize semphore");
		return -1;
	}
	return 0;
}

int del_sem(int sem_id)
{
	union semun sem_union;
	struct semid_ds mysemds;
	unsigned short a;
	//sem_union.array = &a;
	//sem_union.buf = &mysemds;
	if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
	{
		perror("delete semaphore");
		return -1;
	}
	return 0;
}

int sem_p(int sem_id)
{
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op  = -1;
	sem_b.sem_flg = SEM_UNDO;
	if(semop(sem_id, &sem_b, 1) == -1)
	{
		perror("P operation");
		return -1;
	}
	return 0;
}

int sem_v(int sem_id)
{
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = 1;
	sem_b.sem_flg = SEM_UNDO;
	if(semop(sem_id, &sem_b, 1) == -1)
	{
		perror("V operation");
		return -1;
	}
	return 0;
}
