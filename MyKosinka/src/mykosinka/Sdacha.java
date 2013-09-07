/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mykosinka;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author sakazi
 */
public class Sdacha {
    Stopka opened=new Stopka();//открытая часть
    Stopka closed=new Stopka();//закрытая часть
    
    public void output(){
        System.out.printf("Раздача.Закрытая ");
        closed.output();
        System.out.println();
                
        System.out.printf("Раздача.Открытая ");
        opened.output();
        System.out.println();
    }
            
    
}
