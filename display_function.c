#include "head.h"

void DisplayOneStuInfo(int stu_no_input, p_student p_head) {

	stu_no_input -= 10;
	p_student find_student = p_head;

	while (find_student) {
		if (find_student->no == stu_no_input) {
			printf("your record is:\n");
			HEAD();
			printf(
				" %2d %10s %3d   %c  %-7.2f %-7.2f %-7.2f\n",
				find_student->no,
				find_student->name,
				find_student->age,
				find_student->sex,
				find_student->chnScr,
				find_student->mahScr,
				find_student->engScr
				);
			break;
		}
		else {
			find_student = find_student->p_next;
		}
	}

	if (find_student == NULL) {
		printf("not found, please input again:\n");
	}

	system("pause");

}

void DisplayAllStuInfo(p_student* p_head) {

	p_student current_student = *p_head;

	system("cls");
	HEAD();
	while (current_student) {
		printf(
			" %2d %10s %3d   %c  %-7.2f %-7.2f %-7.2f\n", 
			current_student->no, 
			current_student->name, 
			current_student->age, 
			current_student->sex, 
			current_student->chnScr, 
			current_student->mahScr, 
			current_student->engScr
		);
		current_student = current_student->p_next;
	}
	system("pause");
	system("cls");

}