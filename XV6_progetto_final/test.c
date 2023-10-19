#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main (int argc,char * argv[]){
    int k,n,id;
    double x =0,z,d;

    if(argc <2)
        n=1; //valore di default
    else
        n=atoi(argv[1]); 
    if(n<0 || n>20)
        n=2;
    if (argc < 3)
        d=1.0;
    else
        d=atoi(argv[2]);
    
    x=0;
    id=0;
    for(k=0; k<n;k++){
        id=fork();
        if(id<0){
            printf(1,"%d fork fallita\n",getpid());
        }else if (id >0) { //Padre
            printf(1,"Padre %d crea  il figlio  %d \n",getpid(),id);
            wait();
        }else{
           
            for(z=0;z<8000000.0;z +=d)
                x=x+3.14*89.64;
            printf(1,"sono il processo figlio %d \n",getpid());
            break;
        }
    }
    exit();
}