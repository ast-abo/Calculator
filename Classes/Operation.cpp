#include "Operation.h"
#include <iostream>

Operation::Operation(float a, float b, int Index, char Op)
    : First(a), Second(b), Index(Index), Operator(Op)
{

}

float Operation::Evaluate()
{
    std::cout << "Hello from MyClass!" << std::endl;
    switch (Operator)
    {
    case '+':
        return First + Second;
        break;
    case '-':

        return First - Second;
        break;

    default:
    std::cout << "Invalid Operator";
        break;
    }
}