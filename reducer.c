#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"

#define MAX 30

int update_topic(Topic **topics, char *topic, int score, int length)
{
    for(int i = 0; i < length; i++)
    {
        if(strcmp(topics[i]->topic, topic) == 0)
        {
            topics[i]->score = topics[i]->score + score;
            return length;
        }
    }
    Topic *top = malloc(sizeof(Topic));
    top->topic = malloc(sizeof(topic));
    strcpy(top->topic, topic);
    top->score = score;
    topics[length++] = top;

    return length;
}

int main(int argc, char *argv[])
{
    // Read each tuple from the stdin
    char buf[MAX];
    char *prev_user_id = NULL;
    Topic *topics[50];
    int count = 0;
    char *delim = "(),";

    while(fgets(buf, MAX, stdin) != NULL)
    {
        // (2222,sports,60)
        // printf("Got the line from the buffer %s\n", buf);
        if(strcmp("\n", buf) == 0)
        {
            break;
        }
        char *user_id = strtok(buf, delim);
        char *topic = strtok(NULL, delim);
        int score = atoi(strtok(NULL, delim));

        if(prev_user_id == NULL)
        {
            prev_user_id = malloc(sizeof(user_id));
            strcpy(prev_user_id, user_id);

            Topic *top = malloc(sizeof(Topic));
            top->topic = malloc(sizeof(topic));
            strcpy(top->topic, topic);

            top->score = score;

            topics[count++] = top;
        }
        else if(strcmp(prev_user_id, user_id) == 0)
        {
            // Check for the topic and update the score
            count = update_topic(&topics, topic, score, count);
        }
        else
        {
            for(int i=0; i < count; i++)
            {
                printf("(%s,%s,%d)\n", prev_user_id, topics[i]->topic, topics[i]->score);
                free(topics[i]);
            }
            prev_user_id = strcpy(prev_user_id, user_id);
            count = 0;
            // Now that the user is changed, create a new Topic struct and re-initialize the count
            Topic *top = malloc(sizeof(Topic));
            top->topic = malloc(sizeof(topic));
            strcpy(top->topic, topic);

            top->score = score;
            topics[count++] = top;
        }
        
    }
    for(int i=0; i < count; i++)
    {
        printf("(%s,%s,%d)\n", prev_user_id, topics[i]->topic, topics[i]->score);
        free(topics[i]);
    }
    return 0;
}