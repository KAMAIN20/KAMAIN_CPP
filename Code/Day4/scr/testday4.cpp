#include <iostream>
#include <string> // 显式包含，让代码更清晰
/*
	class:构造函数在对象实例时自动调用的函数 Cat cat;
	class:析构函数在对象销毁时自动调用的函数 delete[] cat
		delete cat3; //正常销毁单个new出来在堆中的对象
		delete[] cat;//用于销毁堆中的数组，会导致重复销毁连续空间，造成析构函数的不断调用
		在栈中的对象：在根据在作用域的生命周期自动销毁
		在堆中的对象：只能通过手动delete销毁或者智能指针
		析构函数可以手动调用
		
		特别说明：基类和派生类中存在函数签名一致时，派生类会对继承下了的基类重叠函数进行“隐藏”
		const class A {
		public:
			void est() { cout << "this's A" << endl; };
		};

		class B : public A {
		public:
			void est() { cout << "this's B"<<endl; };
		};
*/

struct Dog {
	int age;
	Dog() :age(10)
	{
		printf("%d \n", age);
	}

};

class Cat {
private:
	int age;
	std::string name;
	static int count;
public:
	/*
	Cat() {
		age = 1;
		name = "哈吉米";
	}*/
	//Cat() = delete; 删除默认构造函数
	Cat() {
		printf("这是构造函数\n");
	}
	Cat(int age, std::string name)
	{
		this->age = age;
		this->name = name;
	}
	int GetAge()
	{
		return age;
	}
	std::string GetName()
	{
		return name;
	}
	~Cat()
	{
		count++;
		printf("这是第%d析构函数\n",count);
	}
};

int Cat::count = 0;

int main() {
	//在栈中实例对象，构造函数同样会调用 
	{
		//Cat cat;这种情况是直接在栈中实例对象，无参构造函数不需要写括号
		Cat CatTest;
		Cat cat1(3, "哈吉米");//有参构造函数需要括号
		std::cout << cat1.GetAge() << " " << cat1.GetName() << std::endl;
	}
	//在堆中实例对象（动态内存分配）
	{
		Cat* cat2 = new Cat(2, "哈吉米");
		std::cout << cat2->GetAge() << " " << cat2->GetName() << std::endl;
	}
	//结构体中同样有构造函数
	{
		Dog dog;
	}
	//析构函数的运用，在栈或者堆中销毁对象都可以自动调用析构函数
	{
		Cat* cat3 = new Cat(8, "哈吉米");
		std::cout << cat3->GetAge() << " " << cat3->GetName() << std::endl;
		delete cat3; //正常销毁单个new出来在堆中的对象
		//delete[] cat;会导致重复销毁连续空间，造成析构函数的不断调用
	}
	return 0;
}