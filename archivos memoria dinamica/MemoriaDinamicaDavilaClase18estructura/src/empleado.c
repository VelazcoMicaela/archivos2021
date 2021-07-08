/*
 * empleado.c
 *
 *  Created on: 3 may. 2021
 *      Author: Asus
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#include "setGet.h"

eEmpleado* empleado_Nuevo (void)
{
	eEmpleado* aux=NULL;

	aux= (eEmpleado*) malloc (sizeof(eEmpleado));

	return aux;
}

eEmpleado* empleado_NuevoParametro (int legajo, char* nombre, float sueldo)
{
	eEmpleado* aux=NULL;

	aux= empleado_Nuevo();

	if(aux!=NULL)
	{
		aux->legajo=legajo;
		strcpy(aux->nombre, nombre);
		aux->sueldo=sueldo;
	}

	return aux;
}

int empleado_AgregarArray (eEmpleado* array[], int* len,int* legajo, char* nombre, float sueldo)
{
	int error=-1;
	eEmpleado* aux=NULL;
	int indice;
	printf("len1--- %d\n",*len);
	if(array!=NULL && len!=NULL && nombre!=NULL && legajo!=NULL && sueldo>0)
	{
		if(empleado_BuscarLibre(array, *len, &indice)==0)
		{
			if(indice>=0)
			{
				aux=empleado_NuevoParametro(*legajo, nombre, sueldo);
				if(aux!=NULL)
				{
					array[indice]=aux;
					aux=NULL;
					*legajo=*legajo+1;
					*len=*len+1;
					array[indice+1]=NULL;
					printf("len %d\n",*len);

				}
			}
			else
			{
				printf("No hay lugar en el array %d\n",indice);
			}
		}
		error=0;
	}

	return error;
}

int empleado_InicializarArray (eEmpleado* array[], int len)
{
	int error=-1;

	if(array!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			array[i]=NULL;
		}
		error=0;
	}

	return error;
}

int empleado_BuscarLibre (eEmpleado* array[], int len, int* pIndice)
{
	int error=-1;

	if(array!=NULL && len>0 && pIndice!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(array[i]==NULL)
			{
				*pIndice=i;
				break;
			}
			else
			{
				*pIndice=-1;
			}
		}
		error=0;
	}

	return error;
}

int empleado_BuscarPorId (eEmpleado* array[], int len, int* pIndice, int legajo)
{
	int error=-1;

	if(array!=NULL && len>0 && legajo>0 && pIndice!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(array[i]!=NULL && array[i]->legajo==legajo)
			{
				*pIndice=i;
				break;
			}
			else
			{
				*pIndice=-1;
			}
		}
		error=0;
	}

	return error;
}

int empleado_ImprimirUno(eEmpleado* array[], int indice)
{
	int error=-1;
	int legajo;
	char nombre[20];

	if( array[indice]!=NULL &&
		empleado_getLegajo(array[indice], &legajo)==0 &&
		empleado_getNombre(array[indice], nombre)==0)
	{
		printf("%d   %s   %.2f\n",legajo, nombre,array[indice]->sueldo);
		error=0;
	}

	return error;
}

int empleado_ImprimirArray (eEmpleado* array[], int len)
{
	int error=-1;

	if(array!=NULL && len>0)
	{
		printf("Legajo Nombre Sueldo\n");
		for(int i=0; i<len; i++)
		{
			if(empleado_ImprimirUno(array, i)==0)
			{
				error=0;;
			}
		}
	}


	return error;
}

void alumno_Borrar(eEmpleado* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

int empleado_EliminarIndice (eEmpleado* array[], int indice)
{
	int error=-1;

	if(array!=NULL && indice>=0 && array[indice]!=NULL)
	{
		alumno_Borrar(array[indice]);
		array[indice]=NULL;
		error=0;
	}

	return error;
}

int empleado_EliminarPorLegajo (eEmpleado* array[], int tam)
{
	int error=-1;
	int legajoABorrar;
	int indice;
	char corroborar;

	if(array!=NULL && tam>0)
	{
		empleado_ImprimirArray(array, tam);
		utn_getNumeroEnteroConIntentos(&legajoABorrar, "Ingrese el legajo a borrar", "ERROR Reingrise el legajo entre 1000 y 2000", 1000, 2000, 5);

		if(empleado_BuscarPorId(array, tam, &indice, legajoABorrar)==0)
		{
			if(indice>=0)
			{
				if(empleado_ImprimirUno(array, indice)==0 &&
					utn_getCaracterCorroboraDosCarac(&corroborar, "Confirme eliminacion s/n " , "ERROR Ingrese s/n", 's', 'n')==0)
				{
					if(corroborar=='s' && empleado_EliminarIndice(array, indice)==0)
					{
						error=0;
					}
				}
				else
				{
					printf("ERROR ");
				}
			}
			else
			{
				printf("ERROR legajo %d no existe\n",legajoABorrar);
			}
		}

	}

	return error;
}

int empleado_Modificar(eEmpleado* array[], int tam)
{
	int error=-1;
	int legajoModificar;
	int indice;
	char corroborar;

	if(array!=NULL && tam>0)
	{
		empleado_ImprimirArray(array, tam);
		utn_getNumeroEnteroConIntentos(&legajoModificar, "Ingrese el legajo a modificar", "ERROR Reingrise el legajo entre 1000 y 2000", 1000, 2000, 5);

		if(empleado_BuscarPorId(array, tam, &indice, legajoModificar)==0)
		{
			if(indice>=0)
			{
				if(empleado_ImprimirUno(array, indice)==0 &&
					utn_getCaracterCorroboraDosCarac(&corroborar, "Confirme modificacion s/n " , "ERROR Ingrese s/n", 's', 'n')==0)
				{
					if(corroborar=='s' && modificar(array, indice)==0)
					{
						error=0;
					}
				}
			}
			else
			{
				printf("ERROR legajo %d no existe\n",legajoModificar);
			}
		}
	}


	return error;
}

int modificar(eEmpleado* array[], int indice)
{
	int error=-1;
	int opcion;
	char respuesta;
	eEmpleado aux;

	if(array!=NULL && indice>-1)
	{
		aux=*array[indice];
		do
		{
			if(utn_getNumeroEnteroConIntentos(&opcion, "Modificar\n 1-Nombre\n 2-Sueldo\n 3-Guardar ", "ERROR reingrese entre 1-3 ", 1, 3, 5)==0)
			{
				switch(opcion)
				{
				case 1:
					printf("---- NOMBRE ----\n");
					if(utn_getString(aux.nombre, "Ingrese nombre ", "ERROR Reingrese ", 5)==0)
					{
						printf("%d %s %.2f\n", aux.legajo, aux.nombre, aux.sueldo);
					}
					break;

				case 2:
					printf("---- SUELDO ----\n");
					if(utn_getNumeroFlotante(&aux.sueldo, "Ingrese sueldo ", "ERROR Reingrese ", 1000, 10000000,5)==0)
					{
						printf("%d %s %.2f\n", aux.legajo, aux.nombre, aux.sueldo);
					}

					break;

				case 3:
					printf("---- GUARDAR ----\n");
					if(utn_getCaracterCorroboraDosCarac(&respuesta, "Seguro que desea guardar? s/n ", "ERROR ingrese s/n ", 's', 'n')==0)
					{
						if(respuesta=='s')
						{
							*array[indice]=aux;
						}
						else
						{
							respuesta='s';
						}
					}
					break;
				}

			}
		}while(respuesta!='s');
		error=0;
	}

	return error;
}

int empleado_Ordenar(eEmpleado* array[], int tam)
{
	int error=-1;
	eEmpleado* aux;

	if(array!=NULL && tam>0)
	{
		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam; j++)
			{
				if(array[i]!=NULL && array[j]!=NULL &&
					strcmp(array[i]->nombre,array[j]->nombre)>0)
				{
					aux=array[i];
					array[i]=array[j];
					array[j]=aux;
				}
			}
		}

		error=0;
	}

	return error;
}

