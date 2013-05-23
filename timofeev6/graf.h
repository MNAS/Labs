
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
    
public:    
    int findOutRebra(Versh *a);//находит ребра,выходящие из вершины
    int findInRebra(Versh *a);//находит ребра, входящие в вершину
    void copyOutRebra(Graf* G); ///Выполняет копирование ребер найденных как исходящие для  вершины.

protected:
  
    int numReber;//количество ребер
    int numVersh;//количество вершин
    Rebro **rebrs;//указатель на массив указателей на ребра
    Versh **vershins;//указатель на массив указателей на вершины

protected:
    Rebro **outRebra;//массив ребер,которые найдены в функции findOutRebra
    Rebro **inRebra;//массив ребер,которые найдены в функции findInRebra

    int numOutReber;//количество найденых выходящих ребер
    int numInReber;//количество найденых исходящих ребер
    void addRebro(Rebro *R);///<Добавляет ребро R по указателю
    bool isExist(Versh *V);///<Проверяет присутствует-ли вершина V в графе. Возвращает: true|false - вершина найдена|не найдена среди вершин графа.
    bool isExist(Rebro *R);///<Проверяет присутствует-ли ребро R в графе. Возвращает: true|false - ребро найдено|не найдено среди ребер графа.
};

class Kaima:public Graf {
public:
    Kaima();
    ~Kaima();
    void createKaima(Kaima* tree, Graf* G);//создает кайму на основе дерева tree для графа g.
    int findWay(Versh *From,Versh *A);//Возвращает расстояние края каймы A до вершины From (корень каймы).
    Versh * findVershWhisMinWayFrom(Versh *aStart);//нахождение вершины, путь до которой из начальной точки каймы будет минимальным
    void clean(){numReber=0; numVersh=0;}///Удаляет из каймы вершины и ребра, делая ее пустой.
    void copy(Kaima& K);///Выполняет копирование ребер и вершин из каймы K.
private:
    Versh **endVershins;//Versh **vershinsассив вершин из которых не выходят ребра
    int numEndVersh;
    int ListOfEndVersh();//ищет список конечных вершин(из которых не выходит ребер)
    void addOutRebersIfNotExist();///Добавляет к канве ребра, если они не присутствуют в кайме.
};

