package pkg4;

import com.google.java.contract.Ensures;
import com.google.java.contract.Invariant;
import com.google.java.contract.Requires;

@Invariant({"solde + decouvert > 0"})
public class Compte {
	
	private int solde;
	private int decouvert;
	
	@Requires("decouvert > 0")
	@Ensures("solde + decouvert > 0")
	public Compte(int solde, int decouvert) {
		super();
		this.solde = solde;
		this.decouvert = decouvert;
	}
	
	@Requires("montant >= 0")
	public void crediter(int montant) {
		this.solde += montant;
	}
	
	@Requires("montant >= 0")
	@Ensures("montant > - decouvert")
	public void debiter(int montant) {
		this.solde -= montant;
	}

	@Override
	public String toString() {
		return "Compte [solde=" + solde + ", decouvert=" + decouvert + "]";
	}
	
	
	
}
