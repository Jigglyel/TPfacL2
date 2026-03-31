import java.lang.String;



public class Voiture extends Vehicule {
    boolean autoradio;
    Voiture(boolean autoradio,String modele,int anneeAchat, float prix, String immatriculation, char permis)
    {
        super(modele, anneeAchat, prix, immatriculation, permis);
        this.autoradio=autoradio;
    }
    public void ajouterAutoradio()
    {
        this.autoradio=true;
    }
    public void enleverAutoradio()
    {
        this.autoradio=false;
    }

    public void afficherVoiture()
    {
        super.afficherVehicule();
        if (autoradio) {
            System.out.println(" la Voiture a un autoradio");
        }
        else
            System.out.println(" la Voiture n'a pas d'autoradio");
        

    }
    
}