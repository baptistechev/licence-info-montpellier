package etudes;
import java.time.*;

public class Etudiant{
    private String nom;
    private final LocalDate dateNaissance;
    private boolean premierInsc;
    private CodePays codeP;
    private float[] notes = {-1,-1,-1};
   

    public Etudiant(String nom, LocalDate date , boolean Insc, CodePays cP, float n1,float n2,float n3){
	this.nom = nom;
	dateNaissance = date;
	premierInsc = Insc;
	codeP = cP;
	this.notes[0] = n1;
	this.notes[1] = n2;
	this.notes[2] = n3;	
    }

    public boolean getPremierInsc(){
	return this.premierInsc;
    }
    
    public String getNom(){
	return this.nom;
    }
    
    public void setNom(String nom){
        this.nom = nom;
    }

    public void setNotes(float n1,float n2,float n3){
	this.notes[0] = n1;
	this.notes[1] = n2;
	this.notes[2] = n3;
    }
    public void setNotes(int i,float n){
	this.notes[i] = n;
    }

    public void getNotes(){
	System.out.print("Voici les notes de "+this.nom+" :");
	for(int i=0; i<notes.length;i++){
	    System.out.print(" "+this.notes[i]);
	}
	System.out.println();
    }

    public CodePays getCodePays(){
	return this.codeP;
    }
    public void setCodePays(CodePays cp){
	this.codeP = cp;
    }
    public float moyenne(){
	float moy=0;
	int nbNotes=0;
	for(int i=0; i<notes.length ; i++){
	    if(notes[i] >= 0){
		moy+=notes[i];
		nbNotes++;
	    }
	}
	if(nbNotes > 0)
	    moy = moy/nbNotes;
	else
	    System.out.println("erreur pas de notes repertoriés pour cet étudiant");
	
	return moy;
    }

    public Mention mention(){
	float moy = this.moyenne();
	if((moy >= 10) && (moy < 12))
	    return Mention.PasDeMention; 
	if((moy >= 12) && (moy < 14))
	    return Mention.AB;
	else if((moy >= 14) && (moy < 16))
	    return Mention.B;
	else if(moy >= 16)
	    return Mention.TB;
	else
	    return Mention.Ajourne;
    }
    
    public int getAge(){
        Period.between(this.dateNaissance, LocalDate.now());
        return Period.between(this.dateNaissance, LocalDate.now()).getYears();
    }

    public void ligneResultats(){
	System.out.print(this.nom+" moyenne: "+this.moyenne()+" mention: "+this.mention()+" ");
	if(this.moyenne() < 10){
	    for(int i=0; i<this.notes.length ; i++){
		if(this.notes[i] >= 10)
		    System.out.print(this.notes[i]+" ");
	    }
	    System.out.print(" ces modules sont validés.");
	}
	System.out.println(" ");
    }

    public String toString(){
	return this.nom;
    }
}

