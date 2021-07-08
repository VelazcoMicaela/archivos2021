/*
 ============================================================================
 Name        : estructura.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "menu.h"




int main(void) {
	setbuf(stdout,NULL);

	menu();


/*
	if(empleado_InicializarArray(arrayPEmpleado, TAM)==0)
	{
		printf("Inicializacion exitosa\n");
	}

	if(empleado_AgregarArray(arrayPEmpleado, TAM, 1111, "Carlos", 12000.25)==0)
	{
		printf("Alta exitosa\n");
	}

	if(empleado_AgregarArray(arrayPEmpleado, TAM, 1222, "Felipe", 25550.15)==0)
	{
		printf("Alta exitosa\n");
	}

	if(empleado_AgregarArray(arrayPEmpleado, TAM, 1333, "Anabella", 15895)==0)
	{
		printf("Alta exitosa\n");
	}

	empleado_ImprimirArray(arrayPEmpleado,TAM);
	printf("\n\n");
	int legajo;
	char nombre[20];

	empleado_setNombre(arrayPEmpleado[1], "anabella");
	empleado_setLegajo(arrayPEmpleado[1], "5555");

	empleado_getLegajo(arrayPEmpleado[1], &legajo);
	empleado_getNombre(arrayPEmpleado[1], nombre);
	//printf("legajo: %d Nombre: %s \n",legajo, nombre);*/



	/*if(empleado_EliminarPorLegajo(arrayPEmpleado,TAM)==0)
	{
		printf("Baja exitosa\n");
		empleado_ImprimirArray(arrayPEmpleado,TAM);
	}
*/



	return EXIT_SUCCESS;
}


