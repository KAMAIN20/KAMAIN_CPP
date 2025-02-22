#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
*	运算符重载  	operator 运算符(other)
*	this: 
	是一个隐藏的指针参数，由编译器自动传递给每个非静态成员函数。
	它的类型是 ClassName* const，即指向当前类实例的指针，并且是常量指针（不能修改 this 的值）。
	MyClass::print(&obj);  // 编译器隐式传递 obj 的地址作为 this 指针
	若该函数是只读函数。那么this 是 const class* const this

	smart pointer智能指针
	unique_ptr在头文件#include <memory>
	本质是：通过包装指针，然后利用析构函数随着指针的销毁进行自动delete对应堆内存,同时内部有自动new构造函数

	shared pointer共享指针
	shared_ptr
	本质是在智能指针的基础上进行引用次数的判断，当引用次数等于0则析构删除

	weak pointer（弱引用/软引用）指针 ：只能用于和shared_ptr做判断的，不能解引用对象
*	weak_ptr
*	当使用 std::shared_ptr 时，如果两个对象互相引用对方的 shared_ptr，
	会导致它们的引用计数永远不为零，从而无法正确释放资源，形成内存泄漏。
	std::weak_ptr 可以打破这种循环引用。
	weak_ptr 不增加对象的引用计数，但它可以用来观察一个对象是否存在。

	控制块：在和对象分配在一块连续的内存空间中
	std::shared_ptr 和 std::weak_ptr 的引用计数信息存储在一个共享的控制块中。这个控制块通常包含以下内容：
	Strong Count（强引用计数）：记录当前对象被多少个 std::shared_ptr 持有。当强引用计数为零时，对象会被销毁。
	Weak Count（弱引用计数）：记录当前对象被多少个 std::weak_ptr 持有。弱引用计数用于管理控制块本身的生命周期。
	指向对象的指针：存储实际对象的地址。
	控制块的生命周期由所有 std::shared_ptr 和 std::weak_ptr 共同管理：
	当最后一个 std::shared_ptr 被销毁时，对象会被销毁，但控制块仍然存在，直到最后一个 std::weak_ptr 被销毁。
	当最后一个 std::weak_ptr 被销毁时，控制块也会被销毁。这样能够根据weak_ptr.lock()判断强引用次数是否为0，然后返回有效或者无效的shared_ptr地址否则为nullptr

*/

class Animal {
public:
	int eatNum;
public:
	Animal(int eatNum) :eatNum(eatNum) {}
	int AddFood(int other)
	{
		
		this->eatNum;
		return eatNum + other;
	}
	int operator+(Animal other)
	{
		return AddFood(other.eatNum);
	}
};

class Cat : public Animal{
public:
	Cat(int eatNum):Animal(eatNum){}
};

class Dog :public Animal {
public:
	Dog(int eatNum) :Animal(eatNum) {}
};

int main()
{
	Cat cat = 94;
	Dog dog = 30;
	int sum = cat + dog;
	cout << sum << endl;
	Animal* a = new Cat(13);
	cout << a->eatNum << endl;
	Cat cat2 = 34;
	cout << cat.eatNum << " " << &cat << endl;
	cout << cat2.eatNum << " " << &cat2 << endl;
	Cat& x = (cat = cat2);//底层：如果不显式生成=赋值操作符重载，则自动生成操作并返回对象引用
				//步骤是判断是否自赋值，然后返回对应对象引用是cat的
	
	cout << cat.eatNum <<" "<< &cat << endl;
	cout << cat2.eatNum <<" "<< &cat2 << endl;
	cat2.eatNum = 1;
	cout << cat.eatNum <<" "<< &cat << endl;
	cout << cat2.eatNum <<" "<< &cat2 << endl;
	cout << x.eatNum <<" "<< &x << endl;

	//----------------------------------------------------------------------------------------
	
	unique_ptr<Cat> up(new Cat(12));//智能指针
	unique_ptr<Cat> up2 = make_unique<Cat>(12);//智能指针,更安全，有异常检查
	//智能指针不能赋值，因为底层默认生成拷贝构造函数和赋值操作符重载函数 = delete不能用

	shared_ptr<Cat> sp = make_shared<Cat>(23);//只要有一个共享指针在引用，则不会析构删除
	shared_ptr<Cat> sp2 = sp;//这样就可以复制

	weak_ptr<Cat> wp = sp2;

	sp = sp2 = nullptr;
	cout << wp.lock() << endl;

	return 0;
}

