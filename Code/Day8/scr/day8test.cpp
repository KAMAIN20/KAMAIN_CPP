#include <iostream>
#include <string>
using namespace std;

/*
	��Ա��ʼ���б�
*/

class Animal {
	int m_age;
	string m_name;
public:
	Animal() :m_age(0), m_name("N")//��Ա��ʼ���б���ð�������˳��
	{

	} 
	Animal(int age ,const string& name):m_age(age), m_name(name){}
	void print() const
	{
		cout << m_age << " " << m_name << endl;
	}

};
//�������
class TestClass 
{
public:
	TestClass() { cout << "�޲�" << endl; }
	TestClass(int x) { cout << "�в�" << endl; }
};

class Entity 
{
	TestClass testclass;
public:
	//��һ��
	Entity()
	{
		testclass = TestClass(8);
	}
	//�ڶ���
	Entity() :testclass(TestClass(8)) {}//ֱ�ӵ����˹��캯��������Ҫ������ʱ��������testclass(8)һ����
};
//ʵ���ϴ�������������һ������ʱ�ĵ����������β�ͬ���캯������Ϊc++������ջ�ϴ�������Ӧ���õڶ���

int main()
{

	Animal cat;
	cat.print();
	Animal Dog(15,"Dog");
	Dog.print();

	return 0;
}