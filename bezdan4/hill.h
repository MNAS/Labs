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
    void mod(int n);//���������� ������ �������� �� ������� �� �
    void setVector(int i, int a);//��������� � �-��� ������� �������� ���������� �������
    int getSymb(int i);//����������� �������� ����� ������� �� �������
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
    vector mult(vector p);//��������� ����� � �� ������ P
    void output(std::ostream& os);
    void input(std::istream& is);
};

