import java.util.ArrayList;

public class Rectangle extends Polygone {
    public Rectangle(Point p1,Point p2,Point p3,Point p4)
    {
        sommets=new ArrayList<Point>();
        this.sommets.add(p1);
        this.sommets.add(p2);
        this.sommets.add(p3);
        this.sommets.add(p4);
    }

}
