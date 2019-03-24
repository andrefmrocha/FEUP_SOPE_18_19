#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER 512
#define READ    0
#define WRITE   1

struct numbers
{
    int first;
    int second;
};


int main(void){
    int n, fd[2];
    pid_t pid;
    pipe(fd);
    int first, second;
    char line[BUFFER];
    struct numbers num;
    if(fork() > 0){
        close(fd[READ]);
        printf("Write two numbers: \n");
        scanf("%d", &num.first);        
        scanf("%d", &num.second);
        sprintf(line, "%d", num.first);
        write(fd[WRITE], line, sizeof(line));        
        sprintf(line, "%d", num.second);
        write(fd[WRITE], line, sizeof(line));        
    }
    else{
        close(fd[WRITE]);
        n = read(fd[READ], line, BUFFER);
        first = atoi(line);
        n = read(fd[READ], line, BUFFER);
        second = atoi(line);
        int sum = first + second;
        int diff = first - second;
        double division = first/(double) second;
        int mult = first * second;
        printf("Sum: %d, Difference: %d, Division: %f, Multiplication: %d\n", sum, diff, division, mult);
    }
    
}