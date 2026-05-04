import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class Test {
    
    public static void main(String[] args) {

        ArrayList<Region> list=new ArrayList<Region>();
        list.add(new Region("Centre-Val de Loire", 2566759, 70, 39151));
        list.add(new Region("Bretagne", 3329395, 92, 270208));
        list.add(new Region("Ile-de-France", 12213364, 669, 12011));
        list.add(new Region("Auvergne-Rhône-Alpes", 8026685, 250, 69711));
        Collections.sort(list);
        for (Region region : list) {
            System.out.println(region.toString());
        }
        Collections.sort(list,new ComparateurPIB());
        for (Region region : list) {
            System.out.println(region.toString());
        }
        Collections.sort(list,new ComparateurDensite());
        for (Region region : list) {
            System.out.println(region.toString());
        }
    }
}
