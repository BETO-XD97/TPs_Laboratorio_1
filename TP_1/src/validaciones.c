/*
 * validaciones.c
 *
 *  Created on: 8 abr. 2022
 *      Author: BETO
 */

//No puede validar datos alfabeticos por falta de comprension de vectores

//VALIDACION DE KILOMETROS...
#include <stdio.h>

int valKilometros(int kilometros)
{

		while(kilometros <= 0){
			printf("\nError! Reingrese los kilometros: ");
			fflush(stdin);
			scanf("%d", &kilometros);
		}
		return kilometros;


}

//VALIDACION DE PRECIO LATAM...
float valPrecioLatam(float precioLatam)
{
	int intento;
	while(precioLatam < 0){
		if(precioLatam < 0){
			printf("\nEsta ingresando un precio NO valido para calcular.");
			printf("\nDesea reintentar...? (1-SI/0-NO)--> ");
			scanf("%d", &intento);
			if(intento == 1){
				printf("Ingrese el precio de vuelo de Latam: ");
				scanf("%f", &precioLatam);
			} else {
				precioLatam = 0;

			}
		}
	}
	if(precioLatam == 0){

		printf("\n");
		printf("Usted ingreso un precio de $0, por lo tanto no se calcular�. ");
		printf("\n");

	}
	return precioLatam;
}

//VALIDACION DE PRECIO AEROLINEAS...
float valPrecioAerolineas(float precioAerolineas)
{
	int intento;
	while(precioAerolineas < 0){
		if(precioAerolineas < 0){
			printf("\nEsta ingresando un precio NO valido para calcular.");
			printf("\nDesea reintentar...? (1-SI/0-NO)-->");
			scanf("%d", &intento);
			if(intento == 1){
				printf("Ingrese el precio de vuelo de Latam: ");
				scanf("%f", &precioAerolineas);
			} else {
				precioAerolineas = 0;

			}
		}
	}
	if(precioAerolineas == 0){
		printf("\n");
		printf("Usted ingreso un precio de $0, por lo tanto no se calcular�. ");
		printf("\n");
	}
	return precioAerolineas;
}
