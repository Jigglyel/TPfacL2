


public class Rectangle extends Forme {
    private int longueur;
    private int largeur;
    public Rectangle(int x, int y, int longueur, int largeur)
    {
        super(x, y);
        this.largeur=largeur;
        this.longueur=longueur;
    }
    public int getLargeur() {
        return largeur;
    }
    public int getLongueur() {
        return longueur;
    }
    public void setLargeur(int largeur) {
        this.largeur = largeur;
    }
    public void setLongueur(int longueur) {
        this.longueur = longueur;
    }
    @Override
    public String toString() {
        

        return "Rectangle "+getX()+" "+getY()+ " "+getLongueur()+" "+getLargeur();
    }
}
