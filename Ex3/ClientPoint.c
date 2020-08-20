#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
int main()
{
	int i, sd, n, port;
	char sendmsg[100], recvmsg[100];
	struct sockaddr_in servaddr;
	printf("Enter the client port no\n");
	scanf("%d", &port);
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd < 0)
		printf("Can't Create\n");
	else
		printf("Socket is created\n");
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);
	if (connect(sd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
		printf("can't connect\n");
	else
		printf("Connected\n");
	printf("Enter the no of Frames\n");
	scanf("%d", &n);
	printf("\nAll the Frames \n");
	for (i = 0; i <= n; i++)
		printf("Frame %d\n", i);
	recv(sd, recvmsg, 20, 0);
	printf("\nLost Frame %s is retransmitted\n", recvmsg);
	strcpy(sendmsg, recvmsg);
	send(sd, sendmsg, 20, 0);
	return 0;
}