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
<title>감상평 작성</title>
</head>
<body>
	<div class="card card-body">
		<form method="post"
			action="/movie_review/writeReview?action=beforeReview">
			<label class="form-label">제목</label><br>
			<textarea cols="200" rows="1" name="review_title"
				class="form-control"></textarea>
			<hr>
			<label class="form-label">내용</label><br>
			<textarea cols="200" rows="15" name="review_content"
				class="form-control"></textarea>
			<br> <label class="form-label">평점(1~5의 사이로 입력해주세요.)</label>
			<textarea cols="200" rows="1" name="review_rate" class="form-control"></textarea>
			<br>
			<button type="submit" class="btn btn-outline-secondary mt-3">작성</button>

		</form>
	</div>
</body>
</html>