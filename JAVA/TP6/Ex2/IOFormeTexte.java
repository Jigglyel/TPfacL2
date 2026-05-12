import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;

public class IOFormeTexte implements IOForme {

    @Override
    public Collection<Forme> lire(String filename) throws IOException {
        Collection<Forme> formes=new ArrayList<Forme>() {
            
        };
        BufferedReader in = null ;
        try {
        in = new BufferedReader ( new FileReader ( filename ) ) ;
        String ligne = null ;
        while (( ligne = in . readLine () ) != null ) {
            String[] tab= ligne.split(" ");
            
            if (tab[0].equals("Rectangle")) {
                
                formes.add(new Rectangle(Integer.parseInt(tab[1]), Integer.parseInt(tab[2]), Integer.parseInt(tab[3]), Integer.parseInt(tab[4]))) ;
            }
            if (tab[0].equals("Cercle")) {
                formes.add(new Cercle(Integer.parseInt(tab[1]), Integer.parseInt(tab[2]), Integer.parseInt(tab[3]))) ;
                
            }
            
        }
        } finally {
        if ( in != null ) {
        in . close () ;
        }
        }
        return formes;
    }
    @Override
    public void sauver(Collection<Forme> formes, String filename) throws IOException {
        PrintWriter out = null ;
        try {
        out = new PrintWriter ( new FileWriter ( filename) ) ;
            for (Forme forme : formes) {
                out.write(forme.toString());
                out.write("\n");
            }
        } finally {
        if ( out != null ) {
        out . close () ;
        }
        }
        
    }
}