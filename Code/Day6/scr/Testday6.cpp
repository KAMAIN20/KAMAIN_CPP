#include <iostream>
#include <string>
using namespace std;

/*
	数组：
	栈中创建的数组在实例对象整个内存大小的一部分
	堆中则开辟空间，让对象存储该数组的地址，那么整个对象内存空间只会包含一个地址大小
	字符串：
		"字符串"，双引号括起来的是字符串，默认是const char [大小为实际字符个数加+'\0']的字符对象
		字符常量不能修改

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

	//string s = "HELLO" + "WORLD";//因为两个字符常量，不能进行链接
	string s = string("HELLO") + "WORLD"; //因为string类实现了 string s += "***"，因此只需要另一个为string类型
	bool contains = s.find("LL") != string::npos;//这样可以实现包含判断，string中没有contain()函数，
	//所以通过查找第一个出现的位置不等于“不存在的位置”实现
/*
	字符串字面量：
	字符串字面量（如 "asd"）是存储在只读存储区的，不能被修改。
	字符数组（如 char A[5]）是存储在可读写内存中（栈）的，可以被修改。
		char* A = "asd";
		A[1] = '1';//这是不可修改的
		
		char A[5] = "asd";
		A[1] = '1';
		char A[5] 声明了一个大小为5的字符数组。= "asd" 将字符串字面量 "asd" 的内容逐字节复制到数组 A 中。

		特别：
		char* name = "Bob"，在不同编译器是有问题的，因为在clang和GCC编译器中，char*是指向一个可修改的字符串指针
							但字符串字面量返回的是const char*，是一个指向不可修改的字符串。在MSVC中会帮你自动处理
							为const char* name = "Bob"，这是规范写法。不可以用char* name = "Bob"

		特殊字面量：每个字符占用字节不同，用于不同编码场景
		普通字符串		无			const char[]		ASCII/UTF-8
		UTF-8 字符串		u8			const char[]		UTF-8
		UTF-16 字符串	u			const char16_t[]	UTF-16
		UTF-32 字符串	U			const char32_t[]	UTF-32
		宽字符字符串		L			const wchar_t[]		平台依赖（UTF-16/UTF-32）
		原始字符串		R"(...)"	const char[]		原始内容（支持换行）
*/

	cout << endl;
	cout << endl;
	char A[5] = "as";
	cout << A << endl;
//----------------------------------------------------------------------------------------------------------
	using namespace std::string_literals;//标准库
	string s1 = "Hello"s + "World";//重载实现
	const char* B = "as"
		"da";//C和C++语言支持相邻字符串字面量的自动连接
	cout << B << endl;

	return 0;
}