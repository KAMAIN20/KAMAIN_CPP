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

	//隐式转换：通过只有一个参数的构造函数，会通过类型判断函数签名进行匹配。可以进行构造函数隐式调用
	//显式调用explicit关键字：用这种关键字修饰的构造方法只能显式调用。explicit Animal(string name) : name(name){}
	Animal a1 = 22;
	//Animal a1 = string("AC");只能显式调用

	return 0;
}