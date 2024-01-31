<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="javax.servlet.http.HttpSession" %>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>영화 감상 작성앱</title>
    <style>
    .navbar {
        min-height: 60px;
    }

    .navbar-brand,
    .navbar-nav .btn {
        line-height: 60px;
    }

    @media (max-width: 991.98px) {
        .navbar-collapse {
            display: flex !important;
            justify-content: center;
            max-height: initial;
            overflow: visible;
        }

        .navbar-nav {
            margin-top: 0;
            flex-direction: row !important;
            align-items: center;
        }

        .navbar-nav .btn {
            margin-top: 0;
            margin-left: 10px;
        }
    }
</style>
    
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-BmbxuPwQa2lc/FVzBcNJ7UAyJxM6wuqIj61tLrc4wSX0szH/Ev+nYRRuWlolflfl" crossorigin="anonymous">
</head>
<body>
     <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
    <div class="container">
        <a class="navbar-brand" href="#">영화 목록</a>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav ms-auto">
                <c:choose>
    				<c:when test="${empty sessionScope.memberId}">
        <form action="/movie_review/cuser?action=login" method="post">
            <button type="submit" class="btn btn-dark text-light" name="action" value="addUser">로그인</button>
        </form>
        <form action="/movie_review/cuser?action=register" method="post">
            <button type="submit" class="btn btn-dark text-light" name="action" value="addUser">회원가입</button>
        </form>
    </c:when>
    <c:otherwise>
        <form action="/movie_review/cuser?action=memberinfo" method="post">
            <button type="submit" class="btn btn-dark text-light" name="action">마이페이지</button>
        </form>
          <a href="/movie_review/login/logout.jsp" class="btn btn-dark text-light">로그아웃</a>
    </c:otherwise>
</c:choose>
            </ul>
        </div>
    </div>
</nav>

    <br>
<div class="col-md-6" style="float: right;">
    <form class = "float-right" action="moviesearch" method="get">
        <div class="input-group">
            <input type="text" class="form-control" placeholder="영화 검색" name="search">
            <div class="input-group-append">
                <button class="btn btn-outline-secondary" type="submit">검색</button>
            </div>
        </div>
    </form>
</div><br><br>
            
        <div class="row">
            <c:forEach var="movie" items="${movieslist}" varStatus="status">
                <div class="col-md-4 mt-3">
                    <div class="card">
                        <img class="card-img-top" src="${movie.movie_poster}" style="object-fit: cover; width: 100%; height: 580px;"> 
                        <div class="card-body">
                            <h5 class="card-title">${movie.movie_title}</h5>
                            <p class="card-text"> ${movie.movie_release_date}</p>
                          <a href="/movie_review/movies?action=getMovie&movie_id=${movie.movie_id}" class="btn btn-secondary">자세히 보기</a>
                          
                        </div>
                    </div>
                </div>
            </c:forEach>
        </div>
        <hr>
        <c:if test="${error != null}">
            <div class="alert alert-danger alert-dismissible fade show mt-3" role="alert">
                에러 발생: ${error}
                <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
            </div>
        </c:if>


    <!-- Bootstrap JS (optional, if you need JavaScript features from Bootstrap) -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js" integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0" crossorigin="anonymous"></script>

</body>
</html>
