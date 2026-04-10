public class Maison extends Batiment {
    int nbPieces;
    int surfaceJardin;

    public Maison(String adr,int surfaceHabitable, int nbPieces,int surfaceJardin)
    {
        super(adr, surfaceHabitable);
        this.nbPieces=nbPieces;
        this.surfaceJardin=surfaceJardin;
    }

    public String toString()
    {
        return  super.toString() + "nb pieces : " + nbPieces +"\n" + "surface Jardin : "+surfaceJardin+"\n";
    }

    public int getSurfaceJardin()
    {
        return surfaceJardin;
    }
}
