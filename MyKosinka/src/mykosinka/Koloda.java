/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mykosinka;

import mykosinka.Card;
import java.util.Random;
/**
 *
 * @author sakazi
 */
public class Koloda {
    int N=52;
    private Card [] koloda= new Card[N];

    public Koloda() {
       fillKoloda();
    }

    public int getN() {
        return N;
    }

    public Card[] getKoloda() {
        return koloda;
    }
    

    public void fillKoloda(){
        
    int c=0;
    for(int i=0;i<Card.numMast;++i){
      for(int j=0;j<Card.numStarsh;++j){
          Card a=new Card(i,j,0);
          koloda[c++]=a;
      }
    }
}
    
    public void peretosovat(){
        int a,b;//промежуточные переменные,содержащие случайные числа
        Card c=null;
        for(int i=0;i<100;++i){
            a=(int) (Math.random()*1000)%52;
            b=(int) (Math.random()*1000)%52;
            c=koloda[a];
            koloda[a]=koloda[b];
            koloda[b]=c;
//            System.out.printf("a=%d b=%d",a,b);
        }
    }
    
    public void output(){
        for(int i=0;i<N;++i){
            System.out.printf(" %d ",i);
            koloda[i].output();
           

        }
            
    }
   
}
