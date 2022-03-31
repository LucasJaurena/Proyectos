#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    int opcion, returnModifyEmployees, returnDeleteEmployees;
    char salir = 'N';
    Employee list[TAM];

    initEmployees(list, TAM);

    do
    {
        printf("\t\t\tTrabajo Practico N2\n\n");
        printf("1.Altas\n2.Modificar\n3.Baja\n4.Informar\n5.Salir\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        while(opcion<1 || opcion>5)
        {
            printf("\nError!! Ingrese una opcion valida [1-5]: ");
            scanf("%d", &opcion);
            fflush(stdin);
        }

        switch(opcion)
        {
        case 1:
            if((createEmployee(list, TAM)) == 0)
            {
                printf("\nEmpleado agregado correctamente!!\n\n");
            }
            else
            {
                printf("\nA ocurrido un error!!\n\n");
            }

            system("pause");
            system("cls");

            break;

        case 2:

            if((verifyEmployees(list, TAM)) == 0)
            {
                returnModifyEmployees = modifyEmployee(list, TAM);
                if(returnModifyEmployees == 0)
                {
                    printf("\nEmpleado modificado con exito!!\n\n");
                }
                else
                {
                    if(returnModifyEmployees == -2)
                    {
                        printf("\nAccion cancelada con exito!!\n\n");
                    }
                }
            }
            else
            {
                printf("\nError!! Primero debe dar de alta un empleado!!\n\n");
            }

            system("pause");
            system("cls");

            break;

        case 3:
            if((verifyEmployees(list, TAM)) == 0)
            {
                returnDeleteEmployees = deleteEmployee(list, TAM);
                if(returnDeleteEmployees == 0)
                {
                    printf("\nEmpleado eliminado con exito!!!\n\n");
                }
                else
                {
                    if(returnDeleteEmployees == -2)
                    {
                        printf("\nAccion cancelada con exito!!!\n\n");
                    }
                }
            }
            else
            {
                printf("\nError!! Primero debe dar de alta un empleado!!\n\n");
            }

            system("pause");
            system("cls");

            break;

        case 4:
            if((verifyEmployees(list, TAM)) == 0)
            {
                if((printEmployees(list, TAM)) != 0)
                {
                    printf("\nA ocurrido un error!!\n\n");
                }
            }
            else
            {
                printf("\nError!! Primero debe dar de alta un empleado!!\n\n");
            }
            printf("\n");
            system("pause");
            system("cls");

            break;

        case 5:
            printf("\nEsta seguro que desea salir? [S/N]  ");
            salir = toupper(getch());

            while(salir !='S' && salir!='N')
            {
                printf("\nError!!! ingrese una respuesta valida [S/N] ");
                salir = toupper(getch());
            }

            if(salir == 'N')
            {
                printf("\n\nAccion cancelada con exito!!\n\n");
                system("pause");
                system("cls");
            }
            break;
        }
    }
    while(salir == 'N');


    return 0;
}
