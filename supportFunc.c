#include "head.h"

extern int opr;            // operating tag


void menu(pStu* phead, pStu* ptail, int cout) {
    system("cls");
    int num;
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
    scanf("%d", &num);
    switch (num) {
    case 1:search(phead); break;
    case 2:modify(phead); break;
    case 3:insert(phead, ptail); break;
    case 4:del(phead, ptail); break;
    case 5:listPrint(phead); break;
    case 6:save(phead, cout), printf("\nsaving succeeded.\n"), opr = 0; break;
    default:system("cls"), printf("operation must between 1 to 6\n"),system("pause");
    }
}

void save(pStu* phead, int cout) {
    FILE* fp;
    pStu pCur = *phead;
    fp = fopen("record.txt", "w");
    while(pCur->pNext != NULL) {
        fprintf(fp, "%d %s %d %c %f %f %f\n", pCur->no, pCur->name, pCur->age, pCur->sex, pCur->chnScr, pCur->mahScr, pCur->engScr);
        pCur = pCur->pNext;
    }
    fprintf(fp, "%d %s %d %c %f %f %f", pCur->no, pCur->name, pCur->age, pCur->sex, pCur->chnScr, pCur->mahScr, pCur->engScr);
    fclose(fp);
}

int account() {

    system("cls");
    char account_M[50] = "shirohige123456\r";
    char account_S[50] = "654321";
    char m_a[50];
    char m_p[50] = { 0 };
    int ret;

    printf("  Wellcome to the SIMS\n\n");
    printf("please input your account: ");
    scanf("%s", &m_a);
    if (m_a[0] >= 49 && m_a[0] <= 57) {
        ret = studen(m_a);
    }
    else {
        printf("please input your password: ");
        for (int i = 0; i < 50; i++) {
            m_p[i] = _getch();
            if (m_p[i] == '\r') {
                break;
            }
            printf("*");
        }
        strcat(m_a, m_p);
        ret = strcmp(account_M, m_a);
    }
    return ret;
}

void HEAD(){
    printf("  No.     Name  Age Sex Chinese   Math  English\n");
}

int studen(char* m_a) {
    int i = 0;
    int no = 0;
    char m_p[50] = { 0 };
    if (m_a[i] != '\r') {
        no += (int)m_a[i] - 48;
        ++i;
    }
    printf("please input your password: ");
    for (int i = 0; i < 50; i++) {
        m_p[i] = _getch();
        if (m_p[i] == '\r') {
            break;
        }
        printf("*");
    }
    int ret = strcmp("123456\r", m_p);
    if (ret == 0) {
        return no + 10;
    }
    else{
        return ret;
    }
}

void show(int no, pStu phead) {
	no = no - 10;
	pStu pCur = phead;
	while (pCur) {
		if (pCur->no == no) {
            printf("your record is:\n");
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
    system("pause");
    return;
}