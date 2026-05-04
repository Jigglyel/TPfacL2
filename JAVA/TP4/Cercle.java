

public class Cercle extends FormeGeometrique{
    private Point centre;
    private float rayon;
    @Override
    public float perimetre() {
        
        return rayon *((float)Math.PI)*2;
    }
    Cercle(Point centre, float rayon)
    {
        this.centre=centre;
        this.rayon=rayon;
    }
    public void translation(Point v)
    {
        centre.translation(v);
    }
}