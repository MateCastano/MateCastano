/*Se cuenta con un vector de estructuras con datos de camiones que realizan viajes entre ciudades.

struct fecha { int dia; int mes; int anio; }

struct viajecamion {
	char patente[10];
	char ciudad_origen[50];
	char ciudad_destino[50];
float peso_transportado;
struct fecha fecha_viaje;
}

Construya cuatro funciones que reciban el vector y su tamaño, y realicen lo siguiente:

a) Permita el ingreso de los datos de 4 camiones y 2 viajes para cada uno.

b) Muestre en pantalla las patentes, sin repetir. No se debe modificar el orden del vector original.

c) Muestre en pantalla la patente del camión que más viajes realizó. Para esto modifique el punto a, de manera de poder ingresar algún camión con más viajes y
probar este punto c.

d) Muestre en pantalla todos los viajes, ordenados por fecha. Los que son de la misma fecha se deben ordenar por peso transportado descendente.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num 8
#define viajes 10

struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct viajecamion
{
    char patente[10];
    char ciudad_origen[50];
    char ciudad_destino[50];
    float peso_transportado;
    struct fecha fecha_viaje;
};

void cargar(struct viajecamion[], int );
void patentes(struct viajecamion[], int );
void maxPatente(struct viajecamion[], int );
void inicializar(struct viajecamion [], int);
void ordenamiento(struct viajecamion [], int);

int main()
{
    struct viajecamion vec[num];
    inicializar(vec, num);
    cargar(vec, num);
    patentes(vec, num);
    ordenamiento(vec, num);

    return 0;
}
void inicializar(struct viajecamion v[], int n)
{
    for(int i = 0; i < n; i ++)
    {
        strcpy(v[i].patente, "");
        strcpy(v[i].ciudad_origen,"");
        strcpy(v[i].ciudad_destino,"");
        v[i].peso_transportado = 0;
        v[i].fecha_viaje.dia = 0;
        v[i].fecha_viaje.mes = 0;
        v[i].fecha_viaje.anio = 0;
    }
}

void cargar(struct viajecamion v[], int n)
{
    char auxPatente[20];

    for(int i = 0; i < n; i++)
    {
        contViajes = 0;
        printf("Ingrese una patente: ");
        fflush(stdin);
        gets(auxPatente);

        strcpy(v[i].patente, auxPatente);
        printf("Ingrese origen: ");
        fflush(stdin);
        gets(v[i].ciudad_origen);

        printf("Ingrese destino: ");
        fflush(stdin);
        gets(v[i].ciudad_destino);

        printf("Ingrese peso: ");
        fflush(stdin);
        scanf("%f", &v[i].peso_transportado);

        printf("Ingrese dia/mm/anio: ");
        fflush(stdin);
        scanf("%d/%d/%d", &v[i].fecha_viaje.dia, &v[i].fecha_viaje.mes, &v[i].fecha_viaje.anio);

        printf("\n");
    }
}

void patentes(struct viajecamion v[], int n)
{
    int registrada = 0;
    char patentes[10][10] = {""};
    for(int i = 0; i < n; i++)
    {
        registrada = 0;
        if(i == 0)
        {
            printf("%s\n", v[i].patente);
            strcpy(patentes[i], v[i].patente);
        }else
        {
            for(int j = 0; j < 10; j++)
            {
               if(strcmp(patentes[j], v[i].patente) == 0)
               {
                   registrada = 1;
                   break;
               }
            }
            if(registrada == 0)
            {
                printf("%s\n", v[i].patente);
                strcpy(patentes[i], v[i].patente);
            }

        }
    }
    printf("\n");
}
void maxPatente(struct viajecamion v[], int n)
{
    int i, j, cantViajes = 0, auxMayor = 0;
    char mayorPatente[10];
    for(i = 0; i < n; i ++)
    {
        cantViajes = 0;
        for(j = 0; j < viajes; j ++)
        {
            if(strcmp(v[i].ciudad_origen, "") != 0)
            {
                cantViajes ++;
            }
        }
        if(cantViajes > auxMayor)
        {
            auxMayor = cantViajes;
            strcpy(mayorPatente, v[i].patente);
        }
    }
    printf("\nLa patente que mas viajes hizo fue: %s", mayorPatente);
}

void ordenamiento(struct viajecamion v[], int n)
{
    struct viajecamion aux;

    for(int i = 0; i < n -1; i++)
    {
        if(strcmp(v[i].ciudad_origen, "") != 0)
        {
            for(int j = 1 + i; j < n; j++)
            {
                if(v[i].fecha_viaje.anio > v[j].fecha_viaje.anio ||
                   (v[i].fecha_viaje.anio == v[j].fecha_viaje.anio && v[i].fecha_viaje.mes > v[j].fecha_viaje.mes) ||
                   (v[i].fecha_viaje.anio == v[j].fecha_viaje.anio && v[i].fecha_viaje.mes == v[j].fecha_viaje.mes && v[i].fecha_viaje.dia == v[j].fecha_viaje.dia) ||
                   (v[i].fecha_viaje.anio == v[j].fecha_viaje.anio && v[i].fecha_viaje.mes == v[j].fecha_viaje.mes && v[i].fecha_viaje.dia == v[j].fecha_viaje.dia && v[i].peso_transportado > v[j].peso_transportado))
                {
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(strcmp(v[i].ciudad_origen, "") != 0)
        {
            printf("%s %s %s %d/%d/%d %f\n",
                   v[i].patente,
                   v[i].ciudad_origen,
                   v[i].ciudad_destino,
                   v[i].fecha_viaje.dia,
                   v[i].fecha_viaje.mes,
                   v[i].fecha_viaje.anio,
                   v[i].peso_transportado);
        }
    }
}
