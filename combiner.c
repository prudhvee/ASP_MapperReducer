#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // Input to the program in a file
    int fd[2];

    if(pipe(fd) !=0)
    {
        printf("Error in creating the pipe. Exiting");
        exit(1);
    }

    // Creating a process for the mapper
    switch (fork())
    {
    case 0:
        if(close(fd[0]) == -1)
        {
            printf("error in closing the reading end. Exit");
            exit(1);
        }
        if(dup2(fd[1], STDOUT_FILENO) == -1)
        {
            printf("Error in Duplicating the STDOUT");
            exit(1);
        }
        if(close(fd[1]) == -1)
        {
            printf("error in closing the Writing end. Exit");
            exit(1);
        }
        char *mapper_file_name = "mapper.out";
        int ret = execl(mapper_file_name, mapper_file_name, argv[1], (char *) NULL);
        break;
    case -1:
        // Error in the creation of the child
        printf("Error in creating the child for the mapper. Exiting");
        exit(1);
    
    default:
        // This should be the parent. Parent does nothing.
        break;
    }
    
    // Creating a process for the Reducer
    switch (fork())
    {
    case 0:
        // This should be the child
        // Close the writing end
        if(close(fd[1]) == -1)
        {
            printf("Error in closing the writing end for the reducer");
            exit(1);
        }

        if(dup2(fd[0], STDIN_FILENO) == -1)
        {
            printf("Error in Duplicating the STDIN");
            exit(0);
        }

        if(close(fd[0]) == -1)
        {
            printf("error in closing the reading end for reducer");
            exit(1);
        }
        char *reducer_filename = "reducer.out";
        execl(reducer_filename, reducer_filename, (char *) NULL);
        break;
    case -1:
         // Error in the creation of the child
        printf("Error in creating the child for the Reducer. Exiting");
        exit(0);
    
    default:
        // This should be the parent
        break;
    }

    for(int i=0; i < 2; i++)
    {
        if(wait(NULL) == -1)
        {
            exit(1);
        }
    }
    return 0;
}