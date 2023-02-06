#include <stdio.h>
#include "test.h"
#include "poly.h"

monome_type* user_input_polynomial(){
    monome_type *p = init_polynome(0.,0);
    float coef;
    int exponant;
    char user_input ='O';
    while (user_input!='Y'){
        printf("\nInput the monome you wish to add to the polynomial  : (Coefficient Exponant)\n");
        scanf("%f %d",&coef,&exponant);
        add_monome(p,coef,exponant);
        print_poly(p);
        printf("Exit (Y/N) : ");
        scanf(" %c",&user_input);
        printf("\n");
    }
    printf("Final polynomial : ");
    print_poly(p);
    return p;
}


int main(){
    int res;
    res = test_basic_functionality() || test_addition() || test_subtraction() || test_multiplication() || test_evalution();
    monome_type *q,*r,*p;
    printf("Inputting P\n");
    p = user_input_polynomial();
    char operation;
    printf("\n\nChoose an operation/evalutation : (+/-/x/E)\n");
    scanf(" %c",&operation);
    switch (operation)
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
        printf("P(x) = %f",evaluate(p,x,0));
        safe_remove(p);
    default:
        break;
    }
    return 0;
}