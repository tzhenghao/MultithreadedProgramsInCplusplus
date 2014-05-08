// Zheng Hao Tan 
// Email: tanzhao@umich.edu
// Date: May 7, 2014

// Concurrency in Action Code Labs

#include <iostream>
#include <thread>
#include "backgroundTask.h"

using namespace std;

// Prototypes.
void hello();
void doLambda1();
void doLambda2();

int main () 
{
	// Make a separate thread with an initialization function hello.
	thread t(hello);
	t.join();
	
	cout << "Making another thread!\n";
	cout << "************************\n";

	// Making another thread to demonstrate its use.
	backgroundTask task;
	thread t2(task);
	t2.join();
	
	cout << "Making another thread!\n";
	cout << "************************\n";

	// Making another thread without using a named variable.	
	thread anotherThread((backgroundTask()));
	
	anotherThread.join();

	cout << "Making another thread!\n";
	cout << "************************\n";

	// Making another thread with the new uniform initialization syntax.
	thread anotherThread2{backgroundTask()};

	anotherThread2.join();
	
	cout << "Making another thread!\n";
	cout << "************************\n";
	
	// Making another thread with lambda expressions.
	thread lambdaThread([]() {
		doLambda1();
		doLambda2();
	});
	
	lambdaThread.join();

	cout << "Done!\n";
	
	return 0;
}

void hello() {

	cout << "Hello Concurrent World\n";
}

void doLambda1() {

	cout << "Called 1st lambda function!\n";
}

void doLambda2() {

	cout << "Called 2nd lambda function!\n";
}
