/*
 * empleado.h
 *
 *  Created on: 3 may. 2021
 *      Author: Asus
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_


typedef struct
{
	int legajo;
	char nombre [20];
	float sueldo;
}eEmpleado;

eEmpleado* empleado_Nuevo (void);
eEmpleado* empleado_NuevoParametro (int legajo, char* nombre, float sueldo);
int empleado_AgregarArray (eEmpleado* array[], int* len,int* legajo, char* nombre, float sueldo);

void alumno_Borrar(eEmpleado* this);
int empleado_EliminarIndice (eEmpleado* array[], int indice);
int empleado_EliminarPorLegajo (eEmpleado* array[], int tam);

int empleado_InicializarArray (eEmpleado* array[], int len);
int empleado_BuscarLibre (eEmpleado* array[], int len, int* pIndice);
int empleado_BuscarPorId (eEmpleado* array[], int len, int* pIndice, int legajo);
int empleado_ImprimirArray (eEmpleado* array[], int len);
int empleado_ImprimirUno(eEmpleado* array[], int indice);

int empleado_Modificar(eEmpleado* array[], int tam);
int modificar(eEmpleado* array[], int indice);
int empleado_Ordenar(eEmpleado* array[], int tam);

#endif /* EMPLEADO_H_ */
