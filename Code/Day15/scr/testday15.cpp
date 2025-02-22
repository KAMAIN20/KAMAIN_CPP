#include <iostream>
#include <string>
#include <functional>
#include <vector>
using namespace std;

/*
	函数指针：
	返回值类型 (*指针变量名)(参数列表) = 函数名 / &函数名; 会返回一个指向函数入口的指针，称之为函数指针，函数调用就是利用指针跳转执行指令
	函数调用过程：放代码段->定义表（包括函数入口地址）-> 找地址跳转

	lambda表达式: 用在函数指针中
	[](参数及其类型){函数体}匿名函数一次性函数，函数指针变量生命周期结束，就删除
	[捕获]: 捕获：就是将外部变量传递捕获进去匿名函数中，让其能够访问，&捕获外部使用变量的引用、= 值传递复制或者自己明确
	int a = 6;
	[a](){}
	[&a](){}
	[&](){}
	[=](){}

	在<functional>头文件有
	function<void(int)>类型本质上是typedef void (*function)(int)类型重定义了



	命名空间namespace：命名隔离
	uing用法：
	1.引用命名空间：using namespace xxx 或者 引入单个  using std::string 或者 using namespace std::string
		1.1 命名空间取别名 namespace a = std;
	2.类型起别名：using int_type = int; int_type a = 5;
	3.显式地引入基类的成员
		void print() { std::cout << "Derived::print" << std::endl; }
		using Base::print;  // 显式引入基类的 print 函数

*/

using int_type = int;

typedef int (*Add)(int, int);//或者进行类型别名，这里Add就不是指针变量名了，而是整个指针变量类型
// Add add = AddFunc; 这里的Add add = void (*add)(int,int)
void PrintAdd(int x, int y, Add add)
{
	cout << add(x, y) << "\n";
}

int AddFunc(int x, int y)
{
	return x + y;
}

int main()
{
	void (*PrAd)(int, int, Add) = PrintAdd;
	PrAd(1, 3, AddFunc);

	int_type a = 45;
	auto lambda = [a]() mutable {a = 1; cout << "lmabda" << "\n"; };

	/*	按值捕获的变量默认是常量，不能被修改。
		如果需要修改按值捕获的变量，需要使用 mutable 关键字。这样就捕获变量了
		如果需要修改原始变量，应该使用按引用捕获[&a]*/
	vector<int>::iterator;
	cout << "-------------------------------------\n";
	cout << a << endl;
	return 0;
}

