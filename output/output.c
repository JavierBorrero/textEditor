#include <ncurses.h>
#include <string.h>

int main(){

	char mesg[] = "Just a string";

	// Almacenar filas y columnas
	int row, col;

	initscr();

	// Obtener el numero de filas y de columnas
	getmaxyx(stdscr, row, col);

	/*
		Imprimir el mensaje en medio de la pantalla
		- Filas entre 2 (Centrado eje Y)
		- Columnas entre 2, teniendo en cuenta la longitud de la cadena (Centrado eje X)
	*/
	mvprintw(row/2, (col-strlen(mesg))/2, "%s", mesg);

	/*
		Imprimir el mensaje en la posicion:
		- Numero de filas -2
		- 0 (Pegado al borde izquierdo)
	*/
	mvprintw(row-2, 0, "This screen has %d rows and %d columns\n", row, col);
	printw("Try resizing your window and then run this program again");
	
	refresh();
	getch();
	endwin();

	return 0;
	
}
