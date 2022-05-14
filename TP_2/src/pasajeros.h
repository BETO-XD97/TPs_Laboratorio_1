/*
 * pasajeros.h
 *
 *  Created on: 10 may. 2022
 *      Author: BETO
 */

#ifndef PASAJEROS_H_
#define PASAJEROS_H_

#include "tpInput.h"

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;


#endif /* PASAJEROS_H_ */

/**
 *\brief To indicate that all position in the array are empty, this function
 *		 put the flag (isEmpty) in TRUE all position of the array
 * @param list Passenger* Pointer to array of passenger
 * @param len int  Array length
 * @return
 */
int initPassenger(ePassenger list[], int len);

int findPassengerById(ePassenger list[], int len,int id);

void addPassenger(ePassenger list[], int len,int id, char name[],char lastName[], float price, char flyCode[],int typePassenger, int statusFlight,int issEmpty);

void modifyPassengerData(ePassenger list[], int len,int id, char name[],char lastName[], float price, char flyCode[],int typePassenger, int statusFlight, int isEmpty);

void printPassenger(ePassenger list[], int len,int id);

int removePassenger(ePassenger list[], int len, int idRecibida);

int sortPassenger(ePassenger list[], int len, int order);

int sortPassengerByCode(ePassenger list[], int len, int order);

float calculatePrice(ePassenger list[],int len);

float calculatePromPrice(ePassenger list[],int len, float acumPrecio);

int calculatePassengerProm(ePassenger list[], int len, float promedioPrecio);
