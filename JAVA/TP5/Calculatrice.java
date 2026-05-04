import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Array;
import java.sql.Date;
import java.sql.Time;
import java.time.Instant;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.InputMismatchException;
import java.util.Scanner;
public class Calculatrice {
    private ArrayList<String> logs;
    public Calculatrice()
    {
        this.logs=new ArrayList<String>();
    }
    

    public double sasieNombre(Scanner sc)
    {
        System.out.println("veuillez sasir un nombre");
        
        double in =sc.nextDouble();
        
        return in;


    }
    public String saisieOperation(Scanner sc)
    {
        System.out.println("veuillez sasir une operation");
        return sc.next();
    }
    public double lancementCalcul(Scanner sc)
    {
        double nb1=0;
        boolean ok=false;
        while (!ok) {
            
        
            try {nb1=sasieNombre(sc);
                ok=true;
                
            } catch (InputMismatchException  e) {
                System.err.println("une chaine de caractère a été inscrite");
                sc.next();
            }
                
                
        }
        
        String[] valide={"+","-","*","/"};
        String operateur="";
        ok= false;
        while (!ok) {
            
            try{
                 operateur =saisieOperation(sc);
                if (!operateur.equals(valide[0]) && !operateur.equals(valide[1]) && !operateur.equals(valide[2]) && !operateur.equals(valide[3])) {
                    if (operateur.equals("sauvegarde")) {
                        sauvegarder();
                    }
                    throw new OperationException("l'operateur n'est pas valide");
                }
                else ok=true;
            }
            catch(Exception e){
                System.err.println("l'operateur n'est pas valide");
            }
        
        }
        double nb2=0;
        ok=false;
        while (!ok) {
            
        
            try {nb2=sasieNombre(sc);
                ok=true;
                
            } catch (InputMismatchException  e) {
                System.err.println("une chaine de caractère a été inscrite");
                sc.next();
            }
                
                
        }
        logs.add(nb1 + operateur + nb2 + " "+ Date.from(Instant.now()));
        if (operateur.equals("+")) {
            return nb1+nb2;
        }
        if (operateur.equals("-")) {
            return nb1-nb2;
        }
        if (operateur.equals("*")) {
            return nb1*nb2;
        }
        if (operateur.equals("/")) {
            return nb1/nb2;
        }
        return 0;
        
    }
    public void sauvegarder()
    {
        System.out.println("sauvegarde en cours");
        FileWriter w=null;
        try{
            w=new FileWriter("log.txt");
            for (String log : logs) {
                System.out.println();
            
                w.write(log+"\n");
            }
            w.close();
        }
        catch(IOException e){
            System.err.println("skill issue");
        }
        
            
        
        
        
    }
}