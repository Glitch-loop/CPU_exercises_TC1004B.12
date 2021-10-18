#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2];
    pipe(fd); //Creamos "la tuveria o conexcion", fd[0] = input, fd[1] = output
    int pid = fork(); //Creamos otro procesos
    if(pid == 0){//Proceso hijo
        //close(0);
        dup2(1, fd[1]);
        execlp("wc","wc", "-l", NULL);
    } else {//Proceso padre
        //close(1);
        dup2(0, fd[0]); //Con esta funcion estamos intentando decir que el output de un programa sea el input del siguiente 
        execlp("ls", "ls", NULL); //
    }
    return 0;
}

/*
Este programa es muy basico, pero con este mismo esquma podemos usar coordinar programas, usando sus comandos
o comandos del propio sistema operativo

Este programa se deberia de poder ejecutar en cualquier sistema operativo con arquitectura UNIX.
Recuerda que cada sistema operativo tienen sus propias librerias, por lo que se tienen que tener cuidado
para hacer este tipo de aplicaciones.

A estos progrmas se le concen como programas orquestadores, estos son programas los cuales usan otros
programas para hacer otras cosas 


*/ 