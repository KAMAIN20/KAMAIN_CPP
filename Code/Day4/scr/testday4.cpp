#include <iostream>
#include <string> // ��ʽ�������ô��������
/*
	class:���캯���ڶ���ʵ��ʱ�Զ����õĺ��� Cat cat;
	class:���������ڶ�������ʱ�Զ����õĺ��� delete[] cat
		delete cat3; //�������ٵ���new�����ڶ��еĶ���
		delete[] cat;//�������ٶ��е����飬�ᵼ���ظ����������ռ䣬������������Ĳ��ϵ���
		��ջ�еĶ����ڸ���������������������Զ�����
		�ڶ��еĶ���ֻ��ͨ���ֶ�delete���ٻ�������ָ��
		�������������ֶ�����
		
		�ر�˵����������������д��ں���ǩ��һ��ʱ���������Լ̳����˵Ļ����ص��������С����ء�
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
		name = "������";
	}*/
	//Cat() = delete; ɾ��Ĭ�Ϲ��캯��
	Cat() {
		printf("���ǹ��캯��\n");
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
		printf("���ǵ�%d��������\n",count);
	}
};

int Cat::count = 0;

int main() {
	//��ջ��ʵ�����󣬹��캯��ͬ������� 
	{
		//Cat cat;���������ֱ����ջ��ʵ�������޲ι��캯������Ҫд����
		Cat CatTest;
		Cat cat1(3, "������");//�вι��캯����Ҫ����
		std::cout << cat1.GetAge() << " " << cat1.GetName() << std::endl;
	}
	//�ڶ���ʵ�����󣨶�̬�ڴ���䣩
	{
		Cat* cat2 = new Cat(2, "������");
		std::cout << cat2->GetAge() << " " << cat2->GetName() << std::endl;
	}
	//�ṹ����ͬ���й��캯��
	{
		Dog dog;
	}
	//�������������ã���ջ���߶������ٶ��󶼿����Զ�������������
	{
		Cat* cat3 = new Cat(8, "������");
		std::cout << cat3->GetAge() << " " << cat3->GetName() << std::endl;
		delete cat3; //�������ٵ���new�����ڶ��еĶ���
		//delete[] cat;�ᵼ���ظ����������ռ䣬������������Ĳ��ϵ���
	}
	return 0;
}