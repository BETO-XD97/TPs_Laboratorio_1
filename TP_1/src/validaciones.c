/*
 * validaciones.c
 *
 *  Created on: 8 abr. 2022
 *      Author: Roberto Rocabado / Divisio: D
 */

//No puede validar datos alfabeticos por falta de comprension de vectores


#include <stdio.h>

//VALIDACION DE KILOMETROS...
int valKilometros(int kilometros)
{

		while(kilometros <= 0){
			printf("\nError! Los kilometros deben ser mayor a 0."
				   "\nIngrese los kilometros: ");
			fflush(stdin);
			scanf("%d", &kilometros);
		}
		return kilometros;


}

//VALIDACION DE PRECIO LATAM...
float valPrecioLatam(float precioLatam)
{
	while(precioLatam <= 0){
		printf("\nError! El precio de Latam debe ser mayor a 0."
			   "\nIngrese el precio de vuelo de LATAM:: ");
		fflush(stdin);
		scanf("%f", &precioLatam);
	}
	return precioLatam;
}

//VALIDACION DE PRECIO AEROLINEAS...
float valPrecioAerolineas(float precioAerolineas)
{
	while(precioAerolineas <= 0){
			printf("\nError!El precio de Aerolineas debe ser mayor a 0."
				   "\nIngrese el precio de vuelo de Aerolineas:");
			fflush(stdin);
			scanf("%f", &precioAerolineas);
	}
	return precioAerolineas;
}
