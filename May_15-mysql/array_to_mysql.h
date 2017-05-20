
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#define SEP "+------------------------------------------------------------------------+"

struct stu_info
{
    int id;
    char name[20];
    char sex[2];
    char credit[20];
    char phone[20];
    //char hiredate[50];
};
void array_to_mysql(struct stu_info *, MYSQL *);
