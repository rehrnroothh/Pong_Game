#include "mipslab.h"		//writen by Rebecca
void display_winner(char winner)	//displayes winning screen based on who won
{
    switch (winner)
    {case 1:	//player one
    display_string(1, "Player 1 WON!" );
    display_string(2, " ");
    display_string(3, "SW1 ---> Menu");
    display_update();
    break;
    case 2:	//player two
    display_string(1, "Player 2 WON!" );
    display_string(2, " ");
    display_string(3, "SW1 ---> Menu");
    display_update();
    break;  
}}