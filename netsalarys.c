#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>

  main(int argc,char * argv[])
{

 int bp,hra,pt,da,epf,c;
// char msg[10],msg1[10];

 int sockfd=socket(AF_INET,SOCK_STREAM,0);

 struct sockaddr_in ser;

  ser.sin_family=AF_INET;

  ser.sin_port=htons(atoi(argv[2]));

  ser.sin_addr.s_addr=inet_addr(argv[1]);
 
  connect(sockfd,(struct sockaddr *)&ser,sizeof(ser));
 
    printf("enter Bp,hra,da,pt,epf \n");
    scanf("%d%d%d%d%d",&bp,&hra,&da,&pt,&epf);
    

   send(sockfd,(int *)&bp,sizeof(bp),0);
      send(sockfd,(int *)&hra,sizeof(hra),0);
   send(sockfd,(int *)&da,sizeof(da),0);
   send(sockfd,(int *)&pt,sizeof(pt),0);
   send(sockfd,(int *)&epf,sizeof(epf),0);
   

   recv(sockfd,(int *)&c,sizeof(c),0);

   printf("Netsalary is %d\n", c);

  close(sockfd);

 }


 
