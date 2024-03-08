package controller;

import java.io.IOException;
import java.lang.reflect.Method;
import java.sql.SQLException;
import java.util.List;
import java.util.StringTokenizer;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;

import DO.Movie;
import DAO.MoviesDAO;

@WebServlet("/movies")
public class MoviesController extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	private MoviesDAO dao;
	private ServletContext ctx;
	
	private final String START_PAGE = "movieListSearch/moviesList.jsp";
	
	public void init(ServletConfig config) throws ServletException {
		super.init(config);
		dao = new MoviesDAO();
		ctx = getServletContext();		
	}

	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		String action = request.getParameter("action");
		
		dao = new MoviesDAO();
		
		Method m;
		String view = null;
		
		if (action == null) {
			action = "listMovies";
		}

		try {
			m = this.getClass().getMethod(action, HttpServletRequest.class);
			view = (String)m.invoke(this, request);
		} catch (NoSuchMethodException e) {
			e.printStackTrace();
			ctx.log("요청 action 없음!!");
			request.setAttribute("error", "action 파라미터가 잘못 되었습니다!!");
			view = START_PAGE;
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		if(view.startsWith("redirect:/")) {
			String rview = view.substring("redirect:/".length());
			response.sendRedirect(rview);
		} else {
			RequestDispatcher dispatcher = request.getRequestDispatcher(view);
			dispatcher.forward(request, response);	
		}
	}
    
	public String listMovies(HttpServletRequest request) {
    	List<Movie> list;
		try {
			list = dao.getAll();
	    	request.setAttribute("movieslist", list);

		} catch (Exception e) {
			e.printStackTrace();
			ctx.log("영화 목록 생성 과정에서 문제 발생!!");
			request.setAttribute("error", "영화 목록이 정상적으로 처리되지 않았습니다!!");
		}
    	return "movieListSearch/moviesList.jsp";
    }
	
	public String getMovie(HttpServletRequest request) {
	    String movieId = request.getParameter("movie_id");
	    
	    if (movieId != null && !movieId.isEmpty()) {
	        try {
	            dao = new MoviesDAO();
	            Movie movie = dao.getMovie(Integer.parseInt(movieId));

	            if (movie != null) {
	                request.setAttribute("movie", movie);
	                return "reviewWriteMovie/search.jsp";
	            } else {
	                request.setAttribute("error", "해당 ID의 영화를 찾을 수 없습니다.");
	                return "movieListSearch/moviesList.jsp";
	            }
	        } catch (NumberFormatException e) {
	            e.printStackTrace();
	            request.setAttribute("error", "유효하지 않은 영화 ID입니다.");
	            return "movieListSearch/moviesList.jsp";
	        } catch (SQLException e) {
	            e.printStackTrace();
	            request.setAttribute("error", "영화 정보를 가져오는 중에 오류가 발생했습니다.");
	            return "movieListSearch/moviesList.jsp";
	        } catch (Exception e) {
	            e.printStackTrace();
	            request.setAttribute("error", "예외가 발생했습니다.");
	            return "movieListSearch/moviesList.jsp";
	        } 
	    } else {
	        request.setAttribute("error", "영화 ID가 제공되지 않았습니다.");
	        return "movieListSearch/moviesList.jsp";
	    }
	}
}