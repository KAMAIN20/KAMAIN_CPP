#include <iostream>
#include <string>
#include <tuple>
#include <memory>
/*
	ģ��templates: ֻ���ڵ���ʱ�Ż�����������ɺ��������һֱû����������������ɺ��� ��

	��ջ������������ʱϵͳ�����һ��ռ䣬�Ѻ�ջ�������棬���Ĵ����洢�Ÿ�ջ��ָ�루ָ��ջ�������ջ�Ƿǳ���Ķ�λ 
		�������������������г�ջ
		��ջ���䣬ֻ��Ҫ�ƶ�ָ����ַ->С��ַ���У�ֻ��Ҫһ������ָ��������
		�ڶѷ��䣬�����ά��һ���������б���new���ٿռ䣬���ȼ�顰�����б�ȷ����û���㹻���пռ䣬���򷵻�ָ�롣�Ƚ���

	��:�������ı��滻���ñ������Լ��������� #define�궨��
	����һ��ǿ��ı�̹��ߣ��������ڴ��븴�á���������������Ż���
	Ȼ��������ʹ����Ҫ��������Ϊ�����ĺ궨����ܵ��´�������ά���͵��ԡ�
	���ִ�����У���������ṩ�˸���ȫ�����������������������������ģ�塢װ�����ȣ�����Щ����ͨ�����ʺ����ڸ��ӵĴ������ɺͳ���
	���ģ�����һ�����assess
	
	��ָ������жϱ���
	#define LOG(x) cout<<x<<endl;
	LOG("Test");//����������cout<<"Test"s<<endl

	//��;��ͨ��#ifdef #else #endif ʵ��Debug��Release�汾������
	����Ŀ��������->c/c++->Ԥ����������Ԥ�������и��ݰ汾���ö��壬����Ԥ�������ݰ汾���㶨�嶨��汾�ĺ꣬Ȼ����ݺ��ж�ʵ��
	���� ��ĿԤ�������ú�ΪPR_*****=1/0����#define PR_***** 1/0����Ȼ����#if PR_***** == 1 / 0
	���Է�б��\��������
*/
#ifdef PR_DEBUG


template <typename T>//typename/class ��������
void Print(T Value)
{
	std::cout << Value << std::endl;
}

template <int N,class T>//����ģ��ֵ������
class Array//ģ����
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
	
	Print("@#$");//��ʽ�Ƶ��ж�
	Print<std::string>("@#$");//��ʽ�ж�
	Print(34);
	Print(.4f/64);

	Array<5,int> arr;
	arr.Print();

	LOG(2)

	return 0;
}
#elif defined(PR_RELEASE)//����궨��release�汾�ĺ�
#define Nothing
#endif // PR_DEBUG