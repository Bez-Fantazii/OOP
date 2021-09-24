#include <iostream>
#include <cmath>
#include <string>
#include <cstdint>



// ========================================= Task1 =========================================  //
/*
Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена 
для хранения этих вещественных чисел. Еще создать два метода: один с именем set, который позволит присваивать 
значения переменным, второй — calculate, который будет выводить результат возведения первого числа в степень 
второго числа. Задать значения этих двух чисел по умолчанию.
*/

class Power
{
private: // значения X и Y по умолчанию
    double m_X = 2.5;
    double m_Y = 3.5;

public:
    Power() // конструктор по умолчанию (присваиваются значения по умолчанию выше)
    {
    }

    void Set(double X, double Y)
    {
        if (X <= 0 || Y < 0)
        {
            std::cout << "Please, enter positive values of X and Y for calculation X^Y" << std::endl;
            return;
        }
        m_X = X;
        m_Y = Y;
    }
        
    void Calculate()
    {
        std::cout << "Result of pow " << m_X << "^" << m_Y << " is: " << pow(m_X, m_Y) << std::endl;
    }
};

// ========================================= Task2 =========================================  //
/*
2) Написать класс с именем RGBA, который содержит 4 переменные-члена типа 
std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). 
Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. 
Создать конструктор со списком инициализации членов, который позволит пользователю передавать 
значения для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить 
значения переменных-членов.
*/

class RGBA
{
private: // значения палитры по умолчанию
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;

public:
    RGBA() // конструктор по умолчанию (присваиваются значения по умолчанию выше)
    {
    }

    void Set_color (int red, int green, int blue, int alpha)
    {
        if ((red, green, blue, alpha) < 0 || (red, green, blue, alpha) > 255)
        {
            std::cout << "Please, enter correct color code (0 ... 255)" << std::endl;
            return;
        }
        m_red = red;
        m_green = green;
        m_blue = blue;
        m_alpha = alpha;
    }

    void Print()
    {
        std::cout << "RGBA code is: " << "R(" << static_cast<int>(m_red) << "), G(" << static_cast<int>(m_green) << "), B(" << static_cast<int>(m_blue) << "), A(" << static_cast<int>(m_alpha) << ")." << std::endl;
    }
};

// ========================================= Task3 =========================================  //
/*
3) Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
- private-массив целых чисел длиной 10;
- private целочисленное значение для отслеживания длины стека;
- public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
- public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, 
если массив уже заполнен, и true в противном случае;
- public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
- public-метод с именем print(), который будет выводить все значения стека.
*/

class Stack
{
private:
    static const size_t m_SIZE = 10;
    int m_arr[m_SIZE];

public:
    int index;

    void reset() // функция сброса стека
    {
        index = 0;
        for (size_t i = 0; i < m_SIZE; ++i)
        {
            m_arr[i] = 0;
        }
    }

    bool push(int value) // добавление в стек
    {
        if (index == m_SIZE)
        {
            std::cout << "STACK IS OVERFLOW";
            return false;
        }
        else
        {
            m_arr[index++] = value;
            return true;
        }
    }

    int pop() // удаление из стека
    {
        if (index > 0)
        {
            return m_arr[--index];
        }
        else
        {
            std::cout << "STACK IS EMPTY";
        }
    }

    void print_stack() // печать стека
    {
        std::cout << "( ";
        for (int i = 0; i < index; ++i)
        {
            std::cout << m_arr[i] << ' ';
        }
        std::cout << ")" << std::endl;
    }

};


int main()
{
    // ======================================= Task 1 ========================================
    std::cout << "Task 1:" << std::endl;
    Power one;
    one.Calculate(); // считаем результат возведения в степень чисел, заданных по умолчанию, выводим результат на экран
    one.Set(3.5, 4.5); // инициализировали члены класса Power m_X и m_Y своими значениями
    one.Calculate ();  // считаем результат возведения в степень чисел, выводим результат на экран
    std::cout << std::endl;
    std::cout << std::endl;
    // ======================================= Task 2 ========================================
    std::cout << "Task 2:" << std::endl;
    RGBA test;
    test.Print();
    test.Set_color(123, 251, 13, 120);
    test.Print();
    std::cout << std::endl;
    std::cout << std::endl;
    // ======================================= Task 3 ========================================
    std::cout << "Task 3:" << std::endl;
    Stack stack;
    stack.reset();
    std::cout << "Stack was resetted:" << std::endl;
    stack.print_stack();
    std::cout << "Stack was completely filled:" << std::endl;
    for (size_t i = 1; i < 11; ++i)
    {
        stack.push(i);
    }
    stack.print_stack();
    std::cout << "Try to add to stack oversize element:" << std::endl;
    stack.push(12);
    stack.print_stack();
    std::cout << "Delete in stack all elements except the last element:" << std::endl;
    for (size_t i = 1; i < 10; ++i)
    {
        stack.pop();
    }
    stack.print_stack();
    std::cout << "The last stack's element was deleted:" << std::endl;
    stack.pop();
    stack.print_stack();
    std::cout << "Try to delete element from empty stack:" << std::endl;
    stack.pop();
    stack.print_stack();
    std::cout << "Stack was resetted:" << std::endl;
    stack.print_stack();
    std::cout << "One element (15) was added to stack:" << std::endl;
    stack.push(15);
    stack.print_stack();
    return 0;
}
