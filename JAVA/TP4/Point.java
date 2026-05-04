public class Point {

    private float x;
    private float y;
    static float distance(Point p1,Point p2)
    {
        float dx=Math.abs(p1.x-p2.x);
        float dy=Math.abs(p1.y-p2.y);
        return ((float)Math.sqrt(dx*dx+dy+dy));
    }
    public Point(float x,float y)
    {
        this.x=x;
        this.y=y;
    }
    public float getX()
    {
        return x;
    }

    public float getY()
    {
        return y;
    }

    public void setX(float x)
    {
        this.x=x;
    }

    public void setY(float y)
    {
        this.y=y;
    }
    public void translation(Point v)
    {
        this.x+=v.x;
        this.y+=v.y;
    }
}