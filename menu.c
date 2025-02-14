#include "mipslab.h" //writen by Rebecca
void menu()	//displayes menu screen
{
	display_string(1, "MENU");
	display_string(2, "BTN1 -> PONG");
	display_string(3, "BTN4 -> credits");
	display_update();
}