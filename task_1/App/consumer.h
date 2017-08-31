#ifndef _CONSUMER_H_
#define _CONSUMER_H_

#include <mutex>
#include <condition_variable>

class Queue;
class Filemanager;

class Consumer
{
public:

	void Init(Queue* ,Filemanager* );

	void Run();
	
	Consumer();

	~Consumer();

	Consumer(const Consumer&) = delete;

    Consumer& operator=(const Consumer&) = delete;

private:

	void CheckQueue();
	
	int RandomNumber();

private:
	Queue* queue;
	Filemanager* filemanager;
	std::mutex mutexConsumer;
	std::condition_variable cv;
    bool queueIsSmall;
    bool queueIsReady;
};

#endif // _CONSUMER_H_