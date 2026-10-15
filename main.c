#include <stdio.h>
#include <math.h>

double sum_ln(double x, double eps) {
    double s = 0.0;
    double a = 1.0 - x;    
    double term = a;         
    int n = 1;               

    while (fabs(term) > eps) {
        s -= term;           
        term *= a * n / (n + 1.0);
        n++;
    }

    return s;
}

int main(void) {
    double eps = 0.0001;

    for (double x = 0.1; x <= 0.9 + 1e-9; x += 0.1) {
        double a = sum_ln(x, eps);

        printf("%.1lf\t %.6lf\t \n",x, a);
    }

    return 0;
}