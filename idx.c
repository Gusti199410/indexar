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

bool guardar_Idx_En_Archivo_Bin(const char *arc,tVector *vec)
{
    FILE *fp=fopen(arc,"wb");
    if(!fp)
    {
        printf("Error al abrir archivo de escritura idx");
        return false;
    }
    tIdx *inicio=vec->vec;
    tIdx *fin=vec->vec+vec->ce*vec->tam_Elemento;
    while(inicio<fin)
    {
        fwrite(inicio,sizeof(tIdx),1,fp);
        inicio++;
    }
    fclose(fp);
    destruir_Memoria(vec);
}
void leer_Archivo_Idx(const char *archivo)
{
    FILE *fp=fopen(archivo,"rt");
    if(!fp)
    {
        printf("Error al leer archivo");
        return 0;
    }
    tIdx id;
    fread(&id,sizeof(tIdx),1,fp);
    while(!feof(fp))
    {
        printf("\nID: %d\n",id.orden);
        printf("NOMBRE: %s\n",id.nombre);
        printf("\n--------------------------\n");
        fread(&id,sizeof(tIdx),1,fp);
    }
    fclose(fp);
}
