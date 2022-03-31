#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

void initializer(eMovie* movies, int tam)
{
    int i;

    if(movies != NULL)
    {
        for(i=0; i<tam; i++)
        {
            (movies+i)->estado = 0;

        }
    }
}

int newMovie(eMovie* movie, char titulo[], char genero[], int duracion, char descripcion[], int puntaje, char linkImagen[], int estado)
{
    int retorno = 0;

    if(movie != NULL)
    {
        strcpy(movie->titulo, titulo);
        strcpy(movie->genero, genero);
        movie->duracion = duracion;
        strcpy(movie->descripcion, descripcion);
        movie->puntaje = puntaje;
        strcpy(movie->linkImagen, linkImagen);
        movie->estado = estado;
        retorno = 1;
    }
    return retorno;
}

int agregarPelicula(eMovie* movies, int tam)
{
    int i, auxDuracion, auxPuntaje, auxEstado, retorno = 0;
    char auxTitulo[20], auxGenero[20], auxDescripcion[50], auxLinkImagen[50];

    if(movies != NULL)
    {
        for(i=0; i<tam; i++)
        {
            if((movies+i)->estado == 0)
            {
                printf("\nIngrese el titulo de la pelicula: ");
                fflush(stdin);
                gets(auxTitulo);
                while(strlen(auxTitulo)>20)
                {
                    printf("\nError!! a superado el limite de caracteres ingresados: (20 max)\n\nIngrese el titulo de la pelicula: ");
                    fflush(stdin);
                    gets(auxTitulo);
                }
                printf("\nIngrese el genero: ");
                fflush(stdin);
                gets(auxGenero);
                while(strlen(auxGenero)>20)
                {
                    printf("\nError!! a superado el limite de caracteres ingresados: (20 max)\n\nIngrese el genero de la pelicula: ");
                    fflush(stdin);
                    gets(auxGenero);
                }
                printf("\nIngrese la duracion: ");
                scanf("%d", &auxDuracion);
                printf("\nIngrese la descripcion: ");
                fflush(stdin);
                gets(auxDescripcion);
                while(strlen(auxDescripcion)>50)
                {
                    printf("\nError!! a superado el limite de caracteres ingresados: (50 max)\n\nIngrese la descripcion de la pelicula: ");
                    fflush(stdin);
                    gets(auxDescripcion);
                }
                printf("\nIngrese el puntaje (Entre 0 y 10): ");
                scanf("%d", &auxPuntaje);
                while(auxPuntaje>10 || auxPuntaje<0)
                {
                    printf("\nError!! puntaje no valido\n\nIngrese el puntaje de la pelicula: ");
                    scanf("%d", &auxPuntaje);
                }
                printf("\nIngrese el link de una imagen de la pelicula: ");
                fflush(stdin);
                gets(auxLinkImagen);
                 auxEstado = 1;

                if(newMovie(movies+i, auxTitulo, auxGenero, auxDuracion, auxDescripcion, auxPuntaje, auxLinkImagen, auxEstado))
                {
                    guardarPeliculasBin(movies, tam);
                    retorno = 1;
                    break;
                }
                else
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }

    return retorno;
}

int borrarPelicula(eMovie* movie, int tam)
{
    int i, retorno = 0;
    char auxTitulo[20], opcion;

    if(movie != NULL)
    {
        printf("\nIngrese el titulo de la pelicula a buscar: ");
        fflush(stdin);
        gets(auxTitulo);
        for(i=0; i<tam; i++)
        {
            if(stricmp((movie+i)->titulo, auxTitulo)==0 && (movie+i)->estado == 1)
            {
                printf("\nSe a encontrado la siguiente pelicula: \n\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de la imagen: %s", (movie+i)->titulo, (movie+i)->genero, (movie+i)->duracion, (movie+i)->descripcion, (movie+i)->puntaje, (movie+i)->linkImagen);
                printf("\n\nDesea borrar la pelicula encontrada? s/n");
                opcion = getch();

                if(opcion == 's')
                {
                    (movie+i)->estado = 0;
                    guardarPeliculasBin(movie, tam);
                    retorno = 1;
                    break;
                }
                else
                {
                    printf("\n\nAccion cancelada con exito!!!\n");
                    break;
                }
            }
        }
    }

    return retorno;
}

int modificarPelicula(eMovie* movie, int tam)
{
    int i, auxDuracion, auxPuntaje, auxEstado, retorno = 0;
    char auxTitulo[20], auxGenero[20], auxDescripcion[50], auxLinkImagen[50], opcion;

    if(movie != NULL)
    {
        printf("\nIngrese el titulo de la pelicula a buscar: ");
        fflush(stdin);
        gets(auxTitulo);
        for(i=0; i<tam; i++)
        {
            if(stricmp((movie+i)->titulo, auxTitulo)==0 && (movie+i)->estado == 1)
            {
                printf("\nSe a encontrado la siguiente pelicula: \n\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de la imagen: %s", (movie+i)->titulo, (movie+i)->genero, (movie+i)->duracion, (movie+i)->descripcion, (movie+i)->puntaje, (movie+i)->linkImagen);
                printf("\n\nDesea modificar la pelicula encontrada? s/n");
                opcion = getch();

                if(opcion == 's')
                {
                    printf("\nIngrese el nuevo titulo de la pelicula: ");
                    fflush(stdin);
                    gets(auxTitulo);
                    while(strlen(auxTitulo)>20)
                    {
                        printf("\nError!! a superado el limite de caracteres ingresados: (20 max)\n\nIngrese el nuevo titulo de la pelicula: ");
                        fflush(stdin);
                        gets(auxTitulo);
                    }
                    printf("\nIngrese el nuevo genero: ");
                    fflush(stdin);
                    gets(auxGenero);
                    while(strlen(auxGenero)>20)
                    {
                        printf("\nError!! a superado el limite de caracteres ingresados: (20 max)\n\nIngrese el nuevo genero de la pelicula: ");
                        fflush(stdin);
                        gets(auxGenero);
                    }
                    printf("\nIngrese la nueva duracion: ");
                    scanf("%d", &auxDuracion);
                    printf("\nIngrese la nueva descripcion: ");
                    fflush(stdin);
                    gets(auxDescripcion);
                    while(strlen(auxDescripcion)>50)
                    {
                        printf("\nError!! a superado el limite de caracteres ingresados: (50 max)\n\nIngrese la nueva descripcion de la pelicula: ");
                        fflush(stdin);
                        gets(auxDescripcion);
                    }
                    printf("\nIngrese el nuevo puntaje (Entre 0 y 10): ");
                    scanf("%d", &auxPuntaje);
                    while(auxPuntaje>10 || auxPuntaje<0)
                    {
                        printf("\nError!! puntaje no valido\n\nIngrese el nuevo puntaje de la pelicula: ");
                        scanf("%d", &auxPuntaje);
                    }
                    printf("\nIngrese el nuevo link de la imagen de la pelicula: ");
                    fflush(stdin);
                    gets(auxLinkImagen);
                    auxEstado = 1;

                    if(newMovie(movie+i, auxTitulo, auxGenero, auxDuracion, auxDescripcion, auxPuntaje, auxLinkImagen, auxEstado))
                    {
                        guardarPeliculasBin(movie, tam);
                        retorno = 1;
                        break;
                    }
                    else
                    {
                        retorno = 0;
                        break;
                    }

                }
                else
                {
                    printf("\nAccion cancelada con exito!!!\n");
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

int cargarPeliculasBin(eMovie* movies, int tam)
{
    FILE* archivoDePeliculasBinario;
    int retorno = 0;

    if(movies !=NULL)
    {
        archivoDePeliculasBinario = fopen("Archivo Binario.dat","rb");

        if(archivoDePeliculasBinario == NULL)
        {
            archivoDePeliculasBinario = fopen("Archivo Binario.dat","wb");
            retorno = 1;
        }
        else
        {
            fread(movies, sizeof(eMovie), tam, archivoDePeliculasBinario);
        }
        fclose(archivoDePeliculasBinario);
    }
    else
    {
        printf("\nError!! no hay espacio en memoria!!\n");
    }

    return retorno;
}

void guardarPeliculasBin(eMovie* movies, int tam)
{
    FILE* archivoDePeliculasBinario;

    archivoDePeliculasBinario = fopen("Archivo Binario.dat","wb");

    if(archivoDePeliculasBinario != NULL)
    {
        fwrite(movies, sizeof(eMovie), tam, archivoDePeliculasBinario);
    }

    fclose(archivoDePeliculasBinario);
}

void generarPagina(eMovie* movies, int tam)
{
    FILE* archivoDePeliculasHTML;
    int i;

    archivoDePeliculasHTML = fopen("Index.html", "w");
    fprintf(archivoDePeliculasHTML, "<CENTER>PELICULAS</CENTER>");

    for(i=0; i<tam; i++)
    {
        if((movies+i)->estado == 1)
        {
            fprintf(archivoDePeliculasHTML, "<article class='col-md-4 article-intro'><a href='#'>\
                         <img class='img-responsive img-rounded' src=' %s'alt=''>\
                         </a><h3><a href='#'> %s</a></h3><ul><li>Género: %s</li>\
                        <li>Puntaje: %d</li>\
                        <li>Duración: %d</li>\
                        </ul> <p>%s.</p>\
                        </article>\n", (movies+i)->linkImagen, (movies+i)->titulo, (movies+i)->genero, (movies+i)->puntaje, (movies+i)->duracion, (movies+i)->descripcion);
        }
    }
    fclose(archivoDePeliculasHTML);

    printf("\nArchivo HTML generado correctamente!!!\n\n");
}
