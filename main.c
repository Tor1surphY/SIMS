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
        menu(&phead, &ptail, cout);
    }
    system("pause");
}