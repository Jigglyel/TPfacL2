package Ex1;
import java.io.File;

public class Main {

    public static void main(String[] args) {
        File fic=new File(args[0]);

        if (fic.exists()) {
            System.out.println("Chemin : "+args[0]);
            
            if (fic.isFile()) {
                System.out.println("taille : "+fic.length()+" octets");
                System.out.println("chemin absolu : "+fic.getAbsolutePath());
            }
            else
            {
                System.out.println("Liste des fichiers et repertoires du dossier : "+fic.getName() );
               for (File fichier : fic.listFiles()) {
                    System.out.println(fichier.getName());
               } 
            }
        }
    }
}