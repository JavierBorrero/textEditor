#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

// CTRL + Q
#define ctrl(x)		((x) & 0x17)
#define BACKSPACE 263
#define ESCAPE 27

typedef enum {
	NORMAL,
	INSERT,
} Mode;

Mode mode = NORMAL;

char *stringify_mode(){
	switch(mode) {
		case NORMAL:
			return "NORMAL";
			break;
		case INSERT:
			return "INSERT";
			break;
		default:
			return "NORMAL";
			break;
	}
}

int QUIT = 0;

int main(){
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	char *buf = malloc(sizeof(char) * 1024);
	size_t buf_s = 0;

	int row, col;
	getmaxyx(stdscr, row, col);

	mvprintw(row - 1, 0, stringify_mode());
	move(0,0);

	int ch = 0;

	int x, y = 0;
	
	while(ch != ctrl('q') && QUIT != 1){
		refresh();
		mvprintw(row-1, 0, stringify_mode());
		move(y, x);
		ch = getch();
		switch(mode){
			case NORMAL:
				if(ch == 'i'){
					mode = INSERT;
				}
				break;
			case INSERT: {
				//keypad(stdscr, FALSE);
				if(ch == BACKSPACE){
					getyx(stdscr, y, x);
					move(y, x - 1);
					delch();
					buf[buf_s--] = ' ';
				} else if (ch == ESCAPE){
					mode = NORMAL;
					keypad(stdscr, TRUE);
				} else {
					buf[buf_s++] = ch;
					addch(ch);
				}
				break;
			}
		}
		getyx(stdscr, y, x);
	}

	refresh();
	endwin();
	return 0;
	
}
