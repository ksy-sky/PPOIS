/**
 * @file Polynomial.h
 * @brief Класс Polynomial для представления и работы с алгебраическими многочленами одной переменной.
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>

/**
 * @class Polynomial
 * @brief Класс, реализующий многочлен одной переменной с поддержкой арифметических операций, доступа к коэффициентам и вычислений.
 *
 * Многочлен представляется в виде вектора коэффициентов, где индекс соответствует степени переменной.
 * Например, Polynomial с коэффициентами {3, 2, 1} представляет многочлен 3 + 2x + x².
 */
class Polynomial {
public:
    /**
     * @brief Конструктор по умолчанию.
     * @param degree Степень многочлена. По умолчанию — 0 (нулевой многочлен).
     */
    Polynomial(int degree = 0);

    /**
     * @brief Конструктор копирования.
     * @param other Многочлен, который нужно скопировать.
     */
    Polynomial(const Polynomial& other);

    /**
     * @brief Деструктор.
     */
    ~Polynomial();

    /**
     * @brief Оператор присваивания.
     * @param other Многочлен, который нужно присвоить.
     * @return Ссылка на текущий объект.
     */
    Polynomial& operator=(const Polynomial& other);

    /**
     * @brief Оператор сравнения на равенство.
     * @param other Многочлен для сравнения.
     * @return true, если коэффициенты совпадают.
     */
    bool operator==(const Polynomial& other) const;

    /**
     * @brief Оператор сравнения на неравенство.
     * @param other Многочлен для сравнения.
     * @return true, если коэффициенты различаются.
     */
    bool operator!=(const Polynomial& other) const;

    /**
     * @brief Оператор вывода в поток.
     * @param os Поток вывода.
     * @param poly Многочлен для отображения.
     * @return Ссылка на поток вывода.
     *
     * Формат вывода: 3 + 2x + x^2
     */
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);

    /**
     * @brief Оператор ввода из потока.
     * @param is Поток ввода.
     * @param poly Многочлен для чтения.
     * @return Ссылка на поток ввода.
     *
     * Ожидается ввод коэффициентов от степени 0 до n.
     */
    friend std::istream& operator>>(std::istream& is, Polynomial& poly);

    /**
     * @brief Доступ к коэффициенту по индексу.
     * @param index Степень переменной.
     * @return Ссылка на коэффициент соответствующей степени.
     */
    double& operator[](int index);

    /**
     * @brief Доступ к коэффициенту по индексу (константный).
     * @param index Степень переменной.
     * @return Значение коэффициента соответствующей степени.
     */
    double operator[](int index) const;

    /**
     * @brief Вычисление значения многочлена при заданном x.
     * @param x Значение переменной.
     * @return Результат вычисления многочлена.
     *
     * Используется схема Горнера для эффективного вычисления.
     */
    double operator()(double x) const;

    /**
     * @brief Оператор сложения двух многочленов.
     * @param other Второй многочлен.
     * @return Новый многочлен — сумма текущего и другого.
     */
    Polynomial operator+(const Polynomial& other) const;

    /**
     * @brief Оператор += для сложения.
     * @param other Второй многочлен.
     * @return Ссылка на текущий объект после сложения.
     */
    Polynomial& operator+=(const Polynomial& other);

    /**
     * @brief Оператор вычитания двух многочленов.
     * @param other Второй многочлен.
     * @return Новый многочлен — разность текущего и другого.
     */
    Polynomial operator-(const Polynomial& other) const;

    /**
     * @brief Оператор -= для вычитания.
     * @param other Второй многочлен.
     * @return Ссылка на текущий объект после вычитания.
     */
    Polynomial& operator-=(const Polynomial& other);

    /**
     * @brief Оператор умножения двух многочленов.
     * @param other Второй многочлен.
     * @return Новый многочлен — произведение текущего и другого.
     */
    Polynomial operator*(const Polynomial& other) const;

/**
     * @brief Оператор *= для умножения.
     * @param other Второй многочлен.
     * @return Ссылка на текущий объект после умножения.
     */
    Polynomial& operator*=(const Polynomial& other);

    /**
     * @brief Оператор деления двух многочленов.
     * @param other Делитель.
     * @return Новый многочлен — результат деления.
     *
     * Деление реализовано как целочисленное деление многочленов.
     */
    Polynomial operator/(const Polynomial& other) const;

    /**
     * @brief Оператор /= для деления.
     * @param other Делитель.
     * @return Ссылка на текущий объект после деления.
     */
    Polynomial& operator/=(const Polynomial& other);

private:
    std::vector<double> coefficients; ///< Коэффициенты многочлена, индекс — степень переменной.
    static constexpr double EPSILON = 1e-10; ///< Погрешность для сравнения коэффициентов.
    
    /**
     * @brief Получение степени многочлена.
     * @return Максимальная степень с ненулевым коэффициентом.
     */
    int getDegree() const;
};

#endif // POLYNOMIAL_H
