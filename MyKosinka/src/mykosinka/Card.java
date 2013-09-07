/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mykosinka;

/**
 *
 * @author sakazi
 */
public class Card {
    private int mast;
    private int starshinstvo;
    private int sostoyanie;//перевернута или нет
    public static int numMast=4;//количество мастей
    public static int numStarsh=13;//количество значений карт

    Card() {
        this.mast = 2;
        this.starshinstvo = 6;
        this.sostoyanie = 1;
    }

    public boolean isBlack(){
        if(getMast()<2)
            return true;
        return false;
    }
    
     public boolean isRed(){
        return !isBlack();
    }

    public void setMast(int mast) {
        this.mast = mast;
    }

    public void setStarshinstvo(int starshinstvo) {
        this.starshinstvo = starshinstvo;
    }

    public void setSostoyanie(int sostoyanie) {
        this.sostoyanie = sostoyanie;
    }
    

    public int getMast() {
        return mast;
    }

    public int getStarshinstvo() {
        return starshinstvo;
    }

    public int getSostoyanie() {
        return sostoyanie;
    }


    

    public Card(int mast, int starshinstvo, int sostoyanie) {
        this.mast = mast;
        this.starshinstvo = starshinstvo;
        this.sostoyanie = sostoyanie;
    }
    
    public void output(){
/*       
        System.out.printf("% d ",getMast());
        System.out.printf(" %d ",getStarshinstvo());
        System.out.printf(" %d ", getSostoyanie());
        System.out.println();
 */
        
        if(getSostoyanie()==0)
        {
            System.out.printf("[]");
            return;
        }

        System.out.print(name());
        
    }
    
    public String name(){
        String m = null;//mast
        String s=null;//starshinstvo
        
        switch(getStarshinstvo()){
            case 12: s="К";break;
            case 11: s="Д";break;
            case 10: s="В";break;
            case 9:  s="Т";break;
            default:  s=Integer.toString(getStarshinstvo()+1);break;
        }
        switch(getMast()){
            case 0: m="п";break;
            case 1: m="т";break;
            case 2: m="б";break;
            case 3: m="ч";break;
            default:  System.out.printf("Fault");break;
        }
        return s+m;
        
    }

    @Override
    public String toString() {
        return "Card{" + "mast=" + mast + ", starshinstvo=" + starshinstvo + ", sostoyanie=" + sostoyanie + '}';
    }
        
}
