struct two_digit{
    int tens,units;
};

int get_value(struct two_digit x);
struct two_digit remove_tens(struct two_digit x);
struct two_digit remove_units(struct two_digit x);
void print_two_digit_div(struct two_digit num,struct two_digit den);