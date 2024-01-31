<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<link rel="stylesheet"
	href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.rtl.min.css"
	integrity="sha384-nU14brUcp6StFntEOOEBvcJm4huWjB0OcIeQ3fltAfSmuZFrkAif0T+UtNGlKKQv"
	crossorigin="anonymous">
<script
	src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"
	integrity="sha384-C6RzsynM9kWDrMNeT87bh95OGNyZPhcTNXj1NW7RuBCsyN/o0jlpcV8Qyq46cDfL"
	crossorigin="anonymous"></script>
<title>영화 정보</title>
</head>
<style>
.navbar {
	min-height: 60px;
}

.navbar-brand, .navbar-nav .btn {
	line-height: 60px;
}
</style>
<body>
	<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
		<div class="container">
			<a class="navbar-brand" href="#">영화 정보</a>
		</div>
	</nav>

	<br>
	<div class='card w-75 mx-auto'>
		<div class='row g-0'>
			<div class='col-md-4'>
				<img src='${movie.movie_poster}' class='img-fluid'
					alt='Movie Poster'>
			</div>
			<div class='col-md-8'>
				<div class='card-body'>
					<p class='card-text'>
					<h3>${movie.movie_title}</p>
					</h3>
					<p class='card-text'>개봉연도 ${movie.movie_release_date}</p>
					<p class='card-text'>감독 ${movie.movie_director}</p>
					<p class='card-text'>평균 평점 ${movie.movie_rate}</p>
					<p class='card-text'>장르 ${movie.movie_genre}</p>
					<hr>
					<p class='card-text'>${movie.movie_overview}</p>
				</div>
			</div>
		</div>
	</div>
	<br>
	<div class="text-center">
		<c:choose>
			<c:when test="${not empty sessionScope.memberId}">
				<a href="writeReview?action=editReview&movie_id=${movie.movie_id}"
					class="btn btn-secondary">감상평 작성</a>
			</c:when>
		</c:choose>
		<a href="${request.contextPath}reviewList?action=reviewList&movie_id=${movie.movie_id}" class="btn btn-secondary">감상평 목록</a>
	</div>
</body>
</html>