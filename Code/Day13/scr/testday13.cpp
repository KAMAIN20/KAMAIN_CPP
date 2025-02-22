#include <iostream>
#include <string>
#include <tuple>
#include <memory>
/*
	模板templates: 只有在调用时才会根据类型生成函数，如果一直没调用则根本不会生成函数 、

	堆栈：当程序运行时系统分配的一块空间，堆和栈都在里面，而寄存器存储着该栈的指针（指向栈顶）因此栈是非常快的定位 
		，而且作用域结束会进行出栈
		在栈分配，只需要移动指针大地址->小地址就行，只需要一条左右指令就能完成
		在堆分配，程序会维护一个“空闲列表”，new开辟空间，会先检查“空闲列表”确认有没有足够空闲空间，有则返回指针。比较慢

	宏:本质是文本替换，让编译器自己评定填入 #define宏定义
	宏是一种强大的编程工具，可以用于代码复用、条件编译和性能优化。
	然而，它的使用需要谨慎，因为不当的宏定义可能导致代码难以维护和调试。
	在现代编程中，许多语言提供了更安全、更灵活的替代方案（如内联函数、模板、装饰器等），这些工具通常更适合用于复杂的代码生成和抽象。
	宏比模板更快一点进行assess
	
	宏指令可以判断变量
	#define LOG(x) cout<<x<<endl;
	LOG("Test");//会正常填入cout<<"Test"s<<endl

	//用途：通过#ifdef #else #endif 实现Debug和Release版本隔开，
	在项目属性设置->c/c++->预处理器，在预处理器中根据版本设置定义，这样预处理会根据版本帮你定义定义版本的宏，然后根据宏判断实现
	或者 项目预处理设置宏为PR_*****=1/0（即#define PR_***** 1/0），然后用#if PR_***** == 1 / 0
	可以反斜杠\进行续航
*/
#ifdef PR_DEBUG


template <typename T>//typename/class 类型名称
void Print(T Value)
{
	std::cout << Value << std::endl;
}

template <int N,class T>//可以模板值和类型
class Array//模板类
{
	T value = N;
public:
	Array(){}
	Array(T value):value(value) {}
	void Print()
	{
		std::cout << value << std::endl;
	}
};

#define LOG(X) std::cout<<X<<std::endl;
int main()
{
	
	Print("@#$");//隐式推导判断
	Print<std::string>("@#$");//显式判断
	Print(34);
	Print(.4f/64);

	Array<5,int> arr;
	arr.Print();

	LOG(2)

	return 0;
}
#elif defined(PR_RELEASE)//如果宏定义release版本的宏
#define Nothing
#endif // PR_DEBUG