#include <iostream>
#include <cmath>
#include <string>
#include <math.h>
#include <functional>
#include <vector>



// 1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). 
// Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). 
// Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь). 
// Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

class Figure
{
public:
	virtual float area() = 0;
};

class Circle : public Figure
{
private:
	float m_R = 1.0;
	float m_Pi = 3.1415;

protected:
	//get-функции
	float get_R() const { return m_R; }
	float get_Pi() const { return m_Pi; }
	//set-функция
	void set_R(float R) { m_R = R; }

public:
	Circle(float R)
		: m_R(R) {}

	float area()
	{
		float area = m_Pi * pow(m_R, 2);
		std::cout << "Area of circle with radius R = " << m_R << " is: " << area << std::endl;
		return area;
	}
};

class Parallelogram : public Figure
{
private:
	float m_a = 1.0;
	float m_b = 1.0;
	float m_height = 1.0;

protected:
	//get-функции
	float get_a() const { return m_a; }
	float get_b() const { return m_b; }
	float get_height() const { return m_height; }
	//set-функции
	void set_a(float a) { m_a = a; }
	void set_b(float b) { m_b = b; }
	void set_height(float height) { m_height = height; }

public:
	Parallelogram(float a, float height, float b = 0)
		: m_a(a), m_b(b), m_height(height) {}

	float area()
	{
		float area = m_a * m_height;
		std::cout << "Area of parallelogram with base side = " << m_a << " and height = " << m_height << " is: " << area << std::endl;
		return area;
	}
};

class Restangle : public Parallelogram
{
public:
	Restangle(float a, float b) : Parallelogram(a, b, b)
	{}

	float area()
	{
		float area = get_a() * get_b();
		std::cout << "Area of restangle with side a = " << get_a() << " and side b = " << get_b() << " is: " << area << std::endl;
		return area;
	}
};

class Square : public Parallelogram
{
public:
	Square(float a) : Parallelogram(a, a, a)
	{}

	float area()
	{
		float area = pow(get_a(), 2);
		std::cout << "Area of square with side = " << get_a() << " is: " << area << std::endl;
		return area;
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(float a, float height) : Parallelogram(a, height, height)
	{}

	float area()
	{
		float area = get_a() * get_height();
		std::cout << "Area of rhombus with side = " << get_a() << " and height = " << get_height() << " is: " << area << std::endl;
		return area;
	}
};


// 2. Создать класс Car(автомобиль) с полями company(компания) и model(модель).
// Классы - наследники: PassengerCar(легковой автомобиль) и Bus(автобус).
// От этих классов наследует класс Minivan(минивэн).Создать конструкторы для каждого из классов, 
// чтобы они выводили данные о классах.Создать объекты для каждого из классов и посмотреть, в какой 
// последовательности выполняются конструкторы.Обратить внимание на проблему «алмаз смерти».
// Примечание : если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.

class Car
{
private:
	std::string m_company;
	std::string m_model;
protected:
	//get-функции
	std::string getCompany() const { return m_company; }
	std::string getModel() const { return m_model; }
	//set-функции
	void set_m_company(std::string company) { m_company = company; }
	void set_m_model(std::string model) { m_model = model; }
public:
	Car(std::string company, std::string model) : m_company(company), m_model(model)
	{
		std::cout << "The vehicle belongs to the company " + getCompany() + ", vehicle model is " + getModel() << std::endl;
	}
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar(std::string company, std::string model) : Car(company, model)
	{
		std::cout << "The car belongs to the company " + getCompany() + ", car model is " + getModel() << std::endl;
	}
};

class Bus : virtual public Car
{
public:
	Bus(std::string company, std::string model) : Car(company, model)
	{
		std::cout << "The bus belongs to the company " + getCompany() + ", bus model is " + getModel() << std::endl;
	}
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(std::string company, std::string model) :
		PassengerCar(company, model), Bus(company, model), Car(company, model)
	{
		std::cout << "The minivan belongs to the company " + getCompany() + ", minivan model is " + getModel() << std::endl;
	}
};

// 3. Создать класс : Fraction(дробь). Дробь имеет числитель и знаменатель(например, 3 / 7 или 9 / 2).
// Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить :
// - математические бинарные операторы(+, -, *, / ) для выполнения действий с дробями
// - унарный оператор(-)
// - логические операторы сравнения двух дробей(== , != , <, >, <= , >= ).
// Примечание : Поскольку операторы < и >= , > и <= — это логические противоположности, попробуйте перегрузить один через другой.
// Продемонстрировать использование перегруженных операторов.

class Fraction
{
private:
	bool is_zero;
	bool is_integer;
	int numerator;
	int denominator;

	/*
	 * Поиск наибольшего общего делителя
	 * для числителя и знаменателя
	 */
	int NOD(int n1, int n2)
	{
		int div;
		if (n1 == n2)  return n1;
		int d = n1 - n2;
		if (d < 0)
		{
			d = -d;
			div = NOD(n1, d);
		}
		else
			div = NOD(n2, d);

		return div;
	}

	/*
	 * Поиск наименьшего общего кратного
	 * для знаменателей
	 */
	int NOK(int n1, int n2)
	{
		return n1 * n2 / NOD(n1, n2);
	}

	/*
	 * Функция сокращения дроби
	 */
	void reduceFraction(int &a, int &b)
	{
		int divisor = NOD(abs(a), abs(b));
		a = a / divisor;
		b = b / divisor;
	}
public:
	Fraction() : numerator(0), denominator(0)
	{
		is_zero = true;
		is_integer = true;
	}

	Fraction(int num, int dnum) : numerator(num), denominator(dnum)
	{
		if (numerator == 0 || denominator == 0)
		{
			std::cout << "Numerator or denominator can't be = 0!\n"
				<< "The number will be initialize as zero!" << std::endl;
			numerator = 0;
			denominator = 0;
			is_zero = true;
			is_integer = true;
		}
		else
		{
			is_zero = false;
			is_integer = (abs(numerator) == abs(denominator) || denominator == 1);
		}
	}

	friend std::ostream& operator<<(std::ostream&, const Fraction&);

	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);

	Fraction operator-() const;

	bool operator==(const Fraction&);
	bool operator!=(const Fraction&);
	bool operator<(const Fraction&);
	bool operator>=(const Fraction&);
	bool operator>(const Fraction&);
	bool operator<=(const Fraction&);
};

std::ostream& operator<<(std::ostream& s, const Fraction& f)
{
	if (f.is_integer)
	{
		if (f.is_zero)
			s << f.numerator;
		else
			s << f.numerator / f.denominator;
	}
	else
		s << f.numerator << '/' << f.denominator;

	return s;
}

Fraction Fraction::operator+(const Fraction &f)
{
	if (f.is_zero)
		return Fraction(numerator, denominator);

	if (is_zero)
		return Fraction(f.numerator, f.denominator);

	int new_denominator = NOK(denominator, f.denominator);
	int new_numerator = numerator * (new_denominator / denominator) + f.numerator * (new_denominator / f.denominator);

	reduceFraction(new_numerator, new_denominator);

	return Fraction(new_numerator, new_denominator);
}

Fraction Fraction::operator-(const Fraction& f)
{
	if (f.is_zero)
		return Fraction(numerator, denominator);

	if (is_zero)
		return Fraction(-f.numerator, f.denominator);

	int new_denominator = NOK(denominator, f.denominator);
	int new_numerator = numerator * (new_denominator / denominator) - f.numerator * (new_denominator / f.denominator);

	if (new_numerator == 0)
		return Fraction();

	reduceFraction(new_numerator, new_denominator);

	return Fraction(new_numerator, new_denominator);
}

Fraction Fraction::operator*(const Fraction &f)
{
	if (is_zero || f.is_zero)
		return Fraction();

	int new_numerator = numerator * f.numerator;
	int new_denominator = denominator * f.denominator;

	reduceFraction(new_numerator, new_denominator);

	return Fraction(new_numerator, new_denominator);
}

Fraction Fraction::operator/(const Fraction &f)
{
	if (f.is_zero)
	{
		std::cout << " [You cannot divide by zero!] ";
		return Fraction();
	}

	if (is_zero)
		return Fraction();

	return *this * Fraction(f.denominator, f.numerator);
}

Fraction Fraction::operator-() const
{
	return Fraction(-numerator, denominator);
}

bool Fraction::operator==(const Fraction &f)
{
	if (is_zero || f.is_zero)
		return numerator == f.numerator;

	int a_n = numerator;
	int a_d = denominator;

	int b_n = f.numerator;
	int b_d = f.denominator;

	reduceFraction(a_n, a_d);
	reduceFraction(b_n, b_d);

	return a_n == b_n && a_d == b_d;
}

bool Fraction::operator!=(const Fraction &f)
{
	return !(*this == f);
}

bool Fraction::operator<(const Fraction &f)
{
	if (is_zero || f.is_zero)
		return numerator < f.numerator;

	int new_denominator = NOK(denominator, f.denominator);
	int a_n = numerator * (new_denominator / denominator);
	int b_n = f.numerator * (new_denominator / f.denominator);

	return a_n < b_n;
}

bool Fraction::operator>=(const Fraction &f)
{
	return (*this == f || !(*this < f));
}

bool Fraction::operator>(const Fraction &f)
{
	return (*this != f && !(*this < f));
}

bool Fraction::operator<=(const Fraction &f)
{
	return (*this == f || *this < f);
}


// Создать класс Card, описывающий карту в игре БлэкДжек.У этого класса должно быть три поля : масть, 
// значение карты и положение карты(вверх лицом или рубашкой).Сделать поля масть и значение карты типом 
// перечисления(enum).Положение карты - тип bool.Также в этом классе должно быть два метода :
// метод Flip(), который переворачивает карту, т.е.если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
// метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.

class Card
{

public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

	Card(rank r = ACE, suit s = SPADES, bool ifu = true) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) { }
	int GetValue() const;
	void Flip();

	//	friend std::ostream& operator<<(std::ostream& s, const Card& aCard);
private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

int Card::GetValue() const
{
	int value = 0;
	if (m_IsFaceUp)
	{
		value = m_Rank;
		if (value > 10)
		{
			value = 10;
		}
	}
	return value;
}

void Card::Flip()
{
	m_IsFaceUp = !m_IsFaceUp;
}


int main()
{
// --------------------------------------------------------------------
// ---------------------- Task 1 --------------------------------------
// --------------------------------------------------------------------
	// задание на абстрактные классы и виртуальные функции 
	std::cout << "TASK1: abstract classes and virtual functions.." << '\n' << std::endl;
	Parallelogram paral (3.5,4.5);
	Figure *figure1 = &paral;
	figure1 -> area();

	Circle circle(2.3);
	Figure *figure2 = &circle;
	figure2 -> area();

	Restangle rest(2.5, 5.2);
	Figure *figure3 = &rest;
	figure3 -> area();

	Square square(6.625);
	Figure *figure4 = &square;
	figure4 -> area();

	Rhombus rhomb(7.77, 15.6);
	Figure *figure5 = &rhomb;
	figure5 -> area();

// --------------------------------------------------------------------
// ---------------------- Task 2 --------------------------------------
// --------------------------------------------------------------------
	std::cout << '\n' << "TASK2: multiple inheritance and diamond of death..." << '\n' << std::endl;

	std::cout << "Minivan's class object was created..." << std::endl;
	Minivan m("FBI", "VW Multivan");
	std::cout << std::endl;
	std::cout << "Bus's class object was created..." << std::endl;
	Bus bb("CDEK", "GAZ");
	std::cout << std::endl;
	std::cout << "Passenger car's class object was created..." << std::endl;
	PassengerCar cc("Russian post", "Lada Granta");
	std::cout << std::endl;
	std::cout << "Car's class object was created..." << std::endl;
	Car ccc("Goverment", "Aurus");

// --------------------------------------------------------------------
// ---------------------- Task 3 --------------------------------------
// --------------------------------------------------------------------
std::cout << '\n' << "TASK3" << '\n' << std::endl;

	Fraction a(4, 7);
	Fraction b(3, 8);
	Fraction c; // 0
	
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;



	std::cout << "[a + b] " << a << " + " << b << " = " << a + b << std::endl;
	std::cout << "[a - b] " << a << " - " << b << " = " << a - b << std::endl;
	std::cout << "[a * b] " << a << " * " << b << " = " << a * b << std::endl;
	std::cout << "[a / b] " << a << " / " << b << " = " << a / b << std::endl;
	std::cout << "[c + b] " << c << " + " << b << " = " << c + b << std::endl;
	std::cout << "[b + c] " << b << " + " << c << " = " << b + c << std::endl;
	std::cout << "[c - b] " << c << " - " << b << " = " << c - b << std::endl;
	std::cout << "[b - c] " << b << " - " << c << " = " << b - c << std::endl;
	std::cout << "[c * b] " << c << " * " << b << " = " << c * b << std::endl;
	std::cout << "[b * c] " << b << " * " << c << " = " << b * c << std::endl;
	std::cout << "[c / b] " << c << " / " << b << " = " << c / b << std::endl;
	std::cout << "[b / c] " << b << " / " << c << " = " << b / c << std::endl;
	std::cout << "-a = " << -a << std::endl;
	std::cout << "[a == b] " << a << " == " << b << " is " << ((a == b) ? "true" : "false") << std::endl;
	std::cout << "[a != b] " << a << " != " << b << " is " << ((a != b) ? "true" : "false") << std::endl;
	std::cout << "[a < b]  " << a << " < " << b << " is " << ((a < b) ? "true" : "false") << std::endl;
	std::cout << "[a <= b] " << a << " <= " << b << " is " << ((a <= b) ? "true" : "false") << std::endl;
	std::cout << "[a > b]  " << a << " > " << b << " is " << ((a > b) ? "true" : "false") << std::endl;
	std::cout << "[a >= b] " << a << " >= " << b << " is " << ((a >= b) ? "true" : "false") << std::endl;
	std::cout << "[c == a] " << c << " == " << a << " is " << ((c == a) ? "true" : "false") << std::endl;
	std::cout << "[c != a] " << c << " != " << a << " is " << ((c != a) ? "true" : "false") << std::endl;
	std::cout << "[c < a]  " << c << " < " << a << " is " << ((c < a) ? "true" : "false") << std::endl;
	std::cout << "[c <= a] " << c << " <= " << a << " is " << ((c <= a) ? "true" : "false") << std::endl;
	std::cout << "[c > a]  " << c << " > " << a << " is " << ((c > a) ? "true" : "false") << std::endl;
	std::cout << "[c >= a] " << c << " >= " << a << " is " << ((c >= a) ? "true" : "false") << std::endl;

	return 0;
}