#include <signal.h>
#include <stdio.h> 
#include <unistd.h> 

void handle(int signal){
    print("XD %d\n", signal);
}

int main(){
    signal(2, handle);
    while(1){
        print("Trabajando \n");
        sleep(1);
    }

    return 0;
}