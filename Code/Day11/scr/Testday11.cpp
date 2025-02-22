#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	�������캯��������ͬ���Ͳ����Ĺ��캯��
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
	int& operator*()//��Ŀ��������ء�û�в���
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
	//��ΪĬ�����ɸ��ƹ��캯���Ǹ������г�Ա�����г�Ա��ָ��ʱ�ͻ���֡�ǳ���ơ�������Ҫ�Լ���ʽ��д

	Test t = 5;
	Test t1 = 6;
	Test t2{ 2 };
	cout << *t<<endl; //��Ŀ���������

	//vector ��
	/*
		1.����ͨ��{}��ʼ�������Զ��ж�Ϊ��ʼ���б���ù��캯�����δ���
		2.��δָ��Ĭ������ʱ��ÿpush_back׷��һ���ռ�+1�������¿ռ�Ȼ���ƣ��ͻᵼ���Ż����ⲻ�ϸ���
			��˿��ܳ����Ż����⣬��ָ����push_back���ں���׷�ӣ�����ԭ����+1�ռ䣬��1-2��4��8 ��������
			����ͨ��reserveԤ��׷�ӿռ���Ա����ο��ٿռ䣬push_back�����������Ԥ���ռ�
			�����Ϳ�����ȷ���ռ䣬���������캯�������Ѿ����ж���Ĺ�����
			��vector(string) v[3]��ʵ�Ѿ���3�������ռ��string��,size=3��
	*/
	vector<int> v({12,23,45,65,87,98,56,74,56,34,77,678,5747,7});
	//vector<vec> v1(3);��ʵ�Ѿ���3�������ռ��string��
	vector<vec> v1;
	v1.reserve(3);/*�����Ͳ����ȿ��ٿռ�ȵȴ����ݣ�����ȷ���ô�С�������������ʱ�ٷ���
					�������ڴ棺reserve() ֻ�����ڴ�ռ䣬�����ṹ���κζ���
					�ӳٶ����죺����Ĺ��챻�ӳٵ�ʵ�ʲ���Ԫ��ʱ
					������Ʒ�ֹ��ι������

					�������ڴ棺����ͨ��malloc�ȵȣ������ù��췽���ȳ�ʼ������
					new�Ļ��ͻṹ����󣬼����г�ʼ������
					
					ջ�ϵĶ����Զ����죬�Զ����г�ʼ������
					*/
	
	v1.push_back({ 1,2,3 });//������main�������￪��Ȼ���븴�Ƶ�
	
	v1.emplace_back(1,2,3);//�����ڽ������б��븴�Ƶ�׷�ӣ�����reserve��
							//�ô��Ǿ�λ�ø�ֵ������Ҫ���⿪�ٿռ���ø��ƹ��캯��
	v1.push_back({ 1,2,3 });//������main�������￪��Ȼ���븴�Ƶ�
	cout << v1.capacity()<<endl;
	
	

	return 0;
}