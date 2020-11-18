#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
#define size 25
int main()
{
    char buff[size];
    memset(buff,'\0',size);
    char * msg = "Hiiii  from alok";
    int fd[2];
    int rv = pipe(fd);
    if(rv == -1)
    {
        printf("Pipe failed");
        exit(1);
    }
    int cw = write(fd[1],msg,strlen(msg));
    int cr = read(fd[0],buff,cw);
    write(1,buff,cr);   
    printf("\n");
    return 0;
}