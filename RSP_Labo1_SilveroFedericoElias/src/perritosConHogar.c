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

int perritoHogar_getId(ePerritoConHogar* this)
{
	int id = -1;
	if(this != NULL)
	{
		id = this->id;
	}
	return id;
}

int perritoHogar_getNombre(ePerritoConHogar* this, char* nombre)
{
	int ret = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		ret = 0;
	}
	return ret;
}

float perritoHogar_getPeso(ePerritoConHogar* this)
{
	float peso = -1;
	if(this != NULL)
	{
		peso = this->peso;
	}
	return peso;
}

int perritoHogar_getEdad(ePerritoConHogar* this)
{
	int edad = -1;
	if(this != NULL)
	{
		edad = this->edad;
	}
	return edad;
}

int perritoHogar_getRaza(ePerritoConHogar* this, char* raza)
{
	int ret = -1;
	if(this != NULL && raza != NULL)
	{
		strcpy(raza, this->raza);
		ret = 0;
	}
	return ret;
}

int perritoHogar_getIdHogar(ePerritoConHogar* this)
{
	int idHogar = -1;

	if(this != NULL)
	{
		idHogar = this->idHogar;
	}

	return idHogar;
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

int perritoHogar_listar(LinkedList* pListaPerritoHogar)
{
	ePerritoConHogar* auxPerrito;
	int ret = 1;

	int len;
	int i;

	int auxId;
	char auxNombre[21];
	float auxPeso;
	int auxEdad;
	char auxRaza[21];
	int auxIdHogar;

	int retNombre;
	int retRaza;

	int (*pFuncionOrdenarDireccion) (void*, void*);
	pFuncionOrdenarDireccion = hogar_sortByDir;
	ll_sort(pListaPerritoHogar, pFuncionOrdenarDireccion, 0);

	if(pListaPerritoHogar != NULL)
	{
		len = ll_len(pListaPerritoHogar);
		printf("\n%-5s %-16s %-10s %-10s %-10s %-10s\n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA", "DIRECCION");
		for( i = 0; i < len+1 ; i++)
		{
			auxPerrito = (ePerritoConHogar*) ll_get(pListaPerritoHogar, i);
			//COMPLETAR CON GETTER
			auxId = perritoHogar_getId(auxPerrito);
			retNombre = perritoHogar_getNombre(auxPerrito, auxNombre);
			auxPeso = perritoHogar_getPeso(auxPerrito);
			auxEdad = perritoHogar_getEdad(auxPerrito);
			retRaza = perritoHogar_getRaza(auxPerrito, auxRaza);
			auxIdHogar = perritoHogar_getIdHogar(auxPerrito);
			if(auxId != -1 && retNombre != -1 && auxPeso != -1 && auxEdad != -1 && retRaza != -1)
			{
				printf("\n%-5d %-16s %-10.2f %-10d %-10s %-10d", auxId, auxNombre, auxPeso, auxEdad, auxRaza, auxIdHogar );
			}
		}

		ret = 0;
	}


	return ret;
}




