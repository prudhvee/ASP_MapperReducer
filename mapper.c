#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include "util.h"


void process_line(char *line);

void main(int argc, char *argv[]){
    // printf("started here with the filename %s\n", argv[1]);
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        // printf("NULL POINTER");
        exit(1);
    }
    ssize_t chars_read;
    char *line = NULL;
    size_t n = 0;
    chars_read = getline(&line, &n, fp);
    // printf("Chars read %ld", chars_read);
    while(chars_read != -1){
         // printf("%ld\n", chars_read);
         process_line(line);
         chars_read = getline(&line, &n, fp);
    }
    fclose(fp);
    printf("\n");
    return;
}


void process_line(char *line)
{
    //printf("Processing the line %s\n", line);
    char *delim = "(),";
    char* tokens = strtok(line, delim);
    int count = 0;

    char *tuple[3];
    while(tokens != NULL)
    {
        //printf("    THe tokens are       -- %s end\n", tokens);
        if(!is_empty(tokens))
        {
            tuple[count++] = tokens;
        }
        if(count == 3)
        {
            //Get the score for the action
            int score = get_score(scores, tuple[1]);
            count = 0;
            printf("(%s,%s,%d)\n", tuple[0], tuple[2], score);
        }
        tokens = strtok(NULL, delim);
    }
    return;
}