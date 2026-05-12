public class Cercle extends Forme {
    private int rayon;
    public void setRayon(int rayon) {
        this.rayon = rayon;
    }
    public int getRayon() {
        return rayon;
    }
    public Cercle(int x, int y, int rayon)
    {
        super(x, y);
        this.rayon=rayon;
    }
    
    @Override
    public String toString() {
      
        return "Cercle "+getX()+" " +getY()+" "+getRayon();
    }
}
