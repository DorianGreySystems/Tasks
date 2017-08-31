#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <deque>
#include <mutex>

class Queue
{
public:
	
	void Push(int );

	int Pop();

	int Size() const;

	Queue();

	~Queue();

	Queue(const Queue&) = delete;

    Queue& operator=(const Queue&) = delete;

private:
	std::deque<int> numbers;
	std::mutex mutexQueue;
};

#endif