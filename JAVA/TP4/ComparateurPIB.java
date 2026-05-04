import java.util.Comparator;

public class ComparateurPIB implements Comparator<Region>{

    @Override
    public int compare(Region arg0, Region arg1) {
    if(arg0.getPIB()>arg1.getPIB())
        return 1;
    else
    if(arg0.getPIB()==arg1.getPIB())
        return 0;
    else
        return -1;
    }
}