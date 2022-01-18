#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num 2
#define filas 4
#define columnas 6

struct salas
{
    int butaca[filas][columnas];
};

struct horarios
{
    float hora;
};

struct pelicula
{
    char nombre[50];
};

struct entrada
{
    char titulo[50];
    int sala;
    int fila;
    int columna;
    int asiento[filas][columnas];
    float precio;
    float h;
};

void cargar(struct entrada [], int n);
void mostrarHorarios(struct entrada [], struct pelicula [], struct horarios [], int );
void venta(struct entrada [], struct pelicula [], struct salas [], struct horarios [], int );
void ticket(struct entrada [], int );

int main()
{
    struct salas vec4[8] = {0};
    struct horarios vec3[] = {11.30, 14.30, 17.30, 20.30, 22.30};
    struct pelicula vec2[] = {"Star Wars", "Avengers", "Harry Potter", "Spider-Man", "Space Jam", "Bastardos sin gloria", "Toy Story", "X-Men"};
    struct entrada vec1[num];

    cargar(vec1, num);
    mostrarHorarios(vec1, vec2, vec3, num);
    venta(vec1, vec2, vec4, vec3, num);
    ticket(vec1, num);

    return 0;
}
void cargar(struct entrada v[], int n)
{
    for(int i = 0; i < n; i ++)
    {
        strcpy(v[i].titulo, "");
        v[i].precio = 500;
    }
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < filas; j ++)
        {
            for(int k = 0; k < columnas; k ++)
            {
                v[i].asiento[j][k] = 0;
            }
        }
    }
}
void mostrarHorarios(struct entrada v1[], struct pelicula v2[], struct horarios v3[], int n)
{
    printf("\n\t %4s", "PELICULAS");
    for(int i = 0; i < 8; i ++)
    {
        printf("\n\n\t %4s", v2[i].nombre);
    }

    printf("\n************************************************************");

    printf("\n\t %4s", "HORARIOS");
    for(int i = 0; i < 5; i ++)
    {
        printf("\n\n\t %4.2f", v3[i].hora);
    }

    printf("\n************************************************************");
}
void venta(struct entrada v[], struct pelicula v2[], struct salas v3[], struct horarios v4[], int n)
{
    int nroF, nroC, nroS, validacion, validacionSala;
    float auxHora, horaDeseada;
    char peli[50], respuesta[2];

    printf("\n\t SISTEMA DE VENTA DE ENTRADAS");
    printf("\n");
    for(int i = 0; i < n; i ++)
    {
        do
        {
            printf("\nElija el titulo que desea ver: ");
            fflush(stdin);
            gets(peli);

            for(int j = 0; j < 8; j ++)
            {
                if(strcmpi(peli, v2[j].nombre) == 0)
                {
                    strcpy(v[i].titulo, peli);
                    validacion = 1;
                    validacionSala = j;
                    break;
                }
                else
                {
                    validacion = 0;
                }
            }
            if(validacion == 0)
            {
                printf("\nEl titulo que se ingreso no esta en cartelera, elije un titulo valido");
            }
        }
        while(validacion == 0);

        do
        {
            printf("\nIngrese la sala: ");
            fflush(stdin);
            scanf("%d", &nroS);

            nroS = nroS - 1;

            if(nroS == validacionSala)
            {
                v[i].sala = nroS;
                validacion = 1;
            }
            else
            {
                printf("\nEsta sala no proyecta la pelicula ingresada");
                validacion = 0;
            }
        }
        while(validacion == 0);

        do
        {
            printf("\nIngrese el horario: ");
            fflush(stdin);
            scanf("%f", &horaDeseada);
            for(int j = 0; j < 5; j ++)
            {
                if(horaDeseada == v4[j].hora)
                {
                    v[i].h = horaDeseada;
                    validacion = 1;
                    break;
                }
                else
                {
                    validacion = 0;
                }
            }

            if(validacion == 0)
            {
                printf("\nEl horario ingresado no es correcto, ingreso un horario disponible en la cartelera");
            }

        }while(validacion == 0);

        do
        {
            printf("\nIngrese numero de fila de su asiento(maximo 4): ");
            fflush(stdin);
            scanf("%d", &nroF);
            printf("Ingrese numero de columna de su asiento(maximo 6): ");
            fflush(stdin);
            scanf("%d", &nroC);

             auxHora = v[i].h;

            if(nroF > filas || nroC > columnas || (v3[nroS].butaca[nroF][nroC] == 1 && v[i].h == auxHora))
            {
                printf("\nEl ingreso del asiento esta ocupado o no cumple con los requisitos");
                validacion = 0;
            }
            else
            {
                v[nroS].asiento[nroF][nroC] = 1;
                v3[nroS].butaca[nroF][nroC] = 1;
                v[i].fila = nroF - 1;
                v[i].columna = nroC - 1;
                validacion = 1;
            }
        }
        while(validacion == 0);

        do
        {
            printf("\nEl total a pagar es de 500 pesos, desea ver la pelicula en calidad 3D por 100 pesos adicionales?(SI / NO): ");
            fflush(stdin);
            gets(respuesta);

            if(strcmp(respuesta,"SI") == 0)
            {
                v[i].precio = v[i].precio + 100;
                validacion = 0;
            }
            else if(strcmp(respuesta,"NO") == 0);
            {
                validacion = 0;
            }
            if(strcmp(respuesta,"NO") != 0 && (strcmp(respuesta,"SI") != 0))
            {
                printf("\nIngrese SI o NO");
                validacion = 1;
            }
        }while(validacion == 1);

        printf("************************************************************");
    }
}
void ticket(struct entrada v[], int n)
{
    for(int i = 0; i < n; i ++)
    {
        printf("\nTICKET VALIDO PARA:");
        printf("\n\t %4s", v[i].titulo);

        printf("\n\tSALA: %4d", (v[i].sala + 1));

        printf("\n\tColumna: %4d", (v[i].columna + 1));
        printf("\n\tFila: %4d", (v[i].fila + 1));

        printf("\n\tHorario: %4.2f", v[i].h);

        printf("\n");

        printf("\n\tTOTAL A PAGAR: %4.2f", v[i].precio);

        printf("\n************************************************************");
    }
}
