package visites;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.hamcrest.Matchers.*;
import static org.hamcrest.MatcherAssert.*;

public class TestEtape {
	Etape etape;
	
	@BeforeEach
	public void setUp() throws Exception{
		this.etape = new Etape("e1", "rue1", 10, NatureEtape.musee);
	}
	
	@Test
	public void TestConstructeur() {
		assertThat(etape.getNom(), is("e1"));
		assertThat(etape.getRue(), is("rue1"));
		assertThat(etape.getDureeVisite(), is(10));
		assertThat(etape.getType(), is(NatureEtape.musee));
	}
	
	@Test
	public void TestEstCorrect() {
		assertThat(etape.getType()==NatureEtape.lieuInteretSansVisite && etape.getDureeVisite()==0, is(etape.estCorrecte()));
	}
}
