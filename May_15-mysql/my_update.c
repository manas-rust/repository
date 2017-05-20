/*************************************************************************
	* 文件名：  my_update.c
	* 描  述：      
	* 创建人：  王卿
	* 日  期：  2017年05月15日 星期一 14时56分31秒
	* 版  本：  1.0
	* 备  注：  
 ************************************************************************/
#include "my_select.h"
void my_update(MYSQL * con)
{

    int res = 0;
    char * sql = "update score set physic = 75 where id = 12005";


    res = mysql_real_query(con, sql, strlen(sql));
    if(res != 0)
    {
        printf("update error: %s\n", mysql_error(con));
        exit(1);
    }
    printf("update success!\n");

}

