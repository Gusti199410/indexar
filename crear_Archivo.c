#include"crear_Archivo.h"
#include"stdbool.h"

bool cargar_En_Memoria(tVector *vec,void *dato)
{
    if(vec->ce >= vec->tamanio)
    {
        if(!agregar_Memoria(vec))
        {
            printf("\nNo se puedo agregar memoria\n");
            return false;
        }
    }
    void *destino=((char*)vec->vec+(vec->ce*vec->tam_Elemento));
    if(!memcpy(destino,dato,vec->tam_Elemento))
    {
        printf("ERROR AL GRABAR EN MEMORIA");
        return false;
    }
    vec->ce++;
    return true;
}
bool cargar_De_Memoria_A_Archivo(const char *archivo_bin,tVector *vec)
{
    FILE *fp=fopen(archivo_bin,"wb");
    if(!fp)
   {
        printf("Error al abrir el archivo");
        return false;
    }
    tEmpleado *inicio;
    tEmpleado *fin;
    inicio=vec->vec;
    fin=vec->vec +(vec->ce * vec->tam_Elemento);
    while(inicio<fin)
    {
        fwrite(inicio,sizeof(tEmpleado),1,fp);
        inicio++;
    }
    fclose(fp);
    return true;
}
void leer_Archivo_Binario(const char *arc_bin)
{
    FILE *fp=fopen(arc_bin,"rb");
    if(!fp)
    {
        printf("Error al abrir el archivo binario");
        exit(1);
    }
    tEmpleado emp;
    fread(&emp,sizeof(tEmpleado),1,fp);
    while(!feof(fp))
    {
    printf("\nID: %d\n",emp.id);
    printf("NOMBRE Y APELLIDO: %s\n",emp.apyn);
    printf("EDAD: %d\n",emp.edad);
    printf("CATEGORIA: %c\n",emp.categoria);
    printf("SUELDO: %9.2f\n",emp.sueldo);
    printf("****************************************************************");
    fread(&emp,sizeof(tEmpleado),1,fp);
    }
    fclose(fp);
}
