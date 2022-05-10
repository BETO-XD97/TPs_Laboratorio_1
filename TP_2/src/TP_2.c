/*
 ============================================================================
 Name        : TP_2.c
 Author      : Roberto Rocabado
 Division: D
 DNI: 40731247
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"

typedef struct{
	int codigo;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
	int isEmpty;
}eBoleto;

#define PASAJEROS 2

int opcionMP; //Opcion de menu principal

int main(void) {
	setbuf(stdout, NULL);

	eBoleto boleto[PASAJEROS];

	initPassengers(boleto, PASAJEROS);
	//MENU
	do{
		printf("Ingrese la opcion que desea realizar: \n\n"
				"1)ALTA.\n"
				"2)MODIFICAR.\n"
				"3)BAJA.\n"
				"4)INFORMAR.\n"
				"5)CARGA FORZADA.\n"
				"6)SALIR.\n");
		fflush(stdin);
		scanf("%d", &opcionMP);

		switch(opcionMP){
			case 1:
				addPassengers();
				break;

			case 2:
				printf("2");
				break;

			case 3:
				printf("3");
				break;

			case 4:
				printf("4");
				break;

			case 5:
				printf("5");
				break;

			case 6:
				printf("Gracias por usar nuestros servicio!!!");
				break;

			default:
				printf("ERROR! Opcion incorrecta.\n\n");
				break;
		}

	}while(opcionMP != 6);

	return 0;
}
