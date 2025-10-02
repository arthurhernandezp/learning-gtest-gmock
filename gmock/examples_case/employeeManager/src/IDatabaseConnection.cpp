#include "IDatabaseConnection.hpp"
#include <iostream>

IDatabaseConnection::IDatabaseConnection(std::string serverAddress)  : mServerAddress{serverAddress}
{
}

void IDatabaseConnection::connect()
{
    std::cout << "Connecting to database server " << mServerAddress << '\n';
    //initialize real DB connection
}

void IDatabaseConnection::disconnect()
{
    std::cout << "Disconnecting from database server " << mServerAddress << '\n';
    //close the real DB connection
}
