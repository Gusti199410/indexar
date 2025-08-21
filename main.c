#include"idx.h"
#include"memoria_dinamica.h"
#include"crear_Archivo.h"
#define archivo_binario "arch.bin"
#define archivo_Idx "archivo.idx"


int main()
{
    tVector vec;
    tVector idx;
    tEmpleado emp[]={{10,"Gustavo Neubauer",30,'A',5000.3},
                     {5,"Lidia Beltrami",51,'A',5000.3},
                     {2,"Gabriel Neubauer",22,'A',5000.3},
                     {1,"Gustavo julio Neubauer",55,'A',5000.3},
                     {3,"Aldana Neubauer",26,'A',5000.3},
                     {4,"Mirta Neubauer",59,'A',5000.3}};

/** CREAR MEMORIA PARA ALOJAR DATOS */

    if(!crear_memoria_dinamica(&vec,5,sizeof(tEmpleado)))
    {
        printf("Error al agregar memoria");
    }
    size_t ce=sizeof(emp)/sizeof(tEmpleado);

    for(size_t i=0;i<ce;i++)
    {
        cargar_En_Memoria(&vec,&emp[i]);
    }
     for(size_t i=0;i<ce;i++)
    {
        mostrar_Contenido_De_Memoria(&vec,i);
    }
    /** CREAR MEMORIA PARA ALOJAR IDX */
    crear_memoria_dinamica(&idx,3,sizeof(tIdx));
    cargar_De_Memoria_A_Archivo(archivo_binario,&vec);
    if(!indexar_Archivo(archivo_binario,&idx))
    {
        printf("Error al indexar archivo");
        return 0;
    }
   //imprimir_En_Pantalla(&idx);

    /**CREAR archivo para alojar direccion de idx */
    if(!guardar_Idx_En_Archivo_Bin(archivo_Idx,&idx))
    {
        printf("Error al guardar el archivo");
        return 0;
    }
    printf("\nIDX leidos en archivo\n");
    leer_Archivo_Idx(archivo_Idx);

    return 0;
}
