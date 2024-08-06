#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Uso: $0 archivo.c"
	exit 1
fi

archivo=$1

if [ ! -f "$archivo" ]; then
	echo "El archivo $archivo no existe"
	exit 1
fi

gcc -o salida "$archivo" -lncurses
