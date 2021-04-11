package pkg1;

enum TacheType {ECRIRE, AMELIORER_COMPLEXITE, REFACTORISER, TESTER;}

public @interface Todo {
	TacheType type();
	int numVersion() default 1;
	int duree();
}
