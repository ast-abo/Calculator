#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <any>


std::string LeftNumber = "";
std::string RightNumber = "";

void Add(int a, int b) {

}

void Subtract(int a, int b) {

}

void Multiply(int a, int b) {

}

void Divide (int a, int b) {

}

int main()
{
    while (true)
    {
        std::string Expression;
        std::cout << "Enter Expression: ";
        std::cin >> Expression;
        int Index = 0;

        std::vector<std::any> MyArray;


        for (char Character : Expression)
        {

            switch (Character)
            {
            case '*':

                std::cout << std::stoi(LeftNumber) * std::stoi(RightNumber) << std::endl;
                break;
            case '/':


                std::cout << static_cast<double>((std::stoi(LeftNumber))) / std::stoi(RightNumber) << std::endl;
                break;
            case '+':


                std::cout << std::stoi(LeftNumber) + std::stoi(RightNumber) << std::endl;
                break;
            case '-':


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
