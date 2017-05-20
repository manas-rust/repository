/*************************************************************************
	* 文件名： main.c
	* 描  述： 
	* 创建人： 王卿
	* 日  期： 2017年05月14日 星期日 13时51分42秒
	* 版  本： 1.0
	* 备  注： 
 ************************************************************************/
#include "array_to_mysql.h"
#include "delete.h"
#include "link_to_mysql.h"
#include "my_select.h"


int main()
{
    int opt = 1;
    MYSQL mysql;
    MYSQL * con = &mysql;
    
    int n = 0;									//链表结点数
    STU * head = (STU *)calloc(1,sizeof(STU));	//定义链表头指针
    
    struct stu_info stu[5] = {
		{12010, "xiaoli", "M", "3112673123", "15568123456"},
		{12011, "xdads", "M", "3112056123", "15045123456"},
		{12012, "xissli", "M", "3112433123", "1548123456"},
		{12013, "xiadli", "M", "3112453123", "15888123456"},
		{12014, "xicjli", "M", "3112233123", "15188123456"}
	};
				
    mysql_init(con);
    
	if( !mysql_real_connect(con, "localhost", "root", "123", "db_students", 0, NULL, 0) )
	{
		printf("error connecting to database: %s\n", mysql_error(con));
		exit(1);
	}


    while(opt)
    {
        printf("%s\n", SEP);
        printf("|");
        printf("%45s","数据库作业");
        printf("%33s\n","|");
        printf("%s\n", SEP);
        printf("|");
        printf("0、退出\t\t1、数组-数据库\t\t2、删除\t\t3、修改%3s\n", "|");
        printf("|");
        printf("4、链表-数据库\t\t5、数据库-数组\t\t6、数据库-链表\t7、查询%3s\n", "|");
        printf("%s\n", SEP);
        printf("|");

        printf("请输入你的选择：");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
				array_to_mysql(stu,con);
                break;
            case 2:
				delete(con);
                break;
            case 3:
				my_update(con);
                break;
            case 4:
				printf("请输入要插入学生人数:");
    			scanf("%d", &n);
    			
   				creat(head, n);                  //创建链表
   				printf("请输入学生信息:\n");
    			printf("id\tname\tsex\tcredit\tphone\n ");
    			input(head);					//输入数据
    			link_to_mysql(head, con); 		//插入数据库
    			output(head);					//输出
    			my_free(head);					//释放空间
    			free(head);						//释放头结点
   				
                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
            	printf("%s\n", SEP);
            	my_select(con);
            	printf("%s\n", SEP);
            	break;
            case 0:
            	mysql_close(con);
                opt = 0;
                break;
            default:
                printf("亲，别乱来，请正确输入！！\n");
                break;
        }
    }
	return 0;
}

