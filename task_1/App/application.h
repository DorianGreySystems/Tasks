#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <string>
#include <thread>
#include <vector>

class Producer;
class Consumer;
class Queue;
class Filemanager;

class Application
{
public:

	void Run(int ,int ,std::string );

	Application();

	~Application();

	Application(const Application&) = delete;

    Application& operator=(const Application&) = delete;

private:

	void CreateProducers(int );

	void CreateConsumers(int );

	void JoinProducers();

	void JoinConsumers();
	
	void MonitorQueue() const;

	void ChackQuit();

	static void ExitApp(int );

private:
	std::thread* monitor;
	Queue* queue;
	Producer* producers;
	Consumer* consumers;
	Filemanager* filemanager;
	std::vector<std::thread* > producerThreads;
	std::vector<std::thread* > consumerThreads;
};

#endif // _APPLICATION_H_