#include <Windows.h>
 
#include <iostream>
int main(void) {

	int no_menu_bar_width = getSystemMetrics(SM_CXFULLSCREEN);
	int no_menu_bar__height = getSystemMetrics(SM_CYFULLSCREEN);
	std::cout << "no menu bar width:" << getSystemMetrics(SM_CXFULLSCREEN) << std::endl;
	std::cout << "no menu bar height:" << getSystemMetrics(SM_CYFULLSCREEN) << std::endl;

 
	getchar();
	return 0;
}