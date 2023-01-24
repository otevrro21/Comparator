#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//variable declaration
short first_num;
short second_num;
short cycle;//cycle is used for selecting the right function call in the menu_after_input()
short menu_select;
FILE *logfile;

void menu_after_input(), end_menu();

void color(char color_select[100]) {//this function is for coloring the text output
    if (color_select == "red") {
        printf("\033[0;31m");
    }
    else if (color_select == "green") {
        printf("\033[0;32m");
    }
    else if (color_select == "yellow") {
        printf("\033[0;33m");
    }
    else if (color_select == "blue") {
        printf("\033[0;34m");
    }
    else if (color_select == "purple") {
        printf("\033[0;35m");
    }
    else if (color_select == "cyan") {
        printf("\033[0;36m");
    }
}
void color_rst() {//this fuction resets color back to default which is white
    printf("\033[0;37m");
}

void program_intro() {//introduce the app to the user
    color("red");
    printf("----- COMPARATOR -----\n");
    color_rst();
    printf("This program takes two whole numbers as input from the user and outputs which one is greater.\n");
    printf("Input whole numbers in range from 0 to 100, otherwise the program will report an error.\n");    
}

void first_num_input() {//prompt the user for first number input and save it to variable
    cycle = 0;
    printf("\nInput first whole number and hit Enter: ");
    scanf("%d", &first_num);
    printf("\n");
    if (first_num > 100){
        printf("Input Error, try again.\n");
        first_num_input();
    }
    menu_after_input();//call the menu function
}
void second_num_input() {//prompt the user for second number input and save it to variable
    cycle = 1;
    printf("\nInput second whole number and hit Enter: ");
    scanf("%d", &second_num);
    printf("\n");
    if (second_num > 100) {
        printf("Input Error, try again.\n");
        second_num_input();
    }
    menu_after_input();//call the menu function
}

void comparison() {
    if (first_num > second_num) {
        printf("\nThe number %d is greater than %d.\n", first_num, second_num);
    }
    else if (first_num < second_num) {
        printf("\nThe number %d is greater than %d.\n", second_num, first_num);
    }
    else if (first_num == second_num) {
        printf("\nNone of the numbers is greater than the other, because they are equal.\n");
    }
    end_menu();
}

void menu_after_input() {//menu prompting the user to continue, edit their input or to quit the app
    color("blue");
    if (cycle == 0) {
        printf("Your input: %d\n", first_num);
    }
    else if (cycle == 1) {
        printf("Your input: %d\n", second_num);
    }
    color_rst();
    printf("Do you wish to...\n1 - Continue\n2 - Edit your input\n3 - Save and Quit\nSelect one of above: ");
    scanf("%d", &menu_select);
    if (menu_select == 1) {
        if (cycle == 0){
            second_num_input();
        }
        else if (cycle == 1){
            comparison();
        }
    }
    else if (menu_select == 2) {
        printf("\nYou selected 'EDIT'\n");
        if (cycle == 0){
            first_num_input();
        }
        else if (cycle == 1){
            second_num_input();
        }
    }
    else if (menu_select == 3) {
        //SAVE AND QUIT
        logfile = fopen("log.txt", "w");
        fprintf(logfile, "%d;%d;%d", first_num, second_num, cycle);
        fclose(logfile);
        printf("Your progres has been saved.");
        sleep(3);
        exit(0);
    }
    else {
        printf("Input Error, try again.\n");
        menu_after_input();
    }
}
void end_menu() {//this menu will appear at the end of the program and prompt the user to start over or quit the app
    printf("\nDo you wish to compare another pair of numbers or do you want to quit the program...\n1 - Compare another pair\n2 - Quit\nSelect one of above: ");
    scanf("%d", &menu_select);
    if (menu_select == 1) {
        first_num_input();
    }
    else if (menu_select == 2) {
        exit(0);
    }
    else {
        printf("Input Error, try again.\n");
        end_menu();
    }
}

int progress_recover() {
    logfile = fopen("log.txt","r");
    if (logfile == NULL) {
        color("red");
        printf("Error opening log file!");
        color_rst();
        return 1;
    }
    fscanf(logfile, "%d", );
}

int main() {//main function
    program_intro();
    first_num_input();
    return 0;
}