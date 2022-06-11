#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

//Variables auxiliares
int optionMM = 0;
int rtnTxt; //Retorna el archivo texto
int rtnBny; //Retorna el archivo binario
int rtnAdd;
int rtnEdit;
int rtnSort;
int idContador = 0;
int idDescontado = 0;
int idA;
int idE;

int main()
{
	setbuf(stdout, NULL);

    LinkedList* listaPasajeros = ll_newLinkedList();

    //Passenger* unPasajero;

    //FILE* pFile = fopen("data.csv", "r");

    //parser_PassengerFromText(pFile, listaPasajeros);


    /*
    for(int i = 0; i<ll_len(listaPasajeros); i++){

    	unPasajero = (Passenger*) ll_get(listaPasajeros, i);
    	Passenger_printOne(unPasajero);

    }
 */
    do{
    	printf("\n----------------------------Bienvenido al sistema------------------------");
    	printf("\n1)Cargar datos de pasajeros desde el archivo data.csv (modo texto)"
    			"\n2)Cargar datos de pasajeros desde el archivo data.csv (modo binario)"
    			"\n3)Alta de pasajero"
    			"\n4)Modificar datos de pasajeros"
    			"\n5)Baja de pasajero"
    			"\n6)Listar pasajeros"
    			"\n7)Ordenar pasajeros"
    			"\n8)Guardar datos de pasajeros en archivo data.csv (modo texto)"
    			"\n9)Guardar datos de pasajeros en archivo data.csv (modo binario)"
    			"\n10)Salir"
    			"\n\nIngrese la opcion a realizar---> "
    			);
    	scanf("%d", &optionMM);

    	switch(optionMM)
        {
            case 1:
                rtnTxt = controller_loadFromText("data.csv", listaPasajeros);
                if(rtnTxt == 1){
                	printf("\nEl archivo data.csv(texto) se abrio correctamente!\n");
                	if(idContador !=  0){
                		if(verificarId(listaPasajeros, idContador) != 1){
                			printf("\nLa lista ha sido actualizada");
                		}
                	}
                } else {
                	printf("\nEl archivo data.csv(texto) NO se abrio correctamente!\n");
                }
                break;

            case 2:
            	rtnBny = controller_loadFromBinary("data.csv",listaPasajeros);
            	if(rtnBny == 1){
            		printf("\nEl archivo data.csv(binario) se abrio correctamente!\n");
            	} else {
            		printf("\nEl archivo data.csv(binario) NO se abrio correctamente!\n");
            	}
            	break;

            case 3:
            	rtnAdd = controller_addPassenger(listaPasajeros, idDescontado);
            	if(rtnAdd == 1){
            		printf("\nEl pasajero fue agregado correctamente");
            		idContador++;
            	} else {
            		printf("\nHubo un problema al agregar al pasajero");
            	}

            	break;

            case 4:
            	rtnEdit = controller_editPassenger(listaPasajeros);
            	if(rtnEdit == 1){
            		printf("\nLa operacion fue exitosa!");
            	} else {
            		printf("\nLa operacion NO fue exitosa!");
            	}

                break;

            case 5:
            	controller_removePassenger(listaPasajeros);
                break;

            case 6:
            	controller_ListPassenger(listaPasajeros);
            	break;
            case 7:
            	rtnSort = controller_sortPassenger(listaPasajeros);
            	if(rtnSort == 1){
            		printf("\nEl ordenamiento ha sido exitoso, para visulizar los cambios elija la opcion 6\n");
            	} else {
            		printf("\nEl ordenamiento del archivo no ha sido modificado");
            	}
            	break;
        }

    }while(optionMM != 10);


    return 0;
}

