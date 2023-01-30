typedef struct monome{
    float coef;
    int exponent;
    struct monome *next;
} monome_type;

void print_poly(struct monome *p);
int order_polynome(monome_type *p);
void push_end(monome_type *p,float coef,int exponent);
void add_monome(monome_type *p,float coef,int exponent);
void safe_remove(monome_type *p);
monome_type* init_polynome(float coef,int exponent);
monome_type* add(monome_type *p,monome_type *q);
monome_type* subtract(monome_type *p,monome_type *q);
void delete_empty_monome(monome_type *p);
void push_after_p(monome_type *target,float coef,int exponent);
int is_poly_null(monome_type *p);
monome_type* multiply(monome_type *p,monome_type *q);
int check_poly_null(monome_type *p);
float evaluate(monome_type *p,float x,int curr_exp);
void push_beginning(monome_type *p,float coef, int exponent);
void delete_first_node(monome_type *p);