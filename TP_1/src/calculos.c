/*
 * calculos.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Roberto Rocabado / Divison: D
 */

#include <stdio.h>

float CalculoDebito(float precioVuelo, float descuento){
	float precioFinal;
	float descuentoPrecio;
	descuentoPrecio = precioVuelo * (descuento/100);
	precioFinal = precioVuelo - descuentoPrecio;
	return precioFinal;
}

float CalculoCredito(float precioVuelo, float interes){
	float precioFinal;
	float recargoPrecio;
	recargoPrecio = precioVuelo * (interes/100);
	precioFinal = precioVuelo + recargoPrecio;
	return precioFinal;
}

float CalculoBitcoin(float precioVuelo, float bitcoinPrecio){
	float precioFinal;
	precioFinal = (precioVuelo*1)/bitcoinPrecio;
	return precioFinal;
}

float CalculoPreUnit(float precioVuelo, int kilometros){
	float precioUnitario;
	precioUnitario = (float) precioVuelo / kilometros;
	return precioUnitario;
}

float DiferenciaPrecios(float precioLatam, float precioAerolineas){
	float diferencia;
	if(precioLatam > precioAerolineas){
		diferencia = precioLatam - precioAerolineas;
	} else {
		diferencia = precioAerolineas - precioLatam;
	}
	return diferencia;
}


void cargaForzada(void)
{
		int kilometros = 7090;
		float precioLatam = 159339;
		float precioAerolineas = 162965;
		float descuento = 10;
		float interes = 25;
		float bitcoinPrecio = 4770233.18;//El precio lo muestro con 5 decimales

		float debitoLatam=0;
		float creditoLatam=0;
		float bitcoinLatam=0;
		float precioUnitLatam=0;

		//VARIABLES DE CALCULO DE AEROLINEAS
		float debitoAerolineas;
		float creditoAerolineas;
		float bitcoinAerolineas;
		float precioUnitAerolineas;

		//DIFERENCIA DE PRECIOS
		float difPrecios;

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

}
