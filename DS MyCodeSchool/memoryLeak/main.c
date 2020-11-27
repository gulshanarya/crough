#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cash = 100;
void Play(int bet) {
    //char c[] = {'J', 'Q', 'K'};
    char *c = (char*)malloc(sizeof(char));
    c[0] = 'J';
    c[1] = 'K';
    c[2] = 'Q';
    printf("Shuffling ...\n");
    srand(time(NULL)); //seeding random number generator

    for(int i = 0; i<5; i++) {
        int x = rand()%3; //for getting 0,1&2;
        int y = rand()%3; //for getting 0,1&2;

        int temp = c[x];
        c[x] = c[y];
        c[y] = temp;
    }

    int playerGuess;
    printf("What's the position of queen 1, 2 or 3?");
    scanf("%d", &playerGuess);
    if(c[playerGuess-1] == 'Q') {
        cash += 3*bet;
        printf("You won! and result is %c%c%c Total cash: %d", c[0], c[1], c[2], cash);
    } else {
        cash -= bet;
        printf("You Loose! and result is %c%c%c Total cash: %d", c[0], c[1], c[2], cash);
    }

    free(c);
}
int main()
{
    int bet;
    while(cash>0) {

        printf("What's your bet? $");
        scanf("%d", &bet);

        if(bet == 0 || bet > cash) break;
        Play(bet);
        printf("\n***********************************************************************\n");
    }

    return 0;
}

