
class Versh {
public:
    Versh();
    ~Versh();
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

class Rebro {
public:
    Rebro();
    ~Rebro();
    int getWeight()const {
        return weight;
    };//функция не меняет содержимого полей
    Versh *getStart()const {
        return start;
    };
    Versh *getEnd()const {
        return end;
    };
    void setWeight(int value) {
        weight=value;
    };
    void setStart(Versh *aStart) {
        start=aStart;
    };
    void setEnd(Versh *aEnd) {
        end=aEnd;
    };
    void output();//ывод на экран ребра
private:
    int weight;//вес ребра
    Versh *start;//начало ребра
    Versh *end;//конец ребра
};

class Kaima;

class Graf {
public:
    Graf();
    ~Graf();
    void addRebro(Versh *aStart, Versh *aEnd, int aWeight);//добавление ребра
    void addVersh(char aName);//добавление вершины
    void addVersh(Versh *a);//добавление вершины по указателю
    Versh *findVershByName(char aName);//поиск вершины по имени
    void output();//вывод графа
    int findMinWay(char fromName, char toName);//функция нахождения минимального пути

protected:
    int numReber;//количество ребер
    int numVersh;//количество вершин
    Rebro **rebrs;//указатель на массив указателей на ребра
    Versh **vershins;//указатель на массив указателей на вершины

    int findOutRebra(Versh *a);//находит ребра,выходящие из вершины
    int findInRebra(Versh *a);//находит ребра, входящие в вершину

private:
    Rebro **outRebra;//массив ребер,которые найдены в функции findOutRebra
    Rebro **inRebra;//массив ребер,которые найдены в функции findInRebra

    int numOutReber;//количество найденых выходящих ребер
    int numInReber;//количество найденых исходящих ребер
    void addRebro(Rebro *a);//добавление ребра по указателю
    bool isExist(Versh *a);//проверяет есть ли вершина в графе
};

class Kaima:public Graf {
public:
    Kaima();
    ~Kaima();
    void createKaima(Kaima *tree, Graf *g);//создает кайму на основе дерева tree для графа g.
    int findWay(Versh *from,Versh *a);//ищет расстояние от любого края каймы до начальной вершины(a - любая вершина)
    Versh *findMinWayToVersh(Versh *aStart);//нахождение вершины, путь до которой из начальной точки каймы будет минимальным
private:
    Versh **endVershins;//Versh **vershinsассив вершин из которых не выходят ребра
    int numEndVersh;
    int ListOfEndVersh();//ищет список конечных вершин(из которых не выходит ребер)
};

