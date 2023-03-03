#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    vector<string> history;
    bool repeat = true;
    
    while (repeat) {
        char op;
        int num1, num2, result;
        
        cout << "Digite a operação (+, -, *, /): ";
        cin >> op;
        
        cout << "Digite o primeiro número: ";
        cin >> num1;
        
        cout << "Digite o segundo número: ";
        cin >> num2;
        
        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    cout << "Erro: divisão por zero!" << endl;
                    history.push_back("Erro: divisão por zero!");
                    break;
                } else {
                    result = num1 / num2;
                    break;
                }
            default:
                cout << "Operação inválida!" << endl;
                history.push_back("Operação inválida!");
                continue;
        }
        
        cout << "Resultado: " << result << endl;
        history.push_back(to_string(num1) + " " + string(1, op) + " " + to_string(num2) + " = " + to_string(result));
        
        cout << "Deseja continuar? (s/n): ";
        char choice;
        cin >> choice;
        
        if (choice == 's' || choice == 'S') {
            repeat = true;
        } else {
            repeat = false;
        }
    }
    
    cout << "Histórico de cálculos:" << endl;
    for (int i = 0; i < history.size(); i++) {
        cout << history[i] << endl;
    }
    
    return 0;
}

