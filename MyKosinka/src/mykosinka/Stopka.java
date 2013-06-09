/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mykosinka;

import java.util.ArrayList;
import java.util.List;
/*
 *
 * @author sakazi
 */
public class Stopka {
    
    List <Card> stopka=new ArrayList<>();
    public static int numStopok=7;//количество стопок
    
    
    private void StopkaStopka(){
        
    }
    
    private void StopkaDom(){
        
    }
    
    public void output(){
        int size = stopka.size();
        for(int i=0;i<size;++i){
            stopka.get(i).output();
            System.out.printf(" ");
        }
        System.out.println();
     }
    public void openLastCard(){
        if(stopka.isEmpty()) return;
        stopka.get(stopka.size()-1).setSostoyanie(1);
    }
    
    public Card getLastCard(){
        if(stopka.isEmpty()) return null;
        return stopka.get(stopka.size()-1);
    }
    
    public Card getFirstCard(){
        if(stopka.isEmpty()) return null;
        return stopka.get(0);
    }
    
    public void closeCards(){
        int size=stopka.size();
        for(int i=0;i<size;++i) 
            stopka.get(i).setSostoyanie(0);
    }
}
