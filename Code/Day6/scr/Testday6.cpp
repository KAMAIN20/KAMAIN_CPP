#include <iostream>
#include <string>
using namespace std;

/*
	���飺
	ջ�д�����������ʵ�����������ڴ��С��һ����
	�����򿪱ٿռ䣬�ö���洢������ĵ�ַ����ô���������ڴ�ռ�ֻ�����һ����ַ��С
	�ַ�����
		"�ַ���"��˫���������������ַ�����Ĭ����const char [��СΪʵ���ַ�������+'\0']���ַ�����
		�ַ����������޸�

*/

class A {
	int a[5];
public:
	A() {
		for (int i = 0; i < 5; i++)
		{
			a[i] = 3;
		}
	}
};


int main() {
	cout << "day6" << endl;
	char cc[5] = "asd";
	cout << sizeof(cc);

	//string s = "HELLO" + "WORLD";//��Ϊ�����ַ����������ܽ�������
	string s = string("HELLO") + "WORLD"; //��Ϊstring��ʵ���� string s += "***"�����ֻ��Ҫ��һ��Ϊstring����
	bool contains = s.find("LL") != string::npos;//��������ʵ�ְ����жϣ�string��û��contain()������
	//����ͨ�����ҵ�һ�����ֵ�λ�ò����ڡ������ڵ�λ�á�ʵ��
/*
	�ַ�����������
	�ַ������������� "asd"���Ǵ洢��ֻ���洢���ģ����ܱ��޸ġ�
	�ַ����飨�� char A[5]���Ǵ洢�ڿɶ�д�ڴ��У�ջ���ģ����Ա��޸ġ�
		char* A = "asd";
		A[1] = '1';//���ǲ����޸ĵ�
		
		char A[5] = "asd";
		A[1] = '1';
		char A[5] ������һ����СΪ5���ַ����顣= "asd" ���ַ��������� "asd" ���������ֽڸ��Ƶ����� A �С�

		�ر�
		char* name = "Bob"���ڲ�ͬ��������������ģ���Ϊ��clang��GCC�������У�char*��ָ��һ�����޸ĵ��ַ���ָ��
							���ַ������������ص���const char*����һ��ָ�򲻿��޸ĵ��ַ�������MSVC�л�����Զ�����
							Ϊconst char* name = "Bob"�����ǹ淶д������������char* name = "Bob"

		������������ÿ���ַ�ռ���ֽڲ�ͬ�����ڲ�ͬ���볡��
		��ͨ�ַ���		��			const char[]		ASCII/UTF-8
		UTF-8 �ַ���		u8			const char[]		UTF-8
		UTF-16 �ַ���	u			const char16_t[]	UTF-16
		UTF-32 �ַ���	U			const char32_t[]	UTF-32
		���ַ��ַ���		L			const wchar_t[]		ƽ̨������UTF-16/UTF-32��
		ԭʼ�ַ���		R"(...)"	const char[]		ԭʼ���ݣ�֧�ֻ��У�
*/

	cout << endl;
	cout << endl;
	char A[5] = "as";
	cout << A << endl;
//----------------------------------------------------------------------------------------------------------
	using namespace std::string_literals;//��׼��
	string s1 = "Hello"s + "World";//����ʵ��
	const char* B = "as"
		"da";//C��C++����֧�������ַ������������Զ�����
	cout << B << endl;

	return 0;
}