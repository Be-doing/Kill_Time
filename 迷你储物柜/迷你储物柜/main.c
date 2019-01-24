#include"Locker.h"
#include<stdio.h>
#include<stdlib.h>
main()
{
	Interface();
	char* temp = Generate_Password();
	printf("%s\n",temp);
	system("pause");
}