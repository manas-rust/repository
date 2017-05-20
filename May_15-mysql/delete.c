/*************************************************************************
	* 文件名：  delete.c
	* 描  述：      
	* 创建人：  王卿
	* 日  期：  2017年05月15日 星期一 14时56分31秒
	* 版  本：  1.0
	* 备  注：  
 ************************************************************************/
#include "delete.h"

void delete(MYSQL *con)
{
    int res = 0;
    char sql[100] = {0};
    int id = 0;
    printf("please input student's id:\n");
    scanf("%d", &id);

    sprintf(sql, "delete from score where id = '%d'", id);


    res = mysql_real_query(con, sql, strlen(sql));
    if(res != 0)
    {
        printf("delete error: %s\n", mysql_error(con));
        exit(1);
    }
    printf("delete success!\n");

}

