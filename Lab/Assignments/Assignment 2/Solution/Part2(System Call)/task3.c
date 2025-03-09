#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int processCount=0, totalProcessCount=0;

int createProcess(){
	pid_t processId;
	processId = fork();
	processCount++;
	
	//Child process
	if (processId==0){
		//Checking pid odd or not
		if (getpid()%2!=0){
			createProcess();
			processCount++;
		}
		
	}
	//Parent Process
	else{

		wait(NULL);
        exit(0);
	}

	return processCount;
}

int main(){
	
	int a,b,c;
	a = createProcess();
	b = createProcess();
	c = createProcess();
	
	//Counting the total process
	totalProcessCount += a+b+c-3;
	
	printf("Total number of processes : %d\n", totalProcessCount);
}
