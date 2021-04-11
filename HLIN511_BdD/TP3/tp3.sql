SET SERVEROUTPUT ON;
DECLARE
	num number(6) := &numeroAbonne;
	nb number(3);
BEGIN
	IF (num not in (Select distinct num_ab from abonne)) THEN
	       dbms_output.put_line('numero pas bon');
	END IF;
	

	Select count(*) into nb from abonne ab join emprunt em on ab.num_ab=em.num_ab where ab.num_ab=num group by ab.num_ab;
	INSERT INTO AB_NB VALUES (num, nb);
	--dbms_output.put_line(num) ; -- affichage
	--dbms_output.put_line(nb) ; -- affichage
EXCEPTION
	when NO_DATA_FOUND THEN dbms_output.put_line('probleme');
	
END;
/
