<?php
	$user="root";$pass="";
	try{
		$dbh = new PDO("mysql:host=localhost;dbname=ma_base;charset=UTF8", $user, $pass,
		array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,));
		echo "connexion reussie ! <br />";

		foreach ($dbh->query("SELECT nom FROM etudiant") as $row){
			echo $row['nom'] . "<br />";
		}


	} catch(PDOException $e){
		echo $e->getMessage();
		die("Connexion impossible !");
	}
?>