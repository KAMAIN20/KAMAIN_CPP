#include <iostream>
#include <string>
#include <print>

//#define class struct
#define Yep 6 
/*
����#�Ķ���Ԥ����ָ���Ԥ����ʱ���� �������� �Լ� ���滻��
#define class struct ��仰��ʵ���ǽ�����classԤ�����滻Ϊstruct
#define Yep 6 ͬ��
	ply.x = Yep; Ԥ�����-->��Yep�滻Ϊ5
*/

class Player {
private:
	int m_level;//˽�л����Ե������淶 

public:
	int x;
	int y;
	int speed;

};
//struct��class�ĺ�������class�еĳ�Ա����private�ģ�struct����public����C++�нṹ��Ҳ���Զ��巽����

/*
	static �� extern �������ڱ��������ʱstatic��������ⲿ���ӣ�extern��Ὣ�俪���ⲿ����
-------------------------------------------------------------------------------------------
	����extern
	�ļ�1
		extern int a = 10;
		void add(int x, int y)
	�ļ�2
		void add(int x, int y)//��������
		extern int a;�������߱��������������������ӡ����ܽ����ⲿ�ļ��ķ��ʱ���������Ĭ���ǲ������ⲿ���ӵ�
		int main()
		{
			std::cout << a;
		}
-------------------------------------------------------------------------------------------
	����static
	�ļ�1
		static int a = 10;//ͬʱ�ı�������������ڣ���ջ�Ĵ���ھ�̬�������ұ���ˡ��ֲ���ֻ�ܽ����ڲ����ӡ�
		static void add(int x, int y)ʧȥ�ⲿ����Ȩ
	�ļ�2
		void add(int x, int y)//��������
		int main()
		{
			std::cout << a;����
		}
--------------------------------------------------------------------------------------------
��class��struct�е�static
	��̬������static���εĳ�Ա�������Ψһ�ģ���ͬ��ʵ�����õı�����
			һ��ĳ��ʵ���޸ĸñ�����ֵ��������ʵ�����ı䡣��̬������������
			ֻ����������е������ռ䡣����::������
			��̬�����������������������ⶨ���ʼ�����������ܷ���һ���ڴ�ռ䣬������ʵ������
			��Ȼ�����еĶ����ʼ���ᵼ��ÿ��ʵ�����������ڴ�ռ䶼�����һ�ξ�̬��Ա�Ŀռ�
	
	��̬��������javaһ��,��̬����û�취���ʷǾ�̬��Ա����̬��������ֱ�ӷ��ʷ�ʽ������::����
--------------------------------------------------------------------------------------------
	
*/
class Dog {
public:
	static int age;
	std::string name;
	static void shout() {
		std::cout << "ѩ������" << std::endl;
	}
};

struct Cat {
	static int age;
	std::string name;
	static void shout() {
		std::cout << age << std::endl;
		std::cout << "�����ױ���" << std::endl;
	}
};

int Cat::age; //��̬�����������������������ⶨ���ʼ�����������ܷ���һ���ڴ�ռ䣬������ʵ������
			  //��Ȼ�����еĶ����ʼ���ᵼ��ÿ��ʵ�����������ڴ�ռ䶼�����һ�ξ�̬��Ա�Ŀռ�

int add(int x, int y);
extern int a;
void increment();

/*
	ö���ࣺ��Ĭ��˳�����������������Ĭ��4���ֽڣ�������һϵ�е������������ǳ�����
	enum MyEnum : long int ���Խ����������ã���������������float��double�ȶ�����
	��Ϊö����ĳ�Ա�ǳ�������������еĶ���󣬺�static���ƣ�ͨ��class�������ռ���з���class::��Ա
	�Ͼ����е�ö���������౾���������κ����ʵ������˲���Ҫʵ���ഴ������Ŀռ�
*/
enum MyEnum
{
	A,B,C,D,E //Ĭ�ϵ���0-4 ��ֱ��ʹ�þ����£��磺if(B)
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





