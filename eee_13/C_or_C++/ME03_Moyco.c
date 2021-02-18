#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

/*
	ME03 System Calls fork() pipe()


*/
int main()
{
    pid_t mypid1;
    
    int fd[2];
    int input=-1;
    int input2 = -1;
   // int status;
    //int i =-1;
    fflush(stdout);
	if (pipe(fd)<0)	//Creation of pipes
        {
            printf("Unable to create pipes\n");
            return -1;
        }
    mypid1 = fork();	//Fork of process
    
        
    if (mypid1 > 0){
									//parent process
		
		printf("Parent: My PID = %d\n", getpid());		//Printing of Parent process id, parent's pid, and return value
		printf("Parent: My Parent's PID = %d\n", getppid());
		printf("Parent: Return Value = %d\n", mypid1);
		fflush(stdout);
		
		do							//Do while loop that lets the parent enter an integer and sends it to child process, child process then sends it back to parent if it is positive
		{
			printf("Please enter a natural number: \n");
		    scanf("%d", &input);
			fflush(stdin);
		    printf("input: %d\n", input);
		    if(isdigit(input) == 0){		//Checks if the input is an integer
				 if(input >= 0)	//If the input is a positive integer, it will send it to the child and read the int sent by the child
			    {
			    	write(fd[1],&input,sizeof(int));
				read(fd[0],&input2,sizeof(int));
		    		printf("Received %d\n", input2);
				
			    }
			    else if(input < 0)	//If it is negative, it will just continue the loop w.o sending anything to the child process
			    {
			    	continue;
			    }
		    }
		}while(input2 != 0);	
			
		    	//This part will run if the input is 0
		    	printf("Parent process ending\n");
			close(fd[1]);	//Closes the write pipe f parent	
			wait(NULL);	//Waits for the child to terminate
		}
	
	
	else if (mypid1 == 0){
										//child process
		printf("Child: My PID = %d\n", getpid());			//Printing of child process id, parent's pid, and return value
		printf("Child: My Parent's PID = %d\n", getppid());
		printf("Child: Return Value = %d\n", mypid1);
		printf("HELLO WORLD!\n");


/*
At this part of the code, the printing does not happen
		
*/



		do								//do while loop that reads first the sent int by parent, then checks if the sent int is positive or zero	
		{
			read(fd[0],&input,sizeof(int));
			if(input > 0)
			{
				printf("Sending %d to parent\n", input);
				write(fd[1],&input,sizeof(int));
			}
			else if(input == 0 )
			{
				printf("Sending %d to parent\n", input);
				write(fd[1],&input,sizeof(int));
				close(fd[0]);
				break;
			}
			
		} while(input != 0);
		//If the sent int is zero, the code will proceed here
	        printf("Child process Ending\n");
		
	    
	}
	else if (mypid1 == -1)	//Checks if the fork is successful
	{
		printf("Error in creating child process\n");
		return -1;
	}
        
        
        
        
        
        
        
        
    return 0;
}
