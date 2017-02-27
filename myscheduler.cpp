//myschedule.cpp
/*Define all the functions in 'myschedule.h' here.*/
#include "myscheduler.h"
#include <thread>
#include <vector>

void MyScheduler::CreateThread(int arriving_time, int remaining_time, int priority, int tid) //Thread ID not Process ID
{
	Holder holde;
	//Function to Create Thread(s) and insert them in the student
	//defined data structure
}

bool MyScheduler::Dispatch()
{
	//Todo: Check and remove finished threads
	//Todo: Check if all the threads are finished; if so, return false
	switch(policy)
	{
		case FCFS:		//First Come First Serve

			break;
		case STRFwoP:	//Shortest Time Remaining First, without preemption

			break;
		case STRFwP:	//Shortest Time Remaining First, with preemption

			break;
		case PBS:		//Priority Based Scheduling, with preemption

			break;
		default :
			cout<<"Invalid policy!";
			throw 0;
	}
	return true;
}
