#include <stdio.h>
#include <ncurses.h>

#define BACKSPACE 263
#define ctrl(x) ((x) & 0x1f)

typedef enum {
	NORMAL,
	INSERT,
	
} Mode;

Mode mode = NORMAL;

char *stringify_mode() {
	switch(mode){
		case NORMAL:
			return "NORMAL";
			break;
		case INSERT:
			return "INSERT";
			break;
	}
	return "NORMAL";
}

int main(){
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	int row, col;
	getmaxyx(stdscr, row, col);

	mvprintw(row-1, 0, stringify_mode());
	move(0,0);

	int ch;

	int x, y = 0;
	getyx(stdscr, y, x);
	while(ch != ctrl('q')){
		mvprintw(row-1, 0, stringify_mode());
		move(y, x);
		ch = getch();
		switch(mode){
			case NORMAL:
				if(ch == 'i'){
					mode = INSERT;
				}
				break;
			case INSERT:
				keypad(stdscr, FALSE);
				if(ch == BACKSPACE){
					getyx(stdscr, y, x);
					if(x == 0 && y > 0){
						move(y - 1, col - 1);
						int prev_x = col - 1;
						int prev_y = y - 1;
						while (prev_x > 0 && (mvinch(prev_y, prev_x) == ' ' || mvinch(prev_y, prev_x) == '\0')) {
							prev_x--;
						}
						if(prev_x == 0 && (mvinch(prev_y, prev_x) == ' ' || mvinch(prev_y, prev_x) == '\0')){
							move(prev_y, prev_x);
						} else {
							move(prev_y, prev_x + 1);
						}
					} else if (x > 0){
						move(y, x-1);
						delch();
					}
				} else if (ch == 27){
					mode = NORMAL;
					keypad(stdscr, TRUE);
				} else {
					addch(ch);
				}
				break;
		}
		getyx(stdscr, y, x);
	}


	refresh();
	endwin();
	return 0;
}
