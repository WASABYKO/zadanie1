#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
   
    const double x = 0.335;
    const double y = 0.025;

    // Вычисление переменной a
    double a = 1 + x + (pow(x, 2) / 2) + (pow(x, 3) / 3) + (pow(x, 4) / 4);

    // Вычисление переменной b
    double b = x * (sin(pow(x, 3)) + pow(cos(y), 2));

    // Вывод исходных данных
    std::cout << "Исходные данные:" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl << std::endl;

    // Вывод результатов
    std::cout << "Результаты вычислений:" << std::endl;
    std::cout << "a = " << std::fixed << std::setprecision(6) << a << std::endl;
    std::cout << "b = " << std::fixed << std::setprecision(6) << b << std::endl;

    return 0;
}
