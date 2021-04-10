<!DOCTYPE html>
<html>
<head>
	<title>trombino</title>
	<style type="text/css">
		table{
			border: 1px solid black;
		}
		th{
			border-bottom: 1px solid black;
		}
		td{
			border-left: 1px solid black;
		}
		#content{
			border: 1px solid black;
			margin-top: 10px;
			height: 400px;
			width: 1000px;	
			overflow: auto;
		}
	</style>
</head>
<body>

	<?php
		$user="root";$pass="";
		try{
			$dbh = new PDO("mysql:host=localhost;dbname=ma_base;charset=UTF8", $user, $pass,
			array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,));
		} catch(PDOException $e){
			echo $e->getMessage();
			die("Connexion impossible !");
		}

		$optReq = "SELECT DISTINCT nom, code FROM options";
		$ordReq = "SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'etudiant'";
	?>

	<form method="POST">
		
		<table>
	    <thead>
	        <tr>
	            <th>Mon formulaire</th>
	        </tr>
	    </thead>
	    <tbody>
	        <tr>
	        	<th>Options</th>

	            	<?php

	            	foreach ($dbh->query($optReq) as $row){
	            		echo '<td><label for="'.$row['nom'].'">'.$row['nom'].'</label>';

	            		if(in_array($row['code'], $_POST['opt'])){
	            			echo '<input type="checkbox" name="opt[]" id="'.$row['nom'].'" value="'.$row['code'].'" checked></td>';
	            		}else{
	            			echo '<input type="checkbox" name="opt[]" id="'.$row['nom'].'" value="'.$row['code'].'"></td>';
	            		}
	            	}
	            	?>

	        </tr>
	        <tr>
	        	<th>Ordre</th>
	            <td>
	        		<select name="ordre">
	        			<?php
	        				foreach ($dbh->query($ordReq) as $row){
	        					if($row['COLUMN_NAME'] == $_POST['ordre'])
		        					echo "<option selected>".$row['COLUMN_NAME']."</option>";
		        				else
		        					echo "<option>".$row['COLUMN_NAME']."</option>";
	        				}	        				        				
	        			?>
	        		</select>
	            </td>
	        </tr>
	        <tr>
	        	<td><input type="submit" value="valider"/></td>
	        </tr>
	    </tbody>
	</table>
	</form>

	<div id="content">
		
		<?php

			if(empty($_POST['opt'])){
				/*selectionner tout */
				$opt = "(SELECT DISTINCT code FROM options)";
			}else{
				$opt = "('" . $_POST['opt'][0] . "'";
				$i = 1;
				while($i < sizeof($_POST['opt']) && $_POST['opt'][$i] != ""){
					$opt .= " , '" . $_POST['opt'][$i] . "'";
					$i++;
				}
				$opt .= ")";
			}

			$ordre = empty($_POST['ordre'])? "nom" : $_POST['ordre'];
			$sql = "SELECT * FROM etudiant WHERE opt IN ". $opt ." ORDER BY ". $ordre;
			foreach ($dbh->query($sql) as $row){
				echo $row['nom']." ".$row['prenom']." <u>statut</u> ".$row['statut']." <u>groupe</u> ".$row['groupe']." <u>option</u> : ".$row['opt']."<br />";
			}

		?>

	</div>

</body>
</html>