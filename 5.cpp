#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

/**
 * @brief Вычисление факториала числа (итеративный метод)
 * @param n число для вычисления факториала
 * @return факториал числа n
 */
unsigned long long factorial(int n) {
    if (n < 0) return 0;
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

/**
 * @brief Вычисление суммы первых n членов последовательности
 * @param n количество членов последовательности
 * @return сумма первых n членов
 */
double sumFirstNTerms(int n) {
    double sum = 0.0;
    for (int k = 0; k <= n; ++k) {
        sum += pow(-1, k) / factorial(k);
    }
    return sum;
}

/**
 * @brief Вычисление суммы членов последовательности, не меньших по модулю e
 * @param e минимальное значение члена последовательности по модулю
 * @return сумма подходящих членов последовательности
 */
double sumTermsAboveE(double e) {
    double sum = 0.0;
    double term;
    int k = 0;
    
    do {
        term = pow(-1, k) / factorial(k);
        if (abs(term) >= e) {
            sum += term;
        }
        k++;
    } while (abs(term) >= e || k < 10); // Добавляем условие k < 10 для предотвращения бесконечного цикла
    
    return sum;
}

/**
 * @brief Функция для безопасного ввода целого числа с проверкой
 * @param prompt приглашение для ввода
 * @param minValue минимальное допустимое значение
 * @return корректно введенное число
 */
int getValidIntInput(const string& prompt, int minValue = 0) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < minValue) {
            cout << "Ошибка! Введите целое число >= " << minValue << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
}

/**
 * @brief Функция для безопасного ввода числа с плавающей точкой с проверкой
 * @param prompt приглашение для ввода
 * @param minValue минимальное допустимое значение
 * @return корректно введенное число
 */
double getValidDoubleInput(const string& prompt, double minValue = 0.0) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= minValue) {
            cout << "Ошибка! Введите число > " << minValue << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
}

/**
 * @brief Главная функция программы
 * @return 0 при успешном выполнении
 */
int main() {
    cout << "Программа для работы с последовательностью:" << endl;
    cout << "∑[k=0..n] ((-1)^k)/k!" << endl << endl;
    
    // Часть a: Сумма первых n членов
    cout << "Часть a: Сумма первых n членов последовательности" << endl;
    int n = getValidIntInput("Введите количество членов последовательности (n >= 0): ");
    double sumN = sumFirstNTerms(n);
    cout << "Сумма первых " << n << " членов последовательности: " 
         << fixed << setprecision(10) << sumN << endl << endl;
    
    // Часть b: Сумма членов, не меньших по модулю e
    cout << "Часть b: Сумма членов последовательности, не меньших по модулю e" << endl;
    double e = getValidDoubleInput("Введите минимальное значение e (e > 0): ");
    double sumE = sumTermsAboveE(e);
    cout << "Сумма членов последовательности с |a_k| >= " << e << ": " 
         << fixed << setprecision(10) << sumE << endl;
    
    return 0;
}
