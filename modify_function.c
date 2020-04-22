#include "head.h"

void SelectSearchCatigories(p_student* p_head) {

	int menu_opr;

	system("cls");
	while (

		printf("1. search by No.\n"),
		printf("2. search by Name\n"),
		printf("3. search by Age\n"),
		printf("4. search by Sex\n"),
		printf("5. back to menu\n\n"),

		printf("please select which categorie you want to search: "), 
		scanf("%d", &menu_opr)) {
		p_student stu_to_be_found = *p_head;
		system("cls");
		switch (menu_opr) {
		case 1: printf("please input No. (0 to back):\n");
			int target_stu;
			while (scanf("%d", &target_stu)) {
				if (target_stu == 0) {
					break;
				}
				while (stu_to_be_found) {
					if (stu_to_be_found->no == target_stu) {
						DisplayOneStuInfo(stu_to_be_found->no + 10, *p_head);
						break;
					}
					else {
						stu_to_be_found = stu_to_be_found->p_next;
					}
				}
				if (stu_to_be_found == NULL) {
					printf("not found, please input again:\n");
				}
				printf("please input again:\n");
				stu_to_be_found = *p_head;
			}
			system("cls");
			break;

		case 2: printf("please input Name (0 to back):\n");
			char name_searched[MAX_NAME_LEN + 1] = { 0 };
			while (scanf("%s", &name_searched)) {
				if (name_searched[0] == '0') {
					break;
				}
				while (stu_to_be_found) {
					if (strcmp(stu_to_be_found->name, name_searched) == 0) {
						DisplayOneStuInfo(stu_to_be_found->no + 10, *p_head);
						break;
					}
					else {
						stu_to_be_found = stu_to_be_found->p_next;
					}
				}
				if (stu_to_be_found == NULL) {
					printf("not found, please input again:\n");
				}
				printf("please input again:\n");
				stu_to_be_found = *p_head;
			}
			system("cls"); 
			break;

		case 3: printf("please input Age (0 to back):\n");
			int age_searched;
			while (scanf("%d", &age_searched)) {
				if (age_searched == 0) {
					break;
				}
				while (stu_to_be_found) {
					if (stu_to_be_found->age == age_searched) {
						DisplayOneStuInfo(stu_to_be_found->no + 10, *p_head);
						break;
					}
					else {
						stu_to_be_found = stu_to_be_found->p_next;
					}
				}
				if (stu_to_be_found == NULL) {
					printf("not found, please input again:\n");
				}
				printf("please input again:\n");
				stu_to_be_found = *p_head;
			}
			system("cls");
			break;

		case 4: printf("please input Sex (0 to back):\n");
			char sex_searched;
			while (getchar(), scanf("%c", &sex_searched)) {
				if (sex_searched == '0') {
					break;
				}
				while (stu_to_be_found) {
					if (stu_to_be_found->sex == sex_searched) {
						DisplayOneStuInfo(stu_to_be_found->no + 10, *p_head);
						break;
					}
					else {
						stu_to_be_found = stu_to_be_found->p_next;
					}
				}
				if (stu_to_be_found == NULL) {
					printf("not found, please input again:\n");
				}
				printf("please input again:\n");
				stu_to_be_found = *p_head;
			}
			system("cls");
			break;

		case 5: return;
		default:system("cls"), printf("operation must between 1 to 4\n");
		}
	}

}

void FindStuNeedChanged(p_student* p_head) {

	int target_stu;
	p_student stu_to_be_changed = *p_head;

	system("cls");
	while (system("cls"),
		printf("please input the no. of the student that you want to modify: (0 to back)\n"), 
		scanf("%d", &target_stu)) {
		if (target_stu == 0) {
			break;
		}
		while (stu_to_be_changed) {
			if (stu_to_be_changed->no == target_stu) {
				HEAD();
				printf(
					" %2d %10s %3d   %c  %-7.2f %-7.2f %-7.2f\n", 
					stu_to_be_changed->no, 
					stu_to_be_changed->name, 
					stu_to_be_changed->age, 
					stu_to_be_changed->sex, 
					stu_to_be_changed->chnScr, 
					stu_to_be_changed->mahScr, 
					stu_to_be_changed->engScr
				);
				ChangeScore(stu_to_be_changed);
				break;
			}
			else {
				stu_to_be_changed = stu_to_be_changed->p_next;
			}
		}
		if (stu_to_be_changed == NULL) {
			printf("student not found, please input again:\n");
		}
		stu_to_be_changed = *p_head;
	}
	system("cls");

}

void ChangeScore(p_student stu_to_be_changed) {

	int menu_opr;
	float new_score;

	printf("1. change Chinese score\n");
	printf("2. change Math score\n");
	printf("3. change English score\n");
	printf("4. back\n\n");
	printf("please select which subject you want to change: ");

	while (scanf("%d", &menu_opr) != 0) {
		printf("please input the new score: (4 to cancle)");
		switch (menu_opr) {
		case 1: scanf("%f", &new_score), stu_to_be_changed->chnScr = new_score; return;
		case 2: scanf("%f", &new_score), stu_to_be_changed->mahScr = new_score; return;
		case 3: scanf("%f", &new_score), stu_to_be_changed->engScr = new_score; return;
		case 4: return;
		default:system("cls"), printf("operation must between 1 to 4\n");
		}
	}

}

void AddNewRecord(p_student* p_head, p_student* p_tail) {

	p_student new_student = (p_student)calloc(1, sizeof(student));
	p_student p_cur = *p_head;
	p_student p_pre = *p_head;

	system("cls");
	printf("please input the new record:\n");
	HEAD();
	scanf(
		"%d%s%d %c%f%f%f", 
		&new_student->no, 
		&new_student->name, 
		&new_student->age, 
		&new_student->sex, 
		&new_student->chnScr, 
		&new_student->mahScr, 
		&new_student->engScr
	);

	if (*p_head == NULL) {
		*p_head = new_student;
		*p_tail = new_student;
		new_student->p_next = NULL;
	}
	else if (new_student->no < (*p_head)->no) {
		new_student->p_next = *p_head;
		*p_head = new_student;
	}
	else {
		while (p_cur) {
			if (new_student->no > p_cur->no) {
				p_pre = p_cur;
				p_cur = p_cur->p_next;
			}
			else if (new_student->no == p_cur->no) {
				return;
			}
			else {
				new_student->p_next = p_cur;
				p_pre->p_next = new_student;
				return;
			}
		}
		if (p_cur == NULL) {
			p_pre->p_next = new_student;
			*p_tail = new_student;
			new_student->p_next = NULL;
		}
	}
	printf("add succeeded\n");
	system("pause");

}

void DelStuInfo(p_student* p_head, p_student* p_tail) {

	p_student p_cur = *p_head;
	p_student p_pre = *p_head;
	int stu_to_be_deleted;

	system("cls");
	printf("input the student No. that your want to delete:\n");
	scanf("%d", &stu_to_be_deleted);

	if (p_cur->no == stu_to_be_deleted) {
		*p_head = p_cur->p_next;
		p_cur->p_next = NULL;
		free(p_cur);
		p_cur = NULL;
		if (*p_head == NULL) {
			p_tail = NULL;
			printf("list now empty\n");
			return;
		}
	}
	else {
		while (p_cur) {
			if (p_cur->no != stu_to_be_deleted) {
				p_pre = p_cur;
				p_cur = p_cur->p_next;
			}
			else {
				p_pre->p_next = p_cur->p_next;
				p_cur->p_next = NULL;
				break;
			}
		}
		if (p_cur == NULL) {
			printf("student not found\n");
			return;
		}
	}
	printf("delete succeeded\n");
	system("pause");

}