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
