package pkg3;

public class Etudiant {

	public enum TypeMod{
		eCandidat, CampusFrance, autre
	}
	
	private String nom;
	private int age;
	private TypeMod mod;
	public Etudiant(String nom, int age, TypeMod mod) {
		super();
		this.nom = nom;
		this.age = age;
		this.mod = mod;
	}
	public String getNom() {
		return nom;
	}
	public int getAge() {
		return age;
	}
	public TypeMod getMod() {
		return mod;
	}
	@Override
	public String toString() {
		return "Etudiant [nom=" + nom + ", age=" + age + ", mod=" + mod + "]";
	}
	
	
	
}
