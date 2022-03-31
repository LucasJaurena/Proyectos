#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 10

int main()
{
    eMovie movies[TAM];

    char seguir='s';
    int opcion=0;

    if(cargarPeliculasBin(movies, TAM))
    {
        initializer(movies, TAM);
    }

    while(seguir=='s')
    {
        printf("\t\t\t\tTrabajo Practico N3\n\t\t\t\t-------------------\n\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n\n");

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        while(opcion>5 || opcion<1)
        {
            printf("Error!! Ingrese una opcion (Entre el 1 y el 5): ");
            scanf("%d", &opcion);
        }

        switch(opcion)
        {
        case 1:
            if(agregarPelicula(movies, TAM))
            {
                printf("\nPelicula agregada con exito!!!\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("\nError!!! no se pudo agregar la pelicula!!\n\n");
                system("pause");
                system("cls");
            }
            break;

        case 2:
            if(borrarPelicula(movies, TAM))
            {
                printf("\nPelicula eliminada con exito!!!\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("\nLa pelicula NO a sido eliminada o NO se a encontrado!!\n\n");
                system("pause");
                system("cls");
            }
            break;

        case 3:
            if(modificarPelicula(movies, TAM))
            {
                printf("\nPelicula modificada con exito!!!\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("\nLa pelicula NO a sido modificada o NO se a encontrado!!\n\n");
                system("pause");
                system("cls");
            }
            break;

        case 4:
            generarPagina(movies, TAM);
            system("pause");
            system("cls");
            break;

        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
