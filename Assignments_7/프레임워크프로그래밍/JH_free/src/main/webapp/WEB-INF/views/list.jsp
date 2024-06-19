<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Club List</title>
<link
	href="https://fonts.googleapis.com/css2?family=Black+Han+Sans&display=swap"
	rel="stylesheet">
<link rel="stylesheet"
	href="${pageContext.request.contextPath}/resources/list.css"
	type="text/css"></link>
</head>

<body>
	<section>
		<div class="container">
			<h2>모임 목록</h2>
			<%
			Integer memberId = (Integer) session.getAttribute("memberId");
			%>
			<div class="button-container">
				<button onclick="location.href='create';">모임 생성</button>
				<span class="separator">|</span>
				<button onclick="location.href='../members/profile?id=${memberId}';">마이페이지</button>
				<span class="separator">|</span>
				<button onclick="location.href='../members/logout';">로그아웃</button>
			</div>
			<table>
				<tr>
					<th>모임 이름</th>
					<th>현재 인원</th>
					<th>정원</th>
				</tr>
				<c:forEach var="club" items="${clubs}">
					<tr>
						<td><a href="#" class="club-link"
							data-clubid="${club.clubId}"><c:out value="${club.clubName}" /></a></td>
						<td><c:out value="${club.currentMembers}" /></td>
						<td><c:out value="${club.capacity}" /></td>
					</tr>
				</c:forEach>
			</table>
		</div>
	</section>

</body>
<script>
        document.querySelectorAll('.club-link').forEach(link => {
            link.addEventListener('click', function(event) {
                event.preventDefault();

                const clubId = this.getAttribute('data-clubid');

                sessionStorage.setItem('selectedClubId', clubId);

                window.location.href = 'content/'+ clubId;
            });
        });
    </script>
</html>
