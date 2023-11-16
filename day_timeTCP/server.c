#include<string.h>
#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<time.h>
#include<sys/socket.h>
#include<sys/types.h>

int main(int argc,char* argv[]){

struct sockaddr_in servaddr,cliaddr;
int sd,cd;
int ch;
socklen_t len;
char str[100];
time_t tick;
sd=socket(AF_INET,SOCK_STREAM,0);

//sockfd<0 perror
if(sd<0){
perror("socket error");exit(1);}
else
printf("Socket opened");
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_port=htons(5600);
servaddr.sin_addr.s_addr=htonl(0);


//bind

if(bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0){
perror("No nio");exit(1);}
else
printf("Binded");


//listn

listen(sd,50);
for(;;){
len=sizeof(ch);
cd=accept(sd,(struct sockaddr*)&cliaddr,&len);
printf("Accepted");
tick=time(NULL);
snprintf(str,sizeof(str),"%s",ctime(&tick));
printf("%s",str);
write(cd,str,100);
}}









