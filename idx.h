#ifndef IDX_H
#define IDX_H
#include<stdbool.h>
#include"memoria_dinamica.h"
#include"crear_Archivo.h"
#include"idx.h"
typedef struct
{
    char nombre[30];
    int orden;

}tIdx;
bool indexar_Archivo(const char *archivo, tVector *vec);
void imprimir_En_Pantalla(tVector *vec);
bool guardar_Idx_En_Archivo_Bin(const char *arc,tVector *vec);
void leer_Archivo_Idx(const char *archivo);
#endif // IDX_H
