#include <iostream>
#include <string>

#include <array>

/*
	auto�ؼ��� -- �����ʼ������ֵ�����Ƶ��ģ���Ȼ��֪���������ڴ�
	��̬���飺array -#include <array>

	��̬����array			��̬����vector
	1.������ջ��				1.�����ڶ���
	2.�߽���				2.�ɱ߳�


*/

auto func() -> char* //auto��������ȷ��
{
	return 0;
}

int main()
{
	const char* c = "dasd";
	std::string s = c;

	//array
	std::array<int, 5> arr = {1,2,3,4,5};//ģ��<���ͣ���С>
	arr[2] = 1;
	arr[5] = 5;//array�б߽���
	return 0;
}