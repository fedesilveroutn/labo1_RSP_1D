#include "perritosConHogar.h"

ePerritoConHogar* perritoHogar_new()
{
	ePerritoConHogar* new;
	new = (ePerritoConHogar*) malloc (sizeof(ePerritoConHogar));
	return new;
}

ePerritoConHogar* perritoHogar_newParam(char* id,char* nombre,char* peso,char* edad,char* raza,char* idHogar)
{
	ePerritoConHogar* new;
	new = perritoHogar_new();

	if(id != NULL && nombre != NULL && peso != NULL && edad != NULL && raza != NULL && idHogar != NULL && new != NULL )
	{
		perritoHogar_setId(new, id);
		perritoHogar_setNombre(new, nombre);
		perritoHogar_setPeso(new, peso);
		perritoHogar_setRaza(new, raza);
		perritoHogar_setEdad(new, edad);
		perritoHogar_setIdHogar(new, idHogar);
	}

	return new;
}

int perritoHogar_setId (ePerritoConHogar* this, char* id)
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

int perritoHogar_setNombre(ePerritoConHogar* this, char* nombre)
{
	int ret = 1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		ret = 0;
	}
	return ret;
}

int perritoHogar_setPeso (ePerritoConHogar* this, char* peso)
{
	int ret = 1;
	float auxPeso;
	if(this != NULL && peso != NULL)
	{
		auxPeso = atof(peso);
		this->peso = auxPeso;
		ret = 0;
	}
	return ret;
}

int perritoHogar_setEdad (ePerritoConHogar* this, char* edad)
{
	int ret = 1;
	int auxEdad;
	if(this != NULL && edad != NULL)
	{
		auxEdad = atoi(edad);
		this->edad = auxEdad;
		ret = 0;
	}
	return ret;
}

int perritoHogar_setRaza(ePerritoConHogar* this, char* raza)
{
	int ret = 1;
	if(this != NULL && raza != NULL)
	{
		strcpy(this->raza, raza);
		ret = 0;
	}
	return ret;
}

int perritoHogar_setCantidadComida (ePerritoConHogar* this, char* racion)
{
	int ret = 1;
	float auxCantidadComida;
	if(this != NULL)
	{
		auxCantidadComida = atof(racion);
		this->cantidadComidaRacion = auxCantidadComida;
		ret = 0;
	}
	return ret;
}

int perritoHogar_setIdHogar (ePerritoConHogar* this, char* idHogar)
{
	int ret = 1;
	int auxIdHogar;
	if(this != NULL && idHogar != NULL)
	{
		auxIdHogar = atoi(idHogar);
		this->idHogar = auxIdHogar;
		ret = 0;
	}
	return ret;
}

int perritoHogar_textParser(FILE* pFile, LinkedList* pListaPerritosConHogar)
{
	int ret = 1;
	char auxId[21];
	char auxNombre[21];
	char auxPeso[21];
	char auxEdad[21];
	char auxRaza[21];
	char auxIdHogar[21];

	if(pFile != NULL && pListaPerritosConHogar != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", auxId, auxNombre, auxPeso, auxEdad, auxRaza, auxIdHogar);
		while ( !feof(pFile) )
		{
			fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", auxId, auxNombre, auxPeso, auxEdad, auxRaza, auxIdHogar);
			ePerritoConHogar* auxPerritoHogar = perritoHogar_newParam(auxId, auxNombre, auxPeso, auxEdad, auxRaza, auxIdHogar);
			ll_add(pListaPerritosConHogar, auxPerritoHogar);
		}

		ret = 0;
	}

	return ret;
}

int perritoHogar_textLoad(char* path, LinkedList* pListaPerritosConHogar)
{
	FILE* pFile;
	int ret = 1;

	if(path != NULL && pListaPerritosConHogar != NULL)
	{
		pFile = fopen (path, "r");
		if(pFile != NULL)
		{
			perritoHogar_textParser(pFile, pListaPerritosConHogar);
			ret = 0;
		}
	}

	fclose(pFile);
	return ret;
}














