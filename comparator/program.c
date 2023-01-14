#include <stdio.h>

int x;
int y;
int menu_select;

void menu_after_input(){
    printf("\n1 - Continue\n2 - Edit\n3 - quit\nChoose one of above: ");
    scanf("%d", &menu_select);
}

void first_num_input(){
    printf("Type the first number and press Enter: ");
    scanf("%d", &x);
    if(x >= 0 && x <= 100){
        printf("\033[0;32mYour input: %d\n\033[0;37m", x);
        menu_after_input();
    }
    else{
        printf("Input error, try again.\n");
        first_num_input();
    }
}
void second_num_input(){
    printf("Type the second number and press Enter: ");
    scanf("%d", &y);
    if(y >= 0 && y <= 100){
        printf("Your input: %d\n", y);
        menu_after_input();
    }
    else{
        printf("Input error, try again.\n");
        first_num_input();
    }
}
void num_input(){
    first_num_input();
    second_num_input();
}

int main(){
    printf("\033[0;31m----- COMPARATOR -----\n\033[0;37mThis console app takes two numbers as input and outputs which one is greater.\nYou can enter only whole numbers in range from 0 to 100, otherwise the app won't work.\n");
        num_input();
////hello 
test
}