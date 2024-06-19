<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>join</title>
<link rel="stylesheet"
	href="${pageContext.request.contextPath}/resources/join.css"
	type="text/css"></link>
<script src="https://kit.fontawesome.com/51db22a717.js"
	crossorigin="anonymous"></script>
<link href="https://fonts.googleapis.com/css2?family=Alata&display=swap"
	rel="stylesheet">
</head>
<body>
	<div class="page-container">
		<div class="login-form-container shadow">
			<div class="login-form-left-side">
				<form name=form1 action="../members/join/" method="post">
					<div class="login-input-container">
						<div class="login-input-wrap input-id">
							<i class="far fa-user"></i> <input placeholder="Name" type="text"
								name="memberName">
						</div>
						<div class="login-input-wrap input-id">
							<i class="far fa-envelope"></i> <input placeholder="Email"
								type="text" name="email">
						</div>
						<div class="login-input-wrap input-password">
							<i class="fas fa-key"></i> <input placeholder="Password"
								type="password" name="password">
						</div>
					</div>
					<div class="login-btn-wrap">
						<input type="submit" class="login-btn" value="Sign Up">
					</div>
				</form>
			</div>
			<div class="login-form-right-side">
				<div class="top-logo-wrap"></div>
				<h1>Join Us Today!</h1>
				<p>Get ready to embark on exciting adventures with us. Signing
					up is your gateway to a world of new connections and experiences.
					Authenticate yourself and start your journey with us!</p>
			</div>
		</div>
	</div>
</body>
</html>
