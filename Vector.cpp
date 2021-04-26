#include "Norm.cpp"
#include <iostream>
#include <iomanip>
using namespace std;
template <class T>
class Vector3D : public virtual Norm<int>
{
private:
    T* Coords;
    int dimensions = 3;
public:
    Vector3D()
    {
        Coords = new T[dimensions];
    }
    Vector3D(const Vector3D& vec) : //Конструктор копирования
        Coords(vec.Coords), dimensions(vec.dimensions)
    {
        cout << "\n То же самое, но объект создается с помощью конструктор копирования" << endl;
    }
    friend istream& operator>> (istream& in, Vector3D& vec)//перегрузка оператора ввода
    {

        in >> vec.Coords[0];
        in >> vec.Coords[1];
        in >> vec.Coords[2];


        return in;
    }

    Vector3D& operator= (const Vector3D& vec)//Перегруженный оператор присваивания 
    {

        Coords = vec.Coords;
        dimensions = vec.dimensions;


        return *this;
    }
    void set(T x_value, T y_value, T z_value)
    {
        Coords[0] = x_value;
        Coords[1] = y_value;
        Coords[2] = z_value;
    }
    string get()
    {
        string str;
        ostringstream stream;
        stream << Coords[0];
        stream << ";";
        stream << Coords[1];
        stream << ";";
        stream << Coords[2];
        stream << "\n";
        str = stream.str();
        return str;
    }
  
    
    void norm()
    {
        T result = 0;
        double final_result;
        for (unsigned int iterator = 0; iterator < dimensions; iterator++)
        {
            result += Coords[iterator] * Coords[iterator];
        }
        final_result = sqrt(result);
        cout << "norm of this vector is " << final_result << endl;
    }
    void absolute()
    {
        T result = 0;
        double final_result;
        for (unsigned int iterator = 0; iterator < dimensions; iterator++)
        {
            result += Coords[iterator] * Coords[iterator];
        }
        final_result = sqrt(result);
        cout << "abs of this vector is " << final_result << endl;
    }
    friend ostream& operator<< (ostream& out, const Vector3D& vec)//перегрузка оператора вывода
    {
        out << "\n Vector 3D(" << vec.Coords[0] << ";" << vec.Coords[1] << ";" << vec.Coords[2] << ")\n";

        return out;
    }
    ~Vector3D()
    {

    }
};