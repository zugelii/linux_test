/*
 * read_fifo.c
 *
 *  Created on: Nov 20, 2018
 *      Author: cisl
 */


#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#define MYFIFO   "/tmp/myfifo"
#define MAX_BUFFER_SIZE  PIPE_BUF


int main(int argc, char *argv[])
{
	char buff[MAX_BUFFER_SIZE];
	int fd;
	int nread;

	if(access(MYFIFO, F_OK) < 0)
	{
		if((mkfifo(MYFIFO, 0666)) && (errno != EEXIST))
		{
			printf("cannot create fifo file\n");
			exit(1);
		}
	}

	fd = open(MYFIFO, O_RDONLY);
	if(fd < 0)
	{
		printf("can not open MYFIFO\n");
		exit(1);
	}
	while(1)
	{
		memset(buff, 0, MAX_BUFFER_SIZE);
		if((nread = read(fd, buff, MAX_BUFFER_SIZE)) > 0)
		{
			printf("read '%s' form FIFO\n", buff);
		}
	}
	close(fd);
	exit(0);
}
