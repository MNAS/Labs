#include <QTextStream>
#include <QFile>
//#include <iostream>
#include <map>


int main(int argc, char **argv)
{
    std::map<QChar, int> mymap;
    std::map<QChar, double> map_fr;
    std::map<QChar, QString> map_color;
    std::map<QChar, int>::iterator it;
    std::map<QChar, double>::iterator i_map_fr;

    QTextStream cout(stdout);
    cout.setCodec("UTF-8");
    QChar ch;

    if (argc != 2)
        return 1;
    QFile in_f(argv[1]);
    if (in_f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&in_f);
        in.setCodec("UTF-8");

        while (!in.atEnd()) {
            in >> ch;
            it = mymap.find(ch);
            if (it ==  mymap.end())
                mymap[ch] = 1;
            else
                it->second++;
        }
    }
    in_f.close();

    int counter = 0;
    for (std::map<QChar, int>::iterator i = mymap.begin(); i != mymap.end(); ++i) {
        counter += i->second;
    }

    for (std::map<QChar, int>::iterator i = mymap.begin(); i != mymap.end(); ++i) {
        map_fr[i->first] = double(i->second) / double(counter);
        if (map_fr[i->first] < 0.02)
            map_color[i->first] = "\e[0;31m";
        else if (map_fr[i->first] < 0.04)
            map_color[i->first] = "\e[0;32m";
        else if (map_fr[i->first] < 0.08)
            map_color[i->first] = "\e[0;33m";
        else if (map_fr[i->first] < 0.15)
            map_color[i->first] = "\e[0;34m";
        else if (map_fr[i->first] <= 1.0)
            map_color[i->first] = "\e[0;35m";
    }


    for (std::map<QChar, int>::iterator i = mymap.begin(); i != mymap.end(); ++i) {
        cout << i->first << " " << i->second << "\n";
    }

    for (std::map<QChar, double>::iterator i = map_fr.begin(); i != map_fr.end(); ++i) {
        cout << i->first << " " << i->second  << "\n";
    }


    if (in_f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&in_f);
        in.setCodec("UTF-8");

        while (!in.atEnd()) {
            in >> ch;
            cout << map_color[ch] << ch << "\e[0m";
        }
    }
    in_f.close();

    return 0;
}
