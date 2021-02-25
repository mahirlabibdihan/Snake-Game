#include <windows.h>
#include <thread>
#include <iostream>
#include <ctime>
using namespace std;

void play()
{
	PlaySound("Data\\Background.wav", NULL,SND_SYNC);
}
int main()						
{
	cout<<"Play 1"<<endl;
	thread t1([]()
		{
			PlaySound("Data\\Background.wav", NULL,SND_ASYNC);
		});
	// PlaySound("Data\\music.wav", NULL,SND_ASYNC);
	
	Sleep(1000);
	t1.join();
	cout<<"Play 2"<<endl;
	thread t2([]()
		{
			PlaySound("Data\\music.wav", NULL,SND_ASYNC);
		});
	
	Sleep(10000);
	t2.join();
}							


