#include <iostream>
#include <string>
#include <functional>
#include <vector>
using namespace std;

/*
	����ָ�룺
	����ֵ���� (*ָ�������)(�����б�) = ������ / &������; �᷵��һ��ָ������ڵ�ָ�룬��֮Ϊ����ָ�룬�������þ�������ָ����תִ��ָ��
	�������ù��̣��Ŵ����->���������������ڵ�ַ��-> �ҵ�ַ��ת

	lambda���ʽ: ���ں���ָ����
	[](������������){������}��������һ���Ժ���������ָ������������ڽ�������ɾ��
	[����]: ���񣺾��ǽ��ⲿ�������ݲ����ȥ���������У������ܹ����ʣ�&�����ⲿʹ�ñ��������á�= ֵ���ݸ��ƻ����Լ���ȷ
	int a = 6;
	[a](){}
	[&a](){}
	[&](){}
	[=](){}

	��<functional>ͷ�ļ���
	function<void(int)>���ͱ�������typedef void (*function)(int)�����ض�����



	�����ռ�namespace����������
	uing�÷���
	1.���������ռ䣺using namespace xxx ���� ���뵥��  using std::string ���� using namespace std::string
		1.1 �����ռ�ȡ���� namespace a = std;
	2.�����������using int_type = int; int_type a = 5;
	3.��ʽ���������ĳ�Ա
		void print() { std::cout << "Derived::print" << std::endl; }
		using Base::print;  // ��ʽ�������� print ����

*/

using int_type = int;

typedef int (*Add)(int, int);//���߽������ͱ���������Add�Ͳ���ָ��������ˣ���������ָ���������
// Add add = AddFunc; �����Add add = void (*add)(int,int)
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

	/*	��ֵ����ı���Ĭ���ǳ��������ܱ��޸ġ�
		�����Ҫ�޸İ�ֵ����ı�������Ҫʹ�� mutable �ؼ��֡������Ͳ��������
		�����Ҫ�޸�ԭʼ������Ӧ��ʹ�ð����ò���[&a]*/
	vector<int>::iterator;
	cout << "-------------------------------------\n";
	cout << a << endl;
	return 0;
}

