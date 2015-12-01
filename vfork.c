#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int x = 13;     //Store variable x with value 13 in stack
    pid = vfork();   //Would hold 0 for the child process and pid of child for parent, negative value of error occurs if fork unsuccessful
    if (pid < 0) {
        printf("Fork Error\n");
        exit(1);
    }
    if (pid == 0) { //Check if child process is executing this code
        printf("In child process\n");
        printf("Child pid: %u, Parent pid: %u\n", getpid(), getppid());
        x = 10;     //Modify value of x store in stack
        printf("Child's x : %d\n", x);
        printf("Child exiting\n");
        exit(0);    //Normal termination of child process
    }
    else {          //The parent process is executing this code
        printf("In parent process\n");
        printf("Parent pid: %u, Child process%u\n", getpid(), pid);
        printf("Parent sleeping for 10 seconds\n");
        sleep(10);
        printf("Parent waking up\n");
        printf("Parent's x : %d\n", x);  //Print the value of x from stack
    }


}
