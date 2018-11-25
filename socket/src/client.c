/*
 * client.c
 *
 *  Created on: 2018年11月25日
 *      Author: leo
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 	4321
#define BUFFER_SIZE	1024

int main(int argc, char *argv[])
{
	int sockfd, sendbytes;
	char buf[BUFFER_SIZE];
	struct hostent *host;
	struct sockaddr_in serv_addr;
	if(argc < 3)
	{
		printf("usage:./client hostname(or ip address)\n");
		exit(1);
	}
	if((host = gethostbyname(argv[1])) == NULL)
	{
		perror("gethostbyname:");
		exit(1);
	}
	memset(buf, 0, sizeof(buf));
	sprintf(buf, "%s", argv[2]);

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket:");
		exit(1);
	}
	printf("sockfd:%d\n", sockfd);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr = *((struct in_addr *)host->h_addr);
	bzero(&(serv_addr.sin_zero), 8);

	if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("client connect:");
		exit(1);
	}
	if((sendbytes = send(sockfd, buf, strlen(buf), 0)) == -1)
	{
		perror("client send:");
		exit(1);
	}
	close(sockfd);
	exit(0);
}
