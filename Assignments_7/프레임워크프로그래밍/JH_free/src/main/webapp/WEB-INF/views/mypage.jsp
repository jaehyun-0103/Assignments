<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>mypage</title>
<link
	href="https://fonts.googleapis.com/css2?family=Black+Han+Sans&display=swap"
	rel="stylesheet">
<link rel="stylesheet"
	href="${pageContext.request.contextPath}/resources/mypage.css"
	type="text/css"></link>
</head>
<body>
	<section>
		<div class="container">
			<h2>회원 정보 수정</h2>
			<button class="exit" onclick="location.href='../groups/list';">나가기</button>
			<%
			Integer memberId = (Integer) session.getAttribute("memberId");
			%>
			<div class="info">
				<div class="info write">
					<form name=form1 action="../members/modify/" method="post">
						<table>
							<tr>
								<th>Email</th>
								<td><input type="text" name="email" readonly
									value="${member.email}"></td>
							</tr>
							<tr>
								<th>Password</th>
								<td><input type="text" name="password"
									value="${member.password}"></td>

							</tr>
							<tr>
								<th>MemberName</th>
								<td><input type="text" name="memberName"
									value="${member.memberName}"></td>
							</tr>
						</table>
						<div class="button">
							<input type="hidden" name="memberId" value="<%=memberId%>">
							<input type="submit" name="submit" value="최종 수정"> <input
								type="reset" name="reset" value="다시작성">
						</div>
					</form>

				</div>
			</div>
		</div>
		<button class="custom-button"
			onclick="location.href='../members/delete/<%=memberId%>';">회원
			탈퇴></button>


	</section>
</body>

</html>
