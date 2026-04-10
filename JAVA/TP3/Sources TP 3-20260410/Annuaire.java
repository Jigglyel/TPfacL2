import java.util.ArrayList;

public class Annuaire {

    ArrayList<Client> clients;

    public Annuaire()
    {
        clients=new ArrayList<Client>();
    }
    public void ajoutClient(Client client)
    {
        clients.add(client);
    }
    public void afficherTaille()
    {
        System.out.println("La taille de l'annuaire est : "+clients.size());
    }

    public void afficherClients()
    {
        for (Client client : clients) {
            System.out.println(client);
        }
    }
    public Client rechercherClient(int numeroClient)
    {
        for (Client client : clients) {
            if (client.numeroClient==numeroClient) {
                return client;
            }
        }
        return null;
    }

    public void supprimerClient(int numeroClient)
    {
        clients.remove(rechercherClient(numeroClient));
    }
    public void Crediterclient(int numeroClient,double credit)
    {
        rechercherClient(numeroClient).solde+=credit;
    }
    public double totalSolde()
    {
        double somme=0;
        for (Client client : clients) {
            somme+=client.solde;
        }
        return somme;
    }
	
}
