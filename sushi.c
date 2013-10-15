#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 100

char *getstr(void);

int main(void)
{
    char *command;
    char exit_command[] = "exit\n";

    while (strcmp(command, exit_command) != 0) {
        command = getstr();
        if (command[0] != '\n') { 
            /* don't print if user entered nothing */
            write(1, command, MAX_LEN);
        }
    }

    return 0;
}

char *getstr(void) {
    char *command = (char *) calloc(MAX_LEN, sizeof(char));
    char *prompt = "sushi> ";
    int n;

    write(1, prompt, strlen(prompt));
    n = read(0, command, MAX_LEN);
    command[n] = '\0';

    return command;
}
