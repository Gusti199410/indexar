#include"memoria_dinamica.h"
bool crear_memoria_dinamica(tVector *vec, size_t tamanio, size_t tam_Elemento)
{
    vec->vec=malloc(tamanio*tam_Elem);
    if(!vec->vec)
    {
        printf("Error al agregar memoria");
        return false;
    }
    vec->tamanio=tamanio;
    vec->tam_Elemento=tam_Elemento;
    vec->ce=0;

    return true;

}

bool agregar_Memoria(tVector *vec)
{
    size_t nuevo_Tamanio=vec->tamanio*2;
    void *aux=realloc(vec->vec,nuevo_Tamanio*vec->tam_Elemento);
    if(!aux)
    {
        printf("Error al agregar memoria");
        return false;
    }

    vec->vec=aux;

    vec->tamanio=nuevo_Tamanio;

    return true;

}

bool destruir_Memoria(tVector *vec)
{
    free(vec->vec);
    vec->vec=NULL;
    vec->ce=0;
    vec->tamanio=0;
    vec->tam_Elemento=0;
    return true;
}
