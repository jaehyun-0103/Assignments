<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head>
<title>감상평 목록</title>
<link
	href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css"
	rel="stylesheet">
<style>
.review-card {
	margin-bottom: 20px;
	position: relative;
}

.card-date {
	position: absolute;
	bottom: 10px;
	right: 10px;
}

.navbar {
	min-height: 60px;
}

.navbar-brand, .navbar-nav .btn {
	line-height: 60px;
}

.sort-buttons {
	display: flex;
	margin: 20px 0;
	justify-content: flex-end;
}

.sort-buttons a {
	text-decoration: none;
	padding: 10px 10px;
	border: 2px solid #333;
	border-radius: 5px;
	color: #333;
	transition: all 0.3s ease;
}

.sort-buttons a:hover {
	background-color: #333;
	color: #fff;
}
</style>
</head>
<body>
	<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
		<div class="container">
			<a class="navbar-brand" href="#">영화 정보</a>
		</div>
	</nav>

	<div class="container mt-4">
		<h1>감상평 목록</h1>

		<div class="sort-buttons">
			<a href="${request.contextPath}/movie_review/reviewList?sort=date">최신날짜순</a>
			<a href="${request.contextPath}/movie_review/reviewList?sort=rating">평점높은순</a>
		</div>

		<div class="row mt-4">
			<c:forEach var="review" items="${reviewlist}">
				<div class="col-md-12">
					<div class="card review-card">
						<div class="card-body">
							<h5 class="card-title">${review.review_title}</h5>
							평점: ${review.review_rate}
							<p class="card-text">작성자: ${review.member_nickname}</p>
							<p class="card-text">${review.review_content}</p>
						</div>
						<br>
							<span class="card-date">
							<script>
								var reviewDate = new Date(
										'${review.review_created_at}');
								document.write(reviewDate.toISOString()
										.slice(0, 16).replace("T", " "));
							</script>
						</span>
					</div>
				</div>
			</c:forEach>
		</div>
	</div>

</body>
</html>
