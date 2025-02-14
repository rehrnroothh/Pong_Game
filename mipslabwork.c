 #include "pic32mx.h"
#include "mipslab.h" 
volatile int playing = 0;
volatile int time_out = 0;
volatile int winner = 0;
volatile int winner_displayed = 0;
volatile int won = 0;
void user_isr( void ) // written by BOTH Rebecca and Joel Interrupt Service Routine 
{
  if (IFS(0) & 0b100000000)  //timer interupt
  {
    time_out = 1; //time out to make thing happen on clock outside of isr
    if(playing == 1){
      move_ball(); //cahnge the ball in the frame
      display_game(); //uppdates frame

      winner = check_for_score(); // check if a player has reached 4 points
      if (winner !=0)
        {
          won = 1;  //if so won = 1 to prevent button presses in winning screen
          playing=0;  //stops game from running in the background
          display_winner(winner); //displayes the winner
          winner = 0; //to prevent loop
        }
    }
    IFSCLR(0) = 0b100000000;  //clear timer interupt
  }
  if(IFS(0) & 0b10000000) //switch one interupt
  {
    //add code for button interupt
        if(won == 1)    //if pulled when in winning screen exit
        {
          won = 0;
          menu();
       }
        IFSCLR(0) = 0b10000000; //clear flag
  }
  return;
}
void labinit( void )
{
  TRISECLR; //sets port E as out put
  PORTD &= 0b11110000;  //to be able to axcess switches
  PORTECLR; //set LEDs to
  TRISF &= 0x2;			//  sätt för knapp1
  T2CON = 0x0;           // clear control register
  T2CONSET = 0x60;       // set prescaler to 1:128 and start Timer 2
  TMR2 = 0x0;            // clear Timer 2 register
  PR2 = 41250;
  T2CONSET = 0x8000; //start timer
  IECSET(0) = 0x100;
  IPCSET(2) = 0x1F;   
  //activate interupt 2                   
  IECSET(0) = 0b10000000;
  IPC(1) = IPC(1) | (0b111 << 26); //priorety
  enable_interrupt();
  return;
}
void labwork( void ) //written by Rebecca
{
  int buttons;
  buttons = getbtns();
  if(playing == 0 && won == 0) //check for buttons when not in game or in winning screen (menu-mode)
  {
      switch (buttons)
      {
          case 1:
          playing = 1;
          reset();  //stat at pre selected frame
          break;
          case 4:
          menu();
          break;
          case 8:
          credits();
          break;
      }
  }
    if (playing == 1 && time_out == 1) {  //check for buttens when in game
        if (buttons & 4) 
            move_paddle_1(-1);        
        if (buttons & 2) 
            move_paddle_2(-1);
        
        if (buttons & 1) 
            move_paddle_2(1);
        
        if (buttons & 8) 
            move_paddle_1(1);
        time_out = 0;
    }
}
