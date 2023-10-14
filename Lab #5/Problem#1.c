#include <stdio.h>
#include <math.h>

void monthly_sales(double sales[], char* months[]){
    printf("Monthly sales report for 2022:\n\n");
    printf("Month      Sales\n\n");
    for (int x = 0; x<12; x++){
        printf("%-10s $%.2f\n", months[x], sales[x]);
    }
    printf("\n");
}
void sales_summary(double sales[], char* months[]){
    double min = sales[0];
    double max = sales[0];
    double sum;
    int mni = 0, mxi = 0;
    for (int x = 0; x<12; x++){
        if (sales[x]< min){
            min = sales[x];
            mni = x;
        }else if(sales[x] > max){
            max = sales[x];
            mxi = x;
        }
        sum += sales[x];
    }
    double average = sum/12;
    printf("Sales summary:\n\n");
    printf("Minimum sales: $%-10.2f (%s)\n", min, months[mni]);
    printf("Maximum sales: $%-10.2f (%s)\n", max, months[mxi]);
    printf("Average sales: $%-10.2f \n\n", average);    
}

void six_months(double sales[], char* months[]){
    printf("Six-Month Moving Average Report:\n\n");
    int x=0;
    int y = 5;
    while (y < 12){
        double sum = 0;
        for (int b = x; b<= y; b++){
            sum += sales[b];
        }
        printf("%-10s -  %-10s $%.2f\n", months[x], months[y], sum/6);
        x++;
        y++;
    }
}

void sales_report(double sales[], char* months[]){

    for (int i = 0; i<11; i++){
        int mxi = i;
        for (int j = i+1; j<12; j++){
            if (sales[j]>sales[mxi]){
                mxi = j;
            }
        }
        double y = sales[i];
        sales[i] = sales[mxi];
        sales[mxi] = y;

        char* m = months[i];
        months[i] = months[mxi];
        months[mxi] = m;
    }
    printf("\n  Month      Sales\n\n");
    for (int x = 0; x<12; x++){
        printf("%-10s $%.2f\n", months[x], sales[x]);
    }
    printf("\n\n");
}
int main(){
    FILE *f = fopen("sales.txt", "r");
    double sales[12];
    char* months[] = {"January","February","March","April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int x = 0; x < 12; x++){
        fscanf(f, "%lf", &sales[x]);
    }
    monthly_sales(sales, months);
    sales_summary(sales, months);
    six_months(sales, months);
    sales_report(sales, months);
    fclose(f);
}