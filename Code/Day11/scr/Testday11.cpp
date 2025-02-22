#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	拷贝构造函数：与类同类型参数的构造函数
	vector
*/

class Animal {
public:
	int* age;
	Animal(int* age) :age(age) {}
};

class Test{
public:
	int x;
	Test(const int& x):x(x){}
	int& operator*()//单目运算符重载。没有参数
	{
		return this->x;
	}
};

class vec {
public:
	int x, y, z;
	vec(int x,int y,int z): x(x),y(y),z(z)
	{
		cout << "the Memory has alloted" << endl;
	}
	vec()
	{ cout << "the Memory has alloted" << endl; }
	vec(const vec& other):x(other.x),y(other.y),z(other.z)
	{
		cout << "the object has been copied" << endl;
	}
	~vec()
	{
		cout << "the Memory has released" << endl;
	}

};

int main() 
             {
	int test = 1;
	Animal a1 = &test;
	Animal a2 = a1;

	cout << a1.age << " " << &a1 << endl;
	cout << a2.age << " " << &a2 << endl;
	//因为默认生成复制构造函数是复制所有成员，当有成员是指针时就会出现“浅复制”，所有要自己显式编写

	Test t = 5;
	Test t1 = 6;
	Test t2{ 2 };
	cout << *t<<endl; //单目运算符重载

	//vector ：
	/*
		1.可以通过{}初始化，会自动判断为初始化列表调用构造函数依次存入
		2.当未指定默认容量时，每push_back追加一个空间+1，开辟新空间然后复制，就会导致优化问题不断复制
			因此可能出现优化问题，但指定后push_back是在后面追加，会在原基础+1空间，以1-2，4，8 两倍增长
			所以通过reserve预留追加空间可以避免多次开辟空间，push_back会先填完这个预留空间
			这样就可以先确定空间，而不用像构造函数那样已经进行对象的构造了
			如vector(string) v[3]其实已经开3个连续空间的string了,size=3了
	*/
	vector<int> v({12,23,45,65,87,98,56,74,56,34,77,678,5747,7});
	//vector<vec> v1(3);其实已经开3个连续空间的string了
	vector<vec> v1;
	v1.reserve(3);/*这样就不会先开辟空间等等存数据，而是确定好大小，等真正存入后时再分配
					仅分配内存：reserve() 只分配内存空间，但不会构造任何对象。
					延迟对象构造：对象的构造被延迟到实际插入元素时
					特殊机制防止多次构造对象

					仅分配内存：就是通过malloc等等，不调用构造方法等初始化工作
					new的话就会构造对象，即进行初始化工作
					
					栈上的对象自动构造，自动进行初始化工作
					*/
	
	v1.push_back({ 1,2,3 });//这是在main方法这里开辟然后传入复制的
	
	v1.emplace_back(1,2,3);//这是在将参数列表传入复制的追加，搭配reserve用
							//好处是就位置赋值，不需要额外开辟空间调用复制构造函数
	v1.push_back({ 1,2,3 });//这是在main方法这里开辟然后传入复制的
	cout << v1.capacity()<<endl;
	
	

	return 0;
}