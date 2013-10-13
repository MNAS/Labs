#include <QTextStream>//qt нужен для работы с многобайтовыми символами,потому что русские
#include <QFile>
#include <QString>
//#include <iostream>
#include <map>


int main(int argc, char **argv)
{
    std::map<QChar, int> mymap;
    std::map<QChar, double> map_fr;
    std::map<QChar, QString> map_color;
    std::map<QChar, int>::iterator it;
    std::map<QChar, double>::iterator it_color;
	
	QString abc=QString::fromUtf8("абвгдеёжзийклмнопрстуфхцчшщьыъэюя");
	for(int i=0;i<abc.size();++i)//переписали все русские буквы в маймэп
	{
		mymap[abc[i]]=0;//их частота в начале равна 0
	}

    QTextStream cout(stdout);//создание текстового вывода в стандартный поток вывода.нужен для вывода русскоязычных символов
    cout.setCodec("UTF-8");//символы преобразуются в кодировку UTF-8
    QChar ch;//многобайтовыйф символ


    if (argc != 2)
        return 1;
    QFile in_f(argv[1]);//второй параметр - имя файла.создали файл,но он еще не открыт
    if (in_f.open(QIODevice::ReadOnly | QIODevice::Text)) {//открытие файла в режиме только для чтение.инфо содержится не в двоичном,а в текстовом виде
        QTextStream in(&in_f);//подсоединение файла к текстовому потоку(новому)
        in.setCodec("UTF-8");

        while (!in.atEnd()) {//пока не дошло до конца файла
            in >> ch;//из потока считывается по букве в переменную ч
			ch=ch.toLower();//преобразование символа в нижний регистр
            it = mymap.find(ch);//находит симфол в ассоц.массиве и заночит его индекс в итератор ит
            if (it !=  mymap.end())//если нашло букву в массиве,то  
                it->second++;//second - второе значение в ассоц.массиве
        }
    }
    in_f.close();//закрыли файл

    int counter = 0;
	//проход по всему ассоц.массиву маймэп и считает кол-во букв
    for (std::map<QChar, int>::iterator i = mymap.begin(); i != mymap.end(); ++i) {
        counter += i->second;
    }

    for (std::map<QChar, int>::iterator i = mymap.begin(); i != mymap.end(); ++i) {
        map_fr[i->first] = double(i->second) / double(counter);//определяем частоту каждой буквы и переписываем в мэп_фр
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


    /*for (std::map<QChar, int>::iterator i = mymap.begin(); i != mymap.end(); ++i) {
        cout << i->first << " " << i->second << "\n";
    }

    for (std::map<QChar, double>::iterator i = map_fr.begin(); i != map_fr.end(); ++i) {
        cout << i->first << " " << i->second  << "\n";
    }*/

	
    if (in_f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&in_f);
        in.setCodec("UTF-8");

        while (!in.atEnd()) {
            in >> ch;
			QChar copyCh=ch.toLower();
			it_color = map_color.find(copyCh);//находит симфол в ассоц.массиве и заночит его индекс в итератор ит
            if (it_color != map_color.end())//если нашло букву в массиве,то  
				cout << map_color[ch] << ch << "\e[0m";
			else
				cout << ch << "\e[0m";
        }
    }
    in_f.close();

    return 0;
}
