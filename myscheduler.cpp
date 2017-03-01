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
	
	/*switch(policy)
	{
		case FCFS://First Come First Serve
			

			if( holdee.threadInfo.size() == 0)
			{
				holdee.threadInfo.push_back(hold);
			}
			else if(holdee.threadInfo.front()->arriving_time <= arriving_time)
			{
				holdee.threadInfo.emplace(holdee.threadInfo.begin(),hold);
			}
			else
			{

			}
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
*/
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
	int pos= retminarr(holdee.threadInfo);
	
	CPUs[0] = holdee.threadInfo.at(pos);	
	while(CPUs[0]->remaining_time != 0)
	{
		holdee.threadInfo.erase(holdee.threadInfo.begin() + pos);
		CPUs[0]= holdee.threadInfo.at(retminarr(holdee.threadInfo));
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

int MyScheduler::retminarr(std::vector<ThreadDescriptorBlock*> threadInfo)
{
	int low,pos;
	//ThreadDescriptorBlock *holder = new ThreadDescriptorBlock;
	low= threadInfo.at(0)->arriving_time;
	pos=0;	
	//cout << threadInfo.size() << endl;
	for(int i=1; i < threadInfo.size(); i++)
	{	
		if(low >= threadInfo.at(i)->arriving_time)
		{
			low = threadInfo.at(i)->arriving_time;
			pos=i;
		
		}
		

	}
	return pos;

}


