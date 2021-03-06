#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} typedef Employee;

/** \brief To indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all
 *         position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee*, int);

/** \brief add in a existing list of employees the values received as parameters
 *         in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 *         free space] - (0) if Ok
 *
 */
int addEmployee(Employee*, int, int, char[], char[], float, int);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 *         pointer received or employee not found]
 */
int findEmployeeById(Employee*, int, int);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 *         find a employee] - (0) if Ok
 */
int removeEmployee(Employee*, int, int);

/** \brief Sort the elements in the array of employees, the argument order
 *         indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee*, int, int);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee*, int);

/** \brief Create a Employee
 *
 * \param list Employee*
 * \param length int
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int createEmployee(Employee*, int);

/** \brief Modify a Employee by Id
 *
 * \param list Employee*
 * \param length int
 * \return int return (-1) if Error - (0) if Ok
 *
 */
int modifyEmployee(Employee*, int);

/** \brief Delete an Employee by Id
 *
 * \param list Employee*
 * \param length int
 * \return int return (-1) if Error - (0) if Ok
 *
 */
int deleteEmployee(Employee*, int);

/** \brief Verify if exist an Employees
 *
 * \param list Employee*
 * \param length int
 * \return int return (-1) if Error - (0) if Ok
 *
 */
int verifyEmployees(Employee*, int);

#endif // ARRAYEMPLOYEES_H_INCLUDED
