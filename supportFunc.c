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