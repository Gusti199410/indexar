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

bool ordenar_Archivo(const char *archivo)
{
    FILE *fp=fopen(archivo, "r+b");
    if(!fp)
    {
        printf("Error al abrir el archivo lectura L72 memoria_dinamica\n");
        return false;
    }

    tEmpleado emp;
    tVector v;
    crear_memoria_dinamica(&v, 5, sizeof(tEmpleado));

    // Cargar en memoria
    while(fread(&emp,sizeof(tEmpleado),1,fp) == 1)
    {
        cargar_En_Memoria(&v,&emp);
    }
    fclose(fp);

    // Ordenamiento burbuja
    tEmpleado *e = (tEmpleado*)v.vec;
    tEmpleado *fin = e + v.ce;
    tEmpleado aux;

    for(tEmpleado *i=e; i<fin-1; i++)
    {
        for(tEmpleado *j=e; j<fin-1; j++)
        {
            if(j->id > (j+1)->id)
            {
                memcpy(&aux, j, sizeof(tEmpleado));
                memcpy(j, j+1, sizeof(tEmpleado));
                memcpy(j+1, &aux, sizeof(tEmpleado));
            }
        }
    }

    // Reescribir archivo ordenado
    fp=fopen(archivo, "wb");
    if(!fp)
    {
        printf("Error al abrir archivo en escritura\n");
        return false;
    }
    fwrite(v.vec, sizeof(tEmpleado), v.ce, fp);
    fclose(fp);

    return true;
}
