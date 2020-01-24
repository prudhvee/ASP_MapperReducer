#include<ctype.h>

typedef struct {char *topic; int score} Topic;
typedef struct {char *action; int score; } Score;

Score scores[5] = {
    {"P", 50},
    {"L", 20},
    {"D", -10},
    {"C", 30},
    {"S", 40}
};

int is_empty(const char *s) {
  while (*s != '\0') {
    if (!isspace((unsigned char)*s))
      return 0;
    s++;
  }
  return 1;
}

int get_score(Score* scores, char *action)
{
    for(int i=0; i < 5; i++)
    {
        if(strcmp(scores[i].action, action) == 0){
            return scores[i].score;
        }
    }

    printf("Invalid Action");
    exit(1);
}

