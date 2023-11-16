#include "stdio.h"

#include "stdlib.h"
#include "string.h"
//headers for socket and related functions
#include <sys/types.h>

#include <sys/socket.h>
#include <sys/stat.h>
//for including structures which will store information needed
#include <netinet/in.h>
#include <unistd.h>
//for gethostbyname
#include "netdb.h"
#include "arpa/inet.h"
// defining constants
#define PORT 6969
#define BACKLOG 5

int main(){

//ftp

int size,sd=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in servaddr,cliaddr;
socklen_t clilen;
struct stat statVariable;
char buff[100],file[1000];
FILE *filePointer;
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=htons(PORT);

//connect

connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

while(1){
printf("File name - ");
scanf("%s",buff);
send(sd,buff,strlen(buff)+1,0);
printf("%s\n","file output - ");
recv(sd,&file,sizeof(file),0);

printf("%s",file);

}
return 0;
}

