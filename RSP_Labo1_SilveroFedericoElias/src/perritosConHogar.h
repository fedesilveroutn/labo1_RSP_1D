#ifndef PERRITOSCONHOGAR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#define PERRITOSCONHOGAR_H_

typedef struct
{
	int id;
	char nombre[21];
	float peso;
	int edad;
	char raza[21];
	float cantidadComidaRacion;
	int idHogar;

}ePerritoConHogar;

ePerritoConHogar* perritoHogar_new();
ePerritoConHogar* perritoHogar_newParam(char* id,char* nombre,char* peso,char* edad,char* raza,char* idHogar);

int perritoHogar_setId (ePerritoConHogar* this, char* id);
int perritoHogar_setNombre(ePerritoConHogar* this, char* nombre);
int perritoHogar_setPeso (ePerritoConHogar* this, char* peso);
int perritoHogar_setEdad (ePerritoConHogar* this, char* edad);
int perritoHogar_setRaza(ePerritoConHogar* this, char* raza);
int perritoHogar_setCantidadComida (ePerritoConHogar* this, char* racion);
int perritoHogar_setIdHogar (ePerritoConHogar* this, char* idHogar);

int perritoHogar_textParser(FILE* pFile, LinkedList* pListaPerritosConHogar);
int perritoHogar_textLoad(char* path, LinkedList* pListaPerritosConHogar);

#endif /* PERRITOSCONHOGAR_H_ */
