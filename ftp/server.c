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
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(PORT);


//bind

bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

//listen

listen(sd,BACKLOG);
printf("Sever is running//....");


//accept
int cd=accept(sd,(struct sockaddr*)&cliaddr,&clilen);

while(1){
bzero(buff,sizeof(buff));
bzero(file,sizeof(file));

recv(cd,buff,sizeof(buff),0);
filePointer=fopen(buff,"r");
stat(buff,&statVariable);
size=statVariable.st_size;
fread(file,sizeof(file),1,filePointer);
send(cd,file,sizeof(file),0);
}
return 0;
}











