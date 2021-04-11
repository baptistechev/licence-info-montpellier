package visites;

import java.util.Vector;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.hamcrest.Matchers.*;
import static org.hamcrest.MatcherAssert.*;

public class TestTroncon {
	Troncon troncon1;
	Troncon troncon2;
	
	@BeforeEach
	public void setUp() {
		this.troncon1 = new Troncon(new Etape("e1", "rue1", 10, NatureEtape.musee), new Etape("e2", "rue2", 50, NatureEtape.visiteJardin), 50);
		Vector<String> rues = new Vector<>();
		rues.add("rue1");
		rues.add("rue2");
		this.troncon2 = new Troncon(new Etape("e1", "rue1", 10, NatureEtape.musee), new Etape("e2", "rue2", 50, NatureEtape.visiteJardin), 50, rues);
	}
	
	@Test
	public void TestConstructeur() {
		assertThat(troncon1.getTempsTrajet(), is(50));
	}
	
	@Test
	public void TestVerif() {
		assertThat(troncon1.getDepart().getRue()=="rue1" && troncon1.getArrivee().getRue()=="rue2", is(troncon1.verif()));
	}
	
	@Test
	public void TestVerifListeRues() {
		assertThat(!troncon1.getDepart().getRue().equalsIgnoreCase(troncon1.getArrivee().getRue()), is(troncon1.verifListeRues()));
	}

}
