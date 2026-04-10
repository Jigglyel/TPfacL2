
/**
 * cette classe est un tableau de batiment
 */
public class Quartier {
    /**
     * tableau public de batiment représentant la classe
     */
    public Batiment [] batiments=new Batiment[100];
    /**taille courante */
    public int taille=0;
    /**pour ajouter un batiment */
    public void ajoutBatiment(Batiment batiment)
    {
        batiments[taille]=batiment;
        taille++;
    }

    /**pour afficher les batiments supérieur à une catégorie */
    public void afficherBatiment(int categorie)
    {
        for (Batiment batiment : batiments) {
            if (batiment.categorie()>=categorie) {
                System.out.println(batiment);
            }
        }
    }
    /**pour retourner le plus grand bâtiment du quartier */
    public Batiment plusGrandBatiment() {
        int maxindice=-1;
        int max=0;
        for (int i=0; i<taille;++i) {
            if (batiments[i].getSurfaceHabitable()>max) {
                max=batiments[i].getSurfaceHabitable();
                maxindice=i;
            }
        }
        return batiments[maxindice];
    }
}
