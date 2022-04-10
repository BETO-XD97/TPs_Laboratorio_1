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
#include "calculos.h"
int main(void) {
	setbuf(stdout, NULL);
	//variables
	int opcion;
	int kilometros;
	float precioLatam;
	float precioAerolineas;
	float descuento = 10;
	float interes = 15;
	float bitcoinPrecio = 4770233.18;

	//variables de calculo Latam
	float debitoLatam;
	float creditoLatam;
	float bitcoinLatam;
	float precioUnitarioL;

	//variables de calculo Aerolineas
	float debitoAerolineas;
	float creditoAerolineas;
	float bitcoinAerolineas;
	float precioUnitarioA;

	//diferencias de precios
	//float difPrecios;
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
				//Calculos de Latam
				debitoLatam = CalculoDebito(precioLatam, descuento);
				//creditoL = credito(creditoL, interes);
				//bitcoinL = bitcoin(bitcoinL, bitcoinPrecio);
				//precioUnitarioL = PrecioUnitario(precioUnitarioL, km);

				//Calculos de Aerolineas
				debitoAerolineas = CalculoDebito(precioAerolineas, descuento);
				//creditoA = credito(creditoA, interes);//
				//bitcoinA = bitcoin(bitcoinA, bitcoinPrecio);
				//precioUnitarioA = precioUnitario(precioUnitarioA, km);

				//diferencia de precios
				//difPrecios = diferencia(precioLatam, precioAerolineas);
				break;
			case 4:
				printf("El descuento de precio latam es: %.2f", debitoLatam);
				printf("EL descuento de precio aerolineas es: %.2f", debitoAerolineas);

				break;

			case 5:
				kilometros = 7090;
				precioLatam = 159339;
				precioAerolineas = 162965;

				debitoLatam = CalculoDebito(precioLatam, descuento);
				printf("\nEl descuento de precio latam es: %.2f", debitoLatam);
				debitoAerolineas = CalculoDebito(precioAerolineas, descuento);
				printf("\nEL descuento de precio aerolineas es: %.2f", debitoAerolineas);

				creditoAerolineas = CalculoCredito(precioAerolineas, interes);
				printf("\nEl recargo de precio de aerolineas es: %.2f", creditoAerolineas);
				creditoLatam = CalculoCredito(precioLatam, interes);
				printf("\nEl recargo de precio latam es: %.2f", creditoLatam);

				bitcoinLatam =  CalculoBitcoin(precioLatam, bitcoinPrecio);
				printf("\nPrecio final pagando de latam con bitcoin: %.6f", bitcoinLatam);
				bitcoinAerolineas = CalculoBitcoin(precioAerolineas, bitcoinPrecio);
				printf("\nPrecio final pagando de aerolineas con bitcoin es: %.6f", bitcoinAerolineas);

				precioUnitarioA = CalculoPreUnit(precioAerolineas, kilometros);
				printf("\nEl precio unitario de aerolineas es de: %.2f",precioUnitarioA);
				precioUnitarioL = CalculoPreUnit(precioLatam, kilometros);
				printf("\nEl precio unitario de latam es de: %.2f", precioUnitarioL);
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
