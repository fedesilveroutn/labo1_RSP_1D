/*
 ============================================================================
 Name        : SP_Labo1_SilveroFedericoElias.c
 Author      : Federico El?as Silvero
 Version     : 1
 Copyright   : Your copyright notice
 Description : Segundo parcial Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perritos.h"
#include "LinkedList.h"
#include "input.h"
#include "hogar.h"
#include "perritosConHogar.h"

int main(void) {
	setbuf(stdout, NULL);

	LinkedList* pListaPerros = ll_newLinkedList();
	LinkedList* pListaFiltrada = ll_newLinkedList();

	LinkedList* pListaPerrosConHogares = ll_newLinkedList();
	LinkedList* pListaHogares = ll_newLinkedList();

	int (*pFunction)(void*);
	int (*pFilterFunction)(void*);

	//PARA LEER Y GUARDAR DINAMICAMENTE EN LINKEDLIST
	perro_load("src\\perritos.csv", pListaPerros);


	//PARA LISTAR
	printf("\nORDENANDO PERROS...");
	perro_listar(pListaPerros);
	systemPause("\nPresione ENTER para continuar...");


	//PARA CALCULAR RACION
	pFunction = perro_laQueMapea;
	ll_map(pListaPerros, pFunction);


	//PARA LISTAR CON RACION
	printf("\nCALCULANDO RACION DE COMIDA...");
	perro_listarConRacion(pListaPerros);
	systemPause("\nPresione ENTER para continuar...");


	//PARA FILTRAR
	pFilterFunction = perro_laQueFiltra;
	pListaFiltrada = ll_filter(pListaPerros, pFilterFunction);
	perro_listarConRacion(pListaFiltrada);


	//PARA GUARDAR EN MODO TEXTO
	perro_guardarTexto("src\\galgosFlaquitos.csv", pListaFiltrada);


	//PARA LEER Y GUARDAR HOGARES DINAMICAMENTE EN LINKEDLIST
	hogar_loadText("src\\hogares.csv", pListaHogares);


	//PARA LEER Y GUARDAR PERROS CON HOGARES DINAMICAMENTE EN LINKEDLIST
	perritoHogar_textLoad("src\\perritosConHogar.csv", pListaPerrosConHogares);


	//PARA LISTAR PUNTO 8
	printf("\n\nORDENANDO PERROS...\n\n");
	perritoHogar_listar(pListaPerrosConHogares);


	printf("\nFIN DEL PROGRAMA.");


	return 0;
}
