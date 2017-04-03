/*
 * This is olraced, the offline race detector.
 * The input set (olraced_[tid].input) generated by zperf are
 * sent here for analyze.
 *
 * the backend is fasttrack, taken from txgo
 *
 * Nov 2015 Tong Zhang <ztong@vt.edu>
 */

#include "fasttrack.h"

#include <vector>
#include <iostream>

using namespace std;

//test backend
#define TEST_BACKEND 0

void work()
{
	int total_tid=1;
	string line;
	vector<std::string> elements;
	ft_init();
	for(line;getline(cin,line);)
	{
		//split line
		string buf = "";
		for(int i=0;i<line.length();i++)
		{
			if(line[i]==' ')
			{
				if(buf!="")
					elements.push_back(buf);
				buf="";
			}else
			{
				buf = buf + line[i];
			}
		}
		if(buf!="")
		{
			elements.push_back(buf);
		}
#if 0
		cout<<"LINE:";
		while(elements.size())
		{
			string x = *(elements.begin());
			elements.pop_front();
			cout<<" "<<x;
		}
		elements.clear();
		cout<<endl;
#endif
		unsigned long long tsc = strtoll(elements[0].c_str(),NULL,10);
		int tid = atol(elements[1].c_str());
		void * addr;
		addr = (void*)strtoll(elements[3].c_str(),NULL,16);
		void * rip;
		if(elements.size()>4)
		{
			rip = (void*)strtoll(elements[4].c_str(),NULL,16);
		}else
		{
			rip = 0;
		}
		//cout<<tsc<<" "<<tid<<" "<<elements[2]<<" "<<hex<<addr<<dec<<endl;
		if(elements[2]=="pthread_create")
		{
			//TODO: add ip address
			ft_after_thread_create(total_tid,0);
			ft_after_thread_init(total_tid);

			total_tid++;
		}else if(elements[2]=="pthread_mutex_lock")
		{
			ft_after_lock(addr,tid);
		}else if(elements[2]=="pthread_mutex_unlock")
		{
			ft_before_unlock(addr,tid);
		}else if(elements[2]=="pthread_mutex_init")
		{
		}else if(elements[2]=="pthread_mutex_destroy")
		{
		}else if(elements[2]=="pthread_join")
		{
		}else if(elements[2]=="pthread_cond_signal")
		{
			ft_before_signal(addr,tid);
		}else if(elements[2]=="pthread_cond_broadcast")
		{
			ft_before_broadcast(addr,tid);
		}else if(elements[2]=="before_pthread_cond_wait")
		{
			void* addr2 = rip;//actually the second address
			ft_before_wait(addr,addr2,tid);
		}else if(elements[2]=="after_pthread_cond_wait")
		{
			void* addr2 = rip;//actually the second address
			ft_after_wait(addr,addr2,tid);
		}else if(elements[2]=="RMEM")
		{
			ft_read(addr,1,rip,tid);
		}else if(elements[2]=="WMEM")
		{
			ft_write(addr,1,rip,tid);
		}else if(elements[2]=="free")
		{
			ft_mem_free(addr);
		}else if(elements[2]=="malloc")
		{
			int size = (int)(0xEFFFFFFF & (unsigned long)rip);//actually this is size
			ft_mem_alloc(addr,size);
		}

		elements.clear();
	}
	ft_fini();
}

int main(int argc, char** argv)
{
#if TEST_BACKEND
	//init backend
	ft_init();

	int *lock;
	lock = (int*)0x123;
	int *sv;
	sv = (int*)0x6cbd50;

	void* rip;
	rip = (void*)0x0000000000400df6;

	ft_after_thread_create(2,1);
	ft_after_thread_init(2);
	ft_after_thread_create(3,1);
	ft_after_thread_init(3);

	ft_after_lock(lock,1);
	ft_write(sv, 1, rip, 1);
	ft_before_unlock(lock,1);

	ft_write(sv, 1, rip, 2);
	ft_write(sv, 1, rip, 3);

	ft_read(sv, 1, rip, 1);

	//report race
	ft_fini();
#else
	work();
#endif
	return 0;
}
