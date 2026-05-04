import java.util.ArrayList;

public abstract class Polygone extends FormeGeometrique {
    ArrayList<Point> sommets;
    @Override
    public float perimetre() {
        float somme=0;
        for (int index = 0; index < sommets.size()-1; index++) {
            somme+=Point.distance(sommets.get(index), sommets.get(index+1));
        }
        return somme;
    }
    public void translation(Point v) {
        for (Point sommet : sommets) {
            sommet.translation(v);
        }
    }
    public void afficher()
    {   int i=1;
        for (Point sommet : sommets) {
            System.out.println("sommet n°"+i);
            System.out.print(sommet.getX()+"   ");
            System.out.println(sommet.getY());
            i++;
        }
    }
}
