/*
 * sem_com.h
 *
 *  Created on: Nov 20, 2018
 *      Author: cisl
 */

#ifndef SEM_COM_H_
#define SEM_COM_H_
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/sem.h>
int init_sem(int sem_id, int init_value);
int del_sem(int sem_id);
int sem_p(int sem_id);
int sem_v(int sem_id);


#endif /* SEM_COM_H_ */
