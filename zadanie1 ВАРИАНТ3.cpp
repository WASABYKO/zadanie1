#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/**
 * @brief Функция для вычисления значения переменной a (сумма ряда)
 * @param x значение входной переменной
 * @return Результат вычисления суммы ряда 1 + x + x²/2 + x³/3 + x⁴/4
 */
double calculateA(const double x) {
    return 1 + x + (pow(x, 2) / 2) + (pow(x, 3) / 3) + (pow(x, 4) / 4);
}

/**
 * @brief Функция для вычисления значения переменной b
 * @param x первая входная переменная
 * @param y вторая входная переменная
 * @return Результат вычисления x * (sin(x³) + cos²(y))
 */
double calculateB(const double x, const double y) {
    return x * (sin(pow(x, 3)) + pow(cos(y), 2));
}

/**
 * @brief Главная функция программы
 * @return 0 при успешном выполнении
 */
int main() {
    const double x = 0.335;  // Первая входная переменная
    const double y = 0.025;  // Вторая входная переменная

    // Вывод исходных данных
    cout << "Исходные данные:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl << endl;

    // Вывод результатов
    cout << "Результаты вычислений:" << endl;
    cout << "a = " << fixed << setprecision(6) << calculateA(x) << endl;
    cout << "b = " << fixed << setprecision(6) << calculateB(x, y) << endl;

    return 0;
}
