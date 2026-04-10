public class TestBatiment {
    
    public static void main(String[] args) {
        Batiment bat=new Batiment("5 rue de des saucisses flambées",5);
        Maison maison=new Maison("6 rue des cheveux d'anges", 5, 6, 1000000);
        Immeuble immeuble=new Immeuble("7 rue du Marechal Henri IV", 1000, 2);
        Batiment [] tabat={bat,maison,immeuble};
        for (Batiment batiment : tabat) {
            System.out.println(batiment.toString());
        }
        Quartier quartier=new Quartier();
        quartier.ajoutBatiment(bat);
        quartier.ajoutBatiment(maison);
        for (int i=0; i<quartier.taille;i++) {
            System.out.println(quartier.batiments[i].toString());
        }
        System.out.println(maison.categorie());
        System.out.println(immeuble.categorie());

        System.out.println(immeuble.comparer(bat));

    }
    public static int surfaceHabitableTotale(Batiment [] batiments)
    {
        int somme=0;
        for (Batiment batiment : batiments) {
            somme+=batiment.getSurfaceHabitable();
        }
        return somme;
    }
    public static int surfaceJardinTotale(Maison [] maisons)
    {
        int somme=0;
        for (Maison maison : maisons) {
            somme+=maison.getSurfaceJardin();
        }
        return somme;
    }
    

}
