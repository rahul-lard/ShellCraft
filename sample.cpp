#include <iostream>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

const int INT_INPUT_SIZE = 255;

void Execute(char **strInput)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        std::cout << "failed";
    }
    else if(pid ==0)
    {
        if (execvp(*strInput, strInput) < 0)
        {
            std::cout << "wrong  command" << std::endl;
        }
        exit(0);
    }
    else 
    {
        int status;
		waitpid(pid, &status , 0);
    }
}

void GetStrToken(char *input, char **output)
{
    char *chValue = strtok(input, " ");
    int i = 0;
    while (chValue != NULL)
    {
        output[i] = chValue;
        chValue = strtok(NULL, " ");
        i++;
    }
    output[i] = NULL;
}

int main()
{

    char chInput[INT_INPUT_SIZE];
    char *arr[100];
    while (1)
    {
        std::cout << "$rahul-> ";
        std::cin.getline(chInput, INT_INPUT_SIZE);
        if (strcmp(chInput, "exit") == 0)
        {
            break;
        }
        if (strlen(chInput) == 0) 
        {
            continue; 
        }
        GetStrToken(chInput, arr);
        Execute(arr);
    }
    return 0;
}