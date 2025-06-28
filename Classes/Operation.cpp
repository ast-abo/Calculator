#include "Operation.h"
#include <iostream>

Operation::Operation(float a, float b, int Index, char Op)
    : First(a), Second(b), Index(Index), Operator(Op)
{

}

float Operation::Evaluate()
{
    switch (Operator)
    {
    case '+':

        std::cout << "Adding: " << First << " + " << Second << std::endl;
        return First + Second;
        break;
    case '-':

        std::cout << "Subtracting: " << First << " - " << Second << std::endl;
        return First - Second;
        break;

    default:
        std::cout << "Invalid Operator";
        return 0.0f;
        break;
    }
}