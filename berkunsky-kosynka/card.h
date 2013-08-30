#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

/**
 * @author namatv
 */

/*
 * A - туз, K - король, Q - дама, J - валет, T - десятка (не путать с тузом!
 * Это буква от ten, и такое обозначение принято,
 * чтобы сохранить по одному символу для обозначения всех карт).
 * Далее 9-2 - остальные карты.
 * Масти обозначаются по первой букве их английских названий:
 * s - пики;
 * c - трефы;
 * d - бубны;
 * h - червы.
 * Например, Ts - десятка пик.
*/

class Card 
{
private:
    int mast;			///< Масть. 1 - s пика; 2 c - крестья; 3 - d бубна; 4 - h черва.
    int starshinstvo;		///< Старшинство карт 1 - туз; 2 - двойка; ... ; 12 - дама; 13 - король.
    int sostoyanie;		///< 0 - рубашкой вверх; 1 - лицом вверх.
public:    
    static int numMast;		///< Количество мастей;
    static int numStarsh;	///< Количество значений карт;

    Card();
    Card(int mast, int starshinstvo, int sostoyanie=0);
    Card(const std::string &s);
    
    bool operator==(const Card &c) const;

    bool isBlack() const;	///<Возвращает true если масть является черной;
    bool isRed() const;		///<Возвращает true если масть является красной;
    void setMast(int mast);
    void setStarshinstvo(int starshinstvo);
    void setSostoyanie(int sostoyanie);
    int getMast() const;
    int getStarshinstvo() const;
    int getSostoyanie() const;

    std::string name() const;
    std::string toString() const ;
    
private:
    friend std::ostream& operator<<(std::ostream & os, const Card & C);
};

void faceToUp (Card *c);	///<Выполняет пепеворот карты лицом вверх.
void faceToDown (Card *c);	///<Выполняет переворот карты рубашкой вверх.
void toStream(Card *c);		///<Вывод в поток.

#endif // CARD_H
