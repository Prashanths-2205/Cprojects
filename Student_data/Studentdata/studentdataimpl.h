#include<stdio.h>
void manipulate();
void adddata();
void countstudents();
void displaydata();
void Updatedata();
void deletedata();
void memorydata();
int bytes;
int count;
int id;
int choice;
FILE *fe;
FILE *ft;
char str[80];

struct student
{
    int studentid;
    char studentname[20];
    char studentusn[15];
    char studentphno[15];
};
struct student stud;

enum students
{
    addstudentdata=1,
    displaystudentdata=2,
    modifystudentdata=3,
    deletestudentdata=4,
    memoryconsume=5,
    exitfromdata=6
};
