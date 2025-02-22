#include <iostream>

/*
	继承：": 来表示继承关系"
	1 当派生类对象被销毁时，C++ 会按照以下顺序进行析构：
	（1）派生类析构函数的调用
	（2）基类析构函数的调用
	2 在派生类构造函数调用父类构造函数时Cat(int age):Animal(age){} 必须一一对应
		2.1 当派生类没有显式构造函数，默认为Cat():Animal(){} 
	3 继承的内存布局
		在继承关系中，派生类对象的内存布局通常包含基类部分和派生类部分：
		基类部分：存储基类的成员变量。
		派生类部分：存储派生类的成员变量。
		如果存在虚函数，派生类对象还会包含一个指向虚函数表（vtable）的指针，用于支持多态。
		总结

	封装：	private只能由本类和friend友元类和函数访问
			protected只能本类和子类访问
			public大家都能访问包括类和函数内
*/

class Animal {
private:
	int age;
	std::string name;
public:
	Animal()
	{
		std::cout << "oioioi~~\n";
	}
	Animal(int age)
	{
		this->age = age;
	}
	virtual void shout()
	{
		std::cout << "oioioi~~\n";
	}
	virtual void eat() = 0;//纯虚函数，即抽象方法，派生类不行实现override
	int GetAge()
	{
		return age;
	}
};

class Cat :public Animal {
public:
	Cat():Animal(){} //调用父类构造函数，默认的
	Cat(int age):Animal(age){} //调用父类构造函数
	void shout() override {
		std::cout << "雪豹闭嘴\n";
	}
	void eat () override
	{
		std::cout << "雪豹吃屎\n";
	}
};


int main() {
	Animal* a = new Cat(6);
	a->shout();
	a->eat();
	std::cout << a->GetAge() << std::endl;
	
	return 0;
}