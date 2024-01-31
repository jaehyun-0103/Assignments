package controller;

import DAO.ReviewDAO;
import DO.Review;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/reviewList")
public class ReviewController extends HttpServlet {
	private ReviewDAO reviewDAO;
	private ServletContext sc;
	private String movieId;

	@Override
	public void init(ServletConfig config) throws ServletException {
		super.init(config);
		reviewDAO = new ReviewDAO();
		sc = getServletContext();
	}

	protected void service(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		String action = request.getParameter("action");

		String sortType = request.getParameter("sort");
		ReviewDAO reviewDAO = new ReviewDAO();
		List<Review> reviewList = null;

		try {
			if ("date".equals(sortType)) {
				int movie_id = Integer.parseInt(movieId);
				reviewList = reviewDAO.getAllSortedByDate(movie_id);
			} else if ("rating".equals(sortType)) {
				int movie_id = Integer.parseInt(movieId);
				reviewList = reviewDAO.getAllSortedByRating(movie_id);
			} else {
				movieId =request.getParameter("movie_id");
				int movie_id = Integer.parseInt(movieId);
				reviewList = reviewDAO.getAll(movie_id);
			}

			request.setAttribute("reviewlist", reviewList);

			RequestDispatcher dispatcher = request.getRequestDispatcher("reviewList/reviewList.jsp");
			dispatcher.forward(request, response);

		} catch (Exception e) {
			e.printStackTrace();
			response.getWriter().println("에러 발생");
		}
	}
}
