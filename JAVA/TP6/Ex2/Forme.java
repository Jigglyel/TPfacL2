

public abstract class Forme implements java.io.Serializable {
    private int x;
    private int y;
    private static final long serialVersionUID = 4L ;
    public void setXY(int x, int y){this.x=x; this.y=y;}
    public void setX(int x) {
        this.x = x;
    }
    public void setY(int y) {
        this.y = y;
    }
    public int getX() {
        return x;
    }
    public int getY() {
        return y;
    }
    public Forme(int x, int y){this.x=x; this.y=y;}
    
}
