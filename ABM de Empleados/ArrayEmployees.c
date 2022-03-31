#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <strings.h>
#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
    }

    return 0;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int retorno=-1, i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            list[i].id = id;
            strcpy(list[i].name, name);
            strcpy(list[i].lastName, lastName);
            list[i].salary = salary;
            list[i].sector = sector;
            list[i].isEmpty = 0;
            retorno = 0;
            break;
        }
    }

    return retorno;
}

int findEmployeeById(Employee* list, int len, int id)
{
    int retorno=-1, i;

    for(i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }

    }

    return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
    int retorno=-1, index;
    char aceptar;

    index = findEmployeeById(list, len, id);

    if(index != -1)
    {
        printf("\nSe a encontrado el siguiente empleado: \nId: %d, Nombre: %s, Apellido: %s, Salario: %.2f, Sector: %d", list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);
        printf("\n\nDesea eliminarlo? [S/N]");
        aceptar = toupper(getch());

        while(aceptar !='S' && aceptar!='N')
        {
            printf("\nError!!! ingrese una respuesta valida [S/N] ");
            aceptar = toupper(getch());
        }

        if(aceptar == 'S')
        {
            list[index].isEmpty = 1;
            retorno = 0;
        }
        else
        {
            retorno = -2;
        }
    }
    else
    {
        printf("\nError!! no se a encontrado el ID ingresado!!\n\n");
    }

    return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
    Employee auxList;
    int retorno=-1, i, j;

    if(order == 1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName, list[j].lastName) > 0)
                {
                    auxList = list[i];
                    list[i] = list[j];
                    list[j] = auxList;
                }
                else
                {
                    if(strcmp(list[i].lastName, list[j].lastName) == 0)
                    {
                        if(list[i].sector > list[j].sector)
                        {
                            auxList = list[i];
                            list[i] = list[j];
                            list[j] = auxList;
                        }
                    }
                }
            }
        }
    }
    else
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName, list[j].lastName) < 0)
                {
                    auxList = list[i];
                    list[i] = list[j];
                    list[j] = auxList;
                }
                else
                {
                    if(strcmp(list[i].lastName, list[j].lastName) == 0)
                    {
                        if(list[i].sector < list[j].sector)
                        {
                            auxList = list[i];
                            list[i] = list[j];
                            list[j] = auxList;
                        }
                    }
                }
            }
        }
    }

    return retorno;
}

int printEmployees(Employee* list, int len)
{
    int retorno=-1, i, order, contEmployees = 0, contSalary = 0;
    float acumSalary, promSalary;

    printf("\nElija el orden de la lista de empleados:\n\n1.Ascendente\n2.Descendente\n\nIngrese una opcion: ");
    scanf("%d", &order);
    fflush(stdin);
    while(order<1 || order>2)
    {
        printf("\nError!! Ingrese una opcion valida [1-2]: ");
        scanf("%d", &order);
        fflush(stdin);
    }
    sortEmployees(list, len, order);
    printf("\n\t\t\tLISTA DE EMPLEADOS\n\n");

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printf("ID: %d,  Apellido: %s, Nombre: %s, Salario: %.2f, Sector: %d\n", list[i].id, list[i].lastName, list[i].name, list[i].salary, list[i].sector);
            retorno = 0;
        }
    }

    printf("\n======================================================================\n\n");

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            acumSalary+=list[i].salary;
            contSalary++;
        }
    }

    promSalary = acumSalary / (float)contSalary;

    for(i=0; i<len; i++)
    {
        if(list[i].salary > promSalary && list[i].isEmpty == 0)
        {
            contEmployees++;
        }
    }

    printf("\nTotal de los salarios: %.2f \nPromedio de los salarios: %.2f \nCantidad de empleados que superan el salario promedio: %d\n", acumSalary, promSalary, contEmployees);

    return retorno;
}

int createEmployee(Employee* list, int len)
{
    int retorno=-1, i, id, sector, largoCadena, flag = 0, flagAddEmployee;
    char name[51], lastName[51];
    float salary;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            id = 100+i;
            printf("\nIngrese un nombre: ");
            fflush(stdin);
            fgets(name, sizeof(name)-2, stdin);
            largoCadena = strlen(name);
            name[largoCadena-1] = '\0';
            printf("Ingrese un apellido: ");
            fflush(stdin);
            fgets(lastName, sizeof(lastName)-2, stdin);
            largoCadena = strlen(lastName);
            lastName[largoCadena-1] = '\0';
            printf("Ingrese el salario: ");
            scanf("%f", &salary);
            printf("Ingrese el sector: ");
            scanf("%d", &sector);
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        flagAddEmployee = addEmployee(list, len, id, name, lastName, salary, sector);

        if(flagAddEmployee == 0)
        {
            retorno = 0;
        }

    }

    return retorno;
}

int modifyEmployee(Employee* list, int len)
{
    int retorno=-1, auxId, index, largoCadena;
    char aceptar;

    printf("\nIngrese un ID a buscar: ");
    scanf("%d", &auxId);
    index = findEmployeeById(list, len, auxId);

    if(index != -1)
    {
        printf("\nSe a encontrado el siguiente empleado: \nId: %d, Nombre: %s, Apellido: %s, Salario: %.2f, Sector: %d", list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);
        printf("\n\nDesea modificarlo? [S/N]");
        aceptar = toupper(getch());

        while(aceptar !='S' && aceptar!='N')
        {
            printf("\nError!!! ingrese una respuesta valida [S/N] ");
            aceptar = toupper(getch());
        }

        if(aceptar == 'S')
        {
            printf("\nIngrese el nombre modificado: ");
            fflush(stdin);
            fgets(list[index].name, sizeof(list[index].name)-2, stdin);
            largoCadena = strlen(list[index].name);
            list[index].name[largoCadena-1] = '\0';
            printf("Ingrese el apellido modificado: ");
            fflush(stdin);
            fgets(list[index].lastName, sizeof(list[index].lastName)-2, stdin);
            largoCadena = strlen(list[index].lastName);
            list[index].lastName[largoCadena-1] = '\0';
            printf("Ingrese el salario modificado: ");
            scanf("%f", &list[index].salary);
            printf("Ingrese el sector modificado: ");
            scanf("%d", &list[index].sector);
            retorno = 0;
        }
        else
        {
            retorno = -2;
        }
    }
    else
    {
        printf("\nError!!! no se a encontrado el ID ingresado!!\n\n");
    }

    return retorno;
}

int deleteEmployee(Employee* list, int len)
{
    int retorno=-1, auxId, retornoRemoveEmployees;

    printf("\nIngrese un ID a buscar: ");
    scanf("%d", &auxId);
    retornoRemoveEmployees = removeEmployee(list, len, auxId);

    if(retornoRemoveEmployees == 0)
    {
        retorno = 0;
    }
    else
    {
        if(retornoRemoveEmployees == -2)
        {
            retorno = -2;
        }
    }

    return retorno;
}

int verifyEmployees(Employee* list, int len)
{
    int retorno=-1, i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}
