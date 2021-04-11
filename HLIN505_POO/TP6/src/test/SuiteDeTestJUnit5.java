package test;


import org.junit.platform.runner.JUnitPlatform;
import org.junit.platform.suite.api.SelectClasses;
import org.junit.runner.*;

@RunWith(JUnitPlatform.class)
@SelectClasses({TestFooBar.class,TestParametreBarJUnit5.class,TestParametreFooJUnit5.class})
public class SuiteDeTestJUnit5 {

}
