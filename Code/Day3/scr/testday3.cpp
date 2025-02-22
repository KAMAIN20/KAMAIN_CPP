#include <iostream>
#include <string>
#include <print>

//#define class struct
#define Yep 6 
/*
带有#的都是预处理指令，在预处理时进行 “包含” 以及 “替换”
#define class struct 这句话其实就是将所有class预处理替换为struct
#define Yep 6 同理
	ply.x = Yep; 预处理后-->将Yep替换为5
*/

class Player {
private:
	int m_level;//私有化属性的命名规范 

public:
	int x;
	int y;
	int speed;

};
//struct与class的核心区别：class中的成员都是private的，struct则是public。在C++中结构体也可以定义方法。

/*
	static 与 extern 核心在于编译后链接时static不会进行外部链接，extern则会将其开启外部链接
-------------------------------------------------------------------------------------------
	例：extern
	文件1
		extern int a = 10;
		void add(int x, int y)
	文件2
		void add(int x, int y)//正常链接
		extern int a;声明告诉编译器后链接器进行链接。就能进行外部文件的访问变量。变量默认是不进行外部链接的
		int main()
		{
			std::cout << a;
		}
-------------------------------------------------------------------------------------------
	例：static
	文件1
		static int a = 10;//同时改变变量的生命周期，从栈改存放在静态区，并且变成了“局部”只能进行内部链接。
		static void add(int x, int y)失去外部链接权
	文件2
		void add(int x, int y)//不会链接
		int main()
		{
			std::cout << a;报错
		}
--------------------------------------------------------------------------------------------
在class和struct中的static
	静态变量：static修饰的成员变量变成唯一的，不同的实例共用的变量，
			一旦某个实例修改该变量的值，则所有实例均改变。静态变量不属于类
			只是在这个类中的命名空间。类名::变量名
			静态变量必须是类中声明，类外定义初始化，这样才能分配一个内存空间，让其他实例共享
			不然在类中的定义初始化会导致每次实例对象分配的内存空间都会分配一次静态成员的空间
	
	静态方法：和java一样,静态方法没办法访问非静态成员，静态方法可以直接访问方式是类名::方法
--------------------------------------------------------------------------------------------
	
*/
class Dog {
public:
	static int age;
	std::string name;
	static void shout() {
		std::cout << "雪豹闭嘴" << std::endl;
	}
};

struct Cat {
	static int age;
	std::string name;
	static void shout() {
		std::cout << age << std::endl;
		std::cout << "哈吉米闭嘴" << std::endl;
	}
};

int Cat::age; //静态变量必须是类中声明，类外定义初始化，这样才能分配一个内存空间，让其他实例共享
			  //不然在类中的定义初始化会导致每次实例对象分配的内存空间都会分配一次静态成员的空间

int add(int x, int y);
extern int a;
void increment();

/*
	枚举类：按默认顺序递增，必须是整数默认4个字节，本质是一系列的整数集，且是常数；
	enum MyEnum : long int 可以进行类型设置，但必须是整数，float、double等都不行
	因为枚举类的成员是常数，因此在类中的定义后，和static类似，通过class的命名空间进行访问class::成员
	毕竟类中的枚举类属于类本身，不属于任何类的实例，因此不需要实例类创建额外的空间
*/
enum MyEnum
{
	A,B,C,D,E //默认递增0-4 ，直接使用就完事，如：if(B)
};

int main()
{
	int testnum = 1;
	if (testnum == B)
	{
		printf("this is enum's implement");
	}
	{
		Player ply;
		ply.x = Yep;
		std::cout << a << std::endl;
		std::cout << add(1, 5) << std::endl;
		increment();
		increment();
		increment();
		increment();
		increment();
		increment();
		static int xu = 10;
		{
			int xu = 5;
			std::cout << "-----------------------" << std::endl;
			std::cout << xu << std::endl;
		}
	}
	Cat c1;
	Cat::age = 10;
	printf("%d\n", c1.age);
	Cat::shout();
}
void increment()
{
	static int xt = 10;
	std::cout << xt++ << std::endl;
}





