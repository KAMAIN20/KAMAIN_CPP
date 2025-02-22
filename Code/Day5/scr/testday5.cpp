#include <iostream>

/*
	�̳У�": ����ʾ�̳й�ϵ"
	1 ���������������ʱ��C++ �ᰴ������˳�����������
	��1�����������������ĵ���
	��2���������������ĵ���
	2 �������๹�캯�����ø��๹�캯��ʱCat(int age):Animal(age){} ����һһ��Ӧ
		2.1 ��������û����ʽ���캯����Ĭ��ΪCat():Animal(){} 
	3 �̳е��ڴ沼��
		�ڼ̳й�ϵ�У������������ڴ沼��ͨ���������ಿ�ֺ������ಿ�֣�
		���ಿ�֣��洢����ĳ�Ա������
		�����ಿ�֣��洢������ĳ�Ա������
		��������麯������������󻹻����һ��ָ���麯����vtable����ָ�룬����֧�ֶ�̬��
		�ܽ�

	��װ��	privateֻ���ɱ����friend��Ԫ��ͺ�������
			protectedֻ�ܱ�����������
			public��Ҷ��ܷ��ʰ�����ͺ�����
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
	virtual void eat() = 0;//���麯���������󷽷��������಻��ʵ��override
	int GetAge()
	{
		return age;
	}
};

class Cat :public Animal {
public:
	Cat():Animal(){} //���ø��๹�캯����Ĭ�ϵ�
	Cat(int age):Animal(age){} //���ø��๹�캯��
	void shout() override {
		std::cout << "ѩ������\n";
	}
	void eat () override
	{
		std::cout << "ѩ����ʺ\n";
	}
};


int main() {
	Animal* a = new Cat(6);
	a->shout();
	a->eat();
	std::cout << a->GetAge() << std::endl;
	
	return 0;
}