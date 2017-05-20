#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mysql/mysql.h>
#define N 2                 //要添加的人数

typedef struct stu_info2
{
    int id;
    char name[20];
    char sex[2];
    char credit[20];
    char phone[20];
    //char hiredate[50];
    struct stu_info2 * next;
}STU;


void creat(STU * ,int );

void input(STU *);

void link_to_mysql(STU * ,MYSQL *);
void output(STU *);
void my_free(STU * );
