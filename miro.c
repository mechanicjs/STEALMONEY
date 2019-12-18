#include <stdio.h>
#include <unistd.h>
#include <termio.h>
#include <curses.h>
/*char Fgetch(){
	struct termios oldt,newt;
	char ch;
	tcgetattr(STDIN_FILENO,&oldt);
	newt=oldt;
	newt.c_lflag&=~(ICANON|ECHO);
	tcsetattr(STDIN_FILENO,TCSANOW,&newt);
	ch=getchar();
	tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
	return ch;
}*/
int main(){
	char input;
	initscr();
	clear();
	int cur_row=0;
	int cur_col=0;
	char* star="wow";
  char blank=' ';

struct termios info;
tcgetattr(0, &info);


	info.c_lflag &= ~ECHO;		/* turn off bit */

 tcsetattr(0, TCSANOW, &info);	/* set attribs */


	move(cur_row,cur_col);
	addstr(star);
	refresh();

	while((input=getch())!='q'){
		//printf("input is %d\n",input);
		if(input==27){
			getch();
			input=getch();
			switch(input){
				case 65:
				//dowm
				//printf("key is down\n");
				move(cur_row,cur_col);
					addch(blank);
					cur_row-=1;
					move(cur_row,cur_col);
					addstr(star);
          refresh();
					break;
				case 66:
				//up
				//printf("key is up\n");
				move(cur_row,cur_col);
				addch(blank);
				cur_row+=1;
				move(cur_row,cur_col);
				addstr(star);
				refresh();
					break;
				case 68: //left
					//printf("key is left\n");
					move(cur_row,cur_col);
					addch(blank);
					cur_col-=1;
					move(cur_row,cur_col);
				addstr(star);
            refresh();
						break;
				case 67: //right
				//printf("key is right\n");
				move(cur_row,cur_col);
					addch(blank);
					cur_col+=1;
				move(cur_row,cur_col);
				addstr(star);
	       refresh();
					break;
			}

		}

	}
	endwin();

	info.c_lflag |= ECHO;		/* turn on bit */
 tcsetattr(0, TCSANOW, &info);	/* set attribs */
	return 0;
}
