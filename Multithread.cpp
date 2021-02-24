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
			PlaySound("Data\\Background.wav", NULL,SND_SYNC);
		});
	
	Sleep(1000);
	t1.detach();
	cout<<"Play 2"<<endl;
	thread t2([]()
		{
			PlaySound("Data\\Music.wav", NULL,SND_SYNC);
		});
	
	t2.join();
}							


