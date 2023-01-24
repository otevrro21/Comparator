#include <stdio.h>
#include <stdlib.h>

//variable declaration
int first_num;
int second_num;
int cycle;//cycle is used for selecting the right function call in the menu_after_input()
int menu_select;
int log_read;
int recovery_cycle = 0;
int quit_rst;
FILE *log_file;

void menu_after_input(), end_menu(), program_intro(), first_num_input(), second_num_input(), color(), color_rst(), comparison();

void color(char color_select[5]) {//this function is for coloring the text output
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
    log_file = fopen("log.txt", "w");
    fclose(log_file);
    color("red");
    printf("----- COMPARATOR -----\n");
    color_rst();
    printf("This program takes two whole numbers as input from the user and outputs which one is greater.\n");
    printf("Input whole numbers in range from 0 to 100, otherwise the program will report an error.\n");
    first_num_input();
}

void first_num_input() {//prompt the user for first number input and save it to variable
    cycle = 0;
    printf("\nInput first whole number and hit Enter: ");
    scanf("%d", &first_num);
    printf("\n");
    if (first_num < 0 || first_num > 100){
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
    if (second_num < 0 || second_num > 100) {

        printf("Input Error, try again.\n");
        second_num_input();
    }
    menu_after_input();//call the menu function
}

void comparison() {
    if (first_num > second_num) {
        printf("\nThe number \033[0;36m%d\033[0;37m is greater than \033[0;36m%d\033[0;37m.\n", first_num, second_num);
    }
    else if (first_num < second_num) {
        printf("\nThe number \033[0;36m%d\033[0;37m is greater than \033[0;36m%d\033[0;37m.\n", second_num, first_num);
    }
    else if (first_num == second_num) {
        printf("\nNone of the numbers is greater than the other, because they are equal.\n");
    }
    end_menu();
}

void menu_after_input() {//menu prompting the user to continue, edit their input or to quit the app
    color("cyan");
    if (cycle == 0) {
        printf("First number: %d\n", first_num);
    }
    else if (cycle == 1) {
        printf("First number: %d\n", first_num);
        printf("Second number: %d\n", second_num);
    }
    color_rst();
    printf("Do you wish to...\n1 - Continue\n2 - Edit your input\n3 - Restart\n4 - Save and Quit\nSelect one of above: ");
    scanf("%d", &menu_select);
    if (menu_select == 1) {
        printf("\nYou selected");
        color("green");
        printf(" 'CONTINUE'\n");
        color_rst();
        if (cycle == 0){
            second_num_input();
        }
        else if (cycle == 1){
            comparison();
        }
    }
    else if (menu_select == 2) {
        printf("\nYou selected");
        color("yellow");
        printf(" 'EDIT'\n");
        color_rst();
        if (cycle == 0){
            first_num_input();
        }
        else if (cycle == 1){
            second_num_input();
        }
    }
    else if (menu_select == 3) {
        printf("\nYou selected");
        color("red");
        printf(" 'RESTART'\n\n");
        color_rst();
        program_intro();
    }
    else if (menu_select == 4) {
        //SAVE AND QUIT
        printf("\nYou selected");
        color("purple");
        printf(" 'QUIT'\n");
        color_rst();
        log_file = fopen("log.txt", "w");
        fprintf(log_file, "%d;%d;%d;0", first_num, second_num, cycle);
        fclose(log_file);
        printf("Your progres has been saved.");
        exit(0);
    }
    else {
        color("red");
        printf("\nInput Error, try again.\n\n");
        color_rst();
        menu_after_input();
    }
}
void end_menu() {//this menu will appear at the end of the program and prompt the user to start over or quit the app
    printf("\nDo you wish to restart and compare another pair of numbers or do you want to quit the program...\n1 - Restart\n2 - Quit\nSelect one of above: ");
    scanf("%d", &menu_select);
    if (menu_select == 1) {
        printf("\nYou selected");
        color("red");
        printf(" 'RESTART'\n");
        color_rst();
        first_num_input();
    }
    else if (menu_select == 2) {
        log_file = fopen("log.txt", "w");
        fprintf(log_file,"0;0;0;1");
        fclose(log_file);
        printf("\nYou selected");
        color("purple");
        printf(" 'QUIT'\n");
        color_rst();
        exit(0);
    }
    else {
        color("red");
        printf("\nInput Error, try again.\n\n");
        color_rst();
        end_menu();
    }
}

int progress_recovery() {
    log_file = fopen("log.txt", "r");
    if (log_file == NULL) {
        color("red");
        printf("\nError opening log file!\n");
        color_rst();
        return 1;
    }
    while (fscanf(log_file, "%d;", &log_read) != EOF) {
        if (recovery_cycle == 0) {
            first_num = log_read;
        }
        else if (recovery_cycle == 1) {
            second_num = log_read;
        }
        else if (recovery_cycle == 2) {
            cycle = log_read;
        }
        else if (recovery_cycle == 3) {
            quit_rst = log_read;
        }
        recovery_cycle ++;
    }
    if (quit_rst == 0) {
        color("yellow");
        printf("Progress recovered!\n\n");
        color_rst();
    }
    else if (quit_rst == 1) {
        program_intro();
    }
    else {
        return 1;
    }
    if (cycle == 0 || cycle == 1) {
        menu_after_input();
    }
    else {
        return 1;
    }
}

int main() {//main function
    system("cls");
    progress_recovery();
    program_intro();
    return 0;
}