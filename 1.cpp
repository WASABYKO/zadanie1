#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Функция для вычисления значения a по заданной формуле
 * @param x - значение переменной x
 * @param y - значение переменной y
 * @return возвращает рассчитанное значение a
 */
double getA(const double x, const double y);

/**
 * @brief Функция для вычисления значения b по заданной формуле
 * @param x - значение переменной x
 * @param y - значение переменной y
 * @return возвращает рассчитанное значение b
 */
double getB(const double x, const double y);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double x = 0.335;
    const double y = 0.025;
    
    cout << "Исходные данные:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << endl;
    cout << "Результаты вычислений:" << endl;
    cout << "a = " << getA(x, y) << endl;
    cout << "b = " << getB(x, y) << endl;
    
    return 0;
}

double getA(const double x, const double y)
{
    // Формула: a = 1 + x + (x² + x³ + x⁴)/10 + 21
    double x2 = x * x;        // x²
    double x3 = x2 * x;       // x³
    double x4 = x3 * x;       // x⁴
    
    double result = 1 + x + (x2 + x3 + x4) / 10.0 + 21;
    return result;
}

double getB(const double x, const double y)
{
    // Формула: b = x(sin²x + cos²y)
    // Используем тригонометрическое тождество: sin²x + cos²y
    // Но по заданию, вероятно, имеется в виду: x * (sin²x + cos²y)
    
    double sin_x = sin(x);
    double cos_y = cos(y);
    
    double result = x * (sin_x * sin_x + cos_y * cos_y);
    return result;
}
