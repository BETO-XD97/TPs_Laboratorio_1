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

/**
 * \brief find a Passenger by ID en returns the index  position in array
 * @param list Passenger*
 * @param len int length array
 * @param id int of Passenger
 * @return return Return passenger index position  or (-1) if [Invalid length or NULL pointer
 * received or passenger not found]
 */
int findPassengerById(ePassenger list[], int len,int id);

/**
 * \brief add in a existing list of passengers the values received as parameters
   in the firts empty position
 * @param list ePassenger []
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param price float
 * @param flyCode[] char
 * @param typePassenger int
 * @param statusFlight int
 * @param isEmpty int
 */
void addPassenger(ePassenger list[], int len,int id, char name[],char lastName[], float price, char flyCode[],int typePassenger, int statusFlight,int isEmpty);

/**
   \brief modifies an existing list, the values ​​are received as parameters
   and return the modifications made
 * @param list Passenger[]
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param price int
 * @param flyCode[] char
 * @param typePassenger int
 * @param statusFlight int
 * @param isEmpty ints
 */
void modifyPassengerData(ePassenger list[], int len,int id, char name[],char lastName[], float price, char flyCode[],int typePassenger, int statusFlight, int isEmpty);

/**
   \brief prints the list received with the data entered or hardcoated
 * @param list ePassenger*
 * @param len int
 * @param id int
 */
void printPassenger(ePassenger list[], int len,int id);

/**
 * \brief Remove a Passenger by ID (put isEmpty Flag in 0)
 * @param list[] ePassenger
 * @param len int
 * @param id int
 * @return
 */
int removePassenger(ePassenger list[], int len, int id);

/**
 *\brief sort the elements in the array of passenger, the argument order
 		 indicate UP o DOWN order
 * @param list[] Passenger
 * @param len int
 * @param order int 1 - indicate UP / 2 - indicate DOWN
 * @return
 */
int sortPassenger(ePassenger list[], int len, int order);

/**
 * \brief sort the elements in the array of passengers, the argument order indicate UP or DOWN order
 * @param list[] Passenger
 * @param len int
 * @param order int  1-UP / 0-DOWN
 * @return int Return (-1) if error(Invalid length o NULL pointer ) - (0) if ok
 */
int sortPassengerByCode(ePassenger list[], int len, int order);

/**
 * \brief calculate the total of the prices entered
 * @param list[] Passenger
 * @param len int
 * @return Return the total in type float
 */
float calculatePrice(ePassenger list[],int len);

/**
 * \brief calculate the average taking the total price by the number of passengers entered
 * @param list[] Passenger
 * @param len int
 * @param acumPrecio float
 * @return Return the average in type float
 */
float calculatePromPrice(ePassenger list[],int len, float acumPrecio);

/**
 * \brief calculate how many passengers whose prices exceed the average
 * @param list[] Passenger
 * @param len int
 * @param promedioPrecio int
 * @return Returns the number of passengers with a price higher than the average
 */
int calculatePassengerProm(ePassenger list[], int len, float promedioPrecio);
