#include"idx.h"

bool indexar_Archivo(const char *archivo, tVector *vec)
{
    FILE *fp=fopen(archivo,"rb");
    if(!fp)
    {
        printf("Error al abrir archivo para indexar");
        return false;
    }
    tEmpleado emp;
    tIdx idx;
    int contador=0;

    fread(&emp,sizeof(tEmpleado),1,fp);
    while(!feof(fp))
    {
        idx.orden=contador+1;
        strcpy(idx.nombre,emp.apyn);
        cargar_En_Memoria(vec,&idx);
        fread(&emp,sizeof(tEmpleado),1,fp);
        contador++;
    }
    return true;
}

void imprimir_En_Pantalla(tVector *vec)
{
    tIdx *inicio=(tIdx*)vec->vec ;
    tIdx *fin=(tIdx*)vec->vec+vec->ce;
    for(tIdx *i= inicio;i<fin;i++)
    {
        printf("\nID: %d\n",i->orden);
        printf("NOMBRE: %s\n",i->nombre);
    }
}

