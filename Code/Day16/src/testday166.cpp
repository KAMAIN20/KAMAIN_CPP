#include <iostream>
#include <thread>

/*
	线程：#include <thread>


*/
static bool is_finish = false;
void do_work()
{
	using namespace std::literals::chrono_literals;
	for (int i = 0; !is_finish; i++)
	{
		std::cout << i << " ";
		std::this_thread::sleep_for(1s);//线程休眠
	}
	std::cout << std::endl;
}

int main()
{
	using std::cout;
	using std::endl;
	std::thread worker(do_work);//线程对象，传入一个函数指针
	std::cin.get();
	is_finish = true;
	worker.join();//wait,线程等待，等worker线程执行结束
	cout << "thread over" << endl;
	return 0;

}