/*
 * tpInput.c
 *
 *  Created on: 12 may. 2022
 *      Author: BETO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pasajeros.h"
#include "tpInput.h"

#define TAM 51

void rellenarInt(int* inputInt, char inputChar[], char inputError[]){
	*inputInt = 0;
	printf(inputChar);
	scanf("%d", inputInt);
	fflush(stdin);

	while(*inputInt == 0){
		printf(inputError);
		scanf("%d", inputInt);
		fflush(stdin);
	}
}

void rellenarFloat(float* inputFloat, char inputChar[], char inputError[]){
	*inputFloat = 0;
	printf(inputChar);
	scanf("%f", inputFloat);
	fflush(stdin);

	while(*inputFloat == 0){
			printf(inputError);
			scanf("%f", inputFloat);
			fflush(stdin);
		}
}

void rellenarChar(char inputChar[], char outputChar[]){
	fflush(stdin);
	printf(outputChar);
	gets(inputChar);

}

