package visites;

import org.junit.platform.runner.JUnitPlatform;
import org.junit.platform.suite.api.SelectClasses;
import org.junit.runner.RunWith;

@RunWith(JUnitPlatform.class)
@SelectClasses({TestEtape.class, TestTroncon.class, TestParcours.class})
public class SuiteDeTest {

}
