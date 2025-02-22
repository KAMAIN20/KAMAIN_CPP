#include <iostream>
#include <string>
using namespace std;

/*
	成员初始化列表
*/

class Animal {
	int m_age;
	string m_name;
public:
	Animal() :m_age(0), m_name("N")//成员初始化列表，最好按照声明顺序
	{

	} 
	Animal(int age ,const string& name):m_age(age), m_name(name){}
	void print() const
	{
		cout << m_age << " " << m_name << endl;
	}

};
//特殊情况
class TestClass 
{
public:
	TestClass() { cout << "无参" << endl; }
	TestClass(int x) { cout << "有参" << endl; }
};

class Entity 
{
	TestClass testclass;
public:
	//第一种
	Entity()
	{
		testclass = TestClass(8);
	}
	//第二种
	Entity() :testclass(TestClass(8)) {}//直接调用了构造函数，不需要创建临时变量或者testclass(8)一样的
};
//实际上创建了两个对象，一个是临时的但调用了两次不同构造函数，因为c++允许在栈上创建对象，应该用第二种

int main()
{

	Animal cat;
	cat.print();
	Animal Dog(15,"Dog");
	Dog.print();

	return 0;
}