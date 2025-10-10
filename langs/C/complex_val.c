#include <complex.h>
#include <stdio.h>
int main()
{
    //declaring a complex number using complex
    double complex z1 = 1 + 2*I;
    //Arithmetic operation of complex number
    z1 = 3 * z1;
    printf("3 * (1.0+2.0i) = %.1f%+.1fi\n", creal(z1), cimag(z1));
    //declaring a complex number using _Complex
    double _Complex z2 = 1 + 2*I;
    //Arithmetic operation
    z2 = 1 / z2;
    printf("1/(1.0+2.0i) = %.1f%+.1fi\n", creal(z2), cimag(z2));
    return 0;
}
