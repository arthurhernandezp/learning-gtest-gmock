#include <map>

#include "IDatabaseConnection.hpp"
#include "Employee.hpp"
#include "EmployeeManager.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockDatabaseConnection : public IDatabaseConnection
{
    public:
        MockDatabaseConnection(std::string serverAddress);

        MOCK_METHOD(void,connect,());
        MOCK_METHOD(void,disconnect,());

        // virtual float getSalary(int id) const = 0;                  // SELECT * FROM employees WHERE id=...
        // virtual void updateSalary(int id, float newSalary) = 0;

        // virtual std::vector<Employee> getSalariesRange(float low) const = 0;    //just greater than low
        // virtual std::vector<Employee> getSalariesRange(float low, float high) const = 0;   

        MOCK_METHOD(float,getSalary,(int),(const));
        MOCK_METHOD(void,updateSalary,(int,float));
        MOCK_METHOD((std::vector<Employee>),getSalariesRange,(float),(const));
        MOCK_METHOD((std::vector<Employee>),getSalariesRange,(float,float),(const));
};

MockDatabaseConnection::MockDatabaseConnection(std::string serverAddress) : IDatabaseConnection(serverAddress)
{
}

TEST(TestEmployeeManager, TestConnection)
{
    MockDatabaseConnection dbConnection("dummyConnection");
    // Expect call tem que ser usado antes do local onde essas funções membros sao chamadas 
    // por exemplo no constructor e destructor de EmployeeManager
    EXPECT_CALL(dbConnection,connect());
    EXPECT_CALL(dbConnection,disconnect());
    EmployeeManager employeeManager(&dbConnection);
}