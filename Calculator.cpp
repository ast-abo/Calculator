#include <iostream>
#include <vector>
#include <string>

int main()
{
    while (true)
    {
        std::string Equation;
        std::vector<char> Numbers(5);
        std::cout << "Enter Equation: ";
        std::cin >> Equation;
        int Index = 0;

        for (char Character : Equation)
        {
            switch (Character)
            {
            case '*':
                // std::cout << Index;
                std::cout << (Equation[Index - 1] - '0') * (Equation[Index + 1] - '0') << std::endl;
                break;
            case '/':
                // std::cout << Index;
                std::cout << static_cast<double>((Equation[Index - 1] - '0')) / (Equation[Index + 1] - '0') << std::endl;
                break;
            case '+':
                // std::cout << Index;
                std::cout << (Equation[Index - 1] - '0') + (Equation[Index + 1] - '0') << std::endl;
                break;
            case '-':
                // std::cout << Index;
                std::cout << (Equation[Index - 1] - '0') - (Equation[Index + 1] - '0') << std::endl;
                break;
            default:
                // std::cout << "Invalid Symbol!" << std::endl;
                break;
            }

            Index++;
        }

        if (Equation != "exit")
        {
            continue;
        }
        break;
    }

    return 0;
}
