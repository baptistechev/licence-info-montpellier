package visites;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.hamcrest.Matchers.*;
import static org.hamcrest.MatcherAssert.*;

public class TestParcours {
	Parcours parcours;
	
	@BeforeEach
	public void setUp() {
		parcours = new Parcours();
		parcours.ajoutTroncon(new Troncon(new Etape("e1", "rue1", 10, NatureEtape.musee), new Etape("e2", "rue2", 0, NatureEtape.lieuInteretSansVisite), 5));
		parcours.ajoutTroncon(new Troncon(new Etape("e2", "rue2", 0, NatureEtape.lieuInteretSansVisite), new Etape("e3", "rue3", 20, NatureEtape.visiteJardin), 15));
	}

	@Test
	public void TestCalculDuree() {
		assertThat(parcours.calculDuree(), is(50));
	}

	@Test
	public void TestExisteBoucle() {
		assertThat(parcours.existeBoucle(), is(false));
	}
	
	@Test
	public void TestEstUnCircuit() {
		assertThat(parcours.estUnCircuit(), is(false));
	}
}
