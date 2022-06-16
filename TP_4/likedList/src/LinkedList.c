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

	if(this != NULL && len > 0 && nodeIndex < len && nodeIndex >= 0){

		pNode = this->pFirstNode;

		for(int i=0; i<nodeIndex; i++){

			pNode = pNode -> pNextNode;
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
    Node* nodePrev;
    Node* nodeNext;

    len = ll_len(this);

    if (this != NULL){

    	if (nodeIndex <= len && nodeIndex >= 0){

    	   newNode = (Node*)malloc(sizeof(Node));

    	   if (newNode != NULL){

				newNode->pElement = pElement;
				newNode->pNextNode = NULL;

				if (nodeIndex == 0){

					newNode->pNextNode = this->pFirstNode;
					this->pFirstNode = newNode;
				} else {

					nodePrev = this->pFirstNode;
					nodeNext = nodePrev->pNextNode;

					//No puedo usar do/while porque mi programa finaliza
					while(nodeIndex > 1){

						nodePrev = nodeNext;
						nodeNext = nodePrev->pNextNode;
						nodeIndex--;
					}

					nodePrev->pNextNode = newNode;
					newNode->pNextNode = nodeNext;
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
		retorno = nodeAux->pElement;
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

	if(this != NULL && index >= 0 && index < len && len > 0){

		nodeAux = getNode(this,index);
		nodeAux->pElement = pElement;
		retorno = 0;
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
            this->size--;
           retorno = 0;
        } else {

        	if(index>=1){

        		nodeAux = getNode(this,index);
        		nodePrev = getNode(this,index-1);
        		nodeNext = getNode(this,index+1);
				nodePrev->pNextNode = nodeNext;
				free(nodeAux);
				this->size--;
				retorno = 0;
        	}
        }
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
	int len;

	Node* current; //Actual

	len = ll_len(this);

	if (this!=NULL){

		for(int i=0;i<len;i++){

			current = getNode(this,0);
			free(current);
			this->size--;
		}
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

	Node* current; //Actual

	len = ll_len(this);

	if (this!=NULL){

		current = this->pFirstNode;

		for(int i=0;i<len;i++){

			if (current->pElement == pElement){

				retorno = i;
			} else {
				current = current->pNextNode;
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
    void* retorno = NULL;
    void* nodeAux;
    int len;

    len = ll_len(this);

    if (this != NULL && index>=0 && index <= len){

        nodeAux = ll_get(this,index);
        ll_remove(this,index);
       retorno = nodeAux;
    }
    return retorno;
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
    int len;
	int flag = 0;

    Node* current;

    len = ll_len(this);

    if (this != NULL){

    	for(int i=0;i<len;i++){

            current = getNode(this,i);

            if (current->pElement == pElement){

            	retorno = 1;
                flag = 1;
            }
        }
        if (flag == 0){

        	retorno = 0;
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
    int flag = 1;
    int len2;
    void* elementAux;


    len2 = ll_len(this2);

    if (this != NULL && this2 != NULL){

    	for(int i=0;i<len2;i++){

            elementAux = ll_get(this2,i);

            if(ll_contains(this,elementAux)==0){

            	retorno = 0;
                flag = 0;
                break;
            }
        }
        if (flag == 1){

           retorno = 1;
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
    void* elementAux;

	LinkedList* sublist = NULL;

    if(this != NULL && from >= 0 && this->size >= to){

    	sublist = ll_newLinkedList();

        for(int i=from;i<to;i++){

        	elementAux = ll_get(this,i);
            ll_add(sublist,elementAux);
        }
    } else {

    	sublist = NULL;
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
	void* elementAux;
	int len;

	LinkedList* cloneList = NULL;

    cloneList = ll_newLinkedList();

    len = ll_len(this);

    if(this!=NULL){

    	for(int i=0;i<len;i++){

    		elementAux = ll_get(this,i);
            addNode(cloneList,i,elementAux);
        }
    } else {

    	cloneList = NULL;
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
    int orderAux;
    int len;
    void* nodeFirst;
    void* nodeSecond;

    len = ll_len(this);

    if(this != NULL && len > 0 && pFunc != NULL && (order == 0 || order == 1)){

    	if(order == 0){

    		for(int i = 0; i<len-1; i++){

    			for(int j = i+1; j<len; j++){

    				nodeFirst = ll_get(this, i);
    				nodeSecond = ll_get(this, j);
    				orderAux = pFunc(nodeFirst, nodeSecond);

    				if(orderAux < 0){

    					ll_set(this, i, nodeSecond);
    					ll_set(this, j, nodeFirst);
    				}
    			}
    		}
    		retorno = 0;
    	} else {

    		if(order == 1){

    			for(int i = 0; i<len-1; i++){

    				for(int j = i+1; j<len; j++){

    					nodeFirst = ll_get(this, i);
    					nodeSecond = ll_get(this, j);
    					orderAux = pFunc(nodeFirst, nodeSecond);

    					if(orderAux > 0){

    						ll_set(this, i, nodeSecond);
    						ll_set(this, j, nodeFirst);
    					}
    				}
    			}
    			retorno = 0;
    		}
    	}
    }

    return retorno;
}

