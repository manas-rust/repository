/*************************************************************************
	* 文件名：  select.c
	* 描  述：  查询       
	* 创建人：  王卿
	* 日  期：  2017年05月15日 星期一 14时56分31秒
	* 版  本：  1.0
	* 备  注：  创建MySQL变量 ==> 初始化MySQL变量 ==> 连接数据库 ==> 数据
    *        库查询 ==> 存储结果 ==> 获取结果 ==> 释放结果集 ==> 关闭连接
 ************************************************************************/
#include "my_select.h"

void my_select(MYSQL *con)
{

    MYSQL_RES * res;		//数据集
    MYSQL_ROW row;          //行
    MYSQL_FIELD *fd;
    char column[COLUMN_LEN][COLUMN_LEN];
    int tmp = 0;
    int i = 0, j = 0;

    char * query = "select * from stu_info";


    tmp = mysql_real_query(con, query, strlen(query));
    if(tmp != 0)
    {
        printf("error making query: %s\n", mysql_error(con));
        exit(1);
    }

    res = mysql_store_result(con);
    for(i = 0; fd = mysql_fetch_field(res); i++)
    {
        bzero(column[i], sizeof(column[i]));
        strcpy(column[i], fd -> name);
    }
    j = mysql_num_fields(res);
    for(i = 0; i < j; i++)
        printf("%-12s", column[i]);
    printf("\n");
	
    while(row = mysql_fetch_row(res))
    {
        for(i = 0; i < j; i++)
            printf("%-12s", row[i]);
        printf("\n");
    }
    mysql_free_result(res);

}

