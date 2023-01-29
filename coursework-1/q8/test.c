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
    printf("Removing the polynomial from memory\n");
    safe_remove(poly);
    return 0;
}


int test_2(){
    // Test the add function => (1.5 -4.X^2 + 5.7.X^6) + (3.X + 4.X^2) = (1.5 + 3.X + 5.7.X^6)
    printf("\n\n____ TEST 2 ____\n\n");
    monome_type *poly_p,*poly_q,*poly_r;
    poly_p = init_polynome(1.5,0);
    add_monome(poly_p,5.7,6);
    add_monome(poly_p,-4,2);
    poly_q = init_polynome(3.,1);
    add_monome(poly_q,4,2);
    poly_r = add(poly_p,poly_q);

    print_poly(poly_p);
    printf("+\n");
    print_poly(poly_q);
    printf("=\n");
    print_poly(poly_r);
    safe_remove(poly_p);
    safe_remove(poly_r);
    safe_remove(poly_q);

    return 0;
}

int test_3(){
    // Test the add function => (1.5 -4.X^2 + 5.7.X^6) + (3.X + 4.X^2) = (1.5 + 3.X + 5.7.X^6)
    printf("\n\n____ TEST 3 ____\n\n");
    monome_type *poly_p,*poly_q,*poly_r;
    
    poly_p = init_polynome(3,0);
    add_monome(poly_p,1.,1);
    add_monome(poly_p,5.,2);
    // P = 3.0 + 1.0.x^1 + 5.0.x^2

    poly_q = init_polynome(1.,2);
    // Q = 1.0.x^2
    poly_r = substract(poly_p,poly_q);

    print_poly(poly_p);
    printf("-\n");
    print_poly(poly_q);
    printf("=\n");
    print_poly(poly_r);

    safe_remove(poly_p);
    safe_remove(poly_r);
    safe_remove(poly_q);

    return 0;
}


int test_4(){
    // Test the add function => (1.5 -4.X^2 + 5.7.X^6) + (3.X + 4.X^2) = (1.5 + 3.X + 5.7.X^6)
    printf("\n\n____ TEST 4 ____\n\n");
    monome_type *poly_p,*poly_q,*poly_r;
    
    poly_p = init_polynome(3,0);
    add_monome(poly_p,1.,1);
    add_monome(poly_p,5.,2);
    // P = 1.0 + 1.0.x^1 + 5.0.x^2

    poly_q = init_polynome(1.,2);
    // Q = 1.0.x^2
    poly_r = multiply(poly_p,poly_q);

    print_poly(poly_p);
    printf("x\n");
    print_poly(poly_q);
    printf("=\n");
    print_poly(poly_r);

    safe_remove(poly_p);
    safe_remove(poly_r);
    safe_remove(poly_q);

    return 0;
}


int test_5(){
    // Test the add function => (1.5 -4.X^2 + 5.7.X^6) + (3.X + 4.X^2) = (1.5 + 3.X + 5.7.X^6)
    printf("\n\n____ TEST 4 ____\n\n");
    monome_type *poly_p;
    
    poly_p = init_polynome(3,0);
    add_monome(poly_p,1.,1);
    add_monome(poly_p,5.,2);
    // P = 3 + 1.0.x^1 + 5.0.x^2
   

    print_poly(poly_p);
    printf("P(%f) = %0.2f\n",2.,evaluate(poly_p,2.,0)); // 25
    printf("P(%f) = %0.2f\n",5.,evaluate(poly_p,5.,0)); // 135
    printf("P(%f) = %0.2f\n",0.,evaluate(poly_p,0.,0)); //3

    safe_remove(poly_p);


    return 0;
}

int test_temp(){
    printf("\n\n____ TEST CUSTOM ____\n\n");
    monome_type *poly_p,*poly_r;


    poly_p = init_polynome(3,0); // P = 3.0
    add_monome(poly_p,1,3); // P = 3.0 + X^3
    add_monome(poly_p,5,2); // P = 3.0 + X^3 + 5.X^2
    add_monome(poly_p,-3,2); // P = 3.0 + -3.X^2 + X^3 + 5.X^2
    print_poly(poly_p);
    poly_r = substract(poly_p,poly_p);
    print_poly(poly_r);
    return 0;
}

int test_tem(){
    printf("\n\n____ TEST CUSTOM ____\n\n");
    monome_type *poly_p = init_polynome(1.,0);
    monome_type *poly_q = init_polynome(1.,0);
    monome_type *poly_r;
    add_monome(poly_p,1.,1);
    add_monome(poly_q,-1.,1);
    poly_r = multiply(poly_p,poly_q);
    print_poly(poly_p);
    print_poly(poly_r);
    safe_remove(poly_p);
    safe_remove(poly_q);
    safe_remove(poly_r);
    
}