<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>login</title>
<link rel="stylesheet"
	href="${pageContext.request.contextPath}/resources/login.css"
	type="text/css"></link>
<script src="https://kit.fontawesome.com/51db22a717.js"
	crossorigin="anonymous"></script>
<link href="https://fonts.googleapis.com/css2?family=Alata&display=swap"
	rel="stylesheet">
</head>
<body>
	<div class="page-container">
		<div class="login-form-container shadow">
			<div class="login-form-right-side">
				<div class="top-logo-wrap"></div>
				<h1>Welcome Back!</h1>
				<p>A new adventure awaits. Enter your credentials below to
					continue your journey. We look forward to having you with us!</p>
			</div>
			<div class="login-form-left-side">
				<div class="login-top-wrap">
					<span>Don't have an account?</span>
					<button class="create-account-btn shadow-light"
						onclick="location.href='members/join';">Create Profile</button>
				</div>
				<form name=form2 action="members/login/" method="post">
					<div class="login-input-container">
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
						<input type="submit" class="login-btn" value="Login">
					</div>
				</form>
			</div>
		</div>
	</div>
</body>
</html>
