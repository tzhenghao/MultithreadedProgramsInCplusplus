// Zheng Hao Tan 
// Email: tanzhao@umich.edu
// Date: May 7, 2014

// Concurrency in Action Code Labs

#include <iostream>
#include <thread>
#include <cassert>
#include "backgroundTask.h"
#include "threadGuard.h"

using namespace std;

// Prototypes.
void hello();
void doLambda1();
void doLambda2();
void doSomething(int i);
void doSomethingInCurrentThread();
void oops();
void f();

struct func {
	
	int &i;

	func(int &i_):i(i_) {}
	
	void operator() () {

		for (unsigned j = 0; j < 1000000; ++j) {
			doSomething(i);
		}
	}
};

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
	
	cout << "Making another thread!\n";
	cout << "************************\n";

	f();

	cout << "Making another thread!\n";
	cout << "************************\n";

	// Call function oops, which makes another new thread.
	oops();
	
	cout << "Making another thread!\n";
	cout << "************************\n";

	cout << "Checking if it is joinable with an assert...\n";

	// Testing my understanding on whether a detached thread can be joined.
	thread temp(doSomethingInCurrentThread);
	temp.detach();
	assert(!temp.joinable());

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

void doSomething(int i) {

	cout << "You entered " << i <<  " into the doSomething function!\n";
}

void doSomethingInCurrentThread() {

	cout << "I'm doing something in this thread!\n";
}

// EFFECTS: Practice will detach and how threads are handled when/before the 
//			the function exits.
void oops() {

	int someLocalState = 0;
	func myFunc(someLocalState);
	thread funcThread(myFunc);
	// funcThread.detach();
	funcThread.join();
}

void f() {
	
	int someLocalState = 0;
	func myFunc(someLocalState);
	thread funcThread(myFunc);
	threadGuard g(funcThread);

	doSomethingInCurrentThread();
	
	funcThread.join();
}
