#include <stdio.h>

int alphaCheck(int c){
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? 1 : 0);
}
int checkEmpName(char empName[50]){
    int i;
    for(i=0;empName[i]!='\0';i++){
        if(alphaCheck(empName[i])==0){
            printf("Employee Name ented is not only alphabets\nEnter again with only alphabets\n");
            return 0;}
    }
    return 1;
}
int checkCount(int c){
    if (c==50){
        return 0;
    }
    else{
        return 1;
    }
}

int checkEmpNo(int empNo,int maxEmpNo){
    if(empNo<101){
        printf("Employee No entered is less than 101\nEmployee No must be greater than or equal to one and less than or equal to %d\n",maxEmpNo);
        printf("Please enter again with correct values\n");
        return 0;
    }
    else if(empNo>maxEmpNo){
        printf("Employee No entered is more than 150\nEmployee No must be greater than or equal to one and less than or equal to %d\n",maxEmpNo);
        printf("Please enter again with correct values\n");
        return 0;
    }
    else{
        return 1;
    }
}

int checkHireDate(int dd,int mm,int yyyy){
    int result1,result2,result3;
    if(dd<1){
        printf("Day-dd entered is less than 1\n");
        result1 = 0;
    }
    else if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12){
        if(dd>31){
            printf("Day entered is more than 31 for 31 day month %d\n",mm);
            result1 = 0;
        }

    }
    else if(mm==2){
        if((yyyy % 400 == 0) ||(yyyy % 100 != 0) && (yyyy % 4 == 0 ) && dd>29){
            printf("Day entered is more than 29 for 29 day month %d\n",mm);
            result1 = 0;
        }
        else if(!((yyyy % 400 == 0) ||(yyyy % 100 != 0) && (yyyy % 4 == 0 )) && dd>28 ){
            printf("Day entered is more than 28 for 28 day month %d\n",mm);
            result1 = 0;
        }
        
    }
    else if( (mm==4 || mm==6 || mm==9 || mm==11) && dd>30 ){
        printf("Day entered is more than 30 for 30 day month %d\n",mm);
        result1 = 0;
    }
    else{
        result1 = 1;
    }
    if(mm<1){
        printf("Month entered is less than 1\n");
        result2 = 0;
    }
    else if(mm>12){
        printf("Month entered is more than 12\n");
        result2 = 0;
    }
    else{
        result2 = 1;
    }
    if(yyyy<1975){
        printf("Year entered is less than 1975\n");
        result3 = 0;
    }
    else if(yyyy>2023){
        printf("Year entered is more than 2023\n");
        result3 = 0;
    }
    else{
        result3 = 1;
    }
    if(result1 == 0 || result2 == 0 || result3 == 0){
        printf("\nPlease Enter once again\n");
    }
    return result1&&result2&&result3;
}

int checkBasicSalary(float basicSalary){
    int result;
    if(basicSalary<1.0){
        printf("Employee Basic Salary entered is less than 1\n");
        result = 0;
    }
    else if(basicSalary>9999999.99){
        printf("Employee Basic Salary entered is greater than 9999999.99\n");
        result = 0;
    }
    else{
        result = 1;
    }
    if(result == 0){
        printf("Please enter again with correct values\n");
    }
    return result;
}
