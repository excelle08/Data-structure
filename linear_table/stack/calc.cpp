#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

void analyzeExpression(string expr, Stack<char> &optr, Stack<int> &opnd);
bool isNumber(char c);
char popFirstChar(string &str);
int calculate(Stack<char> &optr, Stack<int> &opnd, int tmp=0);

int main(int argc, char const *argv[]){
    Stack<int> operands;
    Stack<char> operators;
    string expression;

    cout << "Expression: ";
    cin >> expression;
    analyzeExpression(expression, operators, operands);
    cout << "Operands: " << endl;
    while(!operands.isEmpty()){
        cout << operands.pop() << ' ';
    }
    cout << endl << "Operators: " << endl;
    while(!operators.isEmpty()){
        cout << operators.pop() << ' ';
    }
    cout << endl << "Result:";
    cout << calculate(operators, operands) << endl;
    return 0;
}

void analyzeExpression(string expr, Stack<char> &optr, Stack<int> &opnd){
    int expr_length = expr.size();
    string temp;
    // Push start flag #
    optr.push('#');
    // Analyze expression - Extract operators and operands
    while(expr.length()){
        while(true){
            char c = popFirstChar(expr);
            if(!isNumber(c)){
                expr.insert(0, 1, c);
                break;
            }
            temp.append(1, c);
        }
        if(temp.length()){
            opnd.push(stoi(temp));
            temp.clear();
        }
        if(expr.length()){
            char op = popFirstChar(expr);
            optr.push(op);
        }
    }
    optr.push('#');
}

bool isNumber(char c){
    return (c <= '9' && c >= '0');
}

char popFirstChar(string &str){
    char res = str[0];
    str.erase(0,1);
    return res;
}

int calculate(Stack<char> &optr, Stack<int> &opnd, int tmp){
    int result = 0;
    while(!optr.isEmpty()){
        char op = optr.pop();
        int x, y;
        switch(op){
            case '#':
            tmp += 1;
            break;

            case '+':
            x = opnd.pop();
            result += x;
            break;

            case '-':
            x = opnd.pop();
            result -= x;
            break;

            case ')':
            calculate(optr, opnd, result);
            break;

            case '(':
            result += tmp;
            break;

            default:
            break;
        }
    }
    return result;
}