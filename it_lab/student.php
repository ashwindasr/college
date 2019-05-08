<?php
	
	$name = $_POST["name"];
	$rollno = $_POST["rollno"];
	$branch = $_POST["branch"];

	$db = "localhost";
	$username = "root";
	$password = "root";
	
	$conn = mysqli_connect($db, $username, $password,"registration");
	
	if(!mysqli_query($conn, "insert into registration values($name, $rollno, $branch)")){
		echo mysqli_error();
	}
	else{
		echo 'success';
}
	mysqli_close($conn);
		
		

?>
