/*
 * calculos.c
 *
 *  Created on: 9 abr. 2022
 *      Author: BETO
 */

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
