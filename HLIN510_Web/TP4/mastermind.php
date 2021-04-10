<?php
	session_start();
	if(isset($_POST['charge']) && isset($_COOKIE['PHPSESSID']) && isset($_COOKIE[$_POST['charge']]))
		$_COOKIE['PHPSESSID'] = $_COOKIE[$_POST['charge']];
	if(isset($_POST['Pname']) && isset($_COOKIE['PHPSESSID']))
		setcookie($_POST['Pname'], $_COOKIE['PHPSESSID'], time()+86400);
?>

<!DOCTYPE html>
<html>
<head>
	<title>MasterMind</title>
</head>
<body>

	<form method="POST">
		<label for="combi">Entrez une combinaison</label>
		<input type="number" name="c1">
		<input type="number" name="c2">
		<input type="number" name="c3">
		<input type="number" name="c4">
		<input type="submit" value="tester">
	</form>

	<?php

		class Jeu{

			private $combi = array();
			
			public function __construct(){
				for ($i=0; $i < 4; $i++) { 
					$n = rand(0,9);
					while(in_array($n, $this->combi))
						$n = rand(0,9);
					$this->combi[$i] = $n;
				}
			}

			public function nbChiffreId($try){
				$chiffreBon = 0;
				for ($i=0; $i < 4; $i++)
					if($this->combi[$i] == $try[$i])
						$chiffreBon++;
				return $chiffreBon;


			}

			public function toString(){
				$str = "";
				for ($i=0; $i < 4; $i++)
					$str = $str . $this->combi[$i] . ";";
				return $str . "\n";
			}
		}

		$j = new Jeu();
		if(!isset($_SESSION['jeu']))
			$_SESSION['jeu'] = $j;

		if(!isset($_SESSION['coups']))
			$_SESSION['coups'] = array();

		if(!isset($_SESSION['nbTry']))
			$_SESSION['nbTry'] = 0;
		

		function combiValid($combi){
			$nbFois = array();
			for ($i=0; $i < 9; $i++) { 
				$nbFois[$i] = 0;
			}

			for ($i=0; $i < 4; $i++) { 
				if($combi[$i] > 9 || $combi[$i] < 0)
					return false;
				$nbFois[$combi[$i]]++;
				if($nbFois[$combi[$i]] > 1)
					return false;
			}
			return true;
		}

		// creation de la combinaison à tester
		$try = array();
		foreach ($_POST as $key => $value) {
			if($key != "Pname" && $key!="nP" && $key!="charge")
				array_push($try, $value);
		}


		if(sizeof($try) != 0){
		//on test
			if(combiValid($try)){
				
				$ncc = $_SESSION['jeu']->nbChiffreId($try);

				$_SESSION['coups'][$_SESSION['nbTry']] = array($try,$ncc);

					//affichage des resultats
				if($ncc == 4)
					echo "<p>Vous avez trouvé la combinaison !!!</p>";
				else
					echo "<p>Vous avez {$ncc} chiffres correctes</p>";

				$_SESSION['nbTry']++;

			}else{
				$_SESSION['coups'][$_SESSION['nbTry']] = "Combi invalid";
			}
		}
		echo "<p> Nombre d'essais : {$_SESSION['nbTry']} </p>";	

	?>

	<p><b>Historique des coups</b></p>

	<?php

	if(isset($_SESSION['coups'][0])){
		foreach ($_SESSION['coups'] as $key => $val) {
			echo "{$key} : ";
			foreach ($val[0] as $k => $v) {
				echo "{$v}";
			}	
			echo " chiffres correctes : {$val[1]} <br/>";
		}
	}

	print_r($_COOKIE);
	print_r($_POST);
	?>

	<form method="POST">
		<label for="Pname">Nom de la partie</label>
		<input type="text" name="Pname">
		<input type="submit" value="Save">
	</form>
	<form method="POST">
		<label for="charge">Nom de la partie</label>
		<input type="text" name="charge">
		<input type="submit" value="Charger">
	</form>
	<form method="POST">
		<input type="submit" name="nP" value="Nouvelle Partie">
	</form>
	<?php

		// if (isset($_POST['nP'])) {
		// 	//supprimer sessid
		// }

	?>

</body>
</html>

