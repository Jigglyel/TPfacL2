import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collection;

public class IOFormeBinaire implements IOForme {
    @Override
    public Collection<Forme> lire(String filename) throws IOException {
        Collection<Forme> formes =new ArrayList<Forme>();
        ObjectInputStream ois = new ObjectInputStream (
        new FileInputStream (filename)
        ) ;
        try {
        while ( true ) {
         formes.add((Forme)(ois . readObject ()));
        }
        } catch ( ClassNotFoundException cnf ) {
        // erreur de lecture
        } catch ( EOFException eof ) {
        // fin de fichier
        }
        ois . close () ;
        return formes;
    }
    @Override
    public void sauver(Collection<Forme> formes, String filename) throws IOException {
        ObjectOutputStream oos = new ObjectOutputStream (
        new FileOutputStream (filename)
        ) ;
        try {
        for (Forme forme : formes) {
            oos.writeObject(forme);
        }
        }  catch ( EOFException eof ) {
        // fin de fichier
        }
        oos . close () ;
        
    }
}
