#include <stdint.h>   /* Declarations of uint_32 and the like */
#include "mipslab.h"  /* Declatations for these labs */
#include "pic32mx.h"
uint8_t icon[] = {  //the screen white in top and bottom
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
};
void display_game() //updates frame
{
    display_image(0, icon);
}
char ball_x = 63;   //starting x cordinates for ball
char ball_y = 16;   //starting y cordinates for ball
void draw(char x, char y)   //written by Joel - converts array ro cordinates and draws a pixel (y+ = one step down)
{
    int byte = x + 128 * (y / 8);
    int bit = 1 << (y%8);
    icon[byte] = icon[byte] | (255 & bit);
    
}
char paddle_1_x = 1;    //starting cordinates for paddles
char paddle_1_y = 12;
char paddle_2_x = 126;
char paddle_2_y = 12;
void draw_paddle(char x, char y)    //written by Joel - draws a paddle downwords from given x,y cordinates
{
    draw(x, y);
    draw(x, y+1);
    draw(x, y+2);
    draw(x, y+3);
    draw(x, y+4);
    draw(x, y+5);
}
void erase(char x, char y)  //written by Joel - erases a pixel
{
    int byte = x + 128 * (y / 8);
    int bit = 1 << (y%8);
    icon[byte] = icon[byte] & ~bit;
}
void erase_paddle(char x, char y)   //written by - Joel erases the paddle  for givven x,y cordinates
{
    erase(x, y);
    erase(x, y+1);
    erase(x, y+2);
    erase(x, y+3);
    erase(x, y+4);
    erase(x, y+5);
}
char move_paddle_1(char d)  //writtten by Joel - moves paddle 1 one pixel based on paramiter d wich one or -one (down or up)
{
    erase_paddle(paddle_1_x, paddle_1_y);
    char next_y = paddle_1_y + d;
    if(next_y != 0 && next_y != 25)
        paddle_1_y = next_y;
    draw_paddle(paddle_1_x, paddle_1_y);
}
char move_paddle_2(char d)  //written by Joel moves paddle 2 one pixel based on paramiter d wich one or -one (down or up)
{
    erase_paddle(paddle_2_x, paddle_2_y);
    char next_y = paddle_2_y + d;
    if(next_y != 0 && next_y != 25)
        paddle_2_y = next_y;
    draw_paddle(paddle_2_x, paddle_2_y);
}
void draw_ball(char x, char y)  //written by Joel draws a ball based on given x,y cordinates
{
    draw(x, y);
    draw(x + 1, y);
    draw(x, y - 1);
    draw(x + 1, y - 1);
}

void erase_ball(char x, char y) //written by Joel - erases a ball based on given x,y cordinates
{
    erase(x, y);
    erase(x, y-1);
    erase(x+1, y);
    erase(x+1, y-1);
}
int dx = 1;     //dx represents the direction in x
int dy = 0;     //dy represents the direction in y
void move_ball()    //written by Joel - moves the ball
{
    erase_ball(ball_x, ball_y);
    char next_x = ball_x + dx;
    char next_y = ball_y + dy;
    if((icon[(next_x + 1 ) + (next_y / 8) * 128] & (1 << (next_y % 8))) == 0
    && (icon[(next_x - 1 ) + (next_y / 8) * 128] & (1 << (next_y % 8))) == 0
    && next_y > 1 && next_y < 31)   //check if next pixel is white and if next pixel is out of bound y wise
    {
        ball_x = next_x;    //updates x cordinate
        ball_y = next_y;    //updates x cordinate
    }
    else if(ball_x != 3 && ball_x != 124)   // if we hit the roof or the floor
    {
        dy = - dy;  //bounce down
    }
    else if (ball_x == 3)   //if we hit the left paddle
    {
        dx = -dx;       //bounce back
        dy = (ball_y - (paddle_1_y+2));     //change dy based on the offset between the ball. centered on the 3de pixel in the paddle and bottom left in the ball
    }
    else if (ball_x == 124)     //if we hit the right paddle
    {
        dx = -dx;       //bounce back
        dy = (ball_y - (paddle_2_y+2));     //change dy based on the offset between the ball. centered on the 3de pixel in the paddle and bottom left in the ball
    }
    draw_ball(ball_x, ball_y);      //draws ball at the new position
}
void reset()    //written by Joel - resets the game bord while keeping the scores does this by erasing and then drawing on start position
{
erase_ball(ball_x, ball_y);
erase_paddle(paddle_1_x, paddle_1_y);
erase_paddle(paddle_2_x, paddle_2_y);
paddle_1_x = 1;
paddle_1_y = 12;
paddle_2_x = 126;
paddle_2_y = 12;
draw_paddle(paddle_1_x, paddle_1_y);
draw_paddle(paddle_2_x, paddle_2_y);
ball_x = 63;
ball_y = 16;
dy = 0;
dx = -dx;
}
char p1_score = 0b10000000;     //scores to be shown on the LEDs
char p2_score = 0b00000001;
int check_for_score()       //written by Rebecca - checking if any player made a GOAL!
{
    switch (ball_x)
    {
        case 0:     //ball in the left GOAL
            PORTE |= p2_score;
            p2_score = p2_score << 1;   //light LED for woch goal
            reset();
            break;

        case 126:   //ball in the right GOAL
            PORTE |= p1_score;      //light LED for woch goal
            p1_score = p1_score >> 1;
            reset();
            break;
    }
    //if a GOAL 4 registered for a player return wich player
	if (p1_score & 0b00001000)
	{ 
        p1_score = 0b10000000;
        p2_score = 0b00000001;
        PORTE = PORTE & 0;
	    return 1;
	}
	if (p2_score & 0b00010000)
	{
        PORTE = PORTE & 0;
        p1_score = 0b10000000;
        p2_score = 0b00000001;
	    return 2;
	}

    return 0;
}
