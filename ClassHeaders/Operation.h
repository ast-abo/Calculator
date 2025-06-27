#pragma once

class Operation {
public:
    Operation(float a, float b, int Index, char Op);
    float Evaluate();
    float First;
    float Second;
    int Index;
    char Operator;

private:

};