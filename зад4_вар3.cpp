#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <limits>
using namespace std;

/**
 * @brief Функция для вычисления значения y = x + √x + ∛x - 2.5
 * @param x значение аргумента
 * @return значение функции или NAN, если вычисление невозможно
 */
double calculateFunction(double x) {
    // Проверка на возможность вычисления корней
    if (x < 0) return NAN;
    
    try {
        return x + sqrt(x) + cbrt(x) - 2.5;
    } catch (...) {
        return NAN;
    }
}

/**
 * @brief Функция для безопасного ввода числа с проверкой
 * @param prompt приглашение для ввода
 * @param minValue минимальное допустимое значение
 * @param maxValue максимальное допустимое значение
 * @return корректно введенное число
 */
double getValidInput(const string& prompt, double minValue = -INFINITY, double maxValue = INFINITY) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < minValue || value > maxValue) {
            cout << "Ошибка! Введите число в диапазоне [" << minValue << ", " << maxValue << "]" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
}

/**
 * @brief Функция для табулирования функции на заданном интервале
 * @param start начальное значение x
 * @param end конечное значение x
 * @param step шаг изменения x
 * @return вектор пар (x, y)
 */
vector<pair<double, double>> tabulateFunction(double start, double end, double step) {
    vector<pair<double, double>> results;
    
    for (double x = start; x <= end + 1e-9; x += step) {
        double y = calculateFunction(x);
        results.emplace_back(x, y);
    }
    
    return results;
}

/**
 * @brief Главная функция программы
 * @return 0 при успешном выполнении
 */
int main() {
    cout << "Программа табулирования функции y = x + √x + ∛x - 2.5" << endl;
    
    // Ввод параметров табулирования
    double start = getValidInput("Введите начальное значение x: ");
    double end = getValidInput("Введите конечное значение x (должно быть >= начального): ", start);
    double step = getValidInput("Введите шаг табулирования (должен быть > 0): ", 0.0, end - start);
    
    // Табулирование функции
    auto results = tabulateFunction(start, end, step);
    
    // Вывод результатов
    cout << "\nРезультаты табулирования:" << endl;
    cout << "┌────────────┬────────────┐" << endl;
    cout << "│     x      │     y      │" << endl;
    cout << "├────────────┼────────────┤" << endl;
    
    for (const auto& [x, y] : results) {
        cout << "│ " << setw(10) << fixed << setprecision(4) << x << " │ ";
        if (isnan(y)) {
            cout << setw(10) << "нет реш." << " │" << endl;
        } else {
            cout << setw(10) << fixed << setprecision(4) << y << " │" << endl;
        }
    }
    
    cout << "└────────────┴────────────┘" << endl;
    
    // Вывод данных для построения графика
    cout << "\nДанные для построения графика:" << endl;
    cout << "x = [";
    for (const auto& [x, y] : results) {
        cout << x << (x + step <= end + 1e-9 ? ", " : "");
    }
    cout << "]" << endl;
    
    cout << "y = [";
    for (const auto& [x, y] : results) {
        if (isnan(y)) {
            cout << "nan" << (x + step <= end + 1e-9 ? ", " : "");
        } else {
            cout << y << (x + step <= end + 1e-9 ? ", " : "");
        }
    }
    cout << "]" << endl;
    
    return 0;
}
