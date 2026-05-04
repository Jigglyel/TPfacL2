import java.util.Scanner;

public class Test {
    

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Calculatrice numworks=new Calculatrice();
        while (true) {
            System.out.println("le resultat est " +numworks.lancementCalcul(sc));
        }
        
        
    }
}
