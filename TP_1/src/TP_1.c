/*
 ============================================================================
 Name        : TP_1.c
 Author      : Roberto Rocabado
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 DNI: 40731247
 Division: D
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

int main(void) {
	setbuf(stdout, NULL);
	//variables
	int opcion;
	int kilometros;
	float precioLatam;
	float precioAerolineas;

	//menu
	do
	{
		printf("1- Ingrese los KMs. \n"
				"2- Ingrese el precio del vuelo. \n"
				"3- Calcular los precios. \n"
				"4- Mostrar los precios. \n"
				"5- Carga forzada de datos. \n"
				"6- Salir. \n"
				"\nELEGIR SU OPCION: ");
		fflush(stdin);
		scanf("%d", &opcion);

		//OPCIONES
		switch(opcion){
			case 1:
				printf("\nIngrese los kilometros: ");
				scanf("%d", &kilometros);
				kilometros = valKilometros(kilometros);
				break;
			case 2:
				printf("\nIngrese el precio de vuelo de LATAM: ");
				scanf("%f", &precioLatam);
				precioLatam = valPrecioLatam(precioLatam);
				printf("\nIngrese el precio de vuelo de Aerolineas: ");
				scanf("%f", &precioAerolineas);
				precioAerolineas = valPrecioAerolineas(precioAerolineas);
				break;

			case 3:

				break;
			case 6:
				printf("Gracias por usar nuestro servicio.!!!");
				break;
			default:
				printf("Error! Reingrese una opcion: \n");
				break;
		}
		printf("\n");
	}while(opcion !=6);
	return 0;
}
