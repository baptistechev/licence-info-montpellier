<?php
	$user="root";$pass="";
	try{
		$dbh = new PDO("mysql:host=localhost;dbname=ma_base;charset=UTF8", $user, $pass,
		array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,));
	} catch(PDOException $e){
		echo $e->getMessage();
		die("Connexion impossible !");
	}
?>

<!DOCTYPE html>
<html>
<head>
	<title>stageA</title>
</head>
<body>

	<h1>Liste des stages</h1>

	<?php

		$i = 0;
		$sql = "SELECT nom, prenom, etudiant.numStageA, sujet, respEnt, respPeda FROM etudiant, stageA where etudiant.numStageA=stageA.numStageA order by etudiant.numStageA";

		foreach ($dbh->query($sql) as $row){
			if($i != $row['numStageA']){
				echo "<h4>". $row['numStageA']." ) <u>".$row['sujet']."</u> [ ".$row['respEnt']." | ".$row['respPeda']." ] </h4>";
				$i = $row['numStageA'];
			}else{
				echo $row['nom'] . " " . $row['prenom'] ."<br />";
			}

		}

	?>

</body>
</html>