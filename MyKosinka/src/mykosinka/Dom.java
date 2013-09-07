/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mykosinka;

/**
 *
 * @author sakazi
 */
public class Dom {
    Stopka A=new Stopka();
    Stopka B=new Stopka();
    Stopka C=new Stopka();
    Stopka D=new Stopka();
    
    public void output(){
        System.out.println("\nДом");
        if(A.stopka.isEmpty()) System.out.println("--");
        else A.output();
        
        if(B.stopka.isEmpty()) System.out.println("--");
        else B.output();
        
        if(C.stopka.isEmpty()) System.out.println("--");
        else C.output();
        
        if(D.stopka.isEmpty()) System.out.println("--");
        else D.output();
        
        System.out.println();
    }
}
