#include <stdio.h>
#include "test.h"
#include "poly.h"

monome_type* user_input_polynomial(){
    // Function to capture the user input and create a polynomial (linked list) 
    // Mostly based on the function add_polynomial in poly.c file
    monome_type *p = init_polynome(0.,0);
    float coef;
    int exponant;
    char user_input ='O';
    while (user_input!='Y'){
        // While the user does not stop the process
        printf("\nInput the monome you wish to add to the polynomial  : (Coefficient Exponant)\n");
        scanf("%f %d",&coef,&exponant);
        getchar();
        add_monome(p,coef,exponant);
        printf("P = ");
        print_poly(p);
        printf("Exit (Y/N) : ");
        scanf(" %c",&user_input);
        getchar();
        printf("\n");
    }
    printf("Final polynomial : ");
    print_poly(p);
    return p;
}


int main(){
    int res;
    // First we run the basic tests using the basic components
    res = test_basic_functionality() || test_addition() || test_subtraction() || test_multiplication() || test_evalution();
    monome_type *q,*r,*p;
    printf("\n____ READING USER INPUT ____\n");
    p = user_input_polynomial();
    char operation;
    printf("\n\nChoose an operation/evalutation : (+/-/x/E)\n");
    scanf(" %c",&operation);
    getchar();
    switch (operation)
    // The user can add/subtract/multiply and evalute polynomials
    {
    case '+':
        printf("Inputting Q\n");
        q = user_input_polynomial();
        r = add(p,q);
        printf("\n\nP = ");
        print_poly(p);
        printf("Q = ");
        print_poly(q);
        printf("P + Q = ");
        print_poly(r);
        safe_remove(p);
        safe_remove(q);
        safe_remove(r);
        break;
    case '-':
        printf("Inputting Q\n");
        q = user_input_polynomial();
        r = subtract(p,q);
        printf("\n\nP = ");
        print_poly(p);
        printf("Q = ");
        print_poly(q);
        printf("P - Q = ");
        print_poly(r);
        safe_remove(p);
        safe_remove(q);
        safe_remove(r);
        break;
    case 'x':
        printf("Inputting Q\n");
        q = user_input_polynomial();
        r = multiply(p,q);
        printf("\n\nP = ");
        print_poly(p);
        printf("Q = ");
        print_poly(q);
        printf("P x Q = ");
        print_poly(r);
        safe_remove(p);
        safe_remove(q);
        safe_remove(r);
        break;
    case 'E':
        float x;
        printf("Input the value of x :\n");
        scanf(" %f",&x);
        printf("P = ");
        print_poly(p);
        printf("P(%f) = %f",x,evaluate(p,x,0));
        safe_remove(p);
    default:
        break;
    }
    return 0;
}