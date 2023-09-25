#include <stdio.h>
#include "library.h"

void manageEmployee(){
    emp employee[50];//Maximum limit of Employees : 50 
    int choice;//choice to input choice 
    char query;//query to ask for more inputs
    menu://label menu
    printf("\n1. Accept Employee Data\n2. Display Net Pay of an Employee\n3. Show Employee Data of an Employee\n4. Update Employee Details \n5. Show All Employee\n6. Delete an Employee\n7. Exit\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1:addEmployeeData(employee);
            break;
    case 2:displayNetPay(employee);
            break;
    case 3:showEmployeeData(employee);
            break;
    case 4:UpdateEmployeeData(employee);
            break;
    case 5:ShowEmployeesData(employee);
            break;
    case 6:DeleteEmployee(employee);
            break;
    case 7:printf("\nExiting.......\n");
            return;
    default:printf("\nInvalid choice\n");
    }
    printf("\nDo you want to continue(Y)?\n");
    scanf("%s",&query);
    if( query == 'Y' || query == 'y' )
        goto menu;
    else
        printf("\nExiting.......\n");
}