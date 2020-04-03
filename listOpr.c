#include "head.h"


/*
function:
initalizing list by tail insert
parameter:
the addr of head and tail pointer, pointer of new node
return:
the numbers of nodes
*/

int listInsert(pStu* phead, pStu* ptail, pStu new) {

	int num = 0;

	if (*phead == NULL) {
		*phead = new;
		*ptail = new;
		++num;
	}
	else {
		(*ptail)->pNext = new;
		*ptail = new;
		new->pNext = NULL;
		++num;
	}

	return num;

}

void listPrint(pStu* phead) {
	
	pStu pCur = *phead;

	system("cls");
	HEAD();
	while (pCur) {
		printf(" %2d %10s %3d   %c  %-7.2f %-7.2f %-7.2f\n", pCur->no, pCur->name, pCur->age, pCur->sex, pCur->chnScr, pCur->mahScr, pCur->engScr);
		pCur = pCur->pNext;
	}
	system("pause");
	system("cls");

}

/*
function:
display record by choosing different categories
parameter:
opreation tag 
return:
back to menu
*/

void search(pStu* phead) {
	
	int tag;

	system("cls");
	while (

		printf("1. search by No.\n"),
		printf("2. search by Name\n"),
		printf("3. search by Age\n"),
		printf("4. search by Sex\n"),
		printf("5. back to menu\n\n"),

		printf("please select which categorie you want to search: "), scanf("%d", &tag)) {
		pStu pCur = *phead;
		system("cls");
		switch (tag) {
		case 1: printf("please input No. (0 to back):\n");
			int no;
			while(scanf("%d", &no)){
				if (no == 0) {
					break;
				}
				while (pCur) {
					if (pCur->no == no) {
						HEAD();
						printf(" %2d %10s %3d   %c  %-7.2f %-7.2f %-7.2f\n", pCur->no, pCur->name, pCur->age, pCur->sex, pCur->chnScr, pCur->mahScr, pCur->engScr);
						break;
					}
					else {
						pCur = pCur->pNext;
					}
				}
				if (pCur == NULL) {
					printf("not found, please input again:\n");
				}
				pCur = *phead;
			}
			system("cls");
			break;
		case 2: printf("please input Name (0 to back):\n"); 
			char name[LEN + 1] = {0};
			while (scanf("%s", &name)) {
				if (name[0] == '0') {
					break;
				}
				while (pCur) {
					if (strcmp(pCur->name, name) == 0) {
						HEAD();
						printf(" %2d %10s %3d   %c  %-7.2f %-7.2f %-7.2f\n", pCur->no, pCur->name, pCur->age, pCur->sex, pCur->chnScr, pCur->mahScr, pCur->engScr);
						pCur = pCur->pNext;
					}
					else {
						pCur = pCur->pNext;
					}
				}
				printf("please input again:\n");
				pCur = *phead;
			}
			system("cls"); break;
		case 3: printf("please input Age (0 to back):\n"); 
			int age;
			while (scanf("%d", &age)) {
				if (age == 0) {
					break;
				}
				while (pCur) {
					if (pCur->age == age) {
						HEAD();
						printf(" %2d %10s %3d   %c  %-7.2f %-7.2f %-7.2f\n", pCur->no, pCur->name, pCur->age, pCur->sex, pCur->chnScr, pCur->mahScr, pCur->engScr);
						pCur = pCur->pNext;
					}
					else {
						pCur = pCur->pNext;
					}
				}
				printf("please input again:\n");
				pCur = *phead;
			}
			system("cls");
			break;
		case 4: printf("please input Sex (0 to back):\n"); 
			char sex;
			while (getchar(), scanf("%c", &sex)) {
				if (sex == '0') {
					break;
				}
				while (pCur) {
					if (pCur->sex == sex) {
						HEAD();
						printf(" %2d %10s %3d   %c  %-7.2f %-7.2f %-7.2f\n", pCur->no, pCur->name, pCur->age, pCur->sex, pCur->chnScr, pCur->mahScr, pCur->engScr);
						pCur = pCur->pNext;
					}
					else {
						pCur = pCur->pNext;
					}
				}
				printf("please input again:\n");
				pCur = *phead;
			}
			system("cls");
			break;
		case 5: return;
		default:system("cls"), printf("operation must between 1 to 4\n");
		}
	}

}

/*
function:
first make sure the No of inputing exists
if exist, go to the change()
*/

void modify(pStu* phead) {
	
	int no;
	pStu pCur = *phead;

	system("cls");
	while (system("cls"), 
		printf("please input the no. of the student that you want to modify: (0 to back)\n"), scanf("%d", &no)) {
		if (no == 0) {
			break;
		}
		while (pCur) {
			if (pCur->no == no) {
				HEAD();
				printf(" %2d %10s %3d   %c  %-7.2f %-7.2f %-7.2f\n", pCur->no, pCur->name, pCur->age, pCur->sex, pCur->chnScr, pCur->mahScr, pCur->engScr);
				change(pCur);
				break;
			}
			else {
				pCur = pCur->pNext;
			}
		}
		if (pCur == NULL) {
			printf("not found, please input again:\n");
		}
		pCur = *phead;
	}
	system("cls");

}

void change(pStu pCur) {

	int val;
	float score;

	printf("1. change Chinese score\n");
	printf("2. change Math score\n");
	printf("3. change English score\n");
	printf("4. back\n\n");
	printf("please select which subject you want to change: ");

	while (scanf("%d", &val) != 0) {
		printf("please input the new score: ");
		switch (val) {
		case 1: scanf("%f", &score), pCur->chnScr = score; return;
		case 2: scanf("%f", &score), pCur->mahScr = score; return;
		case 3: scanf("%f", &score), pCur->engScr = score; return;
		case 4: return;
		default:system("cls"), printf("operation must between 1 to 4\n");
		}
	}

}

/*
function:
insert new node in sort
if succeeded, back to menu
*/

void insert(pStu* phead, pStu* ptail) {
	
	pStu new = (pStu)calloc(1, sizeof(stu));
	pStu pCur = *phead;
	pStu pPre = *phead;

	system("cls");
	printf("please input the new record:\n");
	HEAD();
	scanf("%d%s%d %c%f%f%f", &new->no, &new->name, &new->age, &new->sex, &new->chnScr, &new->mahScr, &new->engScr);
	if (*phead == NULL) {
		*phead = new;
		*ptail = new;
		new->pNext = NULL;
	}
	else if (new->no < (*phead)->no) {
		new->pNext = *phead;
		*phead = new;
	}
	else {
		while (pCur) {
			if (new->no > pCur->no) {
				pPre = pCur;
				pCur = pCur->pNext;
			}
			else if (new->no == pCur->no) {
				return;
			}
			else {
				new->pNext = pCur;
				pPre->pNext = new;
				return;
			}
		}
		if (pCur == NULL) {
			pPre->pNext = new;
			*ptail = new;
			new->pNext = NULL;
		}
	}
	printf("add succeeded\n");
	system("pause");

}

void del(pStu* phead, pStu* ptail) {
	
	pStu pCur = *phead;
	pStu pPre = *phead;
	int val;

	system("cls");
	printf("input the student No. that your want to delete:\n");
	scanf("%d", &val);
	if (NULL == pCur) {
		printf("list empty\n");
		return;
	}
	else if (pCur->no == val) {
		*phead = pCur->pNext;
		pCur->pNext = NULL;
		free(pCur);
		pCur = NULL;
		if (*phead == NULL) {
			ptail = NULL;
			printf("list now empty\n");
			return;
		}
	}
	else {
		while (pCur) {
			if (pCur->no != val) {
				pPre = pCur;
				pCur = pCur->pNext;
			}
			else {
				pPre->pNext = pCur->pNext;
				pCur->pNext = NULL;
				break;
			}
		}
		if (pCur == NULL) {
			printf("val not found\n");
			return;
		}
	}
	printf("delete succeeded\n");
	system("pause");

}

/*
function:
list quick sort
recursive function
*/

void quickSort(pStu phead, pStu ptail) {

	if (phead != ptail) {
		pStu tag = partition(phead, ptail);
		quickSort(phead, tag);
		quickSort(tag->pNext, ptail);
	}
	return;

}

pStu partition(pStu phead, pStu ptail) {

	int key = phead->no;
	pStu pCur = phead->pNext;
	pStu pPre = phead;

	while (pCur != ptail) {
		if (pCur->no < key) {
			SWAP(pPre, pCur);
			pPre = pPre->pNext;
		}
		pCur = pCur->pNext;
	}
	if (pCur->no < pPre->no) {
		SWAP(pPre->pNext, pCur);
		SWAP(pPre->pNext, pPre);
	}
	SWAP(phead, pPre);
	return pPre;

}

void SWAP(pStu a, pStu b) {

	pStu tmp = (pStu)calloc(1, sizeof(stu));

	tmp->no = a->no;
	tmp->age = a->age;
	tmp->name[LEN - 1] = a->name[LEN - 1];
	tmp->sex = a->sex;
	tmp->chnScr = a->chnScr;
	tmp->mahScr = a->mahScr;
	tmp->engScr = a->engScr;

	a->no = b->no;
	a->age = b->age;
	a->name[LEN - 1] = b->name[LEN - 1];
	a->sex = b->sex;
	a->chnScr = b->chnScr;
	a->mahScr = b->mahScr;
	a->engScr = b->engScr;

	b->no = tmp->no;
	b->age = tmp->age;
	b->name[LEN - 1] = tmp->name[LEN - 1];
	b->sex = tmp->sex;
	b->chnScr = tmp->chnScr;
	b->mahScr = tmp->mahScr;
	b->engScr = tmp->engScr;

}