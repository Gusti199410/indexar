#ifndef CREAR_ARCHIVO_H_INCLUDED
#define CREAR_ARCHIVO_H_INCLUDED
#include"memoria_dinamica.h"
#include"idx.h"
#include<string.h>
typedef struct
{
    int id;
    char apyn[35];
    int edad;
    char categoria;
    float sueldo;

}tEmpleado;

bool cargar_En_Memoria(tVector *vec,void* dato);
bool cargar_De_Memoria_A_Archivo(const char *archivo,tVector *vec);
#endif // CREAR_ARCHIVO_H_INCLUDED
