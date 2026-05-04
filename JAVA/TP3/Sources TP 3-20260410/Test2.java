public class Test2 {
    public static void main(String[] args) {
        Annuaire an=new Annuaire();
        Client c1=new Client("lol");
        Client c2=new Client("lil");
        Client c3=new Client("lal");
        an.clients.add(c1);
        an.clients.add(c2);
        System.out.println(an.contient(c1));
        System.out.println(an.contient(c3));
    }
}
