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
	while(!holdee.threadInfo.empty())
	{	
		int pos= retminarr(holdee.threadInfo);
		int openCPU = openCpu();

		while(openCPU == -1)
		{
			openCPU = openCpu();
			if (openCPU == -1)
			{
				return true;
			}
		}
		CPUs[openCPU]=holdee.threadInfo.at(pos);
		holdee.threadInfo.erase(holdee.threadInfo.begin() + pos);
		while(CPUs[openCPU]->remaining_time != 0)
		{
			return true;
		}
		
	}
	for(int i =0; i< (signed)num_cpu;i++)
	{
		if( CPUs[i] != NULL)
		{
			return true;
		}	

	}

	return false;

}


bool MyScheduler::STRFwoP_fun()
{

	while(!holdee.threadInfo.empty())
	{	
		int pos= retminrem(holdee.threadInfo);
		int openCPU = openCpu();

		while(openCPU == -1)
		{
			openCPU = openCpu();
			if (openCPU == -1)
			{
				return true;
			}
		}
		CPUs[openCPU]=holdee.threadInfo.at(pos);
		holdee.threadInfo.erase(holdee.threadInfo.begin() + pos);
		while(CPUs[openCPU]->remaining_time != 0)
		{
			return true;
		}
		
	}
	for(int i =0; i< (signed)num_cpu;i++)
	{
		if( CPUs[i] != NULL)
		{
			return true;
		}	

	}

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
	low= threadInfo.at(0)->arriving_time;
	pos=0;	
	for(int i=1; i < (signed)threadInfo.size(); i++)
	{	
		if(low >= threadInfo.at(i)->arriving_time)
		{
			low = threadInfo.at(i)->arriving_time;
			pos=i;
		
		}
		

	}
	return pos;

}

int MyScheduler::retminrem(std::vector<ThreadDescriptorBlock*> threadInfo)
{
	int low,pos;
	low= threadInfo.at(0)->remaining_time;
	pos=0;	
	for(int i=1; i < (signed)threadInfo.size(); i++)
	{	
		if(low >= threadInfo.at(i)->remaining_time)
		{
			low = threadInfo.at(i)->remaining_time;
			pos=i;
		
		}
		

	}
	return pos;

}

int MyScheduler::openCpu()
{
	int open;
	for(int i=0; i < (signed)num_cpu; i++)
	{
		if(CPUs[i] == NULL)
		{
			return i;
		}
		else
		{
			open = -1;
		}
	}

	return open;
}

