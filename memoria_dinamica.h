#ifndef MEMORIA_DINAMICA_H_INCLUDED
#define MEMORIA_DINAMICA_H_INCLUDED
#include""
#include"idx.h"
typedef struct
{
    void *vec;
    size_t tamanio;
    size_t ce;
    size_t tam_Elemento;

}tVector;



bool crear_memoria_dinamica(tVector *vec,size_t tamanio,size_t tam_Elemento);
bool agregar_Memoria(tVector *vec);
bool destruir_Memoria(tVector *vec);
#endif // MEMORIA_DINAMICA_H_INCLUDED
