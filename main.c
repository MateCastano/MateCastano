/*Donde cada BUTACA tiene 0 si el asiento esta vacio, y 1 si está ocupado; CODIGO es el nro de sala y PELI el nombre de la película que se está proyectando
(una película  distinta en cada sala).
Se pide:
    1) Hacer la función (int) MAS_VISTA (struct SALA VEC[4]) Que recibe un vector de 4 salas y retorna
        el CODIGO de sala más concurrida en este momento.
    2) Hacer la función (int) BUSCAR_PELI( struct SALA VEC [4], char TITULO [30]) Que recibe un vector
        de 4 salas y un título, y retorna el CODIGO de la sala en la que se está proyectando,o bien -1 si no está.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num 5
#define filas 4
#define columnas 6

struct SALA
{
    int CODIGO;
    int BUTACA[filas][columnas];
    char PELI[30];
};

void relleno(struct SALA [], int , int , int );
void cargar(struct SALA [], int );
void mirar(struct SALA [], int , int , int );
int masVista(struct SALA []);
int buscarPeli(struct SALA [], char []);

int main()
{
    struct SALA vec[num];
    char titulo[30];
    int codigo;

    relleno(vec, num, filas, columnas);
    mirar(vec, num, filas, columnas);
    cargar(vec, num);

    printf("\nEl codigo de la pelicula mas vista es: %d", (masVista(vec)));

    printf("\nIngrese el titulo que esta buscando: ");
    fflush(stdin);
    gets(titulo);

    codigo = buscarPeli(vec, titulo);

    printf("\nEl codigo de la sala de %s es: %d", titulo, codigo);

    return 0;
}
void mirar(struct SALA v[], int n, int f, int c)
{
    printf("SALAS\n");
    for(int j = 0; j < f; j ++ )
    {
        for(int k = 0; k < c; k ++)
        {
            printf("%4d", v[0].BUTACA[j][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(int j = 0; j < f; j ++ )
    {
        for(int k = 0; k < c; k ++)
        {
            printf("%4d", v[1].BUTACA[j][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(int j = 0; j < f; j ++ )
    {
        for(int k = 0; k < c; k ++)
        {
            printf("%4d", v[2].BUTACA[j][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(int j = 0; j < f; j ++ )
    {
        for(int k = 0; k < c; k ++)
        {
            printf("%4d", v[3].BUTACA[j][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(int j = 0; j < f; j ++ )
    {
        for(int k = 0; k < c; k ++)
        {
            printf("%4d", v[4].BUTACA[j][k]);
        }
        printf("\n");
    }
}
void relleno(struct SALA v[], int n, int f, int c)
{
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < f; j ++)
        {
            for(int k = 0; k < c; k ++)
            {
                v[i].BUTACA[j][k] = 0 + rand() % 2;
            }
        }
    }
}
void cargar(struct SALA v[], int n)
{
    for(int i = 0; i < n; i ++)
    {
        v[i].CODIGO = i + 1;

        if(v[i].CODIGO == 1)
        {
            strcpy(v[i].PELI, "AVENGERS");
        }
        else if(v[i].CODIGO == 2)
        {
            strcpy(v[i].PELI, "STAR WARS");
        }
        else if(v[i].CODIGO == 3)
        {
            strcpy(v[i].PELI, "HARRY POTTER");
        }
        else if(v[i].CODIGO == 4)
        {
            strcpy(v[i].PELI, "TRANSFORMERS");
        }
        else
        {
            strcpy(v[i].PELI, "HALLOWEEN");
        }
    }
}
int masVista(struct SALA v[])
{
    int codigoMayor, contButacas = 0, contAuxButacas = 0;
    for(int i = 0; i < num; i ++)
    {
        contAuxButacas = 0;
        for(int j = 0; j < filas; j ++)
        {
            for(int k = 0; k < columnas; k ++)
            {
                if(v[i].CODIGO == i + 1 && v[i].BUTACA[j][k] != 0)
                {
                    contAuxButacas ++;
                    if(contAuxButacas > contButacas)
                    {
                        contButacas = contAuxButacas;
                        codigoMayor = i + 1;
                    }
                }
            }
        }
    }
    return codigoMayor;
}
int buscarPeli(struct SALA v[], char titulo[])
{
    int codigo;
    for(int i = 0; i < num; i ++)
    {
        if(strcmp(titulo, v[i].PELI) == 0)
        {
            codigo = i + 1;
            break;
        }
        else
        {
            codigo = -1;
        }
    }
    return codigo;
}
