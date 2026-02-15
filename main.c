#include <stdio.h>
#include <string.h>

struct Player {
    char name[50];
    int score;
    float health;
};

struct Player* create_player(char *name, int score) {
    struct Player *new_p = malloc(sizeof(struct Player));

    if (new_p == NULL) {
        return NULL;
    }

    strncpy(new_p->name, name, 49);
    new_p->name[49] = '\0';
    
    new_p->score = score;

    return new_p;
}


void level_up(struct Player *p) {
    p->score += 10;
    p->health = 100.0;
}

int main() {
    struct Player *p = create_player("Hero", 250);

    if (p != NULL) {
        printf("Player: %s, Score: %d\n", p->name, p->score);
        free(p); 
    }

    return 0;
}