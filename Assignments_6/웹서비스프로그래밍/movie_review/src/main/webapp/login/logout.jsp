<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="javax.servlet.http.HttpSession" %>
<%
    // 세션 무효화
    session = request.getSession(false); // 현재 세션 가져오기 (세션이 없으면 생성하지 않음)
    if (session != null) {
        session.invalidate(); // 세션 무효화
    }
    response.sendRedirect("/movie_review/movies"); // 로그아웃 후 movieList.jsp로 이동
%>
