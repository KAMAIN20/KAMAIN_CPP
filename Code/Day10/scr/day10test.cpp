#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
*	���������  	operator �����(other)
*	this: 
	��һ�����ص�ָ��������ɱ������Զ����ݸ�ÿ���Ǿ�̬��Ա������
	���������� ClassName* const����ָ��ǰ��ʵ����ָ�룬�����ǳ���ָ�루�����޸� this ��ֵ����
	MyClass::print(&obj);  // ��������ʽ���� obj �ĵ�ַ��Ϊ this ָ��
	���ú�����ֻ����������ôthis �� const class* const this

	smart pointer����ָ��
	unique_ptr��ͷ�ļ�#include <memory>
	�����ǣ�ͨ����װָ�룬Ȼ������������������ָ������ٽ����Զ�delete��Ӧ���ڴ�,ͬʱ�ڲ����Զ�new���캯��

	shared pointer����ָ��
	shared_ptr
	������������ָ��Ļ����Ͻ������ô������жϣ������ô�������0������ɾ��

	weak pointer��������/�����ã�ָ�� ��ֻ�����ں�shared_ptr���жϵģ����ܽ����ö���
*	weak_ptr
*	��ʹ�� std::shared_ptr ʱ������������������öԷ��� shared_ptr��
	�ᵼ�����ǵ����ü�����Զ��Ϊ�㣬�Ӷ��޷���ȷ�ͷ���Դ���γ��ڴ�й©��
	std::weak_ptr ���Դ�������ѭ�����á�
	weak_ptr �����Ӷ�������ü������������������۲�һ�������Ƿ���ڡ�

	���ƿ飺�ںͶ��������һ���������ڴ�ռ���
	std::shared_ptr �� std::weak_ptr �����ü�����Ϣ�洢��һ������Ŀ��ƿ��С�������ƿ�ͨ�������������ݣ�
	Strong Count��ǿ���ü���������¼��ǰ���󱻶��ٸ� std::shared_ptr ���С���ǿ���ü���Ϊ��ʱ������ᱻ���١�
	Weak Count�������ü���������¼��ǰ���󱻶��ٸ� std::weak_ptr ���С������ü������ڹ�����ƿ鱾����������ڡ�
	ָ������ָ�룺�洢ʵ�ʶ���ĵ�ַ��
	���ƿ���������������� std::shared_ptr �� std::weak_ptr ��ͬ����
	�����һ�� std::shared_ptr ������ʱ������ᱻ���٣������ƿ���Ȼ���ڣ�ֱ�����һ�� std::weak_ptr �����١�
	�����һ�� std::weak_ptr ������ʱ�����ƿ�Ҳ�ᱻ���١������ܹ�����weak_ptr.lock()�ж�ǿ���ô����Ƿ�Ϊ0��Ȼ�󷵻���Ч������Ч��shared_ptr��ַ����Ϊnullptr

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
	Cat& x = (cat = cat2);//�ײ㣺�������ʽ����=��ֵ���������أ����Զ����ɲ��������ض�������
				//�������ж��Ƿ��Ը�ֵ��Ȼ�󷵻ض�Ӧ����������cat��
	
	cout << cat.eatNum <<" "<< &cat << endl;
	cout << cat2.eatNum <<" "<< &cat2 << endl;
	cat2.eatNum = 1;
	cout << cat.eatNum <<" "<< &cat << endl;
	cout << cat2.eatNum <<" "<< &cat2 << endl;
	cout << x.eatNum <<" "<< &x << endl;

	//----------------------------------------------------------------------------------------
	
	unique_ptr<Cat> up(new Cat(12));//����ָ��
	unique_ptr<Cat> up2 = make_unique<Cat>(12);//����ָ��,����ȫ�����쳣���
	//����ָ�벻�ܸ�ֵ����Ϊ�ײ�Ĭ�����ɿ������캯���͸�ֵ���������غ��� = delete������

	shared_ptr<Cat> sp = make_shared<Cat>(23);//ֻҪ��һ������ָ�������ã��򲻻�����ɾ��
	shared_ptr<Cat> sp2 = sp;//�����Ϳ��Ը���

	weak_ptr<Cat> wp = sp2;

	sp = sp2 = nullptr;
	cout << wp.lock() << endl;

	return 0;
}

