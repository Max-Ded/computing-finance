#include <stdio.h>
#include "poly.h"
#include <stdlib.h>
#define INF 100000

void print_poly(struct monome *p){
    while (p!=NULL){
        // Iterate through the nodes
        if (p->exponent>1){ 
            printf("%0.1f.X^%d",p->coef,p->exponent);
        }
        else if (p->exponent==1){
            printf("%0.1f.X",p->coef);
        }
        else{
            printf("%0.1f",p->coef);
        }
        if (p->next!=NULL){
            // Only print a "+" if there is a next term in the polynomial
            printf(" + ");
        }
        p=p->next;
    }
    printf("\n");
}


int is_poly_null(monome_type *p){
    // All coefficient in the polynomial are 0. (not degree 0 necesseraly) => returns 1
    monome_type* current = p;
    int all_null = 1;
    while (current!=NULL){
        if (current->coef!=0.){
            all_null = 0;
        }
        current = current->next;
    }   
    return all_null;
}

int order_polynome(monome_type *p){
    // Get the degree of a polynomial
    int highest_expo = 0;
    while (p!=NULL){
        highest_expo = p->exponent;
        p=p->next;
    }
    return highest_expo;
}

void push_end(monome_type *p,float coef,int exponent){
    // Push a node with coefficient coef and exponent at the end of the polynomial
    monome_type *current;
    current = p;
    while(current->next!=NULL){
        current = current->next;
        // go to the end of the list
    }
    monome_type *new = (monome_type *) malloc(sizeof(monome_type)); // allocate memory to the new node
    new->coef = coef;
    new->exponent = exponent;
    new->next = NULL;
    current->next = new;
}


int get_exposant_next_in_line(monome_type *p){
    // get the exposant in the next node from the input (to the right), returns +INF (1e5 here) if it's the last node
    monome_type *next = p->next;
    if (next!=NULL){
        return next->exponent;
    }
    else{
        return INF;
    }
}

void push_after_p(monome_type *target,float coef,int exponent){
    // Push a monome (coef,exponent) after the monome pointed by p (p->exponent inferior or equal to exponent)
    if (target->exponent==exponent){
        // Add the coeff of the monome if they are the same exponent
        target->coef += coef;
    }
    else if (get_exposant_next_in_line(target)==exponent){
        // Add the coeff of the monome to the next node if they have the same exponent
        target->next->coef += coef;
    }
    else{
        // Insert the new block
        monome_type *new = init_polynome(coef,exponent);
        new->next = target->next;
        target->next = new;
    }
}

void delete_first_node(monome_type *p){
    // Delete the first node of the linked list ad copy the remanining to tthe reference so it's still usable
    // USE CASE : The first coef becomes null
    monome_type *current,*before_current;
    current=p;
    while (current->next!=NULL){
        current->exponent = current->next->exponent;
        current->coef = current->next->coef;
        before_current = current;
        current = current->next;
    }
    before_current->next=NULL;
    free(current);
}


void delete_empty_monome(monome_type *p){
    // travels the polynome for monome with 0. coef and deletes them => depends on the position of the zero coeff
    monome_type *before,*current;
    before = NULL;
    current = p;
    if (current->coef==0. && !is_poly_null(p)){
            // If the first coef is null and the polynomial isn't the 0 element
            delete_first_node(p);
            return;
    }
    if (!is_poly_null(p)){
        while(current->next!=NULL){
            if (current->coef==0. && before!=NULL){
                // if the current coeff is null and (This is not the first element of the list OR there is another element after //// i.e deleting the element won't empty the list)
                // we cut out the node
                before->next = current->next;
                free(current);
            }
            before = current;
            current = current->next;
        }
    }
    else{
        // it the polynomial is all null we remove the next nodes in line and change it to the 0 element
        safe_remove(p->next);
        p->next = NULL;
        p->coef = 0.;
        p->exponent =0;
    }

}


int check_poly_null(monome_type *p){
    // is the null element 0.X^0
    return p->next==NULL && p->coef ==0. && p->exponent==0;
}

void push_beginning(monome_type *p,float coef, int exponent){
    // Push a node at the begining of the list (copy all information one block forward and push a new node)
    monome_type *current;
    current = p;
    float coef_curr,coef_before;  // t and t-1 lag
    int exponent_curr,exponent_before; // t and t-1 lag
    exponent_before = exponent;
    coef_before = coef;

    while(current!=NULL){
        coef_curr = current->coef;
        exponent_curr = current->exponent;
        current->coef = coef_before;
        current->exponent = exponent_before;
        coef_before = coef_curr;
        exponent_before = exponent_curr;
        current=current->next;
    }
    push_end(p,coef_curr,exponent_curr);
}
void add_monome(monome_type *p,float coef,int exponent){
    
    if (check_poly_null(p)){
        // if the polynome is the null element on Pn(R) -> just replace the coef & exponent
        p->coef=coef;
        p->exponent=exponent;
    }
    else if(exponent<p->exponent){
        // if we add something that should go before the beginning of the list
        push_beginning(p,coef,exponent);
    }
    else{
        monome_type *before_current,*current;
        before_current=NULL;
        current = p;
        while(current->next!=NULL && get_exposant_next_in_line(current)<exponent){
            // at the end => current will be end of list or of exponent >= arg
            before_current = current;
            current = current->next;
        }
        push_after_p(current,coef,exponent);
    }
    delete_empty_monome(p); // delete all empty monome in case coef* - coef = 0.
}

void safe_remove(monome_type *p){
    int count=0;
    monome_type *current,*next;
    current = p;
    while(current!= NULL){
        next = current->next;
        free(current);
        current = next;
        count++;
    }
}

monome_type* init_polynome(float coef,int exponent){
    // create the first block in memory for the linked list, initialized with the args
    monome_type *head = NULL;
    head = (monome_type *) malloc(sizeof(monome_type));
    head->coef = coef;
    head->exponent = exponent;
    head->next = NULL;
    return head;
}

monome_type* add(monome_type *p,monome_type *q){
    // Addition of two polynomial => returns a reference to the result
    monome_type *r = init_polynome(0.,0);
    monome_type *current_p,*current_q;
    current_p = p;
    current_q =q;
    while(current_p!=NULL){
        add_monome(r,current_p->coef,current_p->exponent);
        current_p = current_p->next;
    }
    while(current_q!=NULL){
        add_monome(r,current_q->coef,current_q->exponent);
        current_q = current_q->next;
    }
    return r;
}

monome_type* multiply(monome_type *p,monome_type *q){
    // Multiplication of two polynomial => returns a reference to the result
    monome_type *r = init_polynome(0.,0);
    monome_type *current_p,*current_q;
    current_p = p;
    current_q =q;
    if (check_poly_null(p) || check_poly_null(q)){
        // if one of the term is the null element,r eturn the null element
        return r;
    }
    while(current_p!=NULL){
        // For each monome in P
        monome_type *r_temp = init_polynome(0.,0);
        current_q =q;
        while(current_q!=NULL){
            //ADD to r_temp the product of X_p * Q
            add_monome(r_temp,current_q->coef * current_p->coef,current_p->exponent + current_q->exponent);
            current_q = current_q->next;
        }
        r = add(r,r_temp); // add the sub_poly to the total
        safe_remove(r_temp); //remove the sub_poly then re-init it to the null element at the begining of the loop
        current_p = current_p->next;
    }

    return r;
}

float evaluate(monome_type *p,float x,int curr_exp){
    // Evaluation of two polynomial => returns the float result
    if (p->next==NULL && curr_exp==p->exponent){
        // If we have reached our target exponant and it's the last node in the list => return the coef
        return p->coef;
    }
    else{
        // is the exponant equal to the current node ? If not we multiply by x and call the function again increasing curr_exp
        if (p->exponent==curr_exp){
            return evaluate(p->next,x,curr_exp+1) *x + p->coef;
        }
        else{
            return x* evaluate(p,x,curr_exp+1);
        }
    }
}

monome_type* subtract(monome_type *p,monome_type *q){
    // Subtration of two polynomial => returns a reference to the result
    monome_type *r = init_polynome(0.,0);
    monome_type *current_p,*current_q;
    current_p =p;
    current_q =q;
    while(current_p!=NULL){
        add_monome(r,current_p->coef,current_p->exponent);
        current_p = current_p->next;
    }
    while(current_q!=NULL){
        add_monome(r,-(current_q->coef),current_q->exponent);
        current_q = current_q->next;
    }
    return r;
}