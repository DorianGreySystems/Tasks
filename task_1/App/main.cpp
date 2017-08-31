#include <iostream>
#include "application.h"

// Validate input arguments to between 1 and 10
bool ValidateArgs(int producerNumber,int consumerNumber)
{
	if ( producerNumber < 1 || producerNumber > 10 ) 
	{
        std::cout << "Insert number of Produsers and Consumers ( between 1-10 )." << std::endl;
        return false;
    }
    else if ( consumerNumber  < 1 || consumerNumber > 10 )
    {
        std::cout << "Insert number of Produsers and Consumers ( between 1-10 )." << std::endl;
        return false;
    }
    else
    {
    	return true;
    }
}

int main(int argc, char const *argv[])
{
	if ( 3 != argc ) 
	{
        std::cout << "Number of argument must me 2 ,Produsers and Consumers number" << std::endl;
        return -1;
    }
    int producerNumber = std::atoi(argv[1]);
    int consumerNumber = std::atoi(argv[2]);
    std::cout << producerNumber << "  " << consumerNumber << std::endl;
    if ( !ValidateArgs(producerNumber, consumerNumber))
    {
        return -1;
    }
    std::cout<<"Insert Q or q  and [ENTER] ,to terminate program."<<std::endl;
	try 
	{
        Application app;
		app.Run(producerNumber,consumerNumber,"data.txt");
    }
    catch (std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }

	return 0;
} // main