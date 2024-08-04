#include <ncurses.h>

int main(){	

	int ch;

	initscr();					// Iniciar curses mode
	raw();						// Line buffering disabled
	keypad(stdscr, TRUE);		// Obtenemos F1, F2 etc..
	noecho();					// Don't echo() while we do getch

    printw("Type any character to see it in bold\n");
	ch = getch();			/* If raw() hadn't been called
					 		* we have to press enter before it
							* gets to the program 		*/


	if(ch == KEY_F(1)){				// Without keypad enabled this will not get to us either
		printw("K1 Key pressed");	// Some ugly escape charachters might have been printed on screen
	} else {
		printw("The pressed key is ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}

	
	refresh();			// Print it on to the real screen
	getch();			// Wait for user input
	endwin();			// End curses mode

	return 0;
}
