#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;

} eMovie;

/**
 *  Inicializa los estados de la estructura en 0
 *  \param movie la estructura
 *  \param tam el tamaño de la estructura
 */
void initializer(eMovie*, int);

/**
 *  Crea una nueva pelicula con los datos ingresados
 *  \param movie la estructura
 *  \param tam el tamaño de la estructura
 *  \return retorna 1 o 0 de acuerdo a si pudo crear la pelicula o no
 */
int newMovie(eMovie*, char[], char[], int, char[], int, char[], int);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @param tam el tamaño de la estructura
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie*, int );

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie*, int );

/**
 *  Modifica una pelicula del archivo binario
 *  @param movie la estructura a ser modificada al archivo
 *  @param tam el tamaño de la estructura
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
int modificarPelicula(eMovie*, int);

/**
 *  Carga las peliculas del archivo binario
 *  \param movie la estructura a ser cargada del archivo
 *  \param tam el tamaño de la estructura
 *  \return retorna 1 o 0 de acuerdo a si pudo cargar las peliculas o no
 */
int cargarPeliculasBin(eMovie*, int);

/**
 *  Guarda una pelicula en el archivo binario
 *  \param movie la estructura a ser guardada en el archivo
 *  \param tam el tamaño de la estructura
 */
void guardarPeliculasBin(eMovie*, int);

/**
*  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
*  @param lista la lista de peliculas a ser agregadas en el archivo.
*/
void generarPagina(eMovie*, int);

#endif // FUNCIONES_H_INCLUDED
