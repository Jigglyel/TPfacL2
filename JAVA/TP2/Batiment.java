import java.lang.String;
public class Batiment {
    private String adresse;
    private int surfaceHabitable;


    public String toString(){
        return getClass().getCanonicalName() +"\n" +"adresse : " + adresse + "\n"+"surfaceHabitable : " + surfaceHabitable+ "\n";
    };
    public Batiment(String adr,int surfaceHabitable)
    {
        this.adresse=adr;
        this.surfaceHabitable=surfaceHabitable;
    }
    public int getSurfaceHabitable()
    {
        return surfaceHabitable;
    }
    public int categorie()
    {
        if (surfaceHabitable<30) {
            return 1;
        }
        else if (surfaceHabitable<70) {
            return 2;
        }
        else return 3;
    }
    public Batiment comparer(Batiment batiment){
        if (this.surfaceHabitable>batiment.surfaceHabitable) {
            return this;
        }
        else
            return batiment;
    }
}
