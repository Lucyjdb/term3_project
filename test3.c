#include <ncurses.h>
#include <locale.h>
#include <unistd.h>

int main(int argc, char *argv[])
{	
    setlocale(LC_ALL, "");
	int startx, starty, width, height;
	int ch;
    int direction = 0;
    int DELAY = 90;
    int move = 0;
    int loop = 1;
    int counter = 50000000;
    int b_mover = 0;
    int deaths = 0;
	initscr();		
	cbreak();			
	nodelay(stdscr, TRUE);		
	keypad(stdscr, TRUE);
    int shoot = 0;
	height = -20;
	width = 60;
    int heightb = 3;
    int widthb = 10;
    int height_2 = 20;
    int width_2 = -60;
    int shoot_speed = 0;
    int shoot_delay = 0;
    int shoot_active = 0;
    int shoot_direction;

	starty = ((LINES - height) / 2);
	startx = ((COLS - width) / 2);
    
    int starty_2 = ((LINES - height_2)/2);
    int startx_2 = ((LINES - width_2)/2);

    int Bstarty = ((LINES - heightb)/2);
    int Bstartx = (COLS - widthb)/2;
    int x_dif;
    int y_dif;
    int x2_dif;
    int y2_dif;
	printw("Press F1 to exit");
	refresh();
	

	while(loop != 0)
	{	

        timeout(DELAY);
        
        counter -=1;
        ch = getch();
        if (ch == 10) // if enter is pressed
        {
            if(shoot_delay == 0){
            shoot_delay = 100;
            shoot = 1;
            }
            else{}
        }

		if( ch == KEY_LEFT){
                direction -=1;
    
        }
				
				
		if (ch == KEY_RIGHT){
                direction +=1;
        }

		if (ch == KEY_UP){
                move = 1;
        }
            
        if (ch == KEY_DOWN){
                move = 0;
                
        }
            
        if (ch == KEY_F(1)){
            loop = 0;
            break;
        }

        
        else{}
        
        if (ch == -1){}


        if (direction > 7){
            direction -= 8;
        }
        if(direction < 0){direction += 8;}
        else{}

        b_mover+= 1;
        if (b_mover > 5){
            

            if( ( ((x_dif)*(x_dif)) > (y_dif)*(y_dif))){
                if(x_dif < 0 ){startx -=1;}
                if(x_dif > 0){startx+=1;}
                else{}
                if(shoot_active == 1){
                if(y2_dif != 0){
                    if(y2_dif < 0 ){starty_2 -=1;}
                    if(y2_dif > 0){starty_2+=1;}
                }
                if(x2_dif != 0){
                    if(x2_dif < 0 ){startx_2 -=1;}
                    if(x2_dif > 0){startx_2+=1;}
                }
                else{}
                }
                else{}
                b_mover = 0;
            }
        }
    if (b_mover > 5){
            if(((y_dif)*(y_dif)) > ((x_dif)*(x_dif))){
                if(y_dif < 0){starty-= 1;}
                if(y_dif > 0){starty +=1;}
                else{}
                if(shoot_active == 1){
                 if(y2_dif != 0){
                    if(y2_dif < 0 ){starty_2 -=1;}
                    if(y2_dif > 0){starty_2+=1;}
                }
                if(x2_dif != 0){
                    if(x2_dif < 0 ){startx_2 -=1;}
                    if(x2_dif > 0){startx_2+=1;}
                }
                else{}
                }
                else{}
                b_mover = 0;
            }
}
if (b_mover > 5){
            if(((y_dif)*(y_dif)) == ((x_dif)*(x_dif))){
                if(x_dif < 0 && y_dif < 0){startx-=1;starty-=1;}
                if(x_dif < 0 && y_dif > 0 ){startx-=1;starty+=1;}
                if(x_dif > 0 && y_dif > 0){startx+=1;starty+=1;}
                if(x_dif > 0 && y_dif < 0 ){startx+=1;starty-=1;}
                
                else{}
                if(shoot_active == 1){
                 if(y2_dif != 0){
                    if(y2_dif < 0 ){starty_2 -=1;}
                    if(y2_dif > 0){starty_2+=1;}
                }
                if(x2_dif != 0){
                    if(x2_dif < 0 ){startx_2 -=1;}
                    if(x2_dif > 0){startx_2+=1;}
                }
                else{}
                }
                else{}
                b_mover = 0;

            }
            else{}
                 }



        
else{}
if(shoot == 1){
            shoot_active = 1;
            startx_2 = startx;
            starty_2 = starty;
            shoot = 0;
            shoot_direction = direction;
            if (move== 1){
                shoot_speed = 1;
            }
            else{shoot_speed = 0;}
            }

            else{}
        if (direction == 0){
            clear();
            if (move == 1){
                startx +=1;
                
            }
            
        
            else{}
            move(starty,startx);
            printw(">");
            
        }

        if (direction ==1)
        {
            clear();
            if (move == 1){
                startx +=1;
                starty +=1;
                
            }
            else{}
            move(starty,startx);
            printw("┘");
        }


        if (direction ==2)
        {
            clear();
            if (move == 1){
                starty +=1;
                
            }
            else{}
            move(starty,startx);
            printw("v");
        }
        if (direction ==3)
        {
            clear();
            if (move == 1){
                startx -=1;
                starty +=1;
                
            }
            else{}
            move(starty,startx);
            printw("└");
        }

        if (direction ==4)
        {
            clear();
            if (move == 1){
                startx -=1;
                
            }
            else{}
            move(starty,startx);
            printw("<");
        }
        if (direction ==5)
        {
            clear();
            if (move == 1){
                startx -=1;
                starty -=1;
                
            }
            else{}
            move(starty,startx);
            printw("┌");
        }
        if (direction ==6)
        {
            clear();
            if (move == 1){
                starty -=1;
                
            }
            else{}
            move(starty,startx);
           printw("^");
        }
        if (direction ==7)
        {
            clear();
            if (move == 1){
                startx +=1;
                starty -=1;
                
            }
            else{}
            move(starty,startx);
            printw("┐");

        }

        




        if(shoot_active == 1){

        if (shoot_direction == 0){
            
                startx_2 +=1;
            
            if(shoot_speed == 1){
                startx_2 +=1;
            }
        else{}
            
        
            move(starty_2,startx_2);
            printw("o");
            
        }

        if (shoot_direction ==1)
        {
            
        
                startx_2 +=1;
                starty_2 +=1;
                if(shoot_speed == 1){
                    startx_2+=1;
                    starty_2+=1;
            }
        else{}
            move(starty_2,startx_2);
            printw("o");
        }


        if (shoot_direction ==2)
        {
            
            
                starty_2 +=1;
                if(shoot_speed == 1){
                starty_2 +=1;
            }
        else{}
            
        
            move(starty_2,startx_2);
            printw("o");
        }
        if (shoot_direction ==3)
        {
            
           
                startx_2 -=1;
                starty_2 +=1;
          if(shoot_speed == 1){
                startx_2 -=1;
                starty_2 +=1;
            }
        else{}
            move(starty_2,startx_2);
            printw("o");
        }

        if (shoot_direction ==4)
        {
          
                startx_2 -=1;
                if(shoot_speed == 1){
                startx_2 -=1;
            }
        else{}
           
            move(starty_2,startx_2);
            printw("o");
        }
        if (shoot_direction ==5)
        {
            
                startx_2 -=1;
                starty_2 -=1;
                if(shoot_speed == 1){
                startx_2 -=1;
                starty_2 -=1;
            }
        else{}
       
            move(starty_2,startx_2);
            printw("o");
        }
        if (shoot_direction ==6)
        {
         
         
                starty_2 -=1;
                if(shoot_speed == 1){
                starty_2 -=1;
            }
        else{}
          
            move(starty_2,startx_2);
           printw("o");
        }
        if (shoot_direction ==7)
        {
  
          
                startx_2 +=1;
                starty_2 -=1;
                
           if(shoot_speed == 1){
                startx_2 +=1;
                starty_2 -=1;

            }
        else{}
            move(starty_2,startx_2);
            printw("o");

        }

        }





    







        x_dif = Bstartx - startx;
        y_dif = Bstarty - starty;

        if(shoot_active == 1){
            x2_dif = Bstartx - startx_2;
            y2_dif = Bstarty - starty_2;
        }
        move(0,0);
        printw("Direction is: %d Move is: %d",direction, move);
        move(1,0);
        printw("Start x is %d and start y is %d Line is %d, Col is: %d", startx, starty, LINES, COLS);
        
        move(Bstarty,Bstartx);
        printw("@");
        move(2,0);
        printw("x_dif is: %d y_dif is: %d B mover is: %d x2_dif is: %d y2_dif is: %d", x_dif, y_dif, b_mover, x2_dif, y2_dif);
        move(3,0);
        printw("shoot_delay is: %d shoot_active is: %d shoot is: %d shoot speed is: %d", shoot_delay, shoot_active, shoot, shoot_speed);
        move(4,0);
        printw("%d", ch);
        move(5,0);
        printw("You have died %d time(s)",deaths);


        if (starty > LINES){
            starty -= LINES;
        }
        if (starty < 0){
            starty += LINES;
        }
        else{}
        if (startx > COLS){startx -=COLS;}
        if (startx < 0){startx += COLS;}
        else{}

if (starty_2 > LINES){
            starty_2 -= LINES;
        }
        if (starty_2 < 0){
            starty_2 += LINES;
        }
        else{}
        if (startx_2 > COLS){startx_2 -=COLS;}
        if (startx_2 < 0){startx_2 += COLS;}
        else{}

        if (x_dif == 0 && y_dif == 0)
        {
            move(Bstarty+1, Bstartx);
            printw("|");
            move(Bstarty-1, Bstartx);
            printw("|");
            move(Bstarty, Bstartx+1);
            printw("-");
            move(Bstarty, Bstartx-1);
            printw("-");
            move(Bstarty, Bstartx+2);
            printw("-");
            move(Bstarty, Bstartx-2);
            printw("-");
            move(Bstarty+1, Bstartx+1);
            printw("\\");
            move(Bstarty-1, Bstartx+1);
            printw("/");
            move(Bstarty+1, Bstartx-1);
            printw("/");
            move(Bstarty-1, Bstartx-1);
            printw("\\");
            


            move(Bstarty+2, Bstartx);
            printw("|");
            move(Bstarty-2, Bstartx);
            printw("|");
            move(Bstarty, Bstartx+2);
            printw("-");
            move(Bstarty, Bstartx-2);
            printw("-");
            move(Bstarty, Bstartx+4);
            printw("-");
            move(Bstarty, Bstartx-4);
            printw("-");
            move(Bstarty+2, Bstartx+2);
            printw("\\");
            move(Bstarty-2, Bstartx+2);
            printw("/");
            move(Bstarty+2, Bstartx-2);
            printw("/");
            move(Bstarty-2, Bstartx-2);
            printw("\\");


            
            

            move(0,0);

            timeout(10000);
            starty = ((LINES - height) / 2);
	        startx = ((COLS - width) / 2);	
            deaths +=1;
            
        }

if(shoot_active == 1){
if (x2_dif == 0 && y2_dif == 0)
        {
            move(Bstarty+1, Bstartx);
            printw("|");
            move(Bstarty-1, Bstartx);
            printw("|");
            move(Bstarty, Bstartx+1);
            printw("-");
            move(Bstarty, Bstartx-1);
            printw("-");
            move(Bstarty, Bstartx+2);
            printw("-");
            move(Bstarty, Bstartx-2);
            printw("-");
            move(Bstarty+1, Bstartx+1);
            printw("\\");
            move(Bstarty-1, Bstartx+1);
            printw("/");
            move(Bstarty+1, Bstartx-1);
            printw("/");
            move(Bstarty-1, Bstartx-1);
            printw("\\");
            


            move(Bstarty+2, Bstartx);
            printw("|");
            move(Bstarty-2, Bstartx);
            printw("|");
            move(Bstarty, Bstartx+2);
            printw("-");
            move(Bstarty, Bstartx-2);
            printw("-");
            move(Bstarty, Bstartx+4);
            printw("-");
            move(Bstarty, Bstartx-4);
            printw("-");
            move(Bstarty+2, Bstartx+2);
            printw("\\");
            move(Bstarty-2, Bstartx+2);
            printw("/");
            move(Bstarty+2, Bstartx-2);
            printw("/");
            move(Bstarty-2, Bstartx-2);
            printw("\\");


            shoot_active = 0;
            x2_dif = 0;
            y2_dif = 0;

            move(0,0);

            timeout(10000);
        }
        else{}
}
else{}


        if(startx_2 == startx && starty_2 == starty){
            move(starty_2+1, startx_2);
            printw("|");
            move(starty_2-1, startx_2);
            printw("|");
            move(starty, startx+1);
            printw("-");
            move(starty, startx-1);
            printw("-");
            move(starty, startx+2);
            printw("-");
            move(starty, startx-2);
            printw("-");
            move(starty+1, startx+1);
            printw("\\");
            move(starty-1, startx+1);
            printw("/");
            move(starty+1, startx-1);
            printw("/");
            move(starty-1, startx-1);
            printw("\\");
            


            move(starty+2, startx);
            printw("|");
            move(starty-2, startx);
            printw("|");
            move(starty, startx+2);
            printw("-");
            move(starty, startx-2);
            printw("-");
            move(starty, startx+4);
            printw("-");
            move(starty, startx-4);
            printw("-");
            move(starty+2, startx+2);
            printw("\\");
            move(starty-2, startx+2);
            printw("/");
            move(starty+2, startx-2);
            printw("/");
            move(starty-2, startx-2);
            printw("\\");

move(0,0);

            timeout(10000);
            starty = ((LINES - height) / 2);
	        startx = ((COLS - width) / 2);	
            deaths +=1;

        }


        else{refresh();}
        if(shoot_delay > 0){
            shoot_delay -= 1;
        }
        else{shoot = 0; shoot_active = 0; shoot_speed = 0;}
	}
		
	endwin();
	return 0;
}



