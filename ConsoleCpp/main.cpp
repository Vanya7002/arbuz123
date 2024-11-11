#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string convertBase(string number, int baseFrom, int baseTo) {
    if (baseFrom < 2 || baseFrom > 32 || baseTo < 2 || baseTo > 32) {
        return "Ошибка: Основание системы счисления должно быть в диапазоне от 2 до 32.";
    }

    // Преобразование в десятичную систему
    int decimalNumber = 0;
    for (int i = 0; i < number.length(); i++) {
        int digit = (number[i] >= '0' && number[i] <= '9') ? number[i] - '0' : number[i] - 'A' + 10;
        decimalNumber += digit * pow(baseFrom, number.length() - i - 1);
    }

    // Преобразование из десятичной системы
    string convertedNumber = "";
    while (decimalNumber > 0) {
        int remainder = decimalNumber % baseTo;
        char digit = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
        convertedNumber = digit + convertedNumber;
        decimalNumber /= baseTo;
    }
    return convertedNumber;
}

int main() {
    string number;
    int baseFrom, baseTo;

    cout << "Введите число: ";
    cin >> number;

    cout << "Введите исходную систему счисления (от 2 до 32): ";
    cin >> baseFrom;

    cout << "Введите целевую систему счисления (от 2 до 32): ";
    cin >> baseTo;

    string convertedNumber = convertBase(number, baseFrom, baseTo);
    cout << "Число " << number << " в системе счисления " << baseFrom
        << " равно " << convertedNumber << " в системе счисления " << baseTo << endl;
    system("pause");
    return 0;
}
