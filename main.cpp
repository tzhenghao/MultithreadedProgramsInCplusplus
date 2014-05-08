// Zheng Hao Tan 
// Email: tanzhao@umich.edu
// Date: May 7, 2014

// Concurrency in Action Code Labs


#include <iostream>
#include <thread>
using namespace std;

// Prototypes.
void hello();

int main () 
{
	// Make a separate thread with an initialization function hello.
	thread t(hello);
	t.join();

	return 0;
}

void hello() {

	cout << "Hello Concurrent World\n";
}






