#include <stdio.h>
#include <unistd.h>

int main(){
    int pid = fork();//En esta linea se crea el hijo

    //El proceso hijo se ejecutaria desde la linea 7
    if(pid == 0){//Es proceso hijo
        //fork(); //Con este fork nosotros podemos hacer un ataque llamada "bomba fork".
        printf("Soy el proceso hijo\n");
    }else{//Es el proceso padre
        printf("Soy el padre y mi hijo es %d\n", pid);
        //Si aqui pusieramos un exec(), se ejecutaria el programa que quisieramos.
    }
    return 0;
}