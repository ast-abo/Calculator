#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <any>

std::string LeftNumber = "";
std::string RightNumber = "";

void ConnectNumsLeft(int StartIndex, std::string Expression)
{
    if (Expression[StartIndex - 1])
    {
        char NextChar = Expression[StartIndex - 1];
        LeftNumber.insert(0, 1, NextChar);
        ConnectNumsLeft(StartIndex - 1, Expression);
    };
}

void ConnectNumsRight(int StartIndex, std::string Expression)
{
    if (Expression[StartIndex + 1])
    {
        char NextChar = Expression[StartIndex + 1];
        RightNumber.insert(RightNumber.length(), 1, NextChar);
        ConnectNumsRight(StartIndex + 1, Expression);
    };
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

int main()
{
    while (true)
    {
        std::string Expression;
        std::cout << "Enter Expression: ";
        std::cin >> Expression;
        int Index = 0;

        std::vector<std::any> ParsedEqaution;

        for (char Character : Expression)
        {

            switch (Character)
            {
            case '+':

                std::cout << std::stoi(LeftNumber) + std::stoi(RightNumber) << std::endl;

                break;

            default:
                break;
            }

            if (Expression != "exit")
            {
                continue;
            }
            break;
        }

        return 0;
    }
