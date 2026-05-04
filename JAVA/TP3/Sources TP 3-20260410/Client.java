public class Client {
    int numeroClient;
    String nom;
    double solde=0;
    static int cpClient=0;
    public Client(String nom)
    {
        this.nom=nom;
        numeroClient=cpClient;
        cpClient++;
    }

    public void setNumeroClient(int numeroClient) {
        this.numeroClient = numeroClient;
    }
    public void setSolde(double solde) {
        this.solde = solde;
    }
    public void setNom(String nom) {
        this.nom = nom;
    }
    public String getNom() {
        return nom;
    }
    public double getSolde() {
        return solde;
    }
    public int getNumeroClient() {
        return numeroClient;
    }
    @Override
    public String toString() {
        return "nom : "+nom+ "\n"+"solde : " +solde +"\n" + "numero client : "+numeroClient + "\n";
    }
    @Override
    public boolean equals(Object obj) {
        return this==((Client)obj);
    }
}
