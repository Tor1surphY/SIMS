#include "head.h"

extern int system_quit;

void ListInit(p_student* phead, p_student* ptail, p_student new_student) {

	if (*phead == NULL) {
		*phead = new_student;
		*ptail = new_student;
	}
	else {
		(*ptail)->p_next = new_student;
		*ptail = new_student;
		new_student->p_next = NULL;
	}

}

void Menu(p_student* p_head, p_student* p_tail) {

    int menu_opr;

    system("cls");
    printf("\n");
    printf("---------------------------------------------------------\n\n");
    printf("           Student Information Management System         \n\n");
    printf("-------------------------MENU----------------------------\n\n");
    printf("                1. Search record\n\n");
    printf("                2. Modify record by student No.\n\n");
    printf("                3. Add a new record\n\n");
    printf("                4. Delete record by student No.\n\n");
    printf("                5. Display record sort by No.\n\n");
    printf("                6. Save and Quit\n\n");
    printf("---------------------------------------------------------\n");
    printf("Please input your operating number: ");
    scanf("%d", &menu_opr);

    switch (menu_opr) {
    case 1:SelectSearchCatigories(p_head); break;
    case 2:FindStuNeedChanged(p_head); break;
    case 3:AddNewRecord(p_head, p_tail); break;
    case 4:DelStuInfo(p_head, p_tail); break;
    case 5:DisplayAllStuInfo(p_head); break;
    case 6:SaveBeforeQuit(p_head), printf("\nsaving succeeded.\n"), system_quit = 0; break;
    default:system("cls"), printf("operation must between 1 to 6\n"), system("pause");
    }

}

void SaveBeforeQuit(p_student* head) {

    FILE* file;
    p_student write_new_line = *head;

    file = fopen("record.txt", "w");
    while (write_new_line->p_next != NULL) {
        fprintf(
            file, "%d %s %d %c %f %f %f\n",
            write_new_line->no,
            write_new_line->name,
            write_new_line->age,
            write_new_line->sex,
            write_new_line->chnScr,
            write_new_line->mahScr,
            write_new_line->engScr
            );
        write_new_line = write_new_line->p_next;
    }

    // this step for fprintf the record ending not by '\n'
    // so it will be easy for inti next time
    fprintf(
        file, "%d %s %d %c %f %f %f\n",
        write_new_line->no,
        write_new_line->name,
        write_new_line->age,
        write_new_line->sex,
        write_new_line->chnScr,
        write_new_line->mahScr,
        write_new_line->engScr
        );
    fclose(file);

}