#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc,char* argv[]){


int sd;
char buff[1024];
struct sockaddr_in cliaddr,servaddr;
socklen_t clilen;
clilen=sizeof(cliaddr);

//socket

sd = socket(AF_INET,SOCK_DGRAM,0);
if(sd<0){
perror("Cannt open socket");
exit(1);
}
bzero(&servaddr,sizeof(servaddr));

//socket add structure

servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(5669);


if(bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0){
perror("Error");
exit(1);
}
printf("%s", "running bc\n");
while(1){
bzero(&buff,sizeof(buff));
if(recvfrom(sd,buff,sizeof(buff),0,(struct sockaddr*)&cliaddr,&clilen)<0){

perror("Error bc");exit(1);}

printf("Message received - %s",buff);

if(sendto(sd,buff,sizeof(buff),0,(struct sockaddr*)&cliaddr,clilen)<0){
perror("Cannt");exit(1);}
printf("Send data to UDP Client %s",buff);
}
close(sd);
return 0;

}






