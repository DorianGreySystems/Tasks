#ifndef _PRODUCER_H_
#define _PRODUCER_H_

#include <mutex>
#include <condition_variable>

class Queue;

class Producer
{
public:

	void Run();
	
	void Init(Queue* );
	
	Producer();

	~Producer();

	Producer(const Producer&) = delete;

    Producer& operator=(const Producer&) = delete;

private:

	void CheckQueue();

	int RandomNumber();

private:
	Queue* queue;
	std::mutex mutexProducer;
    std::condition_variable cv;
    std::string data;
    bool queueIsBig;
    bool queueIsReady;
};

#endif