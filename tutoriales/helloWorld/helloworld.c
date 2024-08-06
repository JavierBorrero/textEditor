#include <ncurses.h>

int main()
{	
	initscr(); 					// Iniciar curses mode
	printw("Hello World !!!");	// Escribir hola mundo
	refresh();					// Escribirlo en la pantalla real
	getch();					// Esperar a un input del usuario
	endwin();					// Fin  curses mode

	return 0;
}
