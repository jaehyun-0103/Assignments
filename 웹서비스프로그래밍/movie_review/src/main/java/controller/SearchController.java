package controller;

import java.io.IOException;
import java.lang.reflect.Method;
import java.math.BigDecimal;
import java.sql.SQLException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import DAO.ReviewDAO;
import DAO.MoviesDAO;
import DO.Movie;
import DO.Review;

@WebServlet("/writeReview")
public class SearchController extends HttpServlet {
	private static final long serialVersionUID = 1L;

	private ReviewDAO Rdao;
	private MoviesDAO Mdao;
	private ServletContext ctx;

	private int member_id;
	private int movie_id;

	public void init(ServletConfig config) throws ServletException {
		super.init(config);
		Rdao = new ReviewDAO();
		ctx = getServletContext();
	}

	protected void service(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		String action = request.getParameter("action");
		Rdao = new ReviewDAO();

		String view = null;

		if ("editReview".equals(action)) {
			try {
				movie_id = Integer.valueOf(request.getParameter("movie_id"));
				view = "reviewWriteMovie/writeReview.jsp";
				RequestDispatcher dispatcher = request.getRequestDispatcher(view);
				dispatcher.forward(request, response);
			} catch (Exception e) {
				e.printStackTrace();
			}
		} else if ("beforeReview".equals(action)) {
			addReview(request, response);
		}
	}

	public void addReview(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		Review r = new Review();
		try {
			HttpSession session = request.getSession();
			member_id = (int) session.getAttribute("memberId");
			r.setMovie_id(movie_id);
			r.setMember_id(member_id);
			r.setReview_title(request.getParameter("review_title"));
			r.setReview_content(request.getParameter("review_content"));
			r.setReview_rate(Integer.valueOf(request.getParameter("review_rate")));
			Rdao.addReview(r);
			request.setAttribute("review", r);
			
			Mdao = new MoviesDAO();
			Movie movie = Mdao.getMovie(movie_id);
			request.setAttribute("movie", movie);
			
			RequestDispatcher dispatcher = request.getRequestDispatcher("reviewWriteMovie/search.jsp");
			dispatcher.forward(request, response);

		} catch (Exception e) {
			e.printStackTrace();
			ctx.log("리뷰 추가 과정에서 문제 발생");
			request.setAttribute("error", "리뷰가 정상적으로 등록되지 않았습니다");
		}
	}
}
