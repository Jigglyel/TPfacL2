import java.io.*;

public class Saisie {

	public static String lireChaine(String message){
		String ligne = null;

		try{
			InputStreamReader isr = new InputStreamReader(System.in);
			BufferedReader br = new BufferedReader(isr);
			System.out.print(message);
			ligne = br.readLine();
		}
		catch (IOException e){
			System.err.println(e.getMessage());
		}
		return ligne;
	}

	public static int lireEntier(String message){
		return Integer.parseInt(lireChaine(message));
	}

	public static double lireReel(String message){
		return Double.parseDouble(lireChaine(message));
	}

	public static String lireString(String message){
		return lireChaine(message);
	}
}