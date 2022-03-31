#include <stdio.h>
#include <stdlib.h>
#include "FuncionesDeLaCalculadora.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivi;
    float resultadoMulti;
    long unsigned int resultadoFacto;
    float num1;
    float num2;
    int flagNum1 = 0;
    int flagNum2 = 0;

    while(seguir=='s')
    {
        system("color 3");
        if(flagNum1 == 0 && flagNum2 == 0)
        {
            printf("\n\t\t\t\tCALCULADORA\n\n");
            printf("1- Ingresar 1er operando (A=x)\n");
            printf("2- Ingresar 2do operando (B=y)\n");
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");
            printf("\nElija una opcion y presione ENTER: ");
        }
        else if(flagNum1 == 1 && flagNum2 == 0)
        {
            printf("\n\t\t\t\tCALCULADORA\n\n");
            printf("1- Ingresar 1er operando (A=%.2f)\n",num1);
            printf("2- Ingresar 2do operando (B=y)\n");
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");
            printf("\nElija una opcion y presione ENTER: ");
        }
        else if(flagNum1 == 0 && flagNum2 == 1)
        {
            printf("\n\t\t\t\tCALCULADORA\n\n");
            printf("1- Ingresar 1er operando (A=x)\n");
            printf("2- Ingresar 2do operando (B=%.2f)\n",num2);
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");
            printf("\nElija una opcion y presione ENTER: ");
        }
        else
        {
            printf("\n\t\t\t\tCALCULADORA\n\n");
            printf("1- Ingresar 1er operando (A=%.2f)\n",num1);
            printf("2- Ingresar 2do operando (B=%.2f)\n",num2);
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");
            printf("\nElija una opcion y presione ENTER: ");
        }

        scanf("%d",&opcion);

        if(opcion < 1 || opcion > 9)
        {
            printf("\nError!! Ingrese una opcion valida!!\n\n");
            system("pause");
            system("cls");
        }

        switch(opcion)
        {
            case 1: num1 = pedirNumero();
                    flagNum1 = 1;
                    system("pause");
                    system("cls");

                break;
            case 2: num2 = pedirNumero();
                    flagNum2 = 1;
                    system("pause");
                    system("cls");

                break;
            case 3: if(flagNum1 == 0 && flagNum2 == 0)
                    {
                        printf("\nError!! No a ingresado ningun numero\n\n");
                        system("pause");
                        system("cls");
                    }
                    else if(flagNum1 == 0 || flagNum2 == 0)
                    {
                        printf("\nError!! Inngrese el numero que falta \n\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        resultadoSuma = suma(num1,num2);
                        printf("\nEl resultado de la suma es: %.2f\n\n",resultadoSuma);
                        system("pause");
                        system("cls");
                    }

                break;
            case 4: if(flagNum1 == 0 && flagNum2 == 0)
                    {
                        printf("\nError!! No a ingresado ningun numero\n\n");
                        system("pause");
                        system("cls");
                    }
                    else if(flagNum1 == 0 || flagNum2 == 0)
                    {
                        printf("\nError!! Inngrese el numero que falta \n\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        resultadoResta = resta(num1,num2);
                        printf("\nEl resultado de la resta es: %.2f\n\n",resultadoResta);
                        system("pause");
                        system("cls");
                    }
                break;
            case 5: if(flagNum1 == 0 && flagNum2 == 0)
                    {
                        printf("\nError!! No a ingresado ningun numero\n\n");
                        system("pause");
                        system("cls");
                    }
                    else if(flagNum1 == 0 || flagNum2 == 0)
                    {
                        printf("\nError!! Inngrese el numero que falta \n\n");
                        system("pause");
                        system("cls");
                    }
                    else if(num1 == 0 || num2 == 0)
                    {
                        printf("\nNo se puede realizar la division si un operando es 0\n\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        resultadoDivi = division(num1,num2);
                        printf("\nEl resultado de la division es: %.2f\n\n",resultadoDivi);
                        system("pause");
                        system("cls");
                    }
                break;
            case 6: if(flagNum1 == 0 && flagNum2 == 0)
                    {
                        printf("\nError!! No a ingresado ningun numero\n\n");
                        system("pause");
                        system("cls");
                    }
                    else if(flagNum1 == 0 || flagNum2 == 0)
                    {
                        printf("\nError!! Inngrese el numero que falta \n\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        resultadoMulti = multiplicacion(num1,num2);
                        printf("\nEl resultado de la multiplicacion es: %.2f\n\n",resultadoMulti);
                        system("pause");
                        system("cls");
                    }
                break;
            case 7: if(num1 - (int)num1 == 0)
                    {
                        resultadoFacto = factorial(num1);
                        printf("\nEl resultado del facorial es: %lu\n\n",resultadoFacto);
                        system("pause");
                        system("cls");
                    }
                    else if(flagNum1 == 0)
                    {
                        printf("\nError!! No a ingresado el numero A\n\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("\nError!! No se puede calcular el factorial porque a ingresado un numero con decimales\n\n");
                        system("pause");
                        system("cls");
                    }


                break;
            case 8: if(flagNum1 == 0 && flagNum2 == 0)
                    {
                        printf("\nError!! No a ingresado ningun numero\n\n");
                        system("pause");
                        system("cls");
                    }
                    else if(flagNum1 == 0 || flagNum2 == 0)
                    {
                        printf("\nError!! Inngrese el numero que falta \n\n");
                        system("pause");
                        system("cls");
                    }
                    else if(num1 == 0 || num2 == 0)
                    {
                        resultadoSuma = suma(num1,num2);
                        resultadoResta = resta(num1,num2);
                        resultadoMulti = multiplicacion(num1,num2);
                        printf("\nEl resultado de la suma es: %.2f\n",resultadoSuma);
                        printf("\nEl resultado de la resta es: %.2f\n",resultadoResta);
                        printf("\nNo se puede realizar la division si un operando es 0\n");
                        printf("\nEl resultado de la multiplicacion es: %.2f\n\n",resultadoMulti);

                        system("pause");
                        system("cls");
                    }
                    else if(num1 - (int)num1 == 0)
                    {
                        resultadoSuma = suma(num1,num2);
                        resultadoResta = resta(num1,num2);
                        resultadoDivi = division(num1,num2);
                        resultadoMulti = multiplicacion(num1,num2);
                        resultadoFacto = factorial(num1);
                        printf("\nEl resultado de la suma es: %.2f\n",resultadoSuma);
                        printf("\nEl resultado de la resta es: %.2f\n",resultadoResta);
                        printf("\nEl resultado de la division es: %.2f\n",resultadoDivi);
                        printf("\nEl resultado de la multiplicacion es: %.2f\n",resultadoMulti);
                        printf("\nEl resultado del facorial es: %lu\n\n",resultadoFacto);
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        resultadoSuma = suma(num1,num2);
                        resultadoResta = resta(num1,num2);
                        resultadoDivi = division(num1,num2);
                        resultadoMulti = multiplicacion(num1,num2);
                        printf("\nEl resultado de la suma es: %.2f\n",resultadoSuma);
                        printf("\nEl resultado de la resta es: %.2f\n",resultadoResta);
                        printf("\nEl resultado de la division es: %.2f\n",resultadoDivi);
                        printf("\nEl resultado de la multiplicacion es: %.2f\n",resultadoMulti);
                        printf("\nError!! No se puede calcular el factorial porque a ingresado un numero con decimales\n\n");

                        system("pause");
                        system("cls");
                    }
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}
