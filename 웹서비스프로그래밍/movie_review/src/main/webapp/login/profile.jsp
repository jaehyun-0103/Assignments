<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.util.*"%>
<%@ page import="java.text.*"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
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
<link
	href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css"
	rel="stylesheet">
<script
	src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js"
	integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0"
	crossorigin="anonymous"></script>
<style>
.half-hr {
	border: none;
	border-top: 2px solid #000;
	width: 500px;
	margin: auto;
}

.container {
	max-width: 400px;
}

.custom-navbar {
	min-height: 85px !important;
}

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
</style>
<title>마이페이지</title>
</head>
<script>
	function toggleFormVisibility() {
		var viewForm = document.getElementById("viewForm");
		var editForm = document.getElementById("editForm");

		if (viewForm.style.display === "none") {
			viewForm.style.display = "block";
			editForm.style.display = "none";
		} else {
			viewForm.style.display = "none";
			editForm.style.display = "block";
		}
	}
	function saveForm() {
		var form = document.getElementById('editForm');
        form.submit();
        location.reload();
	}

	function cancelForm() {
		document.getElementById("nicknameEdit").value = "${member.member_nickname}";
	    document.getElementById("nameEdit").value = "${member.member_name}";
	    document.getElementById("passwordEdit").value = "${member.member_password}";
		location.reload();
	}
</script>
<body>
	<nav class="navbar navbar-expand-lg navbar-dark bg-dark custom-navbar">
		<div class="container">
			<a class="navbar-brand" href="#">영화 정보</a>
		</div>
	</nav>

	<div class="container">
		<div class="jumbotron" style="padding-top: 20px;" id="viewForm">
			<form method="post" >
				<h3 style="text-align: center;">마이 페이지</h3>
				<br>
				<h4>회원 정보</h4>
				<hr>

				<div class="form-group">
					<div>
						<label for="nickname">닉네임</label> <br> <input type="text"
							class="form-control" id="member_nickname"
							value="${member.member_nickname}" readonly>
					</div>
					<br>
					<div>
						<label for="id">아이디</label> <br> <input type="text"
							class="form-control" id="member_name" value="${member.member_name}"
							readonly>
					</div>
					<br>
					<div>
						<label for="password">비밀번호</label> <br> <input type="text"
							class="form-control" id="member_password"
							value="${member.member_password}" readonly>
					</div>
					<br>

				</div>
			</form>
			<button onclick="toggleFormVisibility()" class="btn btn-primary">수정</button>
		</div>
	</div>
	<div class="container">
		<div class="jumbotron" style="padding-top: 20px; display: none;"
			id="editForm">
			<form method="post" action="/movie_review/cuser?action=memberedit">
				<h3 style="text-align: center;">마이 페이지</h3>
				<br>
				<h4>회원 정보</h4>
				<hr>

				<div class="form-group">
					<div>
						<label for="nickname">닉네임</label> <br> <input type="text"
							class="form-control" id="nicknameEdit" name="nicknameEdit" 
							value="${member.member_nickname}">
					</div>
					<br>
					<div>
						<label for="id">아이디</label> <br> <input type="text"
							class="form-control" id="nameEdit" name="nameEdit" value="${member.member_name}">
					</div>
					<br>
					<div>
						<label for="password">비밀번호</label> <br> <input type="text"
							class="form-control" id="passwordEdit" name="passwordEdit"
							value="${member.member_password}">
					</div>
					<br>
					<button onclick="saveForm()" class="btn btn-primary">저장</button>
					<button onclick="cancelForm()" class="btn btn-primary">취소</button>
				</div>
			</form>

		</div>
	</div>

	<br>
	<hr class="half-hr">
	<br>
	<div class="container mt-4">
		<div class="row mt-4">
			<br>
			<h4>리뷰 내역</h4>
			<hr>
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
