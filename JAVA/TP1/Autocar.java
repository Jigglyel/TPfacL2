import java.lang.String;

public class Autocar extends Camion{
    int nbPassagers;
    Autocar(int nbPassagers,double volume,boolean autoradio,String modele,int anneeAchat, float prix, String immatriculation, char permis)
    {
        super(volume,modele, anneeAchat, prix, immatriculation, permis);
        this.nbPassagers=nbPassagers;
    }
    public boolean peutTransporterPassagers(int nb,double vol)
    {
        return (nb<nbPassagers && super.peutTransporterVolume(nb*vol));
            
        
    }

    public void afficherAutocar()
    {
        super.afficherVehicule();
            System.out.println("Camion : " +volume);

        

    }
}
