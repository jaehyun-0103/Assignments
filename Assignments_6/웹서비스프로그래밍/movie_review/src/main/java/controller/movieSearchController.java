package controller;

import java.io.IOException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import DAO.MoviesDAO;
import DO.Movie;

@WebServlet("/moviesearch")
public class movieSearchController extends HttpServlet {
    private static final long serialVersionUID = 1L;
    
    private MoviesDAO dao;

    public void init() throws ServletException {
        dao = new MoviesDAO();
    }
    
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String searchTerm = request.getParameter("search");
        if (searchTerm == null || searchTerm.trim().isEmpty()) {
        	 response.sendRedirect("/movie_review/movies"); // 홈 화면으로 리다이렉트
             return; // 코드 실행 중지
        }
        
        List<Movie> searchResults;
        try {
            searchResults = dao.searchMovies(searchTerm);
            if (searchResults.isEmpty()) {
                request.setAttribute("noResultMessage", "검색 결과가 없습니다.");
            } else {
                request.setAttribute("searchResults", searchResults);
            }
            RequestDispatcher dispatcher = request.getRequestDispatcher("movieListSearch/searchResult.jsp");
            dispatcher.forward(request, response);
        } catch (Exception e) {
            e.printStackTrace();
            request.setAttribute("error", "영화 검색이 정상적으로 처리되지 않았습니다!!");
            RequestDispatcher dispatcher = request.getRequestDispatcher("movieListSearch/searchResult.jsp");
            dispatcher.forward(request, response);
        }
    }

}
