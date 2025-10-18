/**
 * @file TicTacToe.h
 * @brief Класс TicTacToe для реализации игры "Крестики-нолики" произвольного размера.
 */

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <iostream>
#include <stdexcept>

/**
 * @class TicTacToe
 * @brief Класс для игры "Крестики-нолики" на поле произвольного размера.
 */
class TicTacToe {
public:
    /**
     * @brief Конструктор с заданным размером поля.
     * @param size Размер игрового поля (size x size).
     */
    explicit TicTacToe(int size);

    /**
     * @brief Конструктор копирования.
     * @param other Игровое поле, которое нужно скопировать.
     */
    TicTacToe(const TicTacToe& other);

    /**
     * @brief Оператор присваивания.
     * @param other Игровое поле, которое нужно присвоить.
     * @return Ссылка на текущий объект.
     */
    TicTacToe& operator=(const TicTacToe& other);

    /**
     * @brief Деструктор.
     */
    ~TicTacToe();

    /**
     * @brief Установка хода игрока.
     * @param x Координата по горизонтали.
     * @param y Координата по вертикали.
     * @param player Символ игрока ('X' или 'O').
     */
    void setMove(int x, int y, char player);

    /**
     * @brief Получение значения ячейки.
     * @param x Координата по горизонтали.
     * @param y Координата по вертикали.
     * @return Символ в ячейке ('X', 'O' или ' ').
     */
    char getValue(int x, int y) const;

    /**
     * @brief Проверка победы игрока.
     * @param player Символ игрока ('X' или 'O').
     * @return true, если игрок победил.
     */
    bool checkWin(char player) const;

    /**
     * @brief Оператор доступа к ячейке (для установки значения).
     * @param pos Пара координат (x, y).
     * @return Ссылка на символ в ячейке.
     */
    char& operator[](std::pair<int, int> pos);

    /**
     * @brief Оператор доступа к ячейке (для чтения значения).
     * @param pos Пара координат (x, y).
     * @return Константная ссылка на символ в ячейке.
     */
    const char& operator[](std::pair<int, int> pos) const;

    /**
     * @brief Оператор сравнения на равенство.
     * @param other Другая игра.
     * @return true, если доски совпадают.
     */
    bool operator==(const TicTacToe& other) const;

    /**
     * @brief Оператор сравнения на неравенство.
     * @param other Другая игра.
     * @return true, если доски различаются.
     */
    bool operator!=(const TicTacToe& other) const;

    /**
     * @brief Копирование игрового поля.
     * @param other Игра, из которой копируется поле.
     */
    void copyBoard(const TicTacToe& other);
    /**
     * @brief Оператор вывода в поток.
     * @param os Поток вывода.
     * @param game Игра для вывода.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const TicTacToe& game);

    /**
     * @brief Оператор ввода из потока.
     * @param is Поток ввода.
     * @param game Игра для ввода.
     * @return Ссылка на поток ввода.
     */
    friend std::istream& operator>>(std::istream& is, TicTacToe& game);

private:
    std::vector<std::vector<char>> board; ///< Игровое поле
    int size; ///< Размер поля
    bool gameWon = false; ///< Флаг победы
    bool isValidMove(int x, int y) const; ///< Проверка корректности хода

};

#endif // TICTACTOE_H


