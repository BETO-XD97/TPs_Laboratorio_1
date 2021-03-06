/*
 ============================================================================
 Name        : TP_1.c
 Author      : Roberto Rocabado
 Version     : 1.0
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
	//VARIABLES GENERALES
	int opcion;
	int kilometros = 0;
	float precioLatam = 0;
	float precioAerolineas = 0;
	float descuento = 10;
	float interes = 25;
	float bitcoinPrecio = 4770233.18;//El precio lo muestro con 5 decimales
	int calculo = 0;

	//VARIABLES DE CALCULO DE LATAM
	float debitoLatam;
	float creditoLatam;
	float bitcoinLatam;
	float precioUnitLatam;

	//VARIABLES DE CALCULO DE AEROLINEAS
	float debitoAerolineas;
	float creditoAerolineas;
	float bitcoinAerolineas;
	float precioUnitAerolineas;

	//DIFERENCIA DE PRECIOS
	float difPrecios;

	//MENU
	do
	{
		printf("\n1- Ingrese los KMs. (KM = %d)\n"
				 "2- Ingrese el precio del vuelo. (precioLatam = %.2f / precioAerolineas = %.2f)\n"
				 "3- Calcular los precios. \n"
				 "4- Mostrar los precios. \n"
				 "5- Carga forzada de datos. \n"
				 "6- Salir. \n"
				 "\nELEGIR SU OPCION: ", kilometros, precioLatam, precioAerolineas);
		fflush(stdin);
		scanf("%d", &opcion);

		//OPCIONES
		switch(opcion){

			//Ingreso de kilometros
			case 1:

				printf("\nIngrese los kilometros: ");
				scanf("%d", &kilometros);
				kilometros = valKilometros(kilometros);
				break;

			//Ingreso de precios
			case 2:

				if(kilometros > 0){
				printf("\nIngrese el precio de vuelo de LATAM: ");
				scanf("%f", &precioLatam);
				precioLatam = valPrecioLatam(precioLatam);
				printf("\nIngrese el precio de vuelo de Aerolineas: ");
				scanf("%f", &precioAerolineas);
				precioAerolineas = valPrecioAerolineas(precioAerolineas);
				} else {
					printf("\nIngrese primero los kilometros \n");
				}
				break;

			//Calculos de precios
			case 3:

				if(precioLatam != 0 && precioAerolineas != 0 && kilometros != 0)
				{
					//Calculos de Latam
					debitoLatam = CalculoDebito(precioLatam, descuento);
					creditoLatam = CalculoCredito(precioLatam, interes);
					bitcoinLatam = CalculoBitcoin(precioLatam, bitcoinPrecio);
					precioUnitLatam = CalculoPreUnit(precioLatam, kilometros);

					//Calculos de Aerolineas
					debitoAerolineas = CalculoDebito(precioAerolineas, descuento);
					creditoAerolineas = CalculoCredito(precioAerolineas, interes);//
					bitcoinAerolineas = CalculoBitcoin(precioAerolineas, bitcoinPrecio);
					precioUnitAerolineas = CalculoPreUnit(precioAerolineas, kilometros);

					//Diferencia de precios
					difPrecios = DiferenciaPrecios(precioLatam, precioAerolineas);
					calculo = 1;
					printf("\nLos datos fueron calculados con EXITO...!!! \n");

				} else {
					printf("\nLos datos NO son validos por lo tanto no se puede calcular... \n");
				}
				break;

			//Muestra de resultados
			case 4:
				if(calculo == 1){
				printf( "\n----------------------------------------------------------"
						"\nKMs ingresados: %d \n"
						"\nPrecio de Latam: %.2f"
						"\nA)Precio con tarjeta de debito es de: %.2f"
						"\nB)Precio con tarjeta de credito es de: %.2f"
						"\nC)Precio pagando con bitcoin es de: %.7f BTC"
						"\nD)Precio unitario: %.2f p/km"
						"\n"
						"\nPrecio de Aerolineas: %.2f"
						"\nA)Precio con tarjeta de debito es de: %.2f"
						"\nB)Precio con tarjeta de credito es de: %.2f"
						"\nC)Precio pagando con bitcoin es de: %.7f BTC"
						"\nD)Precio unitario: %.2f p/km"
						"\n"
						"\nDiferencia de precios ingresada (Latam-Aerolineas):  %.2f"
						"\n----------------------------------------------------------"
						"\n", kilometros, precioLatam, debitoLatam, creditoLatam, bitcoinLatam, precioUnitLatam, precioAerolineas, debitoAerolineas, creditoAerolineas, bitcoinAerolineas, precioUnitAerolineas, difPrecios);
				} else {
					printf("\nNo ha realizado los calculos o no ha ingresado los datos necesarios...\n");
				}
				break;

			//Carga forzada de datos
			case 5:

				cargaForzada();

				break;

			//Salida del programa
			case 6:

				printf("\nGracias por usar nuestro servicio!!!");
				break;

			//En caso de marcar una opcion incorrecto
			default:

				printf("\nError! Ingrese una opcion: \n");
				break;
		}

	}while(opcion !=6);

	return 0;
}
