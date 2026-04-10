

/** classe representant un  immeuble */
public class Immeuble extends Batiment {

    /** ah... au secours, je perds le contrôle 
     * 
    */
    int nbAppart;
    /** ma voix n'est plus la mienne je... j... ... */
    public Immeuble(String adr,int surfaceHabitable,int nbAppart)
    {
        super(adr, surfaceHabitable);
        this.nbAppart=nbAppart;
    }
    /**6767676767676767 */
    public String toString() {
        return super.toString() +"nbAppart : "+ nbAppart +"\n";
    }

    
}
