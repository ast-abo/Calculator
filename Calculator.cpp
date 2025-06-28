#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include "Operation.h"

std::vector<Operation> ParsedExpression;
std::vector<float> ExpressionNumberArray;
std::vector<float> ResultsArray;
bool IsFirstOperation = true;

float ConnectNumsLeft(int StartIndex, std::string Expression, std::string Number)
{
    std::string NewNumber = Number;

    if (StartIndex - 1 >= Expression.length())
    {
        return std::stoi(NewNumber);
    }

    if (!std::isdigit(Expression[StartIndex - 1]))
    {
        return std::stof(NewNumber);
    }

    char NextChar = Expression[StartIndex - 1];
    NewNumber.insert(0, 1, NextChar);
    return ConnectNumsLeft(StartIndex - 1, Expression, NewNumber);
}

float ConnectNumsRight(int StartIndex, std::string Expression, std::string Number)
{
    std::string NewNumber = Number;

    if (StartIndex + 1 >= Expression.length())
    {
        return std::stoi(NewNumber);
    }

    if (!std::isdigit(Expression[StartIndex + 1]))
    {
        return std::stof(NewNumber);
    }

    char NextChar = Expression[StartIndex + 1];
    NewNumber.insert(NewNumber.length(), 1, NextChar);
    return ConnectNumsRight(StartIndex + 1, Expression, NewNumber);
}

void Evaluate()
{
    for (auto &Operation : ParsedExpression)
    {
        if (ResultsArray.size() > 0)
        {
            Operation.First = ResultsArray[ResultsArray.size() - 1];
        }

        float Result = Operation.Evaluate();
        ResultsArray.push_back(Result);

        std::cout << Result << std::endl;
    }
}

void OperatorCheck(char Operator, int Index, std::string Expression)
{
    switch (Operator)
    {
    case '+':
        if (IsFirstOperation)
        {
            ExpressionNumberArray.push_back(ConnectNumsLeft(Index, Expression, ""));
            IsFirstOperation = false;
        }
        ExpressionNumberArray.push_back(ConnectNumsRight(Index, Expression, ""));

        ParsedExpression.push_back(Operation(ExpressionNumberArray[0], ExpressionNumberArray[1], Index, '+'));
        break;
    case '-':
        if (IsFirstOperation)
        {
            ExpressionNumberArray.push_back(ConnectNumsLeft(Index, Expression, ""));
            IsFirstOperation = false;
        }
        ExpressionNumberArray.push_back(ConnectNumsRight(Index, Expression, ""));
        // fix first parameter of subtraction
        ParsedExpression.push_back(Operation(ExpressionNumberArray[0], ExpressionNumberArray[ExpressionNumberArray.size() - 1], Index, '-'));
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

        if (Expression != "exit")
        {
            ParsedExpression.clear();
            Expression.clear();
            ExpressionNumberArray.clear();
            ResultsArray.clear();
            IsFirstOperation = true;
            continue;
        }
        break;
    }
}
