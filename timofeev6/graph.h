
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
    char name;//имя решины
    static int counter;//количество созданных вершин(счетчик вершин)
};

class Rib {
public:
    Rib();
    ~Rib();
    int getWeight()const {
        return weight;
    };//функция не меняет содержимого полей
    Vertex *getStart()const {
        return start;
    };
    Vertex *getEnd()const {
        return end;
    };
    void setWeight(int value) {
        weight=value;
    };
    void setStart(Vertex *aStart) {
        start=aStart;
    };
    void setEnd(Vertex *aEnd) {
        end=aEnd;
    };
    void output();//ывод на экран ребра
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
    void output();//вывод графа
    int findMinWay(char fromName, char toName);//функция нахождения минимального пути
    
public:    
    int findOutRebra(Vertex *a);//находит ребра,выходящие из вершины
    int findInRebra(Vertex *a);//находит ребра, входящие в вершину
    void copyOutRebra(Graph* G); ///Выполняет копирование ребер найденных как исходящие для  вершины.

protected:
  
    int numReber;//количество ребер
    int numVersh;//количество вершин
    Rib **rebrs;//указатель на массив указателей на ребра
    Vertex **vershins;//указатель на массив указателей на вершины

protected:
    Rib **outRebra;//массив ребер,которые найдены в функции findOutRebra
    Rib **inRebra;//массив ребер,которые найдены в функции findInRebra

    int numOutReber;//количество найденых выходящих ребер
    int numInReber;//количество найденых исходящих ребер
    void addRebro(Rib *R);///<Добавляет ребро R по указателю
    bool isExist(Vertex *V);///<Проверяет присутствует-ли вершина V в графе. Возвращает: true|false - вершина найдена|не найдена среди вершин графа.
    bool isExist(Rib *R);///<Проверяет присутствует-ли ребро R в графе. Возвращает: true|false - ребро найдено|не найдено среди ребер графа.
};

class Kaima:public Graph {
public:
    Kaima();
    ~Kaima();
    void createKaima(Kaima* tree, Graph* G);//создает кайму на основе дерева tree для графа g.
    int findWay(Vertex *From,Vertex *A);//Возвращает расстояние края каймы A до вершины From (корень каймы).
    Vertex * findVershWhisMinWayFrom(Vertex *aStart);//нахождение вершины, путь до которой из начальной точки каймы будет минимальным
    void clean(){numReber=0; numVersh=0;}///Удаляет из каймы вершины и ребра, делая ее пустой.
    void copy(Kaima& K);///Выполняет копирование ребер и вершин из каймы K.
private:
    Vertex **endVershins;//Versh **vershinsассив вершин из которых не выходят ребра
    int numEndVersh;
    int ListOfEndVersh();//ищет список конечных вершин(из которых не выходит ребер)
    void addOutRebersIfNotExist();///Добавляет к канве ребра, если они не присутствуют в кайме.
};

