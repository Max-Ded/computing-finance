#include <stdio.h>
#include <math.h>

struct vec
{
    float x;
    float y;
    void add_pos_x(float e){
        x+=e;
    }
    void add_vec(struct vec b){
        x +=b.x;
        y +=b.y;
    }
    vec mult_ctst(float c){
        struct vec rep = {x,y};
        rep.x *= c;
        rep.y *= c;
        return rep;
    }
    void print_coord(){
        printf("x : %f, y : %f\n",x,y);
    }
    void normalize(){
        float norm = sqrt(pow(x,2) + pow(y,2));
        x = x/norm;
        y = y/norm;
    }
    float find_arg(){
        float theta = acos(x);
        if (y<0){
            theta =-theta;
        }
        return theta;
    }
    void rotate_angle(float alpha){
        float angle = find_arg();
        float norm = sqrt(pow(x,2) + pow(y,2));
        x = norm*cos(angle+alpha);
        y = norm*sin(angle+alpha);
    }
};


struct ant
{
    /* data */
    struct vec pos;
    struct vec v;
    float dt = 0.1;
    float turn_angle = 0.0;


    void update_pos(){
        struct vec new_vec = v.mult_ctst(dt);
        //new_vec.rotate_angle(turn_angle);
        pos.add_vec(new_vec);
    }
};

int square(int num){
    return num*num;
}


int main(){
    struct vec p = {0,0};
    struct vec v = {1,-1};
    v.normalize();
    struct ant a = {p,v};

    int steps = 100;
    a.pos.print_coord();

    for (int i = 0;i<steps;i++){
    a.update_pos();
    a.pos.print_coord();
    }
    return 0;
}

