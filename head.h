#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define LEN 15 // lenth of name character


typedef struct record{
    int no;                     // no.
    char name[LEN + 1];         // name
    int age;                    // age
    char sex;                   // gender
    float chnScr;               // score of chinese
    float mahScr;               // score of math
    float engScr;               // score of english
    struct  record* pNext;      // pointer of list
}stu, *pStu;

void HEAD();                        // list head print
void show(int, pStu);               // display the target student's record
int studen(char*);                  // student option
int account();                      // loading
void search(pStu*);                 // search record
void modify(pStu*);                 // modify record
void menu(pStu*, pStu*, int);       // menu
void listPrint(pStu* phead);        // print current list
int listInsert(pStu*, pStu*, pStu); // initalize the list from .txt
void change(pStu);                  // change score
void insert(pStu*, pStu*);          // add a new record
void del(pStu*, pStu*);             // delete
void save(pStu*, int);              // save change
void quickSort(pStu, pStu);         // quick sort records by No.
    pStu partition(pStu, pStu);
    void SWAP(pStu, pStu);