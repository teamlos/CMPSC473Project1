// Project1.cpp : Defines the entry point for the console application.
//

#include "myscheduler.h"

int main(int argc, char* argv[])
{
		cout << "Testbench via Alexandar Devic\n\n";

	cout << "\tUsing FCFS, no priority\n";
	MyScheduler ms = MyScheduler(FCFS, 3);
	ms.CreateThread(19, 1, 0, 00);
	ms.CreateThread(4, 2, 0, 01);
	ms.CreateThread(40, 4, 0, 02);
	ms.CreateThread(7, 8, 0, 03);
	ms.CreateThread(6, 16, 0, 04);
	ms.CreateThread(12, 32, 0, 05);
	ms.CreateThread(1, 64, 0, 06);
	ms.CreateThread(2, 128, 0, 07);

	ms.Go();
	/*Results should be:
	Thread ID : 0 Finishing Time : 1 CPU No. : 1
	Thread ID : 1 Finishing Time : 3 CPU No. : 1
	Thread ID : 2 Finishing Time : 7 CPU No. : 1
	Thread ID : 3 Finishing Time : 15 CPU No. : 1
	Thread ID : 4 Finishing Time : 31 CPU No. : 1
	Thread ID : 5 Finishing Time : 63 CPU No. : 1
	Thread ID : 6 Finishing Time : 127 CPU No. : 1
	Thread ID : 7 Finishing Time : 255 CPU No. : 1
	*/

	cout << "\tUsing STRFwoP, no priority\n";
	MyScheduler ms2 = MyScheduler(STRFwoP, 4);
	ms2.CreateThread(19, 1, 0, 00);
	ms2.CreateThread(4, 2, 0, 01);
	ms2.CreateThread(40, 4, 0, 02);
	ms2.CreateThread(7, 8, 0, 03);
	ms2.CreateThread(6, 16, 0, 04);
	ms2.CreateThread(12, 32, 0, 05);
	ms2.CreateThread(1, 64, 0, 06);
	ms2.CreateThread(2, 128, 0, 07);

	ms2.Go();



	return 0;
}

