#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include "Operation.h"

std::vector<Operation> ParsedExpression;
std::vector<float> ExpressionNumberArray;

float ConnectNumsLeft(int StartIndex, std::string Expression, std::string Number)
{
    std::string NewNumber = Number;

    if (Expression[StartIndex - 1])
    {
        char NextChar = Expression[StartIndex - 1];
        NewNumber.insert(0, 1, NextChar);
        ConnectNumsLeft(StartIndex - 1, Expression, NewNumber);
    }
    else
    {
        return std::stoi(NewNumber);
    }

    return 0;
}

float ConnectNumsRight(int StartIndex, std::string Expression, std::string Number)
{
    std::string NewNumber = Number;

    if (Expression[StartIndex + 1])
    {
        char NextChar = Expression[StartIndex + 1];
        NewNumber.insert(NewNumber.length(), 1, NextChar);
        ConnectNumsRight(StartIndex + 1, Expression, NewNumber);
    }
    else
    {
        return std::stoi(NewNumber);
    }

    return 0;
}

void Evaluate()
{
    for (auto& Operation : ParsedExpression)
    {
        float test = Operation.Evaluate();

        std::cout << test;
    }
}

void OperatorCheck(char Operator, int Index, std::string Expression)
{
    switch (Operator)
    {
    case '+':

        ParsedExpression.push_back(Operation(ConnectNumsLeft(Index, Expression, ""), ConnectNumsRight(Index, Expression, ""), ParsedExpression.size() - 1, '+'));
        break;

    default:
        break;
    }
}

void ParseExpression(std::string Expression)
{
    int Index = 0;

    for (char Character : Expression)
    {
        OperatorCheck(Character, Index, Expression);
        Index++;
    }
}

void main()
{
    while (true)
    {
        std::string Expression;
        std::cout << "Enter Expression: ";
        std::cin >> Expression;

        ParseExpression(Expression);

        Evaluate();

        ParsedExpression.clear();
        Expression.clear();
        ExpressionNumberArray.clear();

        if (Expression != "exit")
        {
            continue;
        }
        break;
    }
}
