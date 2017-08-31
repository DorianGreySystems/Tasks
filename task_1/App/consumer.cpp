#include "consumer.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <random>

#include "queue.h"
#include "filemanager.h"

void Consumer::Init(Queue* queueArg,Filemanager* filemanagerArg)
{
	queue = queueArg;
	filemanager = filemanagerArg;
}

// Do main work of consumer
void Consumer::Run()
{
    int number = -1;
    while(true)
    {   
        if(queue->Size() != 0 )
        {
            number = queue->Pop();
            std::this_thread::sleep_for(std::chrono::seconds(RandomNumber()));
            if(number !=-1)
            {
                filemanager->WriteNumber(number);
            }
        }
        else
        {
            std::thread checkThread(&Consumer::CheckQueue, this);

            {
                std::lock_guard<std::mutex> lk(mutexConsumer);
                queueIsSmall = true;
            }
            cv.notify_one();

            {
                std::unique_lock<std::mutex> lk(mutexConsumer);
                cv.wait(lk, [this]{return queueIsReady;});
            }

            checkThread.join();
        }
    } 
}

// Check if queue is not empty
void Consumer::CheckQueue()
{
    std::unique_lock<std::mutex> lk(mutexConsumer);
    cv.wait(lk, [this]{return queueIsSmall;});
 
    while(queue->Size() > 0)
    {
        queueIsReady = true;
    }

    lk.unlock();
    cv.notify_one();
}

int Consumer::RandomNumber()
{
	std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    return dist(mt);
}

Consumer::Consumer()
{
    queueIsSmall = false;
    queueIsReady = false;
}

Consumer::~Consumer()
{
    
}