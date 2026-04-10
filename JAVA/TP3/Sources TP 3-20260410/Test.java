
public class Test {

	public static void main(String[] args) {
	
		Annuaire annuaire = new Annuaire();	
		
		
		int rep =0; 
		while(rep!=-1){              
			System.out.println("1 ===>  Ajouter un nouveau client"); 
			System.out.println("2 ===>  Afficher la taille de l'annuaire"); 
			System.out.println("3 ===>  Afficher l'annuaire complet"); 
			System.out.println("4 ===>  Rechercher un client par son identifiant"); 
			System.out.println("5 ===>  Supprimer un client par son identifiant"); 
			System.out.println("6 ===>  Crediter le solde d'un client"); 
			System.out.println("7 ===>  Afficher le total des soldes des clients de l'annuaire"); 
			System.out.println("-1 ===>  Quitter"); 
			rep = Saisie.lireEntier("Votre choix ?"); 
			
			if(rep == 1){  
				String nom=Saisie.lireChaine("nom du client : ");           
				Client client=new Client(nom);
				annuaire.ajoutClient(client);
				System.out.println("le client du nom de "+nom+" a été ajouté");
				
				
			} else if (rep ==2){ 
				
				annuaire.afficherTaille();
		
	
			} else if (rep ==3){ 
				
				annuaire.afficherClients();
				
			} else if (rep ==4){ 
				
				System.out.println(annuaire.rechercherClient(Saisie.lireEntier("indiquez le numéro du client à rechercher : ")));
				
			} else if (rep ==5){ 
				int nb=Saisie.lireEntier("indiquez le numéro du client à supprimer : ");
				System.out.println("Le client du nom de "+annuaire.rechercherClient(nb) +"a été supprimé");
				annuaire.supprimerClient(nb);
				
			} else if (rep ==6){ 
				
				annuaire.Crediterclient(Saisie.lireEntier("indiquez le numéro du client à créditer : "), 
				Saisie.lireReel("indiquez le montant à créditer : "));
				
			} else if (rep ==7){ 
				
				System.out.println(annuaire.totalSolde());
				
			}
		}
		
		
	}
}
