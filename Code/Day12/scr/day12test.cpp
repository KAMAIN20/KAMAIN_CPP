#include <iostream>
#include <string>
#include <GLFW\glfw3.h> //<>在系统路径include找，找不到才在该编译单元cpp文件附近找，而""则相反
#include <FileName.h>
using namespace std;
/*
	使用库（静态链接）
	步骤1.在项目设置->c/c++ -> 常规 -> 添加包含路径（include路径） 
	-> 链接器 -> 常规添加库路径 ->在input输出 -> 添加库依赖lib文件
	动态链接只需要添加xxxdll.lib在库依赖项，然后将对应的.dll文件放在可执行文件exe所在的目录下

	
*/

int main() {
	int a = glfwInit();
	cout << "6" << endl;
	

	return 0;
}