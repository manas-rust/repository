/*************************************************************************
	* 文件名：  mysql_to_link.c
	* 描  述：  结构体数组中的信息保存到二维表中        
	* 创建人：  王卿
	* 日  期：  2017年05月15日 星期一 14时56分31秒
	* 版  本：  1.0
	* 备  注：  创建MySQL变量 ==> 初始化MySQL变量 ==> 连接数据库 ==> 数据
    *        库查询 ==> 存储结果 ==> 获取结果 ==> 释放结果集 ==> 关闭连接
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#define COLUMN_LEN 32

typedef struct stu_info
{
    int id;
    char name[20];
    char sex[2];
    char credit[20];
    char phone[20];
    char hiredate[50];
    struct stu_info * next;
}STU;
void creat_link(int n, STU *p);

int main()
{
    MYSQL mysql;
    MYSQL * con = &mysql;
    MYSQL_RES * res;		//数据集
    MYSQL_ROW row;          //行
    MYSQL_FIELD *fd;
    char column[COLUMN_LEN][COLUMN_LEN];
    int t = 0;
    int i = 0, j = 0;       //j为字段名数
    int num = 0;            //行数
    STU * head = (STU *)calloc(1,sizeof(STU));
    STU * p = head;
    STU tmp = {0};
    
    mysql_init(con);        //初始化
    char * query = "select * from stu_info";

    //连接数据库
    if( !mysql_real_connect(con, "localhost", "root", "123", "db_students", 0, NULL, 0) )
    {
        printf("error connecting to database: %s\n", mysql_error(con));
        return -1;
    }

    t = mysql_real_query(con, query, strlen(query));
    if(t != 0)
    {
        printf("error making query: %s\n", mysql_error(con));
        return -1;
    }
    
    res = mysql_store_result(con);
    for(i = 0; fd = mysql_fetch_field(res); i++)
    {
        bzero(column[i], sizeof(column[i]));
        strcpy(column[i], fd -> name);
    }
    num = mysql_num_rows(res);
    j = mysql_num_fields(res);
    for(i = 0; i < j; i++)
        printf("%-12s", column[i]);
    printf("\n");
/*
    while(row = mysql_fetch_row(res))
    {
        for(i = 0; i < j; i++)
        
            printf("%-12s", row[i]);
        printf("\n");
    }
*/    
    creat_link(num, p);
    for(p = p -> next; p != NULL; p = p -> next)
    {
        if( row = mysql_fetch_row(res) )
        {
            p -> id = atoi(row[0]);
            strcpy(p -> name, row[1]);
            strcpy(p -> sex, row[2]);
            strcpy(p -> credit, row[3]);
            strcpy(p -> phone, row[4]);
            strcpy(p -> hiredate, row[5]);
        }
    }
    head = p;
    printf("**********************1111\n");
    p = head;
    printf("**********************123\n");
    for(p = p -> next; p != NULL; p = p -> next)
    {
        printf("%5d", p -> id);
        printf("%6s",p -> name);
        printf("%4s", p -> sex);
        printf("%12s", p -> credit);
        printf("%12s", p -> phone);
        printf("%12s\n", p -> hiredate);
    }

    mysql_free_result(res);

    mysql_close(con);

    return 0;
}

void creat_link(int n, STU *p)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        p -> next = calloc(1, sizeof(STU));
        p = p -> next;
    }
}
