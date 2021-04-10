<!DOCTYPE html>
<html>
<head>
	<title>Commandes</title>
</head>
<body>

	<?php

		$larticle=array('marteau'=>10, 'tenaille'=>5, 'vis'=>5.2,'clou'=>5.8,'tournevis'=>7, 'ciseau'=>4, 'toile émeri'=>3);


		if (isset($_GET['outils']) && isset($_GET['quantite'])) {
			$lcommande = array($_GET['outils'] => $_GET['quantite']);


			//recupere les inputs cachés
			foreach ($_GET as $key => $value) {
				if($key != 'outils' && $key !='quantite'&& $key != $_GET['outils'])
					$lcommande[$key] = $value;
			}

		}

	?>

	<form method="GET">
		<label for="outils">Article : </label>
		<select name="outils">
			<option>marteau</option>
			<option>tenaille</option>
			<option>vis</option>
			<option>clou</option>
			<option>tournevis</option>
			<option>ciseau</option>
			<option>toile émeri</option>
		</select>

		<label for="quantite">Nombre de</label>
		<input type="number" name="quantite">
			<?php
				$somme = 0;
				foreach ($lcommande as $a => $q) {

					//affiche les input cachés
					echo "<input type=\"hidden\" name=\"{$a}\" value=\"{$q}\"/>";

					//calcul la somme
					$somme += $q * $larticle[$a];;
				}
			?>

		<input type="submit" value="ajouter" />
	</form>

	<p>
		<?php
			
			foreach ($lcommande as $a => $q) {

				//affichage des articles
				if($q != 0)	
					echo "{$a} : {$q} x ({$larticle[$a]} €)  <br />";
			}

			echo "\n<p>Total : {$somme}</p>";

		?>
	</p>	

</body>
</html>