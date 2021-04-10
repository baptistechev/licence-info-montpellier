<?php
	session_start();

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
	<title>connexion</title>
</head>
<body>
	<?php
		if(isset($_POST['deco']))
			unset($_SESSION['connect']);

		if(!isset($_SESSION['connect'])){

			if(isset($_POST['login']) && $_POST['login']!="" && isset($_POST['password']) && $_POST['password'] != ""){

				$log = $_POST['login'];
				$pwd = md5($_POST['password']);
				$validLog = false;
				$validPass = false;
				foreach ($dbh->query("SELECT login FROM utilisateur where login='".$log."'") as $row){
					if($row['login'] == $log)
						$validLog = true;
				}

				if ($validLog) {

					foreach ($dbh->query("SELECT password FROM utilisateur where login='".$log."' and password='".$pwd."'") as $row){

							if($row['password'] == $pwd)
								$validPass = true;
						
						}					
						if($validPass){

							echo "Connexion...";
							$_SESSION['connect'] = array();
							foreach ($dbh->query("SELECT login, nom FROM utilisateur where login='".$log."' and password='".$pwd."'") as $row){
									array_push($_SESSION['connect'], $row['login']);
									array_push($_SESSION['connect'], $row['nom']);
							}
							header("Refresh:0");
						}
						else
							echo "Invalid password !";
					}else
						echo "Login invalid !";
			}
			echo '<form method="POST"><label for="login">Login</label><input type="text" name="login"><label for="password">Password</label><input type="password" name="password"><input type="submit" value="connect"></form>';
	}else{
		echo "Vous êtes connecté !";
		echo "Bonjour ".$_SESSION['connect'][0]." !";
		echo '<form method="POST"><input type="submit" name="deco" value="Deconnexion"></form>';
	}
	?>
	
</body>
</html>