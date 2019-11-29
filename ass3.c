#include <math.h>
#include <stdio.h>
#include "ass3.h"
 int counter;
double iterPow(double base, int power){
    const double ONE=1.00;
    //is negative to know when the power is negative
    int isNeg=0;
    double result=1.00;
   //edge cases
    if (power == 0)
        return 1;
    if(power == 1)
        return base;
//    if(power<0&&base==0)
//        return infinity();
    //x to the power of negative number y is 1/(x^-y)
    if(power<0){
        power=power*-1;
        isNeg=1;
    }
    for (int i = 0; i <power ; ++i) {
        counter++;
        result*=base;

    }
    if(isNeg)
        return (ONE / result);
    return result;
}

double recPow(double base, int power){
    const double ONE=1;
    int isNeg=0;
    double result;
    if(power==0)
        return 1;
//   if((power<0) && (base==0))
//        return infinity();
    if(power==1)
        return base;

    if (power<0){
        power*=-1;
        isNeg=1;
    }
    counter++;
    result=base*recPow(base,power-1);
    if(isNeg)
        return (ONE/result);
    return result;

}

double recEffiPow(double base,int power){
    const double ONE=1;
    int isNeg=0;
    double isOdd=0;
    double result=1;
    if(power==0)
        return 1;
//    if(power<0&&base==0)
//        return infinity();
    if(power==1)
        return base;
    if (power<0){
        power*=-1;
        isNeg=1;
    }
    if(power%2){
        isOdd=base;
        power--;
    }
    else
        isOdd=1;
    counter++;
    result=recEffiPow(base,power/2);
    if (isNeg)
        return (ONE/(isOdd * result * result));
    return (isOdd * result * result);



}


//int isPermutation(int arr1[], int size1, int arr2[], int size2){
//
//
//
//
//}
int maxRow(int arr[], int size) {
    int max=0;
    for (int j = 0; j <size ; ++j) {
        max = max > arr[j] ? max : arr[j];
    }

    return max;
}
void printRow(int arr[], int size,int max) {

    //the log will return number of digit -1
    int setSize=(int)log10(max)+1;
    for (int i = 0; i <size ; ++i) {
        printf("%0*d",setSize,arr[i]);
        if(i!=size-1)
            printf(", ");
    }

}

void printArr2D(int arr[][MAX], int row, int column){
   int maxInRow[row],max=0;
    for (int i = 0; i <row ; ++i) {
        maxInRow[i]= maxRow(arr[i],column);
    }
   max=maxRow(maxInRow,row);

    for (int i = 0; i < row ; ++i) {
        printRow(arr[i],column,max);
        printf("\n");
    }

}