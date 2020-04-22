#include "head.h"

// operating tag, when it changed to 0, the system will quit
int system_quit = 1;

int main() {

    p_student p_head = NULL;
    p_student p_tail = NULL;
    FILE* file;
    int error_times = 0;

    file = fopen("record.txt", "r");
    while (!feof(file)) {
        p_student new = (p_student)calloc(1, sizeof(student));
        fscanf(file, "%d%s%d %c%f%f%f", &new->no, &new->name, &new->age, &new->sex, &new->chnScr, &new->mahScr, &new->engScr);
        ListInit(&p_head, &p_tail, new);
    }
    fclose(file);

    Sort(p_head, p_tail);

    while (system_quit) {

        // 0       for manager
        // -1 or 1 for wrong input
        // others  for student, "others" is the no. of the student
        int stu_or_manager = AccountDiffer();

        if (stu_or_manager == 0) {
            while (system_quit) {
                Menu(&p_head, &p_tail);
            }
        }
        else if (stu_or_manager == -1 || stu_or_manager == 1) {
            system("cls");
            printf("\nwrong account or password!\n\nplease input again\n");
            system("pause");
            ++error_times;
        }
        else {
            system("cls");
            DisplayOneStuInfo(stu_or_manager, p_head);
        }
        if (error_times > 2) {
            system("cls");
            printf("you have input wrong info over 3 times\n\nthe system will quit\n");
            break;
        }
    }
    system("pause");

}