#include <stdio.h>
#include <math.h>

/* Define function here */
double f(double x) {
    return 1/(1+x*x);
}

int main() {
    double lower, upper, integration=0.0, stepSize, k;
    int i, subInterval;

    /* Input */
    printf("Enter lower limit of integration: ");
    scanf("%lf", &lower);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &upper);
    printf("Enter number of sub intervals: ");
    scanf("%d", &subInterval);

    /* Calculation */
    /* Finding step size */
    stepSize = (upper - lower)/subInterval;

    /* Finding Integration Value */
    integration = f(lower) + f(upper);
    for(i=1; i<= subInterval-1; i++) {
        k = lower + i*stepSize;
        if(i%2==0) {
            integration = integration + 2 * f(k);
        } else {
            integration = integration + 4 * f(k);
        }
    }
    integration = integration * stepSize/3;
    printf("\nRequired value of integration is: %.6lf\n", integration);
    return 0;
}
