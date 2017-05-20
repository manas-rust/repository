/*************************************************************************
	* 文件名：  array_to_mysql.c
	* 描  述：      
	* 创建人：  王卿
	* 日  期：  2017年05月16日 星期二 16时22分42秒
	* 版  本：  1.0
	* 备  注：  
 ************************************************************************/
#include "array_to_mysql.h"

void array_to_mysql(struct stu_info *stu, MYSQL *con)
{
    int i = 0;
    int res = 0;
	
    char buf[2*sizeof(stu[0])] = {0};
    
    for(i = 0; i < 5; i++)
    {
    	sprintf(buf, "insert into stu_info(id, name, sex, credit, phone)  values('%d', '%s', '%s','%s', '%s')", stu[i].id, stu[i].name, stu[i].sex, stu[i].credit, stu[i].phone );
    
        res = mysql_real_query(con, buf, strlen(buf));
        if(res != 0)
        {
            printf("insert into error: %s\n", mysql_error(con));
            exit(1);
        }
        printf("insert into success\n");
        
        bzero(buf, sizeof(buf));
	}
}

