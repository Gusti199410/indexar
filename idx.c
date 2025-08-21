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
    fclose(fp);
    return true;
}

void imprimir_En_Pantalla(tVector *vec)
{
    tIdx *inicio=(tIdx*)vec->vec ;
    tIdx *fin=(tIdx*)vec->vec+vec->ce;
    while(inicio<fin)
    {
        printf("\nID: %d\n",inicio->orden);
        printf("NOMBRE: %s\n",inicio->nombre);
        printf("\n---------------------------------\n");
        inicio++;
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
    return true;
}
void leer_Archivo_Idx(const char *archivo)
{
    FILE *fp=fopen(archivo,"rb");
    if(!fp)
    {
        printf("Error al leer archivo");
        exit(1);
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
bool cargar_Archivo_IDX_En_Memoria(const char *archivo,tVector *vec)
{
    FILE *fp= fopen(archivo, "rb");
    if(!fp)
    {
        printf("Error al abrir el archivo");
        return false;
    }
    tIdx id;
    fread(&id,sizeof(tIdx),1,fp);
    while(!feof(fp))
    {
        if(!cargar_En_Memoria(vec,&id))
        {
            printf("Error al cargar archivo");
            return false;
        }
        fread(&id,sizeof(tIdx),1,fp);
    }
    fclose(fp);
    return true;
}
void buscar_Archivo(const char *archivo, tVector *vec)
{
    FILE *fp = fopen(archivo,"rb");
    if(!fp)
    {
        printf("Error al abrir archivo de lectura");
        exit(1);
    }
    tEmpleado emp;
    size_t id_B;
    rewind(fp);
    do
    {
        printf("INGRESE EL ID QUE BUSCA: ");
        scanf("%lu",&id_B);
        tIdx *idx=vec->vec;
        tIdx *fin=vec->vec +(vec->ce*vec->tam_Elemento);
        for(; idx<fin; idx++)
        {

            if(idx->orden == id_B)
            {
                fseek(fp,(idx->orden-1)*sizeof(tEmpleado),SEEK_SET);
                fread(&emp,sizeof(tEmpleado),1,fp);
                printf("\nID: %d\n",emp.id);
                printf("NOMBRE Y APELLIDO: %s\n",emp.apyn);
                printf("EDAD: %d\n",emp.edad);
                printf("CATEGORIA: %c\n",emp.categoria);
                printf("SUELDO: %9.2f\n",emp.sueldo);
                printf("\n****************************************************************\n");
                break;

            }else{
                printf("\nError al ingresar numero\n");
                break;
                }
        }
    }while(id_B!=0);
    fclose(fp);
}
