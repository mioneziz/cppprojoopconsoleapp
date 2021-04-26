#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "Complex.cpp"
#include "Vector.cpp"
#include "vector"
#include "Norm.cpp"
#include<algorithm>
using namespace std;
//void readFile(vector<Norm<int>> arr);
Norm<int>* readLine(string line) {
    stringstream jaja;
    string className;
    Norm<int>* norm = new Complex<int>;
    jaja << line;
    jaja >> className;
    if (className == "Complex")
    {
        int a, b;
        jaja >> a;
        jaja >> b;
        norm = new Complex<int>;
        norm->set(a, b);
    }
    if (className == "Vector")
    {
        int a, b, c;
        jaja >> a;
        jaja >> b;
        jaja >> c;
        norm = new Vector3D<int>;
        norm->set(a, b, c);
    }
    return norm;

}
int main()
{
    
    setlocale(LC_ALL, "Russian");
    cout << "Чтение из файла\n";
    vector<Norm<int>*> arr;
    ifstream in("D:\\text.txt");
    string line;
  
    if (in.is_open())
    {
        while (getline(in, line))
            arr.push_back(readLine(line));
        
    }

    in.close();
    for (int i=0;i<arr.size();i++)
    {
        cout << arr[i]->get();
        
    }
    
    Complex<int> complex;//Создаём объект комплексного числа 
    cout << "\n Нахождение нормы и модуля комплексного числа" << endl;
    complex.set(3,4);//С помощью сеттеров методов устанавливаем значения полей комплексного числа
    complex.absolute();//методы для определения модуля и нормы комплексного числа
    complex.norm();
    Complex<int> comp(complex);//вызов конструктора копирования повторяем действия сделанные выше только с объектом,сделанным с помошью переопределенного конструктора копирования
    comp.absolute();
    comp.norm();
    Complex<int> com;
    com = complex;//Перегруженный оператор присваивания
    cout << "\n То же самое,но теперь с помощью перегруженного оператора присваивания" << endl;
    com.norm();
    com.absolute();
    cout << "\n Нахождение нормы и модуля вектора" << endl;
    Vector3D<int> vector3D;//создаём объект вектора
    vector3D.set(2,4,5);//с помощью сеттеров устанавливаем значения полей
    vector3D.norm();//методы для определения модуля и нормы вектора
    vector3D.absolute();
    Vector3D<int> vect3D(vector3D);//вызов конструктора копирования повторяем действия сделанные выше только с объектом,сделанным с помошью переопределенного конструктора копирования
    vector3D.norm();
    vector3D.absolute();
    Vector3D<int> vec;
    vec = vector3D;//Перегруженный оператор присваивания
    cout << "\n То же самое,но теперь с помощью перегруженного оператора присваивания" << endl;
    vec.norm();
    vec.absolute();
    cout << complex;// Перегрузка оператора вывода
    cout << vector3D;
    Vector3D<int> jaja;
    cin >> jaja;
    jaja.absolute();
    jaja.norm();
    system("pause");
       return 0;
}
/*void readFile()
{
    ifstream in("D:\text.txt");
    string line;
    if (in.is_open())
    {
        while (getline(in, line))
            arr.push_back(readLine(line));
    }
    in.close();

}*/




/**/