import java.util.ArrayList;

public class Triangle extends Polygone{
    public Triangle(Point p1,Point p2,Point p3)
    {
        sommets=new ArrayList<Point>();
        this.sommets.add(p1);
        this.sommets.add(p2);
        this.sommets.add(p3);
    }
    
}
