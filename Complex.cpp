#include "Norm.cpp"
#include <iostream>
#include "sstream"
using namespace std;
template <class T>

class Complex : public virtual Norm<int>
{
private:
    T imagine, real;
    
public:
    Complex() {
    }
    Complex(const Complex& com) : // Конструктор копирования
        imagine(com.imagine), real(com.real)
    {
        cout << "\n То же самое, но объект создается с помощью конструктор копирования" << endl;
    }
    Complex& operator= (const Complex& com)//перегрузка оператора присваивания
    {

        imagine = com.imagine;
        real = com.real;


        return *this;
    }
    friend istream& operator>> (istream& in, Complex& com)//перегрузка оператора ввода
    {

        in >> com.imagine;
        in >> com.real;


        return in;
    }

   
    void set(T imagine, T real)
    {
        this->imagine = imagine;
        this->real = real;
        
    }

    T getImagine()
    {
        return imagine;
    }
    T getReal()
    {
        return real;
    }
    string get()
    {
       
        string str;
        ostringstream stream;
        stream << real;
        stream << ".";
        stream << imagine;
        stream << "i\n";
        str = stream.str();
        
        return str;
    }
    //override
    void absolute()
    {
        T result = sqrt(getReal() * getReal() + getImagine() * getImagine());
        cout << result << endl;
    }
    void norm()
    {
        T result = sqrt(getReal() * getReal() + getImagine() * getImagine());
        cout << result << endl;
    }
    friend ostream& operator<< (ostream& out, const Complex& comp)//перегрузк оператора вывода
    {
        out << "\n Complex Num(" << comp.real << "." << comp.imagine << "i)";

        return out;
    }

};