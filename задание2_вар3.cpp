#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * @brief Функция для вычисления объема шара
 * @param radius радиус шара
 * @return объем шара по формуле V = (4/3)*π*R³
 */
double calculateVolume(double radius) {
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

/**
 * @brief Функция для вычисления площади поверхности шара
 * @param radius радиус шара
 * @return площадь поверхности шара по формуле S = 4*π*R²
 */
double calculateSurfaceArea(double radius) {
    return 4 * M_PI * pow(radius, 2);
}

/**
 * @brief Функция для безопасного ввода числа с проверкой
 * @param prompt приглашение для ввода
 * @return корректно введенное число
 */
double getValidInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cout << "Ошибка! Введите положительное число." << endl;
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
    cout << "Программа вычисления объема и площади поверхности шара" << endl;
    
    // Ввод радиуса с проверкой
    double radius = getValidInput("Введите радиус шара (R > 0): ");
    
    // Вычисления
    double volume = calculateVolume(radius);
    double surfaceArea = calculateSurfaceArea(radius);
    
    // Вывод результатов
    cout << fixed;
    cout.precision(4);
    cout << "\nРезультаты вычислений:" << endl;
    cout << "Радиус шара: " << radius << endl;
    cout << "Объем шара: " << volume << endl;
    cout << "Площадь поверхности шара: " << surfaceArea << endl;
    
    return 0;
}
