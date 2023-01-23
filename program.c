#include <stdio.h>

int first_num;
int second_num;
int cycle = 0;
int menu_select;
int num_check;

void menu_after_input(), end_menu();

void program_intro(){
    printf("----- COMPARATOR -----\n");
    printf("This program takes two whole numbers as input from the user and outputs which one is greater.\n");
    printf("Input whole numbers in range from 0 to 100, otherwise the program will report an error.\n");    
}

void first_num_input(){
    cycle = 0;
    printf("\nInput first whole number and hit Enter: ");
    scanf("%d", &first_num);
    printf("\n");
    if(first_num < 0 || first_num > 100){
        printf("Input Error, try again.\n");
        first_num_input();
    }
    menu_after_input();
}
void second_num_input(){
    cycle = 1;
    printf("\nInput second whole number and hit Enter: ");
    scanf("%d", &second_num);
    printf("\n");
    if(second_num < 0 || second_num > 100){
        printf("Input Error, try again.\n");
        second_num_input();
    }
    menu_after_input();
}

void comparison(){
    if(first_num > second_num){
        printf("\nThe number %d is greater than %d.\n", first_num, second_num);
    }
    else if(first_num < second_num){
        printf("\nThe number %d is greater than %d.\n", second_num, first_num);
    }
    else if(first_num == second_num){
        printf("\nNone of the numbers is greater than the other, because they are equal.\n");
    }
    end_menu();
}

void menu_after_input(){
    printf("Do you wish to...\n1 - Continue\n2 - Edit your input\n3 - Quit the program\nSelect one of above: ");
    scanf("%d", &menu_select);
    if(menu_select == 1){
        if(cycle == 0){
            second_num_input();
        }
        else if(cycle == 1){
            comparison();
        }
    }
    else if(menu_select == 2){
        printf("\nYou selected 'EDIT'\n");
        if(cycle == 0){
            first_num_input();
        }
        else if(cycle == 1){
            second_num_input();
        }
    }
    else if(menu_select == 3){
        //SAVE AND QUIT
    }
    else{
        printf("Input Error, try again.\n");
        menu_after_input();
    }
}
void end_menu(){
    printf("\nDo you wish to compare another pair of numbers or do you want to quit the program...\n1 - Compare another pair\n2 - Quit\nSelect one of above: ");
    scanf("%d", &menu_select);
    if(menu_select == 1){
        first_num_input();
    }
    else if(menu_select == 2){
        //SAVE AND QUIT
    }
    else{
        printf("Input Error, try again.\n");
        end_menu();
    }
}

int main(){
    program_intro();
    first_num_input();
}