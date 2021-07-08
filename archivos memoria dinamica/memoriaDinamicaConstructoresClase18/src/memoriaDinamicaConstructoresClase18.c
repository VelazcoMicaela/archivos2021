/*
 ============================================================================
 Name        : memoriaDinamicaConstructoresClase18.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int legajo;
	char nombre[20];
	char sexo;
	float sueldo;
}eEmpleado;

int mostrarEmpleado(eEmpleado*);
int validar(eEmpleado*);

eEmpleado* newConstructor();
eEmpleado* newConstructorParam(int legajo, char* nombre, char sexo, float sueldo);
void destroy(eEmpleado*);

int setLegajo (eEmpleado* e, int legajo);
int setNombre (eEmpleado* e, char* nombre);
int setSexo (eEmpleado* e, char sexo);
int setSueldo(eEmpleado* e, float sueldo);

int getLegajo (eEmpleado* e, int* pLegajo);
int getNombre (eEmpleado* e, char* pNombre);
int getSexo (eEmpleado* e, char* pSexo);
int getSueldo(eEmpleado* e, float* pSueldo);

int main(void) {
	setbuf(stdout,NULL);

	eEmpleado* emp3;

	emp3= newConstructorParam(1111, "Juana", 'f', 50000);

	if(validar(emp3)==0)
	{
		exit(1);
	}

	mostrarEmpleado(emp3);

	destroy(emp3);

	return EXIT_SUCCESS;
}

int validar(eEmpleado* emp)
{
	int error=-1;

	if(emp==NULL)
	{
		printf("No se pudo conseguir memoria\n");
		error=0;
	}

	return error;
}

int mostrarEmpleado(eEmpleado* emp)
{
	int error=-1;

	int legajo;
	char nombre[20];
	char sexo;
	float sueldo;

	if(emp!= NULL)
	{

		if( getLegajo(emp, &legajo)==0 &&
			getNombre(emp, nombre)==0 &&
			getSexo(emp, &sexo)==0 &&
			getSueldo(emp, &sueldo)==0 )

		printf("legajo %d\nnombre %s\nsexo %c\nsueldo %.2f\n",
				legajo, nombre, sexo, sueldo);
		error=0;
	}

	return error;

}


eEmpleado* newConstructor()
{
	eEmpleado* estructura;

	estructura= (eEmpleado*) malloc (sizeof(eEmpleado));
	if(estructura!=NULL)
	{
		//estructura= (eEmpleado*) calloc (1,sizeof(eEmpleado));
		estructura->legajo=0;
		strcpy( estructura->nombre, " ");
		estructura->sexo=' ';
		estructura->sueldo=0;
	}


	return estructura;
}

void destroy(eEmpleado* estructura)
{
	free(estructura);
}

eEmpleado* newConstructorParam(int legajo, char* nombre, char sexo, float sueldo)
{
	eEmpleado* aux;

	aux=newConstructor();

	if(aux!=NULL)
	{
		if(!(setLegajo(aux, legajo)==0 &&
			setNombre(aux, nombre)==0 &&
			setSexo(aux, sexo)==0 &&
			setSueldo(aux, sueldo)==0) )
		{
			destroy(aux);
			aux=NULL;
		}

	}
	return aux;
}

int setLegajo (eEmpleado* e, int legajo)
{
	int error=-1;

	if(e!=NULL && legajo>1000 && legajo<2000)
	{
		e->legajo=legajo;
		error=0;
	}

	return error;
}

int setNombre (eEmpleado* e, char* nombre)
{
	int error=-1;

	if(e!=NULL && nombre!=NULL && strlen(nombre)<20 && strlen(nombre)>2)
	{
		strcpy( e->nombre, nombre);

		error=0;
	}

	return error;
}

int setSexo (eEmpleado* e, char sexo)
{
	int error=-1;

	if(e!=NULL &&  (sexo=='m' || sexo=='f'))
	{
		e->sexo=sexo;
		error=0;
	}

	return error;
}

int setSueldo(eEmpleado* e, float sueldo)
{
	int error=-1;

	if(e!=NULL && sueldo>10000 && sueldo<100000)
	{
		e->sueldo=sueldo;

		error=0;
	}

	return error;
}

int getLegajo (eEmpleado* e, int* pLegajo)
{
	int error=-1;
	if(e!=NULL && pLegajo!=NULL)
	{
		*pLegajo= e->legajo;
		error=0;
	}

	return error;
}
int getNombre (eEmpleado* e, char* pNombre)
{
	int error=-1;
	if(e!=NULL && pNombre!=NULL)
		{
			strcpy( pNombre, e->nombre);
			error=0;
		}

	return error;
}
int getSexo (eEmpleado* e, char* pSexo)
{
	int error=-1;
	if(e!=NULL && pSexo!=NULL)
	{
		*pSexo= e->sexo;
		error=0;
	}

	return error;
}
int getSueldo(eEmpleado* e, float* pSueldo)
{
	int error=-1;
	if(e!=NULL && pSueldo!=NULL)
	{
		*pSueldo= e->sueldo;
		error=0;
	}

	return error;
}
