#include <iostream>
#include <string>

using namespace std;

class Animal {
	int age;
	string name;
public:
	explicit Animal(string name) : name(name){
		cout << "this is constructor with argument of string"<<endl;
	}

	Animal(int age) : age(age)
	{
		cout << "this is constructor with argument of int" << endl;
	}

};

int main() {

	//��ʽת����ͨ��ֻ��һ�������Ĺ��캯������ͨ�������жϺ���ǩ������ƥ�䡣���Խ��й��캯����ʽ����
	//��ʽ����explicit�ؼ��֣������ֹؼ������εĹ��췽��ֻ����ʽ���á�explicit Animal(string name) : name(name){}
	Animal a1 = 22;
	//Animal a1 = string("AC");ֻ����ʽ����

	return 0;
}