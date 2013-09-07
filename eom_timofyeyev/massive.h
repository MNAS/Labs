
class Massive {
public:
    Massive(int rows, int cols);///<создает количество строк и столбцов массиве
    ~Massive();
    int get(int i, int j);
    void set(int i, int j,int value);///<устанавливает значение value  в i-строку j-столбец
    int getRows();///<возвращает количество строк массива
    int getCols();///<возвращает количество столбцов массива
    void outputVnutr();///<внутреннее представление массива
    void outputVnesh();///<внешнее представление массива
protected:
    int *arr;///<Указатель на 1 элемент массива
    int row;///<Количество строк в массиве
    int col;///<Количество столбцов
};
