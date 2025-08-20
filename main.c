#include"idx.h"
#include"memoria_dinamica.h"

int main()
{
    tVector vec;
    tIdx idx;
    crear_memoria_dinamica(&vec,5,sizeof(tIdx));
    destruir_Memoria(&vec);
}
