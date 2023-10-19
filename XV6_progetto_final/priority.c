#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main (int argc,char * argv[]){
    int priority, pid;

    if(argc < 3){
        printf(2,"Devi indicare il pid e la priorità\n");
        exit();
    }
    pid=atoi(argv[1]);
    priority=atoi(argv[2]);

    if(priority <0 || priority > 20){
        printf(2,"Priorità invalida\n");
        exit();
    }

    printf(1,"Setto al processo con pid=%d, la priority=%d\n",pid,priority);
    chpr(pid,priority);
    exit();
}