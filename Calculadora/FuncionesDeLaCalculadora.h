#ifndef FUNCIONESDELACALCULADORA_H_INCLUDED
#define FUNCIONESDELACALCULADORA_H_INCLUDED
#endif

/** \brief Solicita el operando A y/o B y los retorna
 * \return Operandos ingresados por el usuario
 *
 */
float pedirNumero();

/** \brief Recibe los operandos A y B y calcula la suma
 * \param A es el primer operando ingresado
 * \param B es el segundo operando ingresado
 * \return El resultado de la suma
 *
 */

float suma(float,float);

/** \brief Recibe los operandos A y B y calcula la resta
 * \param A es el primer operando ingresado
 * \param B es el segundo operando ingresado
 * \return El resultado de la suma
 *
 */

float resta(float,float);

/** \brief Recibe los operandos A y B y calcula la division
 * \param A es el primer operando ingresado
 * \param B es el segundo operando ingresado
 * \return El resultado de la suma
 *
 */

float division(float,float);

/** \brief Recibe los operandos A y B y calcula la multiplicacion
 * \param A es el primer operando ingresado
 * \param B es el segundo operando ingresado
 * \return El resultado de la multiplicacion
 *
 */

float multiplicacion(float,float);

/** \brief Recibe el operando A y calcula el factorial
 * \param A es el operando ingresado
 * \param i es el contador necesario para calcular el factorial
 * \return El resultado del factorial
 *
 */

int factorial(int);
