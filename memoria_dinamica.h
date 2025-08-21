#ifndef MEMORIA_DINAMICA_H_INCLUDED
#define MEMORIA_DINAMICA_H_INCLUDED
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
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
void mostrar_Contenido_De_Memoria(tVector *vec,size_t i);
#endif // MEMORIA_DINAMICA_H_INCLUDED
