#include <iostream>
#include <string>

using namespace std;


/*
	const:  可以类中的方法成员、变量和指针为“常量”、“只读不可修改”
	1. 修饰变量 const int 
	2. 修饰指针 
		2.1 const int* = int const* 为指针指向的对象或者变量均为“只读不可修改”
		2.2 int* const 为只对该指针本身“只读不可修改”
	3.修饰类中的方法为只读
		3.1 void func() const {} 指的是在该方法内不可以对类中成员进行修改
		3.2 void const est() {};该方法不能被派生类重写
		3.3 用mutable修饰的成员可以访问 mutable int x
	4.不能修饰类

	特别声明情况：
	const int* const func() const {}
		1.const int* 返回一个只读指针
		2.const -int* const- 返回一个只读且自身不可修改的指针
		3.const int* const func() -const- 该函数对类中其他成员为只读权限

	情况说明：
	const A test();
	cout<<A.Getx<<endl;//这里不能调用成员函数了，因为该对象为只读，而Getx有可能对其他成员进行修改
						如 x = 1；这会导致一个漏洞，虽然只读但能够调用该成员函数进行修改。
						因此，成员函数必须也修饰为只读函数void Getx() const {}
						一般可以出现两种版本，会自动定位函数签名
						void Getx() const {}
						void Getx() {}
						函数签名的定义：函数签名只包括函数名和参数列表，不包括修饰符如const。
						而这两个void Getx() const {} void Getx() {} 是存在可调用性的差异，编译器会自动判断
		

	mutable:
		1.搭配const
		2.搭配lambda


*/

const class A {
public:
	int x;
	A() :x(0) {}
	void est() { cout << "this's A" << endl; };
	int Getx() const { return x; }
};

class B : public A {
public:
	void est() { cout << "this's B"<<endl; };
};

struct S {
	S(int x){}
};

int main()
{

	

	A* a = new B();
	a->est();
	B* b = new B();
	b->est();
	cout << "" << endl;

	B c;
	c = B();//重载了，相当于在栈上创建临时对象复制过去，然后销毁，重新赋值了

	S s(3);
	//s = S();//结构体不行

	const A test;
	cout<<test.Getx()<<endl;

	return 0;
}