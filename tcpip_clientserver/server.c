#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
int main(int asrgc,char*argv[]){

int bd,sd,ad;
char buff[1024];
struct sockaddr_in cliaddr,servaddr;
socklen_t clilen;
clilen=sizeof(cliaddr);
bzero(&servaddr,sizeof(servaddr));

servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(1999);

//socket
sd = socket(AF_INET,SOCK_STREAM,0);

bd=bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

//listen
listen(sd,5);
printf("Server runnnnnningggg.....");

//accept
ad=accept(sd,(struct sockaddr*)&cliaddr,&clilen);


//accept message 

while(1){
bzero(&buff,sizeof(buff));
recv(ad,buff,sizeof(buff),0);
printf("Message - %s\n",buff);
}
}
