#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_NAME_LEN 15
#define HEAD(){ printf("  No.     Name  Age Sex Chinese   Math  English\n"); }

typedef struct node{
    int     no;
    int     age;
    char    sex;
    float   chnScr;               // score of chinese
    float   mahScr;               // score of math
    float   engScr;               // score of english
    char    name[MAX_NAME_LEN + 1];
    struct  node* p_next;
}student, *p_student;

// modify function
void SelectSearchCatigories(p_student*);
void FindStuNeedChanged(p_student*);
void ChangeScore(p_student);
void AddNewRecord(p_student*, p_student*);
void DelStuInfo(p_student*, p_student*);

// system function
void ListInit(p_student*, p_student*, p_student);
void Menu(p_student*, p_student*);
void SaveBeforeQuit(p_student*);

// account function
int AccountDiffer();
int IsStudent(char*);

// display function
void DisplayOneStuInfo(int, p_student);
void DisplayAllStuInfo(p_student*);

// sort
void Sort(p_student, p_student);
p_student Partition(p_student, p_student);
void Swap(p_student, p_student);