
program: main.o application.o producer.o consumer.o queue.o filemanager.o
	g++ main.o application.o producer.o consumer.o queue.o filemanager.o -o program -std=c++11 -pthread 

main.o: main.cpp 
	g++ main.cpp -c -std=c++11 -pthread

application.o: application.h application.cpp
	g++ application.cpp -c -std=c++11 -pthread

producer.o: producer.cpp producer.h
	g++ producer.cpp -c -std=c++11 -pthread

consumer.o: consumer.cpp consumer.h
	g++ consumer.cpp -c -std=c++11 -pthread

queue.o: queue.cpp queue.h
	g++ queue.cpp -c -std=c++11 -pthread

filemanager.o: filemanager.cpp filemanager.h
	g++ filemanager.cpp -c -std=c++11 -pthread

.PHONY: clean
clean: clean_objects
	-rm -v program *.o data.text