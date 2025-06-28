#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include "Operation.h"

std::vector<Operation> ParsedExpression;
std::vector<float> ExpressionNumberArray;
bool IsFirstOperation = true;
int OperationIndex = 0;

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
        if (Operation.ParseIndex > 0)
        {
            Operation.Operand1 = ParsedExpression[Operation.ParseIndex - 1].Result;
        }

        Operation.Evaluate();
        std::cout << Operation.Result << std::endl;
    }
}


void OperatorCheck(char Character, int CharIndex, std::string Expression)
{
    switch (Character)
    {
    case '+':
        if (IsFirstOperation)
        {
            ExpressionNumberArray.push_back(ConnectNumsLeft(CharIndex, Expression, ""));
            IsFirstOperation = false;
        }
        ExpressionNumberArray.push_back(ConnectNumsRight(CharIndex, Expression, ""));

        ParsedExpression.push_back(Operation(ExpressionNumberArray[0], ExpressionNumberArray[ExpressionNumberArray.size() - 1], CharIndex, OperationIndex, Character));
        break;
    case '-':
        if (IsFirstOperation)
        {
            ExpressionNumberArray.push_back(ConnectNumsLeft(CharIndex, Expression, ""));
            IsFirstOperation = false;
        }
        ExpressionNumberArray.push_back(ConnectNumsRight(CharIndex, Expression, ""));
        // fix first parameter of subtraction
        ParsedExpression.push_back(Operation(ExpressionNumberArray[0], ExpressionNumberArray[ExpressionNumberArray.size() - 1], CharIndex, OperationIndex, Character));
        break;
    case '*':
        if (IsFirstOperation)
        {
            ExpressionNumberArray.push_back(ConnectNumsLeft(CharIndex, Expression, ""));
            IsFirstOperation = false;
        }

        for (auto &Operation : ParsedExpression)
        {
            if (Operation.Operator == '+' || Operation.Operator == '-') {
                
            }
        }
        ExpressionNumberArray.push_back(ConnectNumsRight(CharIndex, Expression, ""));

        ParsedExpression.push_back(Operation(ExpressionNumberArray[0], ExpressionNumberArray[ExpressionNumberArray.size() - 1], CharIndex, OperationIndex, Character));
        break;

    default:
        break;
    }
    if (Character == '*' || Character == '/' || Character == '+' || Character == '-')
    {
        OperationIndex++;
    }
}

void ParseExpression(std::string Expression)
{
    int CharIndex = 0;

    for (char Character : Expression)
    {
        OperatorCheck(Character, CharIndex, Expression);
        CharIndex++;
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
            IsFirstOperation = true;
            OperationIndex = 0;
            continue;
        }
        break;
    }
}
