#include <iostream>
#include <string>

#include <array>

/*
	auto关键字 -- 必须初始化根据值进行推导的，不然不知道开多少内存
	静态数组：array -#include <array>

	静态数组array			动态数组vector
	1.数据在栈上				1.数据在堆上
	2.边界检查				2.可边长


*/

auto func() -> char* //auto后置类型确定
{
	return 0;
}

int main()
{
	const char* c = "dasd";
	std::string s = c;

	//array
	std::array<int, 5> arr = {1,2,3,4,5};//模板<类型，大小>
	arr[2] = 1;
	arr[5] = 5;//array有边界检查
	return 0;
}