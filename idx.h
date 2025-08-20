#ifndef IDX_H
#define IDX_H
typedef struct
{
    char nombre[30];
    int orden;
}tIdx;
void indexar_Archivo(const char *archiv, tIdx *idx);
#endif // IDX_H
