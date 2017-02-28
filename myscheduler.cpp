//myschedule.cpp
/*Define all the functions in 'myschedule.h' here.*/
#include "myscheduler.h"

void MyScheduler::CreateThread(int arriving_time, int remaining_time, int priority, int tid) //Thread ID not Process ID
{	
	//Function to Create Thread(s) and insert them in the student
	//defined data structure
	ThreadDescriptorBlock *hold = new ThreadDescriptorBlock;
	hold->tid= tid;
	hold->remaining_time=remaining_time;
	hold->arriving_time= arriving_time;
	hold->priority = priority;

	holdee.threadInfo.push_back(hold);
	
}

bool MyScheduler::Dispatch()
{
	//Todo: Check and remove finished threads
	//Todo: Check if all the threads are finished; if so, return false
	switch(policy)
	{
		case FCFS://First Come First Serve
			return FCFS_fun();
			break;
		case STRFwoP:	//Shortest Time Remaining First, without preemption
			return STRFwoP_fun();
			break;
		case STRFwP:	//Shortest Time Remaining First, with preemption
			return STRFwP_fun();
			break;
		case PBS:		//Priority Based Scheduling, with preemption
			return PBS_fun();
			break;
		default :
			cout<<"Invalid policy!";
			throw 0;
	}
	return true;
}

bool MyScheduler::FCFS_fun()
{
	
	for(int i=0; i< holdee.threadInfo.size(); i++)
	{
				
		//CPUs[i]->tid = holdee.threadInfo.front().tid;
		//CPUs[i]->remaining_time = holdee.threadInfo.front().remaining_time;
		//CPUs[i]->arriving_time = holdee.threadInfo.front().arriving_time;
		//CPUs[i]->priority = holdee.threadInfo.front().priority;
		CPUs[i] = holdee.threadInfo.front();	
		holdee.threadInfo.erase(holdee.threadInfo.begin());

	}
	return true;

}


bool MyScheduler::STRFwoP_fun()
{

	return false;

}

bool MyScheduler::STRFwP_fun()
{

	return false;

}

bool MyScheduler::PBS_fun()
{

return false;

}
