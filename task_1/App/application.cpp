#include "application.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <csignal>

#include "producer.h"
#include "consumer.h"
#include "queue.h"
#include "filemanager.h"

std::vector<std::thread*> globalConsumerThreads;

void Application::Run(int producersNumber,int consumersNumber,std::string dataFile)
{
	signal(SIGTERM, Application::ExitApp);
	monitor = new std::thread(&Application::MonitorQueue,this);
	filemanager = new Filemanager(dataFile);
    CreateProducers(producersNumber);
    CreateConsumers(consumersNumber);
	ChackQuit();
	JoinProducers();
	JoinConsumers();
}

void Application::CreateProducers(int producersNumber)
{
	producers = new Producer[producersNumber];
	for (int i = 0; i < producersNumber; ++i)
	{
		producers[i].Init(queue);
		std::thread *tp = new std::thread(&Producer::Run,&producers[i]);
		producerThreads.push_back(tp);
	}
}

void Application::CreateConsumers(int consumersNumber)
{
	consumers = new Consumer[consumersNumber];
	for (int i = 0; i < consumersNumber; ++i)
	{
		consumers[i].Init(queue,filemanager);
		std::thread *tp = new std::thread(&Consumer::Run,&consumers[i]);
		consumerThreads.push_back(tp);
		globalConsumerThreads.push_back(tp);
	}
}

void Application::JoinProducers()
{
	for(int i = 0;i < producerThreads.size();++i)
	{
		if(producerThreads[i] -> joinable())
		{
			producerThreads[i] -> join();
		}
	}
}

void Application::JoinConsumers()
{
	for(int i = 0;i < consumerThreads.size();++i)
	{
		if(consumerThreads[i] -> joinable())
		{
			consumerThreads[i] -> join();
		}
	}
}

void Application::MonitorQueue() const
{
	while(true)
	{
		std::this_thread::sleep_for (std::chrono::seconds(1));
		std::cout<< "Queue Size : "<< queue->Size() <<std::endl;
	}
}

void Application::ChackQuit()
{
    std::string input;
	while(true)
	{
	    std::getline(std::cin,input);
	    if(input == "Q" || input == "q")
	    {
	    	exit(SIGTERM);
	    }
	}
}

void Application::ExitApp(int signal)
{
    for(int i = 0;i < globalConsumerThreads.size();++i)
	{
		globalConsumerThreads[i]->join();
	}
	exit(signal);
}

Application::Application()
{
	queue = new Queue;
}

Application::~Application()
{
	if(producers != NULL)
	{
		delete[] producers;
		producers = NULL;
	}
	if(consumers != NULL)
	{
		delete[] consumers;
		consumers = NULL;
	}
	if(queue != NULL)
	{
		delete queue;
		queue = NULL;
	}
	if(filemanager != NULL)
	{
		delete filemanager;
		filemanager = NULL;
	}
	if(monitor -> joinable())
	{
		monitor -> join();
	}
}