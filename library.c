#include <stdio.h>
#include <string.h>
#include "empStruc.h"
#include "validation.h"

//Factors for finding DA , TA & PF 
#define DA_PERCENT 0.40
#define TA_PERCENT 0.10
#define PF_PERCENT 0.05

int c=0,maxEmpNo=150;

//Function to Accept Employee Data
void acceptEmployeeData(emp *employee){
    employee->empNo=100+c+maxEmpNo-150;
    printf("\nEnter details of Employee whose Employee Number is assigned %d \n",employee->empNo);
    enterEmpName:
    printf("\nEnter Employee Name:");
    scanf("%s",employee->empName);
     if(checkEmpName(employee->empName)==0){
        goto enterEmpName;
    }
    enterHireDate:
    printf("\nEnter Hire Date in digits ( dd mm yyyy):");
    scanf("%d %d %d",&employee->hireDate.dd,&employee->hireDate.mm,&employee->hireDate.yyyy);
    if(checkHireDate(employee->hireDate.dd,employee->hireDate.mm,employee->hireDate.yyyy)==0){
        goto enterHireDate;
    }
    enterBasicSalary:
    printf("\nEnter Basic Salary in digits:");
    scanf("%f",&employee->basicSalary);
    if(checkBasicSalary(employee->basicSalary)==0){
        goto enterBasicSalary;
    }
    
}

//Function to Compute Net Pay
void computeNetPay(emp *employee){
    //calculating Net Pay = Basic Salary + TA + DA - PF 
    //TA= Basic Salary * TA_PERCENT
    //DA= Basic Salary * DA_PERCENT
    //PF= Basic Salary * PF_PERCENT
    employee->netPay=employee->basicSalary*(1 + TA_PERCENT + DA_PERCENT- PF_PERCENT);
}

//Function to display Employee Data
void displayEmployeeData(const emp *employee){
    printf("\nEmployee Data:\n");
    printf("\nEmployee Number: %d",employee->empNo);
    printf("\nEmployee Name: %s",employee->empName);
    printf("\nHire Date: %2d/%2d/%4d",employee->hireDate.dd,employee->hireDate.mm,employee->hireDate.yyyy);
    printf("\nBasic Salary: %7.2f",employee->basicSalary);
    printf("\nNet Pay: %8.2f",employee->netPay);
}

//Function to Add Employee Data
void addEmployeeData(emp employee[]){
    if(checkCount(c+1)==0){
        printf("/nMaximum limit of insertion/nData cannot be entered/n");
    }
    else{
    acceptEmployeeData(&employee[c++]);
    computeNetPay(&employee[c-1]);
    }
}

//Function to show Employee Data
void showEmployeeData(emp employee[]){
    int id,i,count=0;
    enterEmpNo:
    printf("Enter Employee No of the required employee : ");
    scanf("%d",&id);
    if(checkEmpNo(id,maxEmpNo)==0){
        goto enterEmpNo;
    }
    if(c>0){
        for(i=0;i<=c;i++){
            if(employee[i].empNo==id){
                displayEmployeeData(&employee[i]);
                count++;
            }
        }
        if(count==0){
            printf("\nWrong Employee number entered\n");
        }
    }
    else
        printf("\nEmployee record Null\n");
}

//Function to display Net pay
void displayNetPay(emp employee[]){
    int id,i,count=0;
    enterEmpNo:
    printf("Enter Employee No of the required employee : ");
    scanf("%d",&id);
    if(checkEmpNo(id,maxEmpNo)==0){
        goto enterEmpNo;
    }
    if(c>0){
        for(i=0;i<=c;i++){
            if(employee[i].empNo==id){
                printf("\nNet Pay of the employee is %8.2f\n",employee[i].netPay);
                count++;
            }
            if(count==0){
                printf("\nWrong Employee number entered\n");
            }
        }
    }
    else
        printf("\nEmployee record Null\n");
}


//Function to update Employee Data
void UpdateEmployeeData(emp employee[]){
    int id,i,count=0,choice;
    enterEmpNo:
    printf("Enter Employee No of the required employee : ");
    scanf("%d",&id);
    if(checkEmpNo(id,maxEmpNo)==0){
        goto enterEmpNo;
    }
    if(c>0){
        for(i=0;i<=c;i++){
            if(employee[i].empNo==id){
                count++;
                printf("\n1. Update Name of Employee\n2. Update Hire Date\n3. Update Basic Salary\nEnter Choice...");
                scanf("%d",&choice);
                switch(choice){
                    case 1: enterEmpName:
                            printf("\nEnter Employee Name:");
                            scanf("%s",&employee[i].empName);
                            if(checkEmpName(employee[i].empName)==0){
                                goto enterEmpName;
                            }
                            printf("\nEmployee Name Updated\n");
                            break;
                    case 2: enterHireDate:
                            printf("\nEnter Hire Date in digits ( dd mm yyyy):");
                            scanf("%d %d %d",&employee[i].hireDate.dd,&employee[i].hireDate.mm,&employee[i].hireDate.yyyy);
                            if(checkHireDate(employee[i].hireDate.dd,employee[i].hireDate.mm,employee[i].hireDate.yyyy)==0){
                                goto enterHireDate;
                            }
                            printf("\nEmployee Hire Date Updated\n");
                            break;
                    case 3: enterBasicSalary:
                            printf("\nEnter Basic Salary in digits:");
                            scanf("%f",&employee[i].basicSalary);
                            if(checkBasicSalary(employee[i].basicSalary)==0){
                                goto enterBasicSalary;
                            }
                            computeNetPay(&employee[i]);
                            printf("\nEmployee Basic Salary Updated\n");
                            break;
                    default:printf("\nInvalid Choice \n");
                }
            if(count==0){
                printf("\nWrong Employee number entered\n");
            }
        }
    }
    }
    else{
        printf("\nEmployee record Null\n");
    }
}

//Function to show all Employees Data
void ShowEmployeesData(emp employee[]){
    int i;
    if(c>0){
        printf("Employee Number | Employee Name | Hire Date  |Basic Salary| Net Pay\n");
        printf("----------------|---------------|------------|------------|----------\n");   
        for(i=0;i<c;i++){
            printf("%16d|%15s| %2d/%2d/%4d |%12.2f|%8.2f\n",employee[i].empNo,employee[i].empName,employee[i].hireDate.dd,employee[i].hireDate.mm,employee[i].hireDate.yyyy,employee[i].basicSalary,employee[i].netPay);
        }
    }
    else{
        printf("\nEmployee record Null\n");
        printf("Employee Number | Employee Name | Hire Date  | Basic Salary | Net Pay\n");
        printf("----------------|---------------|------------|--------------|----------\n");   
    }
}

//Function to delete Employee
void DeleteEmployee(emp employee[]){
    int id,i,j,count=0;
    enterEmpNo:
    printf("Enter Employee No of the required employee : ");
    scanf("%d",&id);
    if(checkEmpNo(id,maxEmpNo)==0){
        goto enterEmpNo;
    }
    if(c>0){
        for(i=0;i<=c;i++){
            if(employee[i].empNo==id){
                c--;count++;maxEmpNo++;
                for(j=i;j<=c;j++){
                    employee[i].empNo=employee[j].empNo;
                    strcpy(employee[i].empName,employee[j].empName);
                    employee[i].hireDate.dd=employee[j].hireDate.dd;
                    employee[i].hireDate.mm=employee[j].hireDate.mm;
                    employee[i].hireDate.yyyy=employee[j].hireDate.yyyy;
                    employee[i].basicSalary=employee[j].basicSalary;
                    employee[i].netPay=employee[j].netPay;
                }
                printf("\nEmployee %d deleted\n",id);
            }
            
        }
        if(count==0){
            printf("\nWrong Employee number entered\n");
        }
    }
    else
        printf("\nEmployee record Null\n");
}