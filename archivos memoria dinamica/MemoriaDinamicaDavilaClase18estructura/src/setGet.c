/*
 * setGet.c
 *
 *  Created on: 11 jun. 2021
 *      Author: Asus
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#include "setGet.h"

int empleado_setNombre(eEmpleado* this, char*  nombre)
{
	int error=-1;

	if(this!=NULL && nombre!=NULL)
	{
		if(esCaracter(nombre)!=0)
		{
			strcpy(this->nombre, nombre);

		}
		error=0;
	}

	return error=0;
}

int empleado_setLegajo(eEmpleado* this, char* legajo)
{
	int error=-1;
	int numero;

	if(this!=NULL && legajo!=NULL)
	{
		if(esDigito(legajo,&numero)==0)
		{
			this->legajo=numero;
			error=0;
		}

	}

	return error=0;
}

int empleado_getNombre(eEmpleado* this, char*  pNombre)
{
	int error=-1;

	if(this!=NULL && pNombre!=NULL)
	{
		strcpy(pNombre,this->nombre);
		error=0;
	}

	return error=0;
}

int empleado_getLegajo(eEmpleado* this, int* pLegajo)
{
	int error=-1;

	if(this!=NULL && pLegajo!=NULL)
	{
		*pLegajo=this->legajo;
		error=0;
	}

	return error=0;
}


int esDigito(char* cadena, int* numero)
{
	int retorno=-1;

	if(cadena!=NULL && strlen(cadena)>0 && numero!=NULL)
	{
		if(esNumerica(cadena)==0)

		*numero=atoi(cadena);

	}
	return retorno;
}
