#include"Solution.h"
void test1()
{
	Day1 solution;
	//solution.SolutionOne();
	solution.SolutionTwo();
	
}

void test2()
{
	Day2 solution;
	int res = solution.SolutionOne();
	cout << res << endl;

	solution.SolutionTwo();
}
void test3()
{
	Day3 solution;
	//solution.SolutionOne();

	solution.SolutionTwo();
}
void test4()
{
	Day4 solution;
	solution.SolutionTwo(7,2);
}
int main()
{
	test4();

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
