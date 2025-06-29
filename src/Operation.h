#pragma once

class Operation {
public:
    Operation(float a, float b, int ExpressionIndex, int ParseIndex, char OperatorType);
    float Evaluate();
    float Operand1;
    float Operand2;
    float Result;
    int ExpressionIndex;
    int ParseIndex;
    char Operator;

private:

};