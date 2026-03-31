import java.lang.String;

public class Camion extends Vehicule {



    double volume;
    Camion(double volume,String modele,int anneeAchat, float prix, String immatriculation, char permis)
    {
        super(modele, anneeAchat, prix, immatriculation, permis);
        this.volume=volume;
    }
    public boolean peutTransporterVolume(double volume)
    {
        return volume<this.volume;
    }

    public void afficherCamion()
    {
        super.afficherVehicule();
            System.out.println("Camion : " +volume);

        

    }
    
}
