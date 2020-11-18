#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#define size 25

int main()
{
    int fd[2];
    int rv = pipe(fd);
    pid_t cpid = fork();
    if(cpid != 0)
    {
        close(fd[0]);
        char* msg = "msg from writer process";
        int cw = write(fd[1],msg,strlen(msg));
        waitpid(cpid,NULL,0);
        exit(0);
    }
    else
    {
        close(fd[1]);
        char buff[size];
        memset(buff,'\0',size);
        fprintf(stderr,"Message send from parent: ");
        int n = read(fd[0],buff,size);
        write(1,buff,n);
    }
    
    return 0;
}