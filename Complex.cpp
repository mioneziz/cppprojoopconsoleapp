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
    Complex(const Complex& com) : // ����������� �����������
        imagine(com.imagine), real(com.real)
    {
        cout << "\n �� �� �����, �� ������ ��������� � ������� ����������� �����������" << endl;
    }
    Complex& operator= (const Complex& com)//���������� ��������� ������������
    {

        imagine = com.imagine;
        real = com.real;


        return *this;
    }
    friend istream& operator>> (istream& in, Complex& com)//���������� ��������� �����
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
    friend ostream& operator<< (ostream& out, const Complex& comp)//��������� ��������� ������
    {
        out << "\n Complex Num(" << comp.real << "." << comp.imagine << "i)";

        return out;
    }

};