/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mykosinka;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import mykosinka.Stopka;
import mykosinka.Koloda;
import mykosinka.StructFind;

/**
 *
 * @author sakazi
 */
public class Stol {
    int N=7;
    Koloda k=new Koloda();
    
    
    Dom dom=new Dom();
    Sdacha sd=new Sdacha();
    List <Stopka> stopki=new ArrayList<>();
    Stopka selected=new Stopka();//перетаскиваемые карты
    
    public Stol() {
        k.peretosovat();
        int kolN=0;//
        for (int i=0; i<N ;++i){
            Stopka s=new Stopka();
            stopki.add(s);
            for(int j=0;j<=i;++j)
            {
                stopki.get(i).stopka.add(k.getKoloda()[kolN++]);
            }
            stopki.get(i).openLastCard();
        }
        sd.opened.stopka.add(k.getKoloda()[kolN++]);//Добавление в открытую часть сдачи карт.
        sd.opened.openLastCard();
        while(kolN<k.getN()){
            sd.closed.stopka.add(k.getKoloda()[kolN++]);//Добавление в склытую часть сдачи карт.
        }
    }
    
    public void output(){
        int sdClosedSize = sd.closed.stopka.size();
        int sdOpenedSize = sd.opened.stopka.size();
        
        System.out.printf("Стол");
        System.out.println();
        sd.output();
        
        int size = stopki.size();
        System.out.printf("Стол.Стопки\n");
        for (int i=0;i<size;i++){
            System.out.printf("Стопка %d ",i);
            stopki.get(i).output();
        }
        dom.output();
    }
    public void moveStopkaDom(int s){
        Stopka stDom = null;
        
        Card cd=stopki.get(s).getLastCard();
        if(cd==null) return;
        else{
            switch(cd.getMast()){
                case 0: stDom=dom.A; break;
                case 1: stDom=dom.B; break;
                case 2: stDom=dom.C; break;
                case 3: stDom=dom.D; break;
            }
            Card a=stDom.getLastCard();
            if( (a==null && cd.getStarshinstvo()==0) || 
                    (cd.getStarshinstvo()-a.getStarshinstvo()==1)){
                stopki.get(s).stopka.remove(cd);
                stDom.stopka.add(cd);
                stopki.get(s).openLastCard();
            }
                
        }
    }
    
    /*
     * Перемещение масти mast из дома в стопку s.
     */
    public void moveDomStopka(int mast, int s ){
        Card cd=null;
        Stopka a=null;
        switch(mast){
            case 0:a=dom.A;break;
            case 1:a=dom.B;break;
            case 2:a=dom.C;break;
            case 3:a=dom.D;break;
        }
        if(a!=null)
        {
            cd=a.getLastCard();
            if(cd!=null)
                a.stopka.remove(cd);
                stopki.get(s).stopka.add(cd);
        }
        
    }
    /*
     * Перемещение из количества карт num из стопки sFrom в стопку sTo.
     */
    
    public void moveStopkaStopka(int sFrom, int sTo, int num ){
        
        Card cd=stopki.get(sFrom).stopka.get(stopki.get(sFrom).stopka.size()-num);//snimaem num ot kraya kart
        if(cd==null || cd.getSostoyanie()==0)
                return;
        Card a=stopki.get(sTo).getLastCard();//karta iz stopki 2
        
        if((a==null && cd.getStarshinstvo()==12) 
                || (a!=null && a.isBlack()!=cd.isBlack() && 
                 a.getStarshinstvo()-cd.getStarshinstvo()==1))
        {
            int iFrom=stopki.get(sFrom).stopka.size()-num;
             int iTo=stopki.get(sFrom).stopka.size();
            
            
            List<Card> subList = stopki.get(sFrom).stopka.subList(iFrom,iTo);

            stopki.get(sTo).stopka.addAll(subList);
            
            stopki.get(sFrom).stopka.removeAll(subList);
            stopki.get(sFrom).openLastCard();
        }
    }
    
    public void moveRazdachaStopka(int sTo){
        
        Card cd=sd.opened.getLastCard();//karta iz razdachi
        if(cd==null) return;
        Card a=stopki.get(sTo).getLastCard();//karta iz stopki
        if((a==null && cd.getStarshinstvo()==12) 
                ||(a!=null && a.isBlack()!=cd.isBlack() && a.getStarshinstvo()-cd.getStarshinstvo()==1))
        {
            sd.opened.stopka.remove(cd);
            stopki.get(sTo).stopka.add(cd);
            
        }
            
    }
   

    
    public void moveRazdachaDom(){
        Stopka stDom = null;
        
        Card cd=sd.opened.getLastCard();
        if(cd==null) return;
        else{
            switch(cd.getMast()){
                case 0: stDom=dom.A; break;
                case 1: stDom=dom.B; break;
                case 2: stDom=dom.C; break;
                case 3: stDom=dom.D; break;
            }
            Card a=stDom.getLastCard();
            if( (a==null && cd.getStarshinstvo()==0) || 
                    (cd.getStarshinstvo()-a.getStarshinstvo()==1)){
                sd.opened.stopka.remove(cd);
                stDom.stopka.add(cd);
            }    
        }
    }
    
    /*
     * Перемещение одной карты из закрытой части раздачи в открытую часть раздачи.
     */
    

public void openNext(){
        Card cd=sd.closed.getFirstCard();
        if(cd == null)
        {
            sd.closed.stopka.addAll(sd.opened.stopka); 
            sd.opened.stopka.clear();
            sd.closed.closeCards();
        }
        else
        {
            sd.closed.stopka.remove(cd);
            sd.opened.stopka.add(cd);
            cd.setSostoyanie(1);
        }
        
    }



public StructFind findByName(String name){
    StructFind f=new StructFind();
    if(name.equals("0") || name.equals("1") || name.equals("2") ||
            name.equals("3") || name.equals("4") || name.equals("5") || name.equals("6") ||
            name.equals("7") || name.equals("8") || name.equals("9") || name.equals("10"))
    {
        f.indOfStopka=Integer.parseInt(name);
        f.indOfCard=0;
        f.numCards=0;
        return f;
    }
    Card a=null;
    int ind=0;
    for(int i=0;i<k.getN();++i){
        if(k.getKoloda()[i].name().equals(name))
        {
            a=k.getKoloda()[i];
            break;
        }
    }
    for(int i=0;i<stopki.size();++i){
        ind=stopki.get(i).stopka.indexOf(a);//nahodit index zadanoy karti po imeni v kolode
        if(ind!=-1 && a.getSostoyanie()!=0)
        {
            f.indOfStopka=i;
            f.indOfCard=ind;
            f.numCards=stopki.get(i).stopka.size()-f.indOfCard;
            return f;
        }
     }
     if(sd.opened.getLastCard()!=null && sd.opened.getLastCard().name().equals(name)){
         f.indOfStopka=11;
         f.indOfCard=sd.opened.stopka.size()-1;
         f.numCards=1;
         return f;
     }
     if(dom.A.getLastCard()!=null && dom.A.getLastCard().name().equals(name)){
         f.indOfStopka=7;
         f.indOfCard=dom.A.stopka.size()-1;
         f.numCards=1;
         return f;
     }
     if(dom.B.getLastCard()!=null && dom.B.getLastCard().name().equals(name)){
         f.indOfStopka=8;
         f.indOfCard=dom.B.stopka.size()-1;
         f.numCards=1;
         return f;
     }
     if(dom.C.getLastCard()!=null && dom.C.getLastCard().name().equals(name)){
         f.indOfStopka=9;
         f.indOfCard=dom.C.stopka.size()-1;
         f.numCards=1;
         return f;
     }
     if(dom.D.getLastCard()!=null && dom.D.getLastCard().name().equals(name)){
         f.indOfStopka=10;
         f.indOfCard=dom.D.stopka.size()-1;
         f.numCards=1;
         return f;
     }
    return null;  
}


    public void loop(){
        boolean exit=true;
        Scanner scan= new Scanner(System.in);
        while(exit){
            output();
            System.out.println("Menu:\n0 - Exit;");
            System.out.println("1 - Next Card;");
            System.out.println("2 [Из_стопки] [В_стопку] [К-во_карт]");
            System.out.println("3 [Из_стопки] - из стопки в дом");
            System.out.println("4 [Из_дома_масть] [В_стопку номер] - из дома в стопку");
            System.out.println("5 [В_стопку номер] - из раздачи в стопку");
            System.out.println("6 - из раздачи в дом");
            
            String a=scan.nextLine();
            if(a.equals("0"))
                exit=false;
            else if(a.equals("1"))
                openNext();
            else if(a.equals("3"))
            {
                int sForm=scan.nextInt();
               moveStopkaDom(sForm);
            }
            else if(a.equals("6"))
               moveRazdachaDom();
            else if(a.equals("5")){
                int sTo=scan.nextInt();
               moveRazdachaStopka(sTo);
            }
            
            else if(a.equals("2")){
                int sFrom=scan.nextInt();
                int sTo=scan.nextInt();
                int num=scan.nextInt();
               moveStopkaStopka(sFrom,sTo,num);
            }
        }
    }
    
    public void loop1(){
        StructFind sFrom=null;
        StructFind sTo=null;
        boolean exit=true;
        Scanner scan= new Scanner(System.in);
        while(exit){
            output();
            System.out.println("Menu:\nExit - Exit from program;");
            System.out.println("N - Next Card;");
            System.out.println("From  To - из в. Из мб - Дом;");
            
            String from = null;
            String to = null;
            String a=scan.nextLine();
            String[] split = a.split(" ");
             System.out.println(a);
            if(split.length==1){
                from=split[0];
                 sFrom=findByName(from);
            }
            else if(split.length==2){
                from=split[0];
                to=split[1];
            sFrom=findByName(from);
            sTo=findByName(to);
            }


            
            if(from.equals("выход"))
               exit=false;
            else if(to!=null && to.equals("0")&& sFrom!=null && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
                moveStopkaStopka(sFrom.indOfStopka, 0, sFrom.numCards);
            else if(to!=null && to.equals("1")&& sFrom!=null && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
                moveStopkaStopka(sFrom.indOfStopka, 1, sFrom.numCards);
            else if(to!=null && to.equals("2")&& sFrom!=null && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
                moveStopkaStopka(sFrom.indOfStopka, 2, sFrom.numCards);
            else if(to!=null && to.equals("3")&& sFrom!=null && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
                moveStopkaStopka(sFrom.indOfStopka, 3, sFrom.numCards);
            else if(to!=null && to.equals("4")&& sFrom!=null && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
                moveStopkaStopka(sFrom.indOfStopka, 4, sFrom.numCards);
            else if(to!=null && to.equals("5")&& sFrom!=null && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
                moveStopkaStopka(sFrom.indOfStopka, 5, sFrom.numCards);
            else if(to!=null && to.equals("6")&& sFrom!=null && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
                moveStopkaStopka(sFrom.indOfStopka, 6, sFrom.numCards);
               
            else if(from.equals("н"))
                openNext();
            
            else if(sTo!=null && sFrom!=null && (sTo.indOfStopka>=0 && sTo.indOfStopka<7) && sFrom.indOfStopka==11){
                moveRazdachaStopka(sTo.indOfStopka);
            }
            else 
            if(sTo!=null && sFrom!=null && (sTo.indOfStopka>=0 && sTo.indOfStopka<7) && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7)){
                moveStopkaStopka(sFrom.indOfStopka, sTo.indOfStopka, sFrom.numCards);
            }
            else
            if(sFrom!=null &&(sFrom.indOfStopka>=0 && sFrom.indOfStopka<7) && to.equals("дом")){
                moveStopkaDom(sFrom.indOfStopka);
            }
            else
            if(sFrom!=null && sFrom.indOfStopka==11  && to.equals("дом")){
                moveRazdachaDom();
            }
            else
            if(sTo!=null && sFrom!=null && (sTo.indOfStopka>=0 && sTo.indOfStopka<7)  && (sFrom.indOfStopka>=7 && sFrom.indOfStopka<=10)){
                moveDomStopka(sFrom.indOfStopka-7, sTo.indOfStopka);
            }


        }
    }
}
