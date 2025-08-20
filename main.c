#include"idx.h"
#include"memoria_dinamica.h"
#include"crear_Archivo.h"
#define archivo_binario "arch.bin"


int main()
{
    tVector vec;
    tEmpleado emp[]={{10,"Gustavo Neubauer",30,'A',5000.3},
                     {5,"Lidia Beltrami",51,'A',5000.3},
                     {2,"Gabriel Neubauer",22,'A',5000.3},
                     {1,"Gustavo julio Neubauer",55,'A',5000.3},
                     {3,"Aldana Neubauer",26,'A',5000.3},
                     {4,"Mirta Neubauer",59,'A',5000.3}};

    crear_memoria_dinamica(&vec,5,sizeof(tEmpleado));
    size_t ce=sizeof(emp)/sizeof(tEmpleado);

    for(size_t i=0;i<ce;i++)
    {
        cargar_En_Memoria(&vec,&emp[i]);
    }
     for(size_t i=0;i<ce;i++)
    {
        mostrar_Contenido_De_Memoria(&vec,i);
    }
    printf("\n///////////////////////////////////////////////////////\n");
    cargar_De_Memoria_A_Archivo(archivo_binario,&vec);
    leer_Archivo_Binario(archivo_binario);

    return 0;
}
