public class Main {

    public static void main(String[] args) {

        Voiture truc=new Voiture(true, "Twingo", 2026, 10000, "AB-123-CD", 'B');
        truc.afficherVoiture();
        Camion c1=new Camion(10000, "Cammmion", 2023, 5, "67", 'A');
        System.out.println(c1.peutTransporterVolume(7));
        System.out.println(truc.coutLocation());
        System.out.println(c1.coutLocation());
        Autocar bus=new Autocar(67, 47, false, "bus", 59, 59, "pofjpsgjpshgoqihtpqhrgiuhrqgih", 'K');
        System.out.println(bus.peutTransporterPassagers(68, 0.25));
    }
}