#include "producer.h"

#include <iostream>
#include <random>
#include <thread>
#include <chrono>

#include "queue.h"

void Producer::Init(Queue* queueArg)
{
	this->queue = queueArg;
}

// Do main work of Producer
void Producer::Run()
{
	while(true)
    {
    	if(queue->Size() < 100)
    	{
    		std::this_thread::sleep_for (std::chrono::seconds(RandomNumber()));
		    queue -> Push(RandomNumber());
    	}
    	else
    	{
    		std::thread checkThread(&Producer::CheckQueue, this);

    		{
        		std::lock_guard<std::mutex> lk(mutexProducer);
       	   	    queueIsBig = true;
            }
            cv.notify_one();

            {
                std::unique_lock<std::mutex> lk(mutexProducer);
                cv.wait(lk, [this]{return queueIsReady;});
            }

    		checkThread.join();
    	}
    }   
}

// Check if queue is small (less than 80 ) 
// and notify main thread
void Producer::CheckQueue()
{
    std::unique_lock<std::mutex> lk(mutexProducer);
    cv.wait(lk, [this]{return queueIsBig;});
 
    while(queue->Size() < 80)
    {
        queueIsReady = true;
    }

    lk.unlock();
    cv.notify_one();
}

// Generate random integer
// number between [1,100]
int Producer::RandomNumber()
{
	std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 100); 
    return dist(mt);
}

Producer::Producer()
{
	queueIsBig = false;
    queueIsReady = false;
}

Producer::~Producer()
{
	
}