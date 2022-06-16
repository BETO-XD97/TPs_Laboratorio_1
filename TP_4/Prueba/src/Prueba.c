/*
 ============================================================================
 Name        : Prueba.c
 Author      : Roberto Rocabado
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include "utn_Input.h"

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
int optionMM = 0;//opcion Menu Principal
int rtnTxt; //Retorna validacion el archivo texto
int rtnBny; //Retorna validacion el archivo binario
int rtnAdd; //Retorna validacion nuevo pasajero
int rtnEdit; //Retorna validacion de pasajero editado
int rtnSort; //Retorna validacion de lista ordenada
int rtnSst; //Retorna validacion de guardado de lista en texto
int rtnSsb; //Retorna validacion de guardado de lista en binario
int valIng = 0;//Valida que se haya cargado la lista o al menos se haya ingresado un pasajero
int guardar = 0; //Valida que se haya guardado los datos ya se en binario o texto
int opcionS; //Opcion de salida
int opcionG; //Opcion de guardado al salir
int idContador = 0;
int idDescontado = 0;
int idA;
int idE;

int main()
{
	setbuf(stdout, NULL);

    LinkedList* listaPasajeros = ll_newLinkedList();

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
    	fflush(stdin);
    	scanf("%d", &optionMM);

    	switch(optionMM)
        {
            case 1:
                rtnTxt = controller_loadFromText("datamod.csv", listaPasajeros);
                if(rtnTxt == 1){
                	printf("\nEl archivo data.csv(texto) se abrio correctamente!\n");
                	valIng = 1;
                	if(idContador !=  0){
                		if(verificarId(listaPasajeros, idContador) != 1){
                			printf("\nLa lista ha sido actualizada con todos sus datos!\n");
                		}
                	}
                } else {
                	printf("\nEl archivo data.csv(texto) NO se abrio correctamente!\n");
                }
                break;

            case 2:
            	rtnBny = controller_loadFromBinary("datamod.bin",listaPasajeros);
            	if(rtnBny == 1){
            		printf("\nEl archivo data.csv(binario) se abrio correctamente!\n");
            		valIng = 1;
            	} else {
            		printf("\nEl archivo data.csv(binario) NO se abrio correctamente!\n");
            	}
            	break;

            case 3:
            	rtnAdd = controller_addPassenger(listaPasajeros, idDescontado);
            	if(rtnAdd == 1){
            		printf("\nEl pasajero fue agregado correctamente!\n");
            		valIng = 1;
            		idContador++;
            	} else {
            		printf("\nHubo un problema al agregar al pasajero\n");
            	}

            	break;

            case 4:
            	if(valIng == 1){
					rtnEdit = controller_editPassenger(listaPasajeros);
					if(rtnEdit == 1){
						printf("\nDatos actualizados!\n");
					} else {
						printf("\nLa operacion NO fue exitosa!\n");
					}
            	} else {
            		printf("\nNo hay datos para editar!\n");
            	}
                break;

            case 5:
            	if(valIng == 1){
            		controller_removePassenger(listaPasajeros);
            	} else {
            		printf("\nNo hay datos para eliminar!\n");
            	}
            	break;
            case 6:
            	if(valIng == 1){
            		controller_ListPassenger(listaPasajeros);
            	} else {
            		printf("\nNo hay datos para listar!\n");
            	}
            	break;
            case 7:
            	if(valIng == 1){
					rtnSort = controller_sortPassenger(listaPasajeros);
					if(rtnSort == 1){
						printf("\nEl ordenamiento ha sido exitoso, para visulizar los cambios elija la opcion 6\n");
					} else {
						printf("\nEl ordenamiento del archivo no ha sido modificado\n");
					}
            	} else {
            		printf("\nNo hay datos para ordenar!\n");
            	}
            	break;
            case 8:
            	if(valIng == 1){
					rtnSst = controller_saveAsText("datamod.csv", listaPasajeros);
					if(rtnSst == 1){
						guardar++;
						printf("\nEl guardado del archivo en modo texto fue exitoso!\n");
					} else {
						printf("\nHubo un problema al guardar el archivo en modo texto!\n");
					}
            	} else {
            		printf("\nNo hay datos para guardar!\n");
            	}
            	break;

            case 9:
            	if(valIng == 1){
					rtnSsb = controller_saveAsBinary("datamod.bin", listaPasajeros);
					if(rtnSsb == 1){
						guardar++;
						printf("\nEl guardado del archivo en modo binario fue exitoso!\n");
					} else {
						printf("\nHubo un problema al guardar el archivo en modo binario!\n");
					}
            	} else {
            		printf("\nNo hay datos para guardar!\n");
            	}
            	break;

            case 10:
            	while(opcionS != 1){
            		if(valIng == 1 && guardar <= 0){
            			input_Int(&opcionG, "\n1)Texto\n2)Binario\nPara finalizar el programa debe guardar los datos cargados\n---> ", "\nError! Reintente--->", 1, 2);
            			switch(opcionG){
            				case 1:
            					controller_saveAsText("datamod.csv", listaPasajeros);
            					opcionS = 1;
            					printf("\nEl programa ha finalizado...");
            					break;
            				case 2:
            					controller_saveAsBinary("datamod.bin", listaPasajeros);
            					printf("\nEl programa ha finalizado...");
            					opcionS = 1;
            					break;
            				default:
            					printf("\nNo valido!\n");
            					break;
            			}
            		} else {
            				opcionS = 1;
            				printf("\nEl programa ha finalizado...");
            		}
            	}
            	break;

            default:
            	printf("\nLa opcion es invalida. Elija una opcion....\n");
            	break;
        }

    }while(optionMM != 10);

    return 0;
}

