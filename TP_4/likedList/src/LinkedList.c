#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL){

    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL){

    	retorno = this->size;
    }
    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int len;

	Node* pNode = NULL;

	len = ll_len(this);

	if(this != NULL  && nodeIndex < len && nodeIndex >= 0){

		for(int i=0; i <= nodeIndex; i++){

			if(i == 0){

				pNode = this->pFirstNode;

			} else {

				pNode = pNode -> pNextNode;
			}
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	int len;

	Node* pElement = NULL;

	len = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex < len){

		pElement = getNode(this, nodeIndex);
	}
	return pElement;
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int retorno = -1;
    int len;

    Node* newNode;

    len = ll_len(this);

    if (this != NULL){

    	if (nodeIndex <= len && nodeIndex >= 0){

    	   newNode = (Node*)malloc(sizeof(Node));

    	   if (newNode != NULL){

				newNode->pElement = pElement;

				if (nodeIndex == 0){

					newNode->pNextNode = this->pFirstNode;
					this->pFirstNode = newNode;
				} else {

					newNode->pNextNode = getNode(this, nodeIndex);
					(getNode(this, nodeIndex-1))->pNextNode = newNode;
				}
           this->size++;
           retorno = 0;
    	   }
       }
    }
    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int retorno = -1;
	int len;

	len = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= len){ //Si coloco nodeIndex < len me salta error en el testing

		retorno = addNode(this,nodeIndex,pElement);
	}
    return retorno;
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno = -1;
    int len;

    len = ll_len(this);

    if(this!= NULL){

    	addNode(this,len,pElement);
        retorno = 0;
    }
    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void*retorno = NULL;
	int len;

	Node* nodeAux;

	len = ll_len(this);

	if(this != NULL && index >= 0 && index < len && len > 0){

		nodeAux = getNode(this,index);

		if(nodeAux != NULL){

			retorno = nodeAux->pElement;
		}
	}
	return retorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	int retorno = -1;
	int len;

	Node* nodeAux;

	len = ll_len(this);

	if(this != NULL && index >= 0 && index < len){

		nodeAux = getNode(this,index);

		if(nodeAux != NULL){

			nodeAux->pElement = pElement;
			retorno = 0;
		}
	}
	return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int retorno = -1;
    int len;

    Node* nodeAux;
    Node* nodePrev;
    Node* nodeNext;

    len = ll_len(this);

    if(this != NULL && index >= 0 && index < len && len > 0){

    	if (index == 0){

    		nodeAux = getNode(this,index);
            this->pFirstNode = nodeAux->pNextNode;
            free(nodeAux);
            retorno = 0;

        } else {

        	if(index>=1){

        		nodeAux = getNode(this,index);
        		nodePrev = getNode(this,index-1);
        		nodeNext = getNode(this,index+1);
				nodePrev->pNextNode = nodeNext;
				free(nodeAux);
				retorno = 0;
        	}
        }
    	this->size--;
    }
    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int retorno = -1;
    int len;

    len = ll_len(this);

    if (this!=NULL){

    	for(int i=0;i<len;i++){

        	ll_remove(this,i);
        }
       retorno = 0;
    }
    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int retorno = -1;

	if (this!=NULL){

		ll_clear(this);
		free(this);
		retorno = 0;
	}


	return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int retorno = -1;
	int len;
	void* elementAux;

	len = ll_len(this);

	if (this!=NULL){

		for(int i=0;i<len;i++){

			elementAux = ll_get(this, i);

			if (elementAux == pElement){

				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL && this->size != 0){

    	retorno = 0;
    } else {

    	if(this != NULL && this->size == 0){

    		retorno = 1;
    	}
    }
    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno = -1;
    int len;

    len = ll_len(this);

    if (this != NULL && index >= 0 && index <= len){

    	retorno = addNode(this,index,pElement);
    }

    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* elementAux;
    int len;

    len = ll_len(this);

    if (this != NULL && index>=0 && index <= len){

    	elementAux = ll_get(this,index);
        ll_remove(this,index);
    }
    return elementAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if (this != NULL){

    	retorno = 0;

    	if(ll_indexOf(this, pElement) != -1){

    		retorno = 1;
    	}
    }
    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno = -1;
    int len2;

    len2 = ll_len(this2);

    if (this != NULL && this2 != NULL){

    	retorno = 1;

    	for(int i=0;i<len2;i++){

            if(ll_contains(this, ll_get(this2,i))!=1){

            	retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* sublist = NULL;

    if(this != NULL && from >= 0 && to <= ll_len(this) && to>from){

    	sublist = ll_newLinkedList();

        for(int i=from;i<to;i++){

            ll_add(sublist, ll_get(this,i));
        }
    }
    return sublist;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	LinkedList* cloneList = NULL;

    if(this!=NULL){

    	cloneList = ll_subList(this, 0, ll_len(this));
    }
    return cloneList;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int retorno = -1;
    int len;
    void* pElementFirst;
    void* pElementSecond;

    len = ll_len(this);

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1)){

    	for(int i=0; i<len-1; i++){

    		for(int j = i+1; j<len; j++){

    			pElementFirst = ll_get(this, i);
    			pElementSecond = ll_get(this, j);

    			if(order == 1){

    				if(pFunc(pElementFirst, pElementSecond) > 0){

    					ll_set(this, i, pElementSecond);
    					ll_set(this, j, pElementFirst);
    				}
    			} else {

    				if(pFunc(pElementFirst, pElementSecond) < 0){

    					ll_set(this, i, pElementSecond);
    					ll_set(this, j, pElementFirst);
    				}
    			}
    		}
    	}
    	retorno = 0;
    }
    return retorno;
}

//**************************************************************************************

//Funciones extras no entran al tp4 pero necesarias para el segundo parcial (16/6)

/*
 * Completa un campo del elemento, recibiendo como parámetro
 * la función que sera la encargada de calcular el valor de ese campo.
 * Verificando que tanto el puntero this como el puntero a la funcion
 * fn sean distintos de NULL. Retorna la lista completa.
 * */

LinkedList* ll_map(LinkedList* this, void (*pFunc)(void* element)){

	int len;

	LinkedList* list = NULL;

	len = ll_len(this);

	if(this != NULL && pFunc != NULL){

		for(int i=0; i<len; i++){

			pFunc(ll_get(this, i));
		}
		list = this;
	}
	return list;
}

/*
 * Filtra la lista con una condición, recibiendo como parámetro
 * la función que sera la encargada de decidir si cada elemento
 * cumple la condición (1) o no (0) y si se agrega a una nueva lista filtrada.
 * Verificando que tanto el puntero this como el puntero a la funcion
 * fn sean distintos de NULL. Retorna la lista nueva lista filtrada.
 * */


LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*)){

	void* pElement;
	int len;

	LinkedList* filterList = NULL;

	len = ll_len(this);

	if(this != NULL && pFunc != NULL){

		filterList = ll_newLinkedList();

		if(filterList != NULL){

			for(int i=0; i<len; i++){

				pElement = ll_get(this, i);

				if(pFunc(pElement) == 0){

					ll_add(filterList, pElement);
				}
			}
		}
	}
	return filterList;
}
