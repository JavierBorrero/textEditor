#include <ncurses.h>

int main(){
	initscr();
	start_color();

	init_pair(1, COLOR_CYAN, COLOR_BLACK);

	printw("A big string which i didnt care to type fully ");
	mvchgat(0, 0, -1, A_BLINK, 1, NULL);

	/* 
	 * Los 2 primeros parametros: Posicion en la que empezar
	 * El tercer parametro: Numero de caracteres a actualizar. -1 significa hasta el final de la linea
	 * El cuarto parametro: Atributo que le quieras dar al caracter
	 * El quinto parametro: Indice de color. Indice dado en init_pair(). Usa 0 si no quieres color
	 * El sexto parametro: Siempre NULL 
	 */

	refresh();
	getch();
	endwin();

	return 0;
}
