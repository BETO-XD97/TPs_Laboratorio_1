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

int rtnSclon;
int rtnSsub;
int listTo;
int listFrom;
int opcionElim;
int opcionImp;
int rtnPush;
int deletedList;
int deletedSubList;
int deletedClonList;
int push;
int comparar;
int listaComp;
int opcionComp;
int contains;

int main()
{
	setbuf(stdout, NULL);

    LinkedList* listaPasajeros = ll_newLinkedList();
    LinkedList* subListaPasajeros = ll_newLinkedList();
    LinkedList* clonacionListaPasajeros = ll_newLinkedList();

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
    			"\n11)Crear una subList"
    			"\n12)Clonar la lista"
    			"\n13)Eliminar lista"
    			"\n14)Pushear un numero pasajero"
    			"\n15)Comparar dos listas"
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
            		input_Int(&opcionImp, "\n1)Lista de pasajeros\n2)Sublista de pasajeros\n3)Lista de pasajeros clonada\nQue lista desea imprimir: ", "\nError! Reingrese--->", 1, 3);
            		switch(opcionImp){
						case 1:
							controller_ListPassenger(listaPasajeros);
						break;
						case 2:
							controller_ListPassenger(subListaPasajeros);
							break;
						case 3:
							controller_ListPassenger(clonacionListaPasajeros);
							break;
            		}
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

            case 11:
            	if(valIng == 1){
					input_Int(&listFrom, "\nIngrese desde donde quiere sublistar: ", "\nError! Reingrese---> ", 1, ll_len(listaPasajeros));
					input_Int(&listTo, "\nIngrese hasta donde quiere sublistar: ", "\nError! Reingrese---> ", 1, ll_len(listaPasajeros));
					if(listFrom < listTo){
						subListaPasajeros = ll_subList(listaPasajeros, listFrom, listTo);
						rtnSsub = controller_saveAsText("datamodSubList.csv", subListaPasajeros);//Refrescar la carpeta debug
						if(rtnSsub == 1){
							listaComp = 1;
							printf("\nSe ha hecho una sublista de la lista de pasajeros\n");
						} else {
							printf("\nNo se ha hecho una sublista de la lista de pasajeros\n");
						}
					} else {
						printf("\nNo se puede sublistar porque el primer ingreso es mayor al segundo!\n");
					}
            	} else {

            		printf("\nPrimero debe cargar el archivo para poder sublistar!\n");
            	}
            	break;

            case 12:
            	if(valIng == 1){
					clonacionListaPasajeros = ll_clone(listaPasajeros);
					rtnSclon = controller_saveAsText("datamodClone.csv", clonacionListaPasajeros);//Refrescar la carpeta debug
					if(rtnSclon == 1){
						listaComp = 1;
						printf("\nSe ha clonado la lista de pasajeros\n");
					} else {
						printf("\nNo se ha clonado la lista de pasajeros\n");
					}
            	} else {

            		printf("\nPrimero debe cargar el archivo para poder clonar la lista!\n");
            	}
            	break;

            case 13:
            	input_Int(&opcionElim, "\n1)Lista de pasajeros\n2)Sublista de pasajeros\n3)Lista clonada de pasajeros\nCual de las siguientes listas desea eliminar: ", "\nError! Reintente---> ", 1, 3);
            	switch(opcionElim){
            		case 1:
            			deletedList = ll_deleteLinkedList(listaPasajeros);
            			if(deletedList == 0){
            				printf("\nSe ha eliminado la estructura de pasajeros!\n");
            			} else {
            				printf("\nHubo un problema!\n");
            			}
            			break;
            		case 2:
            			deletedSubList = ll_deleteLinkedList(subListaPasajeros);
            			if(deletedSubList == 0){
            				printf("\nSe ha eliminado la estructura de pasajeros de sublista!\n");
            			} else {
            				printf("\nHubo un problema!\n");
            			}
            			break;
            		case 3:
            			deletedClonList = ll_deleteLinkedList(clonacionListaPasajeros);
            			if(deletedClonList == 0){
            				printf("\nSe ha eliminado la estructura de pasajeros clonados!\n");
            			} else {
            				printf("\nHubo un problema!\n");
            			}
            			break;
            	}
            	break;

            	case 14:
            		if(valIng == 1){
            			rtnPush = controller_addPush(listaPasajeros);
            			if(rtnPush == 1){
            				printf("\nEl pusheo fue exitoso!\n");
            			} else {
            				printf("\nHubo un problema al pushear\n");
            			}
            		} else {
            			printf("\nPrimero debe cargar una lista!\n");
            		}
            		break;

            	case 15:
            		if(listaComp == 1){
            			input_Int(&opcionComp, "\nIngre con cual desea comparar 1-subLista / 2- lista clonada\n----> ", "\nError! Reingrese-->", 1, 2);
            			switch(opcionComp){
            				case 1:
            					comparar = ll_containsAll( listaPasajeros, subListaPasajeros);
            					break;
            				case 2:
            					comparar = ll_containsAll( listaPasajeros, clonacionListaPasajeros);
            					break;
            			}
						if(comparar == 0){
							printf("\nLa listas son las mismas!\n");
						} else {
							printf("\nLa listas NO son las mismas!\n");
						}
            		} else {
            			printf("\nPrimero debe clonar el archivo o crear una sublista para poder comparar!\n");
            		}
            		break;
            default:
            	printf("\nLa opcion es invalida. Elija una opcion....\n");
            	break;
        }

    }while(optionMM != 10);

    return 0;
}

