#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
   
    const double x = 0.335;  // Первая входная переменная
    const double y = 0.025;  // Вторая входная переменная

    // Вычисление переменной a как суммы ряда: 1 + x + x²/2 + x³/3 + x⁴/4
    double a = 1 + x + (pow(x, 2) / 2) + (pow(x, 3) / 3) + (pow(x, 4) / 4);

    // Вычисление переменной b как x * (sin(x³) + cos²(y))
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
