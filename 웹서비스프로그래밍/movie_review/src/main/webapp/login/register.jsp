<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link
	href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/css/bootstrap.min.css"
	rel="stylesheet"
	integrity="sha384-BmbxuPwQa2lc/FVzBcNJ7UAyJxM6wuqIj61tLrc4wSX0szH/Ev+nYRRuWlolflfl"
	crossorigin="anonymous">
<script
	src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js"
	integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0"
	crossorigin="anonymous"></script>
<script>
	function checkInputs() {
		var userID = document.getElementsByName("member_name")[0].value;
		var userPassword = document.getElementById("member_password").value;
		var userNickname = document.getElementsByName("member_nickname")[0].value;
		var submitButton = document.getElementById("submitButton");

		if (userID.trim() !== '' && userPassword.trim() !== ''
				&& userNickname.trim() !== '') {
			submitButton.removeAttribute('disabled');
		} else {
			submitButton.setAttribute('disabled', 'disabled');
		}
	}
</script>
<title>회원가입</title>
</head>
<style>
.container {
	max-width: 400px;
}

#submitButton {
	width: 100px;
}
</style>
<body>
	<div class="container">
		<div class="row justify-content-center">
			<div class="jumbotron" style="padding-top: 20px;">
				<form method="post" action="/movie_review/cuser?action=addUser">
					<h3 style="text-align: center;">회원가입</h3>
					<div class="form-group">
						<input type="text" class="form-control" placeholder="아이디"
							name="member_name" onkeyup="checkInputs()" maxlength="20">
					</div>
					<br>
					<div class="form-group">
						<input type="password" class="form-control" placeholder="비밀번호"
							name="member_password" id="member_password"
							onkeyup="checkInputs()" maxlength="20">
					</div>
					<br>
					<div class="form-group">
						<input type="text" class="form-control" placeholder="닉네임"
							name="member_nickname" onkeyup="checkInputs()" maxlength="50">
					</div>
					<br> <input type="submit" class="btn btn-primary form-control"
						id="submitButton" value="회원가입" disabled>
				</form>
			</div>
		</div>
	</div>
</body>
</html>
