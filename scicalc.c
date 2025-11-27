#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_deriv.h>
//#include "scicalc.h"

#define PI 3.14159

// Use the -lgsl -lgslcblas to properly link gsl during compilation like this:
// gcc example.c -o example -lgsl -lgslcblas -lm

int factorial(int num1);

int main() {
    double num1, num2, result;
    int choice;
    double adjusted_value, decimal_rshift;
    int cnt = 0;
    
    printf("Basic Calculator\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Square Root\n");
    printf("6. Power\n");
    printf("7. Arccosine (in radians)\n");
    printf("8. Arccosine (hyperbolic)\n");
    printf("9. Arcsine (in radians)\n");
    printf("10. Cubic Root\n");
    printf("Enter your choice (1-10): ");
    scanf("%2d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        case 5:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 >= 0) {
                result = sqrt(num1);
                printf("Result: %.2lf\n", result);
            } else {
                printf("Error: Cannot calculate square root of a negative number\n");
            }
            break;
        case 6:
            printf("Enter two numbers: ");
            if (num2 > 0) {
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("Result: %2lf\n", result);
            } else {
                printf("Error: Cannot raise x to the power of zero\n");
            }
            break;
        case 7:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = acos(num1);
            printf("Result: %2lf\n", result);
            break;
        case 8:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = acosh(num1);
            printf("Result: %2lf\n", result);
            break;
        case 9:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = asin(num1);
            printf("Result: %2lf\n", result);
            break;
        case 10:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 != 0) {
            result = cbrt(num1);
            printf("Result: %2lf\n", result);
            } else {
                printf("Error: Cannot calculate the cubic root of zero\n");
            }
            break;
        case 11:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 != 0) {
            result = atan(num1);
            printf("Result: %2lf\n", result);
            } else {
                printf("Error: Cannot calculate the arctangent of zero\n");
            }
            break;
        case 12:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 != 0) {
            result = asinh(num1);
            printf("Result: %2lf\n", result);
            } else {
                printf("Error: Cannot calculate hyperbolic arcsine of zero\n");
            }
            break;
        case 13:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num1 && num2 != 0) {
            result = atan2(num1, num2);
            printf("Result: %2lf\n", result);
            } else {
                printf("Error: Cannot calculate angle theta with a zero integer\n");
            }
            break;
        case 14:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 != 0) {
            result = atanh(num1);
            printf("Result: %2lf\n", result);
            } else {
                printf("Error: Cannot calculate the hyperbolic arctangent of zero\n");
            }
            break;
        case 15:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = ceil(num1);
            printf("Result: %2lf\n", result);
            break;
        case 16:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, num2);
            result = copysign(num1, num2);
            printf("Result: %2lf", result);
            break;
        case 17:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = cos(num1);
            printf("Result: %2lf", result);
            break;
        case 18:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 > 1) {
            result = factorial(num1);
            printf("Result: %lf", result);
            } else {
                printf("Error: Cannot calculate factorial of an integer less than 2\n");
            }
            break;
        case 19:
            printf("Enter your radius: ");
            scanf("%2lf", &num1);
            result = 2 * PI * num1;
            printf("Circumference: %2lf", result);
            break;
        case 20:
            printf("Enter your circumference: ");
            scanf("%2lf", &num1);
            result = num1 / 2 * PI;
            adjusted_value = result / 100;
            decimal_rshift = adjusted_value * 10;
            printf("Radius: %2lf", decimal_rshift);
            break;
        case 21:
            printf("Enter your radius: ");
            scanf("%2lf", &num1);
            num2 = 2;
            result = PI * pow(num1, num2);
            printf("Area: %2lf", result);
            break;
        case 22:
            printf("Enter your number: ");
            scanf("%lf", &num1);
            int num_int = (int)num1;
            cnt = 0;

            if (num_int <= 1) {
            printf("%d is NOT prime", num1);
            } else {
                for (int i = 2; i <= num_int; i++) {
                    if (num_int % i == 0)
                        cnt++;
                }
                if (cnt > 2) {
                    printf("%d is NOT prime", num_int);
                } else {
                    printf("%d is prime", num_int);
                }
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}

int factorial(int num1) {
  if (num1 > 1) {
    return num1 * factorial(num1-1);
  } else {
    return 1;
  }
}
