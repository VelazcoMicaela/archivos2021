/*
 * menu.c
 *
 *  Created on: 12 jun. 2021
 *      Author: Asus
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#include "setGet.h"


void menu()
{
	int tam=1;
	eEmpleado* arrayPEmpleado[tam];
	char salir;
	int opcion;
	int proxId=1000;
	float sueldo;
	char nombre[20];


	if(empleado_InicializarArray(arrayPEmpleado, tam)==0)
	{
		printf("Inicializacion exitosa\n");

		do
		{
			if(utn_getNumeroEnteroConIntentos(&opcion, "Ingrese una opcion\n 1-Alta\n 2-Baja\n 3-Modificar\n 4-Ordenar\n 5-Imprimir\n 6-Informe promedio\n 7-mayor\n 8-Salir  ", "ERROR ingrese una opcion entre el 1-8 " , 1, 8, 5)==0)
			{
				switch(opcion)
				{
					case 1:
						printf("---- ALTA ----\n");
						if(utn_getString(nombre, "Ingrese nombre ", "ERROR Reingrese nombre ", 5)==0 &&
							utn_getNumeroFlotante(&sueldo, "Ingrese sueldo entre 1000 y 1000000 ", "ERROR Reingrese sueldo ", 1000, 1000000, 5)==0 &&
							empleado_AgregarArray(arrayPEmpleado, &tam, &proxId, nombre, sueldo)==0)
						{
							printf("tam %d\n",tam);
							printf("Alta exitosa\n\n");
						}


						break;

					case 2:
						printf("---- BAJA ----\n");
						if(empleado_EliminarPorLegajo(arrayPEmpleado,tam)==0)
						{
							empleado_ImprimirArray(arrayPEmpleado,tam);
							printf("Baja exitosa\n\n");
						}
						break;

					case 3:
						printf("---- MODIFICACION ----\n");
						if(empleado_Modificar(arrayPEmpleado,tam)==0)
						{
							empleado_ImprimirArray(arrayPEmpleado,tam);
							printf("Modificacion exitosa\n\n");
						}
						break;

					case 4:
						printf("---- ORDENAR ----\n");
						if(empleado_Ordenar(arrayPEmpleado,tam)==0)
						{
							empleado_ImprimirArray(arrayPEmpleado,tam);
							printf("Ordenamiento exitoso\n\n");
						}
						else
						{
							printf("Ordenamiento ERROR\n\n");
						}
						break;

					case 5:
						printf("---- IMPRIMIR ----\n");
						if(empleado_ImprimirArray(arrayPEmpleado,tam)==0)
						{
							printf("Mostrar exitoso\n");
						}
						break;

					case 6:
						printf("---- INFORME PROMEDIO ----\n");
						break;

					case 7:
						printf("---- INFORME MAYOR ----\n");
						break;

					case 8:
						printf("---- SALIR ----\n");
						if(utn_getCaracterCorroboraDosCarac(&salir, "Seguro que desea salir? s/n ", "ERROR ingrese s/n ", 's', 'n')==0)
						{
							printf("Hasta luego\n");
						}
						break;

				}

			}

		}while(salir!='s');

	}

		free(arrayPEmpleado);

}

