<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>content</title>
<link rel="stylesheet"
	href="${pageContext.request.contextPath}/resources/content.css"
	type="text/css">
<link
	href="https://fonts.googleapis.com/css2?family=Black+Han+Sans&display=swap"
	rel="stylesheet">
</head>

<body>
	<section>
		<div class="container">
			<h2>모임 정보</h2>
			<button class="exit" onclick="location.href='../list';">나가기</button>
			<div class="info">
				<div class="info write">
					<table>
						<%
						Integer memberId = (Integer) session.getAttribute("memberId");
						if (memberId == null) {
							memberId = -1;
						}
						String memberIdStr = memberId.toString();
						%>
						<c:forEach var="club" items="${contents}">
							<tr>
								<th>모임 이름</th>
								<td>${club.clubName}</td>
							</tr>
							<tr>
								<th>리더 이름</th>
								<td>${club.leaderName}</td>
							</tr>
							<tr>
								<th>카테고리</th>
								<td>${club.category}</td>
							</tr>
							<tr>
								<th>설명</th>
								<td>${club.description}</td>
							</tr>
							<tr>
								<th>요일</th>
								<td>${club.meetingDate}</td>
							</tr>
							<tr>
								<th>장소</th>
								<td>${club.location}, ${club.venue}</td>
							</tr>
							<tr>
								<th>구성원</th>
								<td>${club.memberNames}</td>
							</tr>
							<tr>
								<th>정원</th>
								<td>${club.currentMembers} / ${club.capacity}</td>
							</tr>
						</c:forEach>
					</table>
				</div>
			</div>
		</div>

		<c:forEach var="club" items="${contents}">
			<c:set var="leaderId" value="${club.leaderId}" />
			<c:set var="memberIdsArrayStr"
				value="${fn:split(club.memberIds, ',')}" />
			<%
			String[] memberIdsArrayStr = (String[]) pageContext.getAttribute("memberIdsArrayStr");
			int[] memberIdsArray;
			if (memberIdsArrayStr != null) {
				memberIdsArray = new int[memberIdsArrayStr.length];
				for (int i = 0; i < memberIdsArrayStr.length; i++) {
					try {
				memberIdsArray[i] = Integer.parseInt(memberIdsArrayStr[i].trim());
					} catch (NumberFormatException e) {
				memberIdsArray[i] = -1;
					}
				}
			} else {
				memberIdsArray = new int[0];
			}

			boolean isMember = false;
			for (int id : memberIdsArray) {
				if (id == memberId) {
					isMember = true;
					break;
				}
			}
			%>
			<c:choose>
				<c:when test="${leaderId eq memberId}">
					<div class="button">
						<input type="button"
							onclick="location.href='../delete/${club.clubId}';" value="삭제">
					</div>
				</c:when>
				<c:when test="<%=isMember%>">
					<form name="form1" action="../../memberships/delete" method="post"
						enctype="application/x-www-form-urlencoded;charset=UTF-8">
						<input type="hidden" name="memberId" value="<%=memberIdStr%>">
						<input type="hidden" name="clubId" value="${club.clubId}">
						<div class="button">
							<input type="submit" class="login-btn" value="탈퇴">
						</div>
					</form>
				</c:when>
				<c:otherwise>
					<c:choose>
						<c:when test="${club.currentMembers ge club.capacity}">
							<div class="button">
								<input type="button" value="초과">
							</div>
						</c:when>
						<c:otherwise>
							<form name="form2" action="../../memberships/contact"
								method="post"
								enctype="application/x-www-form-urlencoded;charset=UTF-8">
								<input type="hidden" name="memberId" value="<%=memberIdStr%>">
								<input type="hidden" name="clubId" value="${club.clubId}">
								<div class="button">
									<input type="submit" value="참가">
								</div>
							</form>
						</c:otherwise>
					</c:choose>
				</c:otherwise>
			</c:choose>
		</c:forEach>
	</section>
</body>
</html>
