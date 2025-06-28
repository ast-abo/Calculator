#include "Operation.h"
#include <iostream>

Operation::Operation(float Operand1, float Operand2, int ExpressionIndex, int ParseIndex,  char OperaterType)
    : Operand1(Operand1), Operand2(Operand2), ExpressionIndex(ExpressionIndex), Operator(OperaterType), ParseIndex(ParseIndex)
{

}

float Operation::Evaluate()
{
    switch (Operator)
    {
    case '+':

        std::cout << "Adding: " << Operand1 << " + " << Operand2 << std::endl;
        Result = Operand1 + Operand2;
        return Operand1 + Operand2;
        break;
    case '-':

        std::cout << "Subtracting: " << Operand1 << " - " << Operand2 << std::endl;
        Result = Operand1 - Operand2;
        return Operand1 - Operand2;
        break;
     case '*':

        std::cout << "Multiplying: " << Operand1 << " * " << Operand2 << std::endl;
        Result = Operand1 * Operand2;
        return Operand1 * Operand2;
        break;

    default:
        std::cout << "Invalid Operator";
        return 0.0f;
        break;
    }
}