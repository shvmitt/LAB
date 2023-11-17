#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define MAX 100
#define BACKLOG 5	

int main(int argc, char* argv[]){
	
char serverMessage[MAX];
char clientMessage[MAX];
int sd = socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in servaddr;

servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(1999);
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

listen(sd,BACKLOG);

int clientsd=accept(sd,NULL,NULL);

while(1){
printf("\nText here - ");
scanf("%s",serverMessage);

send(clientsd,serverMessage,sizeof(serverMessage),0);

recv(clientsd,&clientMessage,sizeof(clientMessage),0);

printf("\nClient ---- %s ",clientMessage);
}
close(sd);
return 0;}

