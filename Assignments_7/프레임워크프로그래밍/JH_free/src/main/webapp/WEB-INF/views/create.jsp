<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>create</title>
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link
	href="https://fonts.googleapis.com/css2?family=Black+Han+Sans&display=swap"
	rel="stylesheet">
<link rel="stylesheet"
	href="${pageContext.request.contextPath}/resources/create.css"
	type="text/css"></link>
</head>

<body>
	<section>
		<div class="container">
			<h2>모임 생성</h2>
			<button class="exit" onclick="location.href='../groups/list';">나가기</button>
			<%
			Integer memberId = (Integer) session.getAttribute("memberId");
			%>
			<div class="content">
				<div class="contents write">
					<form name="content" method="post" onsubmit="return validateForm()">
						<table>
							<tr>
								<th>모임이름</th>
								<td><input type="text" name="clubName" size="52"
									placeholder="모임 이름을 입력해주세요."></td>
							</tr>
							<tr>
								<th>내용</th>
								<td><textarea name="description" rows="10" cols="80"
										placeholder="내용을 입력해주세요." style="resize: none"></textarea></td>
							</tr>
							<tr>
								<th>카테고리</th>
								<td><select name="category">
										<option value="운동">운동</option>
										<option value="게임">게임</option>
										<option value="여행">여행</option>
										<option value="공연">공연</option>
										<option value="요리">요리</option>
										<option value="음악">음악</option>
										<option value="봉사">봉사</option>
										<option value="댄스">댄스</option>
								</select></td>
							</tr>
							<tr>
								<th>지역</th>
								<td><select name="location">
										<option value="서울" selected>서울</option>
										<option value="경기">경기</option>
										<option value="인천">인천</option>
										<option value="강원">강원</option>
										<option value="충북">충북</option>
										<option value="충남">충남</option>
										<option value="대전">대전</option>
										<option value="세종">세종</option>
										<option value="전북">전북</option>
										<option value="전남">전남</option>
										<option value="광주">광주</option>
										<option value="경북">경북</option>
										<option value="경남">경남</option>
										<option value="대구">대구</option>
										<option value="울산">울산</option>
										<option value="부산">부산</option>
										<option value="제주">제주</option>
								</select></td>
							</tr>
							<tr>
								<th>장소</th>
								<td><input type="text" name="venue" size="52"
									placeholder="모임 장소를 입력해주세요."></td>
							</tr>
							<tr>
								<th>주기</th>
								<td><select name="meetingDate">
										<option value="월요일" selected>월요일</option>
										<option value="화요일">화요일</option>
										<option value="수요일">수요일</option>
										<option value="목요일">목요일</option>
										<option value="금요일">금요일</option>
										<option value="토요일">토요일</option>
										<option value="일요일">일요일</option>
								</select>
							</tr>
							<tr>
								<th>정원</th>
								<td><select name="capacity">
										<option value="3" selected>3</option>
										<option value="4">4</option>
										<option value="5">5</option>
										<option value="6">6</option>
										<option value="7">7</option>
										<option value="8">8</option>
										<option value="9">9</option>
										<option value="10">10</option>
										<option value="11">11</option>
								</select></td>
							</tr>
						</table>
						<input type="hidden" name="leaderId" value="<%=memberId%>">
						<div class="button">
							<input type="submit" value="모임 만들기">
						</div>
					</form>
				</div>
			</div>
		</div>
	</section>
</body>
<script>
	function validateForm() {
		var clubName = document.forms["content"]["clubName"].value;
		var description = document.forms["content"]["description"].value;
		var venue = document.forms["content"]["venue"].value;

		if (clubName == "" || description == "" || venue == "") {
			alert("모든 정보를 입력하세요.");
			return false;
		}
		return true;
	}
</script>
</html>
