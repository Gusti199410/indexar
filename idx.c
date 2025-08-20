#include"memoria_dinamica.h"

void indexar_Archivo(const char *archivo, tIdx *idx)
{
    FILE *fp=fopen(archivo,"rb");
    if(!fp)
    {
        printf("Error al abrir archivo para indexar");
        exit(1);
    }
    tEmpleado emp;
    fread(&emp,sizeof(tEmpleado),1,fp);
    while(!feof(fp))
    {
        idx.orden+=1;
    }
}
