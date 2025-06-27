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

    if (StartIndex > 0)
    {
        char NextChar = Expression[StartIndex - 1];
        NewNumber.insert(0, 1, NextChar);
        return ConnectNumsLeft(StartIndex - 1, Expression, NewNumber);
    }
    else
    {
        return std::stof(NewNumber);
    }
}

float ConnectNumsRight(int StartIndex, std::string Expression, std::string Number)
{
    std::string NewNumber = Number;

    if (StartIndex < Expression.length() - 1)
    {
        char NextChar = Expression[StartIndex + 1];
        NewNumber.insert(NewNumber.length(), 1, NextChar);
        return ConnectNumsRight(StartIndex + 1, Expression, NewNumber);
    }
    else
    {
        return std::stoi(NewNumber);
    }
}

void Evaluate()
{
    for (auto &Operation : ParsedExpression)
    {
        if (Operation.Index > 0)
        {
            Operation.First = ExpressionNumberArray[ExpressionNumberArray.size() - 1];
        }

        float Result = Operation.Evaluate();
        ExpressionNumberArray.push_back(Result);

        std::cout << Result << std::endl;
    }
}

void OperatorCheck(char Operator, int Index, std::string Expression)
{
    switch (Operator)
    {
    case '+':
        if (Index == 1)
        {
            ExpressionNumberArray.push_back(ConnectNumsLeft(Index, Expression, ""));
        }
        ExpressionNumberArray.push_back(ConnectNumsRight(Index, Expression, ""));

        ParsedExpression.push_back(Operation(ExpressionNumberArray[0], ExpressionNumberArray[1], Index, '+'));
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
