#include <ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[]){

	WINDOW *my_win;
	int startx, starty, width, height;
	int ch;

	initscr();
	cbreak(); /* Line buffering disable */
	keypad(stdscr, TRUE);

	height = 3;
	width = 10;
	starty = (LINES - height) / 2; /* Center placement of the window */
	startx = (COLS - width) / 2;   /* Center placement of the window */
	printw("Press F1 to leave");
	refresh();
	my_win = create_newwin(height, width, starty, startx);

	while((ch = getch()) != KEY_F(1)){
		switch(ch){
			case KEY_LEFT:
				destroy_win(my_win);
				my_win = create_newwin(height, width, starty, --startx);
				break;
			case KEY_RIGHT:
				destroy_win(my_win);
				my_win = create_newwin(height, width, starty, ++startx);
				break;
			case KEY_UP:
				destroy_win(my_win);
				my_win = create_newwin(height, width, --starty, startx);
				break;
			case KEY_DOWN:
				destroy_win(my_win);
				my_win = create_newwin(height, width, ++starty, startx);
				break;
		}
	}

	endwin();
	return 0;
	
}

WINDOW *create_newwin(int height, int width, int starty, int startx){
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);

	wrefresh(local_win);
	
	return local_win;
}

void destroy_win(WINDOW *local_win){
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	/*
	 * PARAMETROS:
	 * 1. window: ventana en la que operar
	 * 2. left side: caracter usado para el borde izquierdo de la ventana
	 * 3. right side: caracter usado para el borde derecho de la ventana
	 * 4. top side: caracter usado para el borde superior de la ventana
	 * 5. bottom side: caracter usado para el borde inferior de la ventana
	 * 6. top left: caracter usado para la esquina superior izquierda de la ventana
	 * 7. top right: caracter usado para la esquina superior derecha de la ventana
	 * 8. bottom left: caracter usado para la esquina inferior izquierda de la ventana
	 * 9. bottom right: caracter usado para la esquina inferior derecha de la ventana
	 */
	 wrefresh(local_win);
	 delwin(local_win);
}
