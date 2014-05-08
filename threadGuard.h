// Zheng Hao Tan 
// Email: tanzhao@umich.edu
// Date: May 8, 2014

#ifndef THREADGUARD_H
#define THREADGUARD_H

#include <iostream>
#include <thread>
using namespace std;

// This class demonstrates how we can check and join the thread only when it is 
// done executing its stuff.

class threadGuard {

	public:
	
		explicit threadGuard(thread& t_) : t(t_) {}

		~threadGuard() {

			if (t.joinable()) {
				t.join();
			}
		}
		
		threadGuard(threadGuard const &)= delete;
		threadGuard& operator=(threadGuard const &)=delete;

	private:		
		thread &t;
};

#endif
