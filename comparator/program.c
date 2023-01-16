#include <stdio.h>

int x;
int y;
int menu_select;

void color(), color_reset(), menu_after_input(), first_num_input(), second_num_input();

/*
For color change use the color function with parameter of 1-6
1 - Red
2 - Green
3 - Yellow
4 - Blue
5 - Purple
6 - Cyan
*/
void color(int color_select){ //this function enables you to easily color your output
    if(color_select == 1){
        printf("\033[0;31m");
    }
    else if(color_select == 2){
        printf("\033[0;32m");
    }
    else if(color_select == 3){
        printf("\033[0;33m");
    }
    else if(color_select == 4){
        printf("\033[0;34m");
    }
    else if(color_select == 5){
        printf("\033[0;35m");
    }
    else if(color_select == 6){
        printf("\033[0;36m");
    }
}
void color_reset(){ //this resets color to default white
    printf("\033[0;37m");
}

void menu_after_input(){ //this is the menu that lets you continue, edit your input or quit the app
    printf("\n1 - Continue\n2 - Edit\n3 - Quit\nChoose one of above: ");
    scanf("%d", &menu_select);
    if(menu_select == 1){
        color(4);
        printf("\nYou selected ");
        color(2);
        printf("'Continue'\n");
        color_reset();
        //continue to run the program
    }
    else if(menu_select == 2){
        color(4);
        printf("\nYou selected ");
        color(3);
        printf("'Edit'\n");
        color_reset();
        first_num_input();
    }
    else if(menu_select == 3){
        color(4);
        printf("\nYou selected ");
        color(1);
        printf("'Quit'\n");
        color_reset();
        //quit the application
    }
    else{
        color(1);
        printf("Input error, try again.\n");
        color_reset();
        menu_after_input();
    }
}

void first_num_input(){ //read the first input
    printf("\nType the first number and press Enter: ");
    scanf("%d", &x);
    if(x >= 0 && x <= 100){
        color(4);
        printf("\nYour input: %d\n", x);
        color_reset();
        menu_after_input();
    }
    else{
        color(1);
        printf("Input error, try again.\n");
        color_reset();
        first_num_input();
    }
}
void second_num_input(){ //read the second input
    printf("\nType the second number and press Enter: ");
    scanf("%d", &y);
    if(y >= 0 && y <= 100){
        color(4);
        printf("\nYour input: %d\n", y);
        color_reset();
        menu_after_input();
    }
    else{
        color(1);
        printf("Input error, try again.\n");
        color_reset();
        first_num_input();
    }
}
int comparison(){
    if(x > y){
        return x;
    }
    else if(x < y){
        return y;
    }
}

int main(){
    printf("\033[0;31m----- COMPARATOR -----\n\033[0;37mThis console app takes two numbers as input and outputs which one is greater.\nYou can enter only whole numbers in range from 0 to 100, otherwise the app won't work.\n");
    first_num_input();
    second_num_input();
    printf("The number ");
    color(6);
    printf("%d", comparison());
    color_reset();
    printf(" is greater.");
}