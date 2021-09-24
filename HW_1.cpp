#include <iostream>
#include <cmath>
#include <string>
#include <cstdint>



// ========================================= Task1 =========================================  //
/*
������� ����� Power, ������� �������� ��� ������������ �����. ���� ����� ������ ����� ��� ����������-����� 
��� �������� ���� ������������ �����. ��� ������� ��� ������: ���� � ������ set, ������� �������� ����������� 
�������� ����������, ������ � calculate, ������� ����� �������� ��������� ���������� ������� ����� � ������� 
������� �����. ������ �������� ���� ���� ����� �� ���������.
*/

class Power
{
private: // �������� X � Y �� ���������
    double m_X = 2.5;
    double m_Y = 3.5;

public:
    Power() // ����������� �� ��������� (������������� �������� �� ��������� ����)
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
2) �������� ����� � ������ RGBA, ������� �������� 4 ����������-����� ���� 
std::uint8_t: m_red, m_green, m_blue � m_alpha (#include cstdint ��� ������� � ����� ����). 
������ 0 � �������� �������� �� ��������� ��� m_red, m_green, m_blue � 255 ��� m_alpha. 
������� ����������� �� ������� ������������� ������, ������� �������� ������������ ���������� 
�������� ��� m_red, m_blue, m_green � m_alpha. �������� ������� print(), ������� ����� �������� 
�������� ����������-������.
*/

class RGBA
{
private: // �������� ������� �� ���������
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;

public:
    RGBA() // ����������� �� ��������� (������������� �������� �� ��������� ����)
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
3) �������� �����, ������� ��������� ���������������� �����. ����� Stack ������ �����:
- private-������ ����� ����� ������ 10;
- private ������������� �������� ��� ������������ ����� �����;
- public-����� � ������ reset(), ������� ����� ���������� ����� � ��� �������� ��������� �� 0;
- public-����� � ������ push(), ������� ����� ��������� �������� � ����. push() ������ ���������� �������� false, 
���� ������ ��� ��������, � true � ��������� ������;
- public-����� � ������ pop() ��� ����������� � �������� �������� �� �����. ���� � ����� ��� ��������, �� ������ ���������� ��������������;
- public-����� � ������ print(), ������� ����� �������� ��� �������� �����.
*/

class Stack
{
private:
    static const size_t m_SIZE = 10;
    int m_arr[m_SIZE];

public:
    int index;

    void reset() // ������� ������ �����
    {
        index = 0;
        for (size_t i = 0; i < m_SIZE; ++i)
        {
            m_arr[i] = 0;
        }
    }

    bool push(int value) // ���������� � ����
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

    int pop() // �������� �� �����
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

    void print_stack() // ������ �����
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
    one.Calculate(); // ������� ��������� ���������� � ������� �����, �������� �� ���������, ������� ��������� �� �����
    one.Set(3.5, 4.5); // ���������������� ����� ������ Power m_X � m_Y ������ ����������
    one.Calculate ();  // ������� ��������� ���������� � ������� �����, ������� ��������� �� �����
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
