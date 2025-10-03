#include <map>
#include <stdexcept>
#include <iostream>
#include <vector>

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

        void someMemberErrorFunction()
        {
            std::cout << "Member method called" << '\n';
            throw std::runtime_error("Dummy error");
        }
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

TEST(TestEmployeeManager, TestUpdateSalary)
{
    MockDatabaseConnection dbConnection("dummyConnection");
    // Expect call tem que ser usado antes do local onde essas funções membros sao chamadas 
    // por exemplo no constructor e destructor de EmployeeManager
    EXPECT_CALL(dbConnection,connect());
    EXPECT_CALL(dbConnection,disconnect());

    // Faz a verificação se updateSalary foi chamado exatamente 1 vez usando os parametros 50 e 6000 
    // EXPECT_CALL(dbConnection,updateSalary(50,6000)).Times(1);
    // Faz a verificação se updateSalary foi chamado independente do parametro que está sendo usado
    EXPECT_CALL(dbConnection,updateSalary(testing::_,testing::_)).Times(testing::AtLeast(1));

    EmployeeManager employeeManager(&dbConnection);

    employeeManager.setSalary(50,6000);
}

TEST(TestEmployeeManager, TestGetSalary)
{
    const int employeeId = 50;
    const float salary = 6100.0;

    MockDatabaseConnection dbConnection("dummyConnection");

    EXPECT_CALL(dbConnection,connect());
    EXPECT_CALL(dbConnection,disconnect());
    EXPECT_CALL(dbConnection,getSalary(employeeId)).WillOnce(testing::Return(salary));

    EmployeeManager employeeManager(&dbConnection);

    float employeeSalary = employeeManager.getSalary(employeeId);

    ASSERT_EQ(salary,employeeSalary);
}

// Formas de dizer ao google mock o que irá acontecer ao chamar uma função mockada especifica 

//Usando exception
TEST(TestEmployeeManager, TestConnectionError)
{
    MockDatabaseConnection dbConnection("dummyConnection");

    EXPECT_CALL(dbConnection,connect()).WillOnce(testing::Throw(std::runtime_error("Dummy error")));

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection),std::runtime_error);
}

ACTION(myThrow)
{
    std::cout << "Throwing an error" << '\n';
    throw std::runtime_error("Dummy error");
}

//Usando ACTION
TEST(TestEmployeeManager, TestConnectionErrorAction)
{
    MockDatabaseConnection dbConnection("dummyConnection");
    
    EXPECT_CALL(dbConnection,connect()).WillOnce(myThrow());

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection),std::runtime_error);
}

void someFreeFunction()
{
    std::cout << "someFreeFunction" << '\n';
    throw std::runtime_error("Dummy error");
}

//Usando freefunction
TEST(TestEmployeeManager, TestConnectionErrorInvoke)
{
    MockDatabaseConnection dbConnection("dummyConnection");
    
    EXPECT_CALL(dbConnection,connect()).WillOnce(testing::Invoke(someFreeFunction));

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection),std::runtime_error);
}

// Usando lambda function
TEST(TestEmployeeManager, TestConnectionErrorLambdaInvoke)
{
    MockDatabaseConnection dbConnection("dummyConnection");
    
    EXPECT_CALL(dbConnection,connect()).WillOnce(testing::Invoke([]()
    {
        std::cout << "lambda function" << '\n';
        throw std::runtime_error("Dummy error");
    }));

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection),std::runtime_error);
}

// Usando member function
TEST(TestEmployeeManager, TestConnectionErrorWithMemberFunctionInvoke)
{
    MockDatabaseConnection dbConnection("dummyConnection");
    auto boundMethod = std::bind(&MockDatabaseConnection::someMemberErrorFunction,&dbConnection);
    EXPECT_CALL(dbConnection,connect()).WillOnce(testing::InvokeWithoutArgs(boundMethod));

    ASSERT_THROW(EmployeeManager employeeManager(&dbConnection),std::runtime_error);
}

// Usando member function
TEST(TestEmployeeManager, TestGetSalaryInRange)
{
    const int low = 5000, high = 8000;
    std::vector<Employee> returnedVector{   Employee{1,5600,"John"},
                                            Employee{2,7000,"Jane"},
                                            Employee{3,6600,"Alex"},};



    MockDatabaseConnection dbConnection("dummyConnection");
    EXPECT_CALL(dbConnection,connect());
    EXPECT_CALL(dbConnection,disconnect());
    EXPECT_CALL(dbConnection,getSalariesRange(low,high)).WillOnce(testing::Return(returnedVector));

    EmployeeManager employeeManager(&dbConnection);
    std::map <std::string,float> returnedMap = employeeManager.getSalariesBetweem(low,high);
    ASSERT_EQ(returnedMap.size(),3);
}