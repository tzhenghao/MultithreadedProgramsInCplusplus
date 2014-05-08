// Name: Zheng Hao Tan
// Email: tanzhao@umich.edu
// Date: May 8, 2014

// This is just a dummy class that I use to test my main.cpp with the thread
// constructor.

#ifndef BACKGROUNDTASK_H
#define BACKGROUNDTASK_H

#include <iostream>
using namespace std;

class backgroundTask {
	
	public:
		
		void doSomething() const {

			cout << "Do something!\n";
		}

		void doSomethingElse() const {

			cout << "Do something else!\n";
		}

		void operator() () const {
			
			doSomething();
			doSomethingElse();
		}
	
	private:
};

#endif
