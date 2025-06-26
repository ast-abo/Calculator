#include <iostream>
#include <vector>
#include <string>

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
            case '*':
                // std::cout << Index;
                ConnectNumsLeft(Index, Expression);
                ConnectNumsRight(Index, Expression);

                std::cout << std::stoi(LeftNumber) * std::stoi(RightNumber) << std::endl;
                break;
            case '/':
                ConnectNumsLeft(Index, Expression);
                ConnectNumsRight(Index, Expression);

                std::cout << static_cast<double>((std::stoi(LeftNumber))) / std::stoi(RightNumber) << std::endl;
                break;
            case '+':
                ConnectNumsLeft(Index, Expression);
                ConnectNumsRight(Index, Expression);

                std::cout << std::stoi(LeftNumber) + std::stoi(RightNumber) << std::endl;
                break;
            case '-':
                ConnectNumsLeft(Index, Expression);
                ConnectNumsRight(Index, Expression);

                std::cout << std::stoi(LeftNumber) - std::stoi(RightNumber) << std::endl;
                break;
            default:
                break;
            }

            Index++;
        }

        LeftNumber = "";
        RightNumber = "";

        if (Expression != "exit")
        {
            continue;
        }
        break;
    }

    return 0;
}
