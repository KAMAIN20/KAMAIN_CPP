#include <iostream>
#include <thread>

/*
	�̣߳�#include <thread>


*/
static bool is_finish = false;
void do_work()
{
	using namespace std::literals::chrono_literals;
	for (int i = 0; !is_finish; i++)
	{
		std::cout << i << " ";
		std::this_thread::sleep_for(1s);//�߳�����
	}
	std::cout << std::endl;
}

int main()
{
	using std::cout;
	using std::endl;
	std::thread worker(do_work);//�̶߳��󣬴���һ������ָ��
	std::cin.get();
	is_finish = true;
	worker.join();//wait,�̵߳ȴ�����worker�߳�ִ�н���
	cout << "thread over" << endl;
	return 0;

}