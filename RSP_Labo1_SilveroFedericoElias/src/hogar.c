#include "hogar.h"

eHogar* hogar_new()
{
	eHogar* new = NULL;
	new = (eHogar*) malloc (sizeof(eHogar));
	return new;
}

eHogar* hogar_newParam(char* id, char* direccion)
{
	eHogar* new;
	new = hogar_new();
	if(id != NULL && direccion != NULL)
	{
		hogar_setId(new, id);
		hogar_setDireccion(new, direccion);
	}

	return new;
}

int hogar_setId(eHogar* this, char* id)
{
	int ret = 1;
	int auxId;
	if(this != NULL && id != NULL)
	{
		auxId = atoi(id);
		this->id = auxId;
		ret = 0;
	}
	return ret;
}

int hogar_setDireccion(eHogar* this, char* direccion)
{
	int ret = 1;
	if(this != NULL && direccion != NULL)
	{
		strcpy(this->direccion, direccion);
		ret = 0;
	}
	return ret;
}

int hogar_getId(eHogar* this)
{
	int id = -1;
	if(this != NULL)
	{
		id = this->id;
	}
	return id;
}

int hogar_getDireccion(eHogar* this, char* direccion)
{
	int ret = -1;
	if(this != NULL && direccion != NULL)
	{
		strcpy(direccion, this->direccion);
		ret = 0;
	}
	return ret;
}



int hogar_textParser (FILE* pFile, LinkedList* pListaHogares)
{
	int ret = 1;
	char auxId[31];
	char auxDireccion[31];

	if(pFile != NULL && pListaHogares != NULL)
	{
		fscanf(pFile, "%[^,], %[^\n]", auxId, auxDireccion);
		while ( !feof(pFile) )
		{
			fscanf(pFile, "%[^,], %[^\n]", auxId, auxDireccion);
			eHogar* auxHogar = hogar_newParam(auxId, auxDireccion);
			ll_add(pListaHogares, auxHogar);
		}

		ret = 0;
	}

	return ret;
}

int hogar_loadText(char* path, LinkedList* pListaPerrosConHogar)
{
	FILE* pFile;
	int ret = 1;

	if(path != NULL && pListaPerrosConHogar != NULL)
	{
		pFile = fopen (path, "r");
		if(pFile != NULL)
		{
			hogar_textParser(pFile, pListaPerrosConHogar);
			ret = 0;
		}
	}

	fclose(pFile);
	return ret;
}


int hogar_sortByDir(void* pointer1 , void* pointer2)
{
	eHogar* aux1 = (eHogar*) pointer1;
	eHogar* aux2 = (eHogar*) pointer2;
	char auxDireccion1[21];
	char auxDireccion2[21];
	int ret;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		hogar_getDireccion(aux1, auxDireccion1);
		hogar_getDireccion(aux2, auxDireccion2);
		ret = strcmp(auxDireccion1 , auxDireccion2);
	}
	aux1 = NULL;
	aux2 = NULL;
	return ret;
}







