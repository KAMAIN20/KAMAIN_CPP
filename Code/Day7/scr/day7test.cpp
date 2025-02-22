#include <iostream>
#include <string>

using namespace std;


/*
	const:  �������еķ�����Ա��������ָ��Ϊ������������ֻ�������޸ġ�
	1. ���α��� const int 
	2. ����ָ�� 
		2.1 const int* = int const* Ϊָ��ָ��Ķ�����߱�����Ϊ��ֻ�������޸ġ�
		2.2 int* const Ϊֻ�Ը�ָ�뱾��ֻ�������޸ġ�
	3.�������еķ���Ϊֻ��
		3.1 void func() const {} ָ�����ڸ÷����ڲ����Զ����г�Ա�����޸�
		3.2 void const est() {};�÷������ܱ���������д
		3.3 ��mutable���εĳ�Ա���Է��� mutable int x
	4.����������

	�ر����������
	const int* const func() const {}
		1.const int* ����һ��ֻ��ָ��
		2.const -int* const- ����һ��ֻ�����������޸ĵ�ָ��
		3.const int* const func() -const- �ú���������������ԱΪֻ��Ȩ��

	���˵����
	const A test();
	cout<<A.Getx<<endl;//���ﲻ�ܵ��ó�Ա�����ˣ���Ϊ�ö���Ϊֻ������Getx�п��ܶ�������Ա�����޸�
						�� x = 1����ᵼ��һ��©������Ȼֻ�����ܹ����øó�Ա���������޸ġ�
						��ˣ���Ա��������Ҳ����Ϊֻ������void Getx() const {}
						һ����Գ������ְ汾�����Զ���λ����ǩ��
						void Getx() const {}
						void Getx() {}
						����ǩ���Ķ��壺����ǩ��ֻ�����������Ͳ����б����������η���const��
						��������void Getx() const {} void Getx() {} �Ǵ��ڿɵ����ԵĲ��죬���������Զ��ж�
		

	mutable:
		1.����const
		2.����lambda


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
	c = B();//�����ˣ��൱����ջ�ϴ�����ʱ�����ƹ�ȥ��Ȼ�����٣����¸�ֵ��

	S s(3);
	//s = S();//�ṹ�岻��

	const A test;
	cout<<test.Getx()<<endl;

	return 0;
}