#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

const int SIZE = 7; // Размер массива

/**
 * @brief Заполнение массива случайными числами в диапазоне [-10; 20]
 * @param arr массив для заполнения
 */
void fillArrayRandom(int arr[]) {
    srand(time(0)); // Инициализация генератора случайных чисел
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 31 - 10; // [-10; 20]
    }
}

/**
 * @brief Заполнение массива вручную с клавиатуры
 * @param arr массив для заполнения
 */
void fillArrayManual(int arr[]) {
    cout << "Введите " << SIZE << " целых чисел:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Элемент [" << i << "]: ";
        while (!(cin >> arr[i])) {
            cout << "Ошибка! Введите целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

/**
 * @brief Вывод массива на экран
 * @param arr массив для вывода
 * @param title заголовок для вывода
 */
void printArray(const int arr[], const string& title) {
    cout << title << ": [";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i];
        if (i < SIZE - 1) cout << ", ";
    }
    cout << "]" << endl;
}

/**
 * @brief Найти сумму элементов с нечетными индексами
 * @param arr массив для обработки
 * @return сумма элементов с нечетными индексами
 */
int sumOddIndexElements(const int arr[]) {
    int sum = 0;
    for (int i = 1; i < SIZE; i += 2) { // Индексы 1, 3, 5...
        sum += arr[i];
    }
    return sum;
}

/**
 * @brief Подсчет элементов > A и кратных 5
 * @param arr массив для обработки
 * @param A заданное число для сравнения
 * @return количество элементов, удовлетворяющих условиям
 */
int countElementsGreaterThanAAndMultipleOf5(const int arr[], int A) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > A && arr[i] % 5 == 0) {
            count++;
        }
    }
    return count;
}

/**
 * @brief Разделить элементы с четными индексами на первый элемент
 * @param arr массив для обработки (изменяется)
 */
void divideEvenIndexElementsByFirst(int arr[]) {
    if (arr[0] == 0) {
        cout << "Ошибка: первый элемент равен 0, деление невозможно!" << endl;
        return;
    }
    
    for (int i = 0; i < SIZE; i += 2) { // Индексы 0, 2, 4, 6...
        arr[i] /= arr[0]; // Целочисленное деление
    }
}

/**
 * @brief Главная функция программы
 * @return 0 при успешном выполнении
 */
int main() {
    int arr[SIZE];
    int choice;
    int A;
    
    cout << "Программа работы с массивом из " << SIZE << " элементов" << endl;
    cout << "Диапазон значений: [-10; 20]" << endl;
    cout << "==================================" << endl;
    
    // Выбор способа заполнения массива
    cout << "Выберите способ заполнения массива:" << endl;
    cout << "1 - Случайными числами" << endl;
    cout << "2 - Вручную с клавиатуры" << endl;
    cout << "Ваш выбор: ";
    
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << "Ошибка! Введите 1 или 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    if (choice == 1) {
        fillArrayRandom(arr);
    } else {
        fillArrayManual(arr);
    }
    
    // Вывод исходного массива
    printArray(arr, "Исходный массив");
    
    // Задание 1: Сумма элементов с нечетными индексами
    int sumOdd = sumOddIndexElements(arr);
    cout << "1. Сумма элементов с нечетными индексами: " << sumOdd << endl;
    
    // Задание 2: Подсчет элементов > A и кратных 5
    cout << "Введите число A для сравнения: ";
    while (!(cin >> A)) {
        cout << "Ошибка! Введите целое число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    int count = countElementsGreaterThanAAndMultipleOf5(arr, A);
    cout << "2. Количество элементов > " << A << " и кратных 5: " << count << endl;
    
    // Задание 3: Деление элементов с четными индексами на первый элемент
    cout << "3. Деление элементов с четными индексами на первый элемент:" << endl;
    int tempArr[SIZE]; // Создаем копию для демонстрации
    for (int i = 0; i < SIZE; i++) {
        tempArr[i] = arr[i];
    }
    
    divideEvenIndexElementsByFirst(tempArr);
    printArray(tempArr, "Массив после деления");
    
    return 0;
}
