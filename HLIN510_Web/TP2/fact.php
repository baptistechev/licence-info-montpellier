<!DOCTYPE html>
<html>
<head>
	<title>Fact php</title>
</head>
<body>
	<form method="POST" id="form" >
		<label for="nb">Entrez un nombre</label>	
		<input type="number" name="nb" />
		<input type="submit" value="envoyer !">
	</form>

	<p>
		<?php

	
			function fact($n){
				if($n <= 1)
					return 1;
				else
					return $n*fact($n-1);
			}

			if(isset($_POST['nb'])){

				echo fact($_POST['nb']);
				echo "\n";

			}
			

		?>
		
	</p>

</body>
</html>


