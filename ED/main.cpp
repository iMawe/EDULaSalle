#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

using namespace std;


int main() {
    Stack<int> stack;
    char string[] = "1 2 + 3 - 10 + 2 / 9 *";   //(((1+2)-3)+(10/2))*9

    int number = 0;
    bool added = false;
    for (int i = 0; i < strlen(string); i++) {

        // Arithmetic: Push all numbers and calculate whenever its something else
        char c = string[i];

        if (isdigit(c)) { //isdigit(str[i]) != 0
            number = number * 10 + c - '0';
            added = true;

        } else if (c == ' ' && added) {
            stack.push(number);
            number = 0;
            added = false;

        } else {
            if (stack.getSize() >= 2) {
                int number1 = stack.pop();
                int number2 = stack.pop();
                int result;

                cout << "Calculating: " << number2 << c << number1 << " = ";

                switch (c) {
                    case '+':
                        result = number2 + number1;
                        stack.push(result);
                        cout << result << endl;
                        break;
                    case '-':
                        result = number2 - number1;
                        stack.push(result);
                        cout << result << endl;
                        break;
                    case '*':   
                        result = number2 * number1;
                        stack.push(result);
                        cout << result << endl;
                        break;
                    case '/':
                        result = number2 / number1;
                        stack.push(result);
                        cout << result << endl;
                        break;
                    default:
                        cout << "This is not allowed!" << endl;
                }

            }
        }
    }

    if (!stack.isEmpty()) {
        cout << "Result: " << stack.pop();
    }

    return 0;
}