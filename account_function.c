#include "head.h"

int AccountDiffer() {

    char manager_info[50] = "shirohige123456\r";
    char account_input[50];
    char passwd_input[50] = { 0 };
    int stu_or_manager;

    system("cls");
    printf("  Wellcome to the SIMS\n\n");
    printf("please input your account: ");
    scanf("%s", &account_input);

    // because the project didn't set up a data base for accounts
    // so just divicing by the first character for testing here
    // if account_input[0] is a number, it's a student
    // if not, it's a manager
    if (account_input[0] >= 49 && account_input[0] <= 57) {
        stu_or_manager = IsStudent(account_input);
    }
    else {
        printf("please input your password: ");
        for (int i = 0; i < 50; i++) {
            passwd_input[i] = _getch();
            if (passwd_input[i] == '\r') {
                break;
            }
            printf("*");
        }
        strcat(account_input, passwd_input);
        stu_or_manager = strcmp(manager_info, account_input);
    }
    return stu_or_manager;

}

int IsStudent(char* account_input) {

    int stu_no_input = 0;
    char passwd_input[50] = { 0 };

    if (account_input[0] != '\r') {
        stu_no_input += (int)account_input[0] - 48;
    }
    printf("please input your password: ");
    for (int i = 0; i < 50; i++) {
        passwd_input[i] = _getch();
        if (passwd_input[i] == '\r') {
            break;
        }
        printf("*");
    }

    int stu_or_manager = strcmp("123456\r", passwd_input);
    if (stu_or_manager == 0) {
        // +10 for divicing "return value 1" and "no.1 student"
        return stu_no_input + 10;
    }
    else {
        return stu_or_manager;
    }

}