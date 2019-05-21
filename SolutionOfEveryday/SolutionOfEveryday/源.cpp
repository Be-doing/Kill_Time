#include"Solution.h"

//int test2()
//{
//	Solution2 s;
//	return s.Programe1();
//}
//
//
//int main()
//{
//	int res = test2();
//	printf("%d\n", res);
//	system("pause");//1 2 3 2 2 1 2 3 4 6 9
//	return 0;
//}'
void test1()
{
	Day1 solution;
	//solution.SolutionOne();

	solution.SolutionTwo();
	
}
int main()
{
	test1();
	system("pause");
	return 0;
}


//#include<iostream>
//#include<string.h>
//#include<vector>
//
//using namespace std;
//int leng(char* str) {
//	int len = 0;
//	while (str[len] != '\0') {
//		++len;
//	}
//	return len;
//}
//void swap_one(char* str, int star, int end) {
//
//	while (star <= end) {
//		char temp = str[star];
//		str[star] = str[end];
//		str[end] = temp;
//		++star;
//		--end;
//	}
//}
//
//void swap_two(char* str) {
//	int temp = 0;
//	int start = 0;
//	int end = leng(str) - 1;
//	swap_one(str, start, end);
//	printf("第一次翻转后的字符串：%s\n", str);
//	while (str[temp] != '\0') {
//		start = temp;
//		while ((str[temp] != '\0') && (str[temp] != ' ')) {
//			temp++;
//		}
//		end = temp - 1;
//		swap_one(str, start, end);
//		if (str[temp] != '\0') {
//			temp++;
//		}
//	}
//	printf("最后一次翻转后的字符串为：%s\n", str);
//}
//int main() {
//	char orig[100];
//	cin.getline(orig, 100);
//	int end = leng(orig) - 1;
//	int star = 0;
//	swap_two(orig);
//	system("pause");
//	return 0;
//}
