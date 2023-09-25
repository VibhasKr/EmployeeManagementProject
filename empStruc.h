//Date structure
typedef struct Date{
    int dd,mm,yyyy;
}date;

//Employee structure
typedef struct Employee{
    int empNo;
    char empName[50];
    date hireDate;
    float basicSalary;
    float netPay;
}emp;
