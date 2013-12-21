#include <iostream>



class key;

class vector
{
private:
    int v[3];
public:
    friend key;
    vector();
    ~vector();
    void output(std::ostream& os);
    void mod(int n);//возвращает вектор остатков от деления на н
    void setVector(int i, int a);//заносится в и-тую позицию значение шифруемого символа
    int getSymb(int i);//извлекается значение итого символа из вектора
};


class key
{

private:
    int arr[3][3];
public:
    key();
    key(int a);
    ~key();
    int keySize() {
        return 3;
    }
    vector mult(vector p);//умножение ключа К на вектор P
    void output(std::ostream& os);
    void input(std::istream& is);
};

