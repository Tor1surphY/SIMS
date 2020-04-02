#include "head.h"

int opr = 1;            // operating tag
int tNum = 0;           // total number of students
int nNum = 0;           // number of new students

int main() {
    pStu phead = NULL;
    pStu ptail = NULL;
    FILE* fp;
    int i = 0;
    int cout = 0;
    fp = fopen("record.txt", "r");
    while (!feof(fp)) {
        pStu new = (pStu)calloc(1, sizeof(stu));
        fscanf(fp, "%d%s%d %c%f%f%f", &new->no, &new->name, &new->age, &new->sex, &new->chnScr, &new->mahScr, &new->engScr);
        cout = listInsert(&phead, &ptail, new);
    }
    fclose(fp);
    quickSort(phead, ptail);
    while (opr) {
        int prm = account();
        if (prm == 0) {
            while (opr) {
                menu(&phead, &ptail, cout);
            }
        }
        else if (prm == -1 || prm == 1) {
            system("cls");
            printf("\nwrong account or password!\n\nplease input again\n");
            system("pause");
            ++i;
        }
        else {
            system("cls");
            show(prm, phead);
        }
        if (i > 2) {
            system("cls");
            printf("you have input wrong info over 3 times\n\nthe system will quit\n");
            break;
        }
    }
    system("pause");
}