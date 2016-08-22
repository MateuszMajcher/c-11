#include <iostream>
#include <thread>

void call_from_thread() {
	std::cout<<"Hello world"<<std::endl;
}

int main() {
	std::thread t1(call_from_thread);
	t1.join();
}
