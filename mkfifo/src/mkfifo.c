/*
 ============================================================================
 Name        : mkfifo.c
 Author      : yulu
 Version     :
 Copyright   : cis
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>

#define MYFIFO   "/tmp/myfifo"
#define MAX_BUFFER_SIZE  PIPE_BUF

int main(int argc, char *argv[])
{
	int fd = 0;
	char buff[MAX_BUFFER_SIZE];
	int nwrite;

	if(argc < 1)
	{
		printf("usage:./fifo_write string\n");
		exit(0);
	}
	memset(buff, 0, MAX_BUFFER_SIZE);
	sscanf(argv[1], "%s", buff);


	fd = open(MYFIFO, O_WRONLY);
	if(fd < 0)
	{
		perror("no fifo file\n");
		exit(1);
	}
	if((nwrite = write(fd, buff, MAX_BUFFER_SIZE)) > 0)
	{
		printf("write '%s' to FIFO\n", buff);
	}
	perror("write num");
	close(fd);
	return EXIT_SUCCESS;
}
