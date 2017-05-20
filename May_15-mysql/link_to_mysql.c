/*************************************************************************
	* 文件名：  link.c
	* 描  述：      
	* 创建人：  王卿
	* 日  期：  2017年05月15日 星期一 19时02分36秒
	* 版  本：  1.0
	* 备  注：  
 ************************************************************************/
#include "link_to_mysql.h"

/* 增加链表结点 */
void creat(STU * temp, int n)
{
    int i = 0;
    for( i = 0; i < n; i++ )
    {
        temp -> next = (STU *)calloc(1,sizeof(STU));
        temp = temp -> next;
    }
}
/* 录入学生信息 */ 
void input(STU *p)
{
	//time_t  timep;
    //time(&timep);
	for(p = p -> next; p != NULL; p = p -> next)
    {
        scanf("%d", &p -> id);
        scanf("%s", p -> name);
        scanf("%s", p -> sex);
        scanf("%s", p -> credit);
        scanf("%s", p -> phone);
      //  strcpy(p -> hiredate, ctime(&timep));
    }
	
}
/* 将链表信息写入数据库 */
void link_to_mysql(STU *p, MYSQL * con)
{
	int res =0;
	//由于buf要存入"insert into stu_info..."所以空间要开大一点
    char * buf = (char *)calloc(2, sizeof(STU));
    
    for(p = p -> next; p != NULL; p = p -> next)
    {  
		sprintf(buf, "insert into stu_info(id, name, sex, credit, phone)  values('%d', '%s', '%s','%s', '%s')", p -> id, p -> name, p -> sex, p -> credit, p -> phone );

		res = mysql_real_query(con, buf, strlen(buf));
		if(res != 0)
		{
		    printf("insert into error: %s\n", mysql_error(con));
		    exit(1);
		}
		printf("insert into success\n");
	}
		
    free(buf);
}

/* 输出学生信息 */ 
void output(STU *p)
{
    for(p = p -> next; p != NULL; p = p -> next)
    {
        printf("%-12d", p -> id);
        printf("%-12s", p -> name);
        printf("%-12s", p -> sex);
        printf("%-12s", p -> credit);
        printf("%-12s", p -> phone);
        //printf("%-12s", p -> hiredate);
    }
    printf("\n");
}
/* 释放空间 */
void my_free(STU * p)
{
	STU * ptmp = p;
	while(p != NULL)
	{
		ptmp = p;
		p = p -> next;
		free(ptmp);
	}
}








