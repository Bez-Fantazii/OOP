#include <iostream>
#include <sstream>
#include <string>
#include <vector>


//
// 1) Создать класс Person (человек) с полями: имя, возраст, пол и вес. 
// Определить методы переназначения имени, изменения возраста и веса. 
// Создать производный класс Student (студент), имеющий поле года обучения. 
// Определить методы переназначения и увеличения этого значения. 
// Создать счетчик количества созданных студентов. В функции main() создать несколько студентов. 
// По запросу вывести определенного человека.
// 

class Student; // прототип класса

class Person 
{

protected:
    std::string m_name = "undefined"; // имя
    unsigned int m_age = 0; // возраст
    double m_weight = 0.0; // вес
    std::string m_gender = "undefined"; // пол

public:
    // Конструктор по умолчанию
    Person(std::string name, unsigned int age, std::string gender, double weight) 
        : m_name(name), m_age(age), m_gender(gender), m_weight(weight)
    {
    }

    // get-функции для:
    std::string getName() const { return m_name; } // name
    unsigned int getAge() const { return m_age; } // age
    double getWeight() const { return m_weight; } // weight
    std::string getGender() const { return m_gender; } // gender

    // set-функции для:
    void setName(std::string name) { m_name = name; } // name
    void setAge(unsigned int age) { m_age = age; } // age
    void setWeight(double weight) { m_weight = weight; } // weight

};

class Student : public Person 
{

private:
    unsigned int m_year_of_study;
    static int count;

public:
    // Конструктор по умолчанию
    Student(std::string name, unsigned int age, std::string gender, double weight, unsigned int year_of_study)
        : Person(name, age, gender, weight), m_year_of_study(year_of_study)
    {
        count++;
    }

        // get-функции для:
    unsigned int getYear() const { return m_year_of_study; } // year of study

    // set-функции для:
    void setYear(unsigned int year_of_study)  // year of study
    { 
        m_year_of_study = year_of_study;
    } 

    // set-функции для:
    void increaseYear()  // увеличение year of study
    {
        m_year_of_study++;
        m_age++; // +1 год обучения ~ +1 к годам жизни
    }

    void Print_data()
    {
        std::cout << "Student data: \n" 
            << "Name: " << m_name << "\n" << 
            "Age: " << m_age << "\n" <<
            "Gender: " << m_gender << "\n" <<
            "Weight: " << m_weight << "\n" <<
            "Year of study: " << m_year_of_study << "\n" << std::endl;
    }

    void Total_number_of_students()
    {
        std::cout << "Total quantity of students: " << count << std::endl;
    }
};

int Student::count = 0; // инициализация начального значения count

//
// 2) Создать классы Apple(яблоко) и Banana(банан), которые наследуют класс Fruit(фрукт).
// У Fruit есть две переменные - члена: name(имя) и color(цвет).
// Добавить новый класс GrannySmith, который наследует класс Apple.
//

class Fruit
{

private:
    std::string m_name;
    std::string m_color;

public:
    Fruit(std::string name, std::string color)
        : m_name(name),m_color(color)
    {
    }

    std::string getName1() const { return m_name; }
    std::string getColor() const { return m_color; }
    void setName1(std::string name) { m_name = name; }
    void setColor(std::string color) { m_color = color; }

};

class Apple : public Fruit
{

public:
    Apple(std::string color = "") : Fruit("apple", color)
    {
        if (color == "")
        {
            color = "green";
        }
        setColor(color);
    }
};

class GrannySmith : public Apple
{

public:
    GrannySmith()
    {
        setName1("Granny Smith " + Apple::getName1());
    }
};

class Banana : public Fruit
{
public:
    Banana() : Fruit("Banana", "yellow")
    {}
};



int main()
{
    setlocale(LC_ALL, "Russian");

    // --------------------------------------------------------------------
    // ---------------------- Task 1 --------------------------------------
    // --------------------------------------------------------------------
    std::cout << "TASK 1: \n" << std::endl;
    Student first("Петров", 27, "Муж", 68.5, 1);
    Student second("Пугачева", 76, "Жен", 45.1, 1);
    Student third("Березуцкий", 25, "Муж", 59.8, 2);

    third.Print_data();
    std::cout << "To increase year of study and change weigth for third student. \n" << "New data: \n" << std::endl;
    third.increaseYear();
    third.setWeight(67.1);
    third.Print_data();

    // static переменная count позволяет отследить общее количество студентов, поскольку  
    // static распространяется на все классы и функции в одном cpp файле
    first.Total_number_of_students();
    Student forth("Юрлова", 22, "Жен", 45.3, 3);
    std::cout << "New student (forth) was added." << std::endl;
    second.Total_number_of_students();
    Student fifth("Долгова", 23, "Жен", 46.2, 2);
    std::cout << "New student (fifth) was added." << std::endl;
    third.Total_number_of_students();

    // --------------------------------------------------------------------
    // ---------------------- Task 2 --------------------------------------
    // --------------------------------------------------------------------
    std::cout << "\nTASK 2: \n" << std::endl;
    Apple a("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.getName1() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName1() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName1() << " is " << c.getColor() << ".\n";

    return 0;
}