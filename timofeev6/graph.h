
class Vertex {
public:
    Vertex();
    ~Vertex();
    void setName(char aName) {
        name=aName;
    };//функция задает имя вершине
    void output();//вывод на экран вершины
    char getName() {
        return name;
    };
    int getIndex() {
        return index;
    };
private:
    int index;//уникальный идентификатор вершины
    char name;//имя вершины
    static int counter;//количество созданных вершин(счетчик вершин)
};

class Rib {
public:
    Rib();
    ~Rib();
    int getWeight()const {return weight;}//функция не меняет содержимого полей
    Vertex *getStart()const {return start;}
    Vertex *getEnd()const {return end;}
    void setWeight(int value) {weight=value;}
    void setStart(Vertex *aStart) {start=aStart;}
    void setEnd(Vertex *aEnd) {end=aEnd;}
    void output();//Вывод на экран ребра
private:
    int weight;//вес ребра
    Vertex *start;//начало ребра
    Vertex *end;//конец ребра
};

class Kaima;

class Graph {
public:
    Graph();
    ~Graph();
    void addRebro(Vertex *aStart, Vertex *aEnd, int aWeight);//добавление ребра
    void addVersh(char aName);//добавление вершины
    void addVersh(Vertex *a);//добавление вершины по указателю
    Vertex *findVershByName(char aName);//поиск вершины по имени
    virtual void output();//вывод графа
    int findMinWay(char fromName, char toName);//функция нахождения минимального пути

public:
    int findOutRebra(Vertex *a);//находит ребра,выходящие из вершины
    int findInRebra(Vertex *a);//находит ребра, входящие в вершину
    

protected:

    int numReber;//количество ребер
    int numVersh;//количество вершин
    Rib **rebrs;//указатель на массив указателей на ребра
    Vertex **vershins;//указатель на массив указателей на вершины

protected:
    friend Kaima;
    Rib **outRebra;//массив ребер,которые найдены в функции findOutRebra
    Rib **inRebra;//массив ребер,которые найдены в функции findInRebra

    int numOutReber;//количество найденых выходящих ребер
    int numInReber;//количество найденых исходящих ребер
    void addRebro(Rib *R);///<Добавляет ребро R по указателю
    bool isExist(Vertex *V);///<Проверяет присутствует-ли вершина V в графе. Возвращает: true|false - вершина найдена|не найдена среди вершин графа.
    bool isExist(Rib *R);///<Проверяет присутствует-ли ребро R в графе. Возвращает: true|false - ребро найдено|не найдено среди ребер графа.
    int  index(Vertex *V);
    int  index(Rib *R);
};

/**Класс Kaima предназначен для выполнения поиска кратчайшего пути на графе.
 * Класс состоит из
 * 1) наследуемых от Graph массивов вершин и ребер (граф), которые прочно
 * присоединены к дереву поиска;
 * 2) каймы (массива вершин, ребер, и длин путей вопрос о присоендинении
 * которых к дереву поиска рассматривается в ходе решения задачи на каждом
 * шаге поиска.)
 */
class Kaima:public Graph {
public:
    Kaima();
    ~Kaima();
    void initKaima(Vertex* V, Graph* G);//Cоздает кайму(инициализация начала поиска). Добавление к дереву единственной вершины, присутствующей в графе G. Присоединение каймы.
    void output();
    int findWay(Vertex *From,Vertex *A);//Возвращает расстояние края каймы A до вершины From (корень каймы).
    int findVershWhisMinWayFrom();//Нахождение индекса вершины, ребра и длины маршрута, путь до которой из начальной точки дерева будет минимальным.
    
    void add(int index, Graph * G);///Присоединение ребра и вершины каймы к дереву.    
private:
    int *lenPathTree;//Массив длин путей до вершин дерева.

    Vertex **kajmaVertexes;//Массив вершин каймы.
    Rib **kajmaRibs;//Массив ребер каймы.
    int *kajmaLenPath;//Массив длин путей до вершин каймы.
    int num ;//Количество вершин, ребер и элементов длин путей в кайме.
};

