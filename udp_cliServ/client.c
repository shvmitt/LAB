#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>

int main(int argc,char*argv[]){

int sd;
char buff[1024];
struct sockaddr_in servaddr;
socklen_t len;
len=sizeof(servaddr);

//socket

sd=socket(AF_INET,SOCK_DGRAM,0);
if(sd<0){
perror("socket error");exit(1);}
bzero(&servaddr,len);

//socket struct

servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(5669);

while(1){

printf("Enter input --- \n");
bzero(&buff,sizeof(buff));

//reads data
fgets(buff,sizeof(buff),stdin);

//send to
if (sendto(sd, buff, sizeof(buff), 0,(struct sockaddr*)&servaddr,len) < 0) {

perror("Cnnnnnt");exit(1);}

printf("Data sent is %s ",buff);
bzero(buff,sizeof(buff));


//receiving the echoed message from server

if(recv(sd,buff,sizeof(buff),0)<0){
perror("ahain");exit(1);}
printf("Received data from server is %s ",buff);}
close(sd);
return 0;}




