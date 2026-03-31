import java.lang.String;



public class Vehicule {
    private String modele;
    private int anneeAchat;
    private float prix;
    private String immatriculation;
    private char permis;
    Vehicule(String modele,int anneeAchat, float prix, String immatriculation, char permis)
    {
        this.modele=modele;
        this.anneeAchat=anneeAchat;
        this.prix=prix;
        this.immatriculation=immatriculation;
        this.permis=permis;
    }
    public int age()
    {
        return 2026-this.anneeAchat;
    }
    public void afficherVehicule()
    {
        System.out.println("Véhicule : " +modele+" "+anneeAchat+" "+prix+" "+immatriculation+" "+permis);
    }
    public float coutLocation()
    {
        if ((age()<1)) {
            return prix/200;
        }
        else
            return prix/250;
        
    }
    
    
}
