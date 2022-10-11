
/**
 * Assignment 2: Simple UNIX Shell
 * @file pcbtable.h
 * @author Edgar Del Valle and Ragir Zebari
 * @brief This is the main function of a simple UNIX Shell. You may add additional functions in this file for your implementation
 * @version 0.1
 */
// Remember to add sufficient and clear comments to your code

#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

#define MAX_LINE 80 // The maximum length command

/**
 * @brief parse out the command and arguments from the input command separated by spaces
 *
 * @param command
 * @param args
 * @return int
 */
int parse_command(char command[], char *args[])
{
    // TODO: implement this function
    char *token = strtok(command, " \n");
    int number_of_tokens = 0;

    while (token)
    {
        args[number_of_tokens] = strdup(token);
        token = strtok(NULL, " \n");
        number_of_tokens += 1;
    }
    args[number_of_tokens] = NULL;
    return number_of_tokens;
}
/*void processLess(char *args[]) {
    args[num_args - 2] = NULL; //set the < to NULL so the command can be run
    int inside = open(args[num_args-1], O_RDONLY);
    dup2(inside, STDIN_FILENO);
    close(inside);
} */

/**
 * @brief The main function of a simple UNIX Shell. You may add additional functions in this file for your implementation
 * @param argc The number of arguments
 * @param argv The array of arguments
 * @return The exit status of the program
 */
int main(int argc, char *argv[])
{
    char command[MAX_LINE];       // the command that was entered
    char *args[MAX_LINE / 2 + 1]; // parsed out command line arguments
    int should_run = 1;           /* flag to determine when to exit program */

    char previous_command[MAX_LINE];
    bool prev_command_exists = false;
    bool run_concurrently = false;

    while (should_run)
    {
        printf("osh>");
        fflush(stdout);
        // Read the input command
        fgets(command, MAX_LINE, stdin);

        if (strncmp(command, "!!", 2) == 0)
        {
            // TODO: Need to check if there are no previous commands
            if (!prev_command_exists)
            {
                cout << "No command history found." << endl;
            }
            else
            {
                copy(begin(previous_command), end(previous_command), begin(command));
                cout << command;
            }
        }
        else
        {
            prev_command_exists = true;
            copy(begin(command), end(command), begin(previous_command));
        }

        // Parse the input command
        int num_args = parse_command(command, args);

        if (args[num_args - 1] == string("&"))
        {
            args[num_args - 1] = NULL; // set the & to NULL so the command can be executed
            run_concurrently = true;
        }
        else
        {
            run_concurrently = false;
        }
        if (args[num_args - 2] == string("<"))
        {
            args[num_args - 2] = NULL; // set the < to NULL so the command can be executed
            run_concurrently = true;
            int in = open(args[num_args - 1], O_RDONLY);
            dup2(in, STDIN_FILENO);
            close(in);
        }
        else
        {
            run_concurrently = false;
        }
        if (args[num_args - 2] == string(">"))
        {
            args[num_args - 2] = NULL; // set the > to NULL so the command can be executed
            run_concurrently = true;
            int out = open(args[num_args - 1], O_WRONLY);
            dup2(out, STDOUT_FILENO);
            close(out);
        }
        else
        {
            run_concurrently = false;
        }

        // TODO: Add your code for the implementation
        /**
         * After reading user input, the steps are:
         * (1) fork a child process using fork()
         * (2) the child process will invoke execvp()
         * (3) parent will invoke wait() unless command included &
         */

        if (strncmp(command, "exit", 4) == 0)
        {
            should_run = 0;
            exit(0);
        }

        int rc = fork();
        if (rc < 0)
        {
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if (rc == 0)
        {
            // TODO: Need to add error handling for incorrect commands
            execvp(args[0], args);
        }
        else
        {
            if (run_concurrently == false)
            {
                wait(NULL);
            }
        }
    }
    return 0;
}