#include "poly.h"
#include <stdlib.h>
#include <stdio.h>
#include "test.h"

int test_basic_functionality(){
    // test basic functionallity
    printf("\n\n____ TEST (BASIC FUNCTIONALITY) ____\n\n");
    
    monome_type *poly;
    poly = init_polynome(1,3); // X^3
    if (poly == NULL) {
        return 1;
    }
    printf("Initialized : ");
    print_poly(poly);
    printf("Adding 1.5.X^1 : ");
    add_monome(poly,1.5,1); // 1.5.X^1 + X^3
    print_poly(poly);
    printf("Adding 6.5.X^5 : ");
    add_monome(poly,6.5,5); 
    print_poly(poly);
    printf("Adding 4.X^3 : ");
    add_monome(poly,4,3);
    print_poly(poly);
    printf("Adding -1.5.X^1 : ");
    add_monome(poly,-1.5,1);
    print_poly(poly);
    printf("Adding 1. : ");
    add_monome(poly,1.,0);
    print_poly(poly);
    printf("Removing the polynomial from memory\n\n");
    safe_remove(poly);
    return 0;
}


int test_addition(){
    // Test the add function => (1.5 -4.X^2 + 5.7.X^6) + (3.X + 4.X^2) = (1.5 + 3.X + 5.7.X^6)
    printf("\n\n____ TEST ADDITION ____\n\n");
    monome_type *poly_p,*poly_q,*poly_r,*poly_pp,*poly_qq,*poly_rr;
    poly_p = init_polynome(1.5,0);
    add_monome(poly_p,5.7,6);
    add_monome(poly_p,-4,2);
    print_poly(poly_p);
    printf("+\n");
    poly_q = init_polynome(3.,1);
    add_monome(poly_q,4,2);
    print_poly(poly_q);
    printf("=\n");
    poly_r = add(poly_p,poly_q);
    print_poly(poly_r);
    printf("=======\n");
    poly_pp = init_polynome(1.,1);
    poly_qq = init_polynome(-1.,1);
    poly_rr = add(poly_pp,poly_qq);
    print_poly(poly_pp);
    printf("+\n");
    print_poly(poly_qq);
    printf("=\n");
    print_poly(poly_rr);

    safe_remove(poly_p);
    safe_remove(poly_r);
    safe_remove(poly_q);
    safe_remove(poly_pp);
    safe_remove(poly_qq);
    safe_remove(poly_rr);
    return 0;
}

int test_subtraction(){
    // Test the add function => (3.0 + 1.0.x^1 + 5.0.x^2) - (3.0 + 1.0.X^2) = (1.0.x^1 + 4.0.x^2)
    printf("\n\n____ TEST SUBTRACTION ____\n\n");
    monome_type *poly_p,*poly_q,*poly_r,*poly_pp,*poly_rr;
    
    poly_p = init_polynome(3,0);
    add_monome(poly_p,1.,1);
    add_monome(poly_p,5.,2);
    // P = 3.0 + 1.0.x^1 + 5.0.x^2

    poly_q = init_polynome(1.,2);
    add_monome(poly_q,3,0);
    // Q = 3.0 + 1.0.x^2
    poly_r = substract(poly_p,poly_q);

    print_poly(poly_p);
    printf("-\n");
    print_poly(poly_q);
    printf("=\n");
    print_poly(poly_r);

    printf("=======\n");
    poly_pp = init_polynome(1.,1);
    print_poly(poly_pp);
    printf("-\n");
    print_poly(poly_pp);
    printf("=\n");
    poly_rr = substract(poly_pp,poly_pp);
    print_poly(poly_rr);

    safe_remove(poly_p);
    safe_remove(poly_r);
    safe_remove(poly_q);
    safe_remove(poly_pp);
    safe_remove(poly_rr);
    return 0;
}


int test_multiplication(){
    // Test the add function => (1.5 -4.X^2 + 5.7.X^6) + (3.X + 4.X^2) = (1.5 + 3.X + 5.7.X^6)
    printf("\n\n____ TEST MULTIPLICATION ____\n\n");
    monome_type *poly_p,*poly_q,*poly_r,*poly_pp,*poly_qq,*poly_rr;
    
    poly_p = init_polynome(3,0);
    add_monome(poly_p,1.,1);
    add_monome(poly_p,5.,2);
    // P = 1.0 + 1.0.x^1 + 5.0.x^2

    poly_q = init_polynome(1.,2);
    // Q = 1.0.x^2
    poly_r = multiply(poly_p,poly_q);
    // R = 3.0.x^2 + 1.0.x^3 + 5.0.x^4

    print_poly(poly_p);
    printf("x\n");
    print_poly(poly_q);
    printf("=\n");
    print_poly(poly_r);

    //A²-B² = (A-B)(A+B)
    poly_pp = init_polynome(1.,0);
    poly_qq = init_polynome(1.,0);
    add_monome(poly_pp,1.,1);
    add_monome(poly_qq,-1.,1);
    poly_rr = multiply(poly_pp,poly_qq);
    printf("========\n");
    print_poly(poly_pp);
    printf("x\n");
    print_poly(poly_qq);
    printf("=\n");
    print_poly(poly_rr);

    safe_remove(poly_p);
    safe_remove(poly_r);
    safe_remove(poly_q);
    
    safe_remove(poly_pp);
    safe_remove(poly_rr);
    safe_remove(poly_qq);

    return 0;
}


int test_evalution(){
    // Test the add function => (1.5 -4.X^2 + 5.7.X^6) + (3.X + 4.X^2) = (1.5 + 3.X + 5.7.X^6)
    printf("\n\n____ TEST EVALUATION ____\n\n");
    monome_type *poly_p,*poly_q,*poly_r;
    
    poly_p = init_polynome(3,0);
    add_monome(poly_p,1.,1);
    add_monome(poly_p,5.,2);
    // P = 3 + 1.0.x^1 + 5.0.x^2

    poly_q = init_polynome(1,2);
    add_monome(poly_q,6,3);
    add_monome(poly_q,1.,5);
    // Q = 1.X^2 + 6.X^3 + 1.X^5

    poly_r = init_polynome(3,4);
    // R = 3.X^4

    print_poly(poly_p);
    printf("P(%0.1f) = %0.1f\n",2.,evaluate(poly_p,2.,0)); // 25
    printf("P(%0.1f) = %0.1f\n",5.,evaluate(poly_p,5.,0)); // 135
    printf("P(%0.1f) = %0.1f\n",0.5,evaluate(poly_p,0.5,0)); //3
    printf("P(%0.1f) = %0.1f\n",0.,evaluate(poly_p,0.,0)); //3
    printf("============\n");
    print_poly(poly_q);
    printf("Q(%0.1f) = %0.1f\n",10.,evaluate(poly_q,10.,0)); // 106100.0
    printf("Q(%0.1f) = %0.1f\n",-8.,evaluate(poly_q,-8.,0)); // -35776.0
    printf("Q(%0.00001f) = %0.1f\n",1.1,evaluate(poly_q,1.1,0)); // 10.806510000000003
    printf("Q(%0.1f) = %0.1f\n",0.,evaluate(poly_q,0.,0)); //0
    printf("============\n");
    print_poly(poly_r);
    printf("R(%0.1f) = %0.1f\n",10.,evaluate(poly_r,10.,0)); // 30000
    printf("R(%0.1f) = %0.1f\n",-1.,evaluate(poly_r,-1.,0)); // 3
    printf("R(%0.1f) = %0.1f\n",1.5,evaluate(poly_r,1.5,0)); //15.1875
    printf("============\n");
    safe_remove(poly_p);
    safe_remove(poly_q);
    safe_remove(poly_r);
    return 0;
}
