/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[9];
	char tipoPasajero[50];
	char estadoVuelo[50];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* id,char* nombre,char* apellido, char* precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo);

void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* name);
int Passenger_getNombre(Passenger* this,char* name);

int Passenger_setApellido(Passenger* this,char* lastName);
int Passenger_getApellido(Passenger* this,char* lastName);

int Passenger_setCodigoVuelo(Passenger* this,char* flyCode);
int Passenger_getCodigoVuelo(Passenger* this,char* flyCode);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float price);
int Passenger_getPrecio(Passenger* this,float* price);

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

int Passenger_typePassengerDescripcion(int typePassenger, char* descripcion);
int Passenger_statusFlightDescripcion(int statusFlight, char* descripcion);

void Passenger_printOne(Passenger* this);

int Passenger_searchForId(LinkedList* pArrayListPassengers, int id);

int maximoId(LinkedList* pArrayListPassengers);

int verificarId(LinkedList* pArrayListPassenger, int idContador);

#endif /* PASSENGER_H_ */
