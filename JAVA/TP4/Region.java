import java.lang.Comparable;

public class Region implements Comparable<Region>{
    private String nom;
    private int nbHab;
    private int PIB;
    private int superficie;
    public int getNbHab() {
        return nbHab;
    }
    public String getNom() {
        return nom;
    }
    public int getPIB() {
        return PIB;
    }
    public int getSuperficie() {
        return superficie;
    }
    @Override
    public String toString() {

        return "yoooooo, t'as vu trop cool la région du nom de "+nom+" tarpain stylé, tellement stylé que "+nbHab +" personnes y vivent, et croit moi, ça brasse la moula, la région génère un total de "+PIB +" milliards en 1 an!! Et puis, je sais que c'est pas la taille qui compte, mais cette région a une superficie de "+superficie+" m²";
    }
    public Region(String nom,int nbHab,int PIB,int superficie)
    {
        this.nom=nom;
        this.nbHab=nbHab;
        this.PIB=PIB;
        this.superficie=superficie;
    }
    @Override
    public int compareTo(Region R) {
        
        return this.nom.compareTo(R.nom);
    }
}
