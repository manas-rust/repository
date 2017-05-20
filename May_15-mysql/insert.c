/*************************************************************************
	* 文件名：  insert.c
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
    mysql_init(con);
    int res = 0;
    char * sql = "insert into stu_info values('12007', 'liudehua', 'M', '3112003887', '15088133888', '2017-05-15')";


    if( !mysql_real_connect(con, "localhost", "root", "123", "db_students", 0, NULL, 0) )
    {
        printf("error connecting to database: %s\n", mysql_error(con));
        return -1;
    }

    res = mysql_real_query(con, sql, strlen(sql));
    if(res != 0)
    {
        printf("insert into error: %s\n", mysql_error(con));
        return -1;
    }
    printf("insert into success!\n");

    mysql_close(con);

    return 0;
}

