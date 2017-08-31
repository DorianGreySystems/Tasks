#include "queue.h"

void Queue::Push(int number)
{
	std::lock_guard<std::mutex> guard(mutexQueue);
	numbers.push_front(number);
}

int Queue::Pop()
{
	std::lock_guard<std::mutex> guard(mutexQueue);
	int temp = -1;
	if(!numbers.empty())
	{
		temp = numbers.back();
		numbers.pop_back();	
	}
	return temp;
}

int Queue::Size() const
{
	return numbers.size();
}

Queue::Queue()
{

}

Queue::~Queue()
{

}