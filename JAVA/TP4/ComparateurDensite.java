import java.util.Comparator;

public class ComparateurDensite implements Comparator<Region>{

    @Override
    public int compare(Region arg0, Region arg1) {
        float densite0,densite1;
        densite0=arg0.getSuperficie()/arg0.getNbHab();
        densite1=arg1.getSuperficie()/arg1.getNbHab();
    if(densite0>densite1)
        return 1;
    else
    if(densite0==densite1)
        return 0;
    else
        return -1;
    }
}