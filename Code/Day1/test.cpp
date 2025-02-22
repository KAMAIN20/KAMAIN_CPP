#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void sort(vector<int> &vi)
{
	for (int i = 0; i < vi.size() - 2; i++)
	{
		for (int j = 0; j < vi.size() - i - 2; j++)
		{
			if (vi[j]>vi[j+1])
			{
				int temp = vi[j];
				vi[j] = vi[j + 1];
				vi[j + 1] = temp;
			}
		}
	}
}

int main(){
	int arr[10] = { 9,4,5,7,1,2,3,0,8,6 };
	vector<int> vi(10);
	for (int i = 0; i < vi.size() - 1; i++)
	{
		vi[i] = arr[i];
	}
	sort(vi);

	for (int i = 0; i < vi.size()-1; i++)
	{
		cout << vi[i]<<" ";
	}
}