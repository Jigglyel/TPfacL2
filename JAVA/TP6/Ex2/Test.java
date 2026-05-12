import java.util.ArrayList;

public class Test {
    public static void main(String[] args) {
    
        IOFormeBinaire texte=new IOFormeBinaire();
        ArrayList<Forme> formes=new ArrayList<Forme>();
        formes.add(new Rectangle(5, 4, 12, 6));
        formes.add(new Cercle(4, 6, 48));
        try {
            texte.sauver(formes, "raclette.txt");
            
            for(Forme forme : texte.lire("raclette.txt"))
            {
                System.out.println(forme.toString());
            }
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
        
    }
}
