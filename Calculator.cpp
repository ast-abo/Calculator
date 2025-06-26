#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <any>

std::vector<std::any> ParsedEqaution;

float ConnectNumsLeft(int StartIndex, std::string Expression, std::string Number)
{
    std::string NewNumber = Number;

    if (Expression[StartIndex - 1]) {
        char NextChar = Expression[StartIndex - 1];
        NewNumber.insert(0, 1, NextChar);
        ConnectNumsLeft(StartIndex - 1, Expression, NewNumber);
    }
    else {
        return std::stoi(NewNumber);
    }
}

float ConnectNumsRight(int StartIndex, std::string Expression, std::string Number)
{
    std::string NewNumber = Number;

    if (Expression[StartIndex + 1]) {
        char NextChar = Expression[StartIndex + 1];
        NewNumber.insert(NewNumber.length(), 1, NextChar);
        ConnectNumsRight(StartIndex + 1, Expression, NewNumber);
    }
    else {
        return std::stoi(NewNumber);
    }
}

void Add(int a, int b)
{
}

void Subtract(int a, int b)
{
}

void Multiply(int a, int b)
{
}

void Divide(int a, int b)
{
}

void Evaluate(std::any ParsedEquation) {

}

int main()
{
    while (true)
    {
        std::string Expression;
        std::cout << "Enter Expression: ";
        std::cin >> Expression;
        int Index = 0;

        for (char Character : Expression)
        {
            switch (Character)
            {
            case '+':
                float LeftNumber = ConnectNumsLeft(Index, Expression, "");
                float RightNumber = ConnectNumsRight(Index, Expression, "");
                

                ParsedEqaution[0] = std::map<std::string, int>();
                
                break;

            default:
                break;
            }
            ////

            if (Expression != "exit")
            {
                continue;
            }
            break;
        }

        return 0;
    }
