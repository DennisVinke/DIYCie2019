#include <stdio.h>
#include <wiringPi.h>

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3
#define FIRE1 4
#define FIRE2 5

int buttons_piloc [] = {35, 36, 37, 38, 31, 32}; //Pi pin locations
int buttons [] = {24, 27, 25, 28, 22, 26}; //WiPi pin locations
//pin dir eq       ^   v   <   >   A   B

int states [] =  {0,  0,  0,  0,  0,  0 };

void scanButtons()
{

        printf("  U: %d: - %d,", buttons[UP], digitalRead(buttons[UP]));
        printf("  D: %d: - %d,", buttons[DOWN], digitalRead(buttons[DOWN]));
        printf("  L: %d: - %d,", buttons[LEFT], digitalRead(buttons[LEFT]));
        printf("  R: %d: - %d,", buttons[RIGHT], digitalRead(buttons[RIGHT]));
        printf("  1: %d: - %d,", buttons[FIRE1], digitalRead(buttons[FIRE1]));
        printf("  2: %d: - %d,", buttons[FIRE2], digitalRead(buttons[FIRE2]));

        printf("\n");
}

int main(void)
{
        printf ("Button test");

        wiringPiSetup();

        //setup inputs
        pinMode(buttons[UP], INPUT); //set input 
        pullUpDnControl(buttons[UP], PUD_UP); //set the pin to use a built-in pull up resistor

        pinMode(buttons[DOWN], INPUT);
        pullUpDnControl(buttons[DOWN], PUD_UP);

        pinMode(buttons[LEFT], INPUT);
        pullUpDnControl(buttons[LEFT], PUD_UP);

        pinMode(buttons[RIGHT], INPUT);
        pullUpDnControl(buttons[RIGHT], PUD_UP);

        pinMode(buttons[FIRE1], INPUT);
        pullUpDnControl(buttons[FIRE1], PUD_UP);

        pinMode(buttons[FIRE2], INPUT);
        pullUpDnControl(buttons[FIRE2], PUD_UP);


        for(;;)
        {
                scanButtons();
                delay(50);
        }
}