#ifndef HOGAR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#define HOGAR_H_

typedef struct
{
	int id;
	char direccion[31];

}eHogar;

eHogar* hogar_new();
eHogar* hogar_newParam(char* id, char* direccion);
int hogar_setId(eHogar* this, char* id);
int hogar_setDireccion(eHogar* this, char* direccion);

int hogar_textParser (FILE* pFile, LinkedList* pListaHogares);
int hogar_loadText(char* path, LinkedList* pListaPerrosConHogar);



#endif /* HOGAR_H_ */
