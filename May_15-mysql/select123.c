/*************************************************************************
	* 文件名：  select.c
	* 描  述：      
	* 创建人：  王卿
	* 日  期：  2017年05月15日 星期一 14时56分31秒
	* 版  本：  1.0
	* 备  注：  
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
int main()
{
    MYSQL mysql;
    MYSQL * con = &mysql;
    MYSQL_RES * res;		//数据集
    MYSQL_ROW row;          //行
    int t = 0, r = 0;
    mysql_init(con);        //初始化
    char * query = "select * from stu_info";

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

    res = mysql_use_result(con);
    for(r = 0; r <= mysql_field_count(con); r++)
    {
        row = mysql_fetch_row(res);
        if(row < 0) break;
        for(t= 0; t < mysql_num_fields(res); t++)
            printf("%-12s", row[t]);
        printf("\n");
    }
    mysql_free_result(res);

    mysql_close(con);

    return 0;
}

