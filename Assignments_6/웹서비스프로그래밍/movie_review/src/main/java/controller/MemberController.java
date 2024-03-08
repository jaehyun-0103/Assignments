package controller;

import java.io.IOException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import DO.Member;
import DO.Review;
import DAO.MemberDAO;
import DAO.ReviewDAO;

@WebServlet("/cuser")
public class MemberController extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
	private MemberDAO dao;
	private ReviewDAO reviewDAO;
	private ServletContext ctx;
	
	private int member_id;
	
	
	public void init(ServletConfig config) throws ServletException {
		super.init(config);
		dao = new MemberDAO();
		ctx = getServletContext();
	}

	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		String action = request.getParameter("action");
		
		String view = null;
		
		if ("register".equals(action)) {
		    view = "login/register.jsp";
		    RequestDispatcher dispatcher = request.getRequestDispatcher(view);
			dispatcher.forward(request, response);	
		} else if ("login".equals(action)) {
		    view = "login/login.jsp";
		    RequestDispatcher dispatcher = request.getRequestDispatcher(view);
			dispatcher.forward(request, response);	
		} else if ("join".equals(action)) {
			login(request, response);
		} else if ("addUser".equals(action)) {
		    addUser(request);
		    view = "login/login.jsp";
		    RequestDispatcher dispatcher = request.getRequestDispatcher(view);
			dispatcher.forward(request, response);	
		} else if ("memberinfo".equals(action)) {
			getUser(request);
			view = "login/profile.jsp";
		    RequestDispatcher dispatcher = request.getRequestDispatcher(view);
			dispatcher.forward(request, response);	
		} else if ("memberedit".equals(action)) {
			updateUser(request);
			getUser(request);
			view = "login/profile.jsp";
		    RequestDispatcher dispatcher = request.getRequestDispatcher(view);
			dispatcher.forward(request, response);	
		}
	}
	
    public void updateUser(HttpServletRequest request) {
    	Member n = new Member();
		try {
			HttpSession session = request.getSession();
			int member_id = (int) session.getAttribute("memberId");
			
            String username = request.getParameter("nameEdit");
            String password = request.getParameter("passwordEdit");
            String nickname = request.getParameter("nicknameEdit");
            
            n.setMember_id(member_id);
            n.setMember_name(username);
            n.setMember_password(password);
            n.setMember_nickname(nickname);
			
			dao.updateUser(n);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public void getUser(HttpServletRequest request) {
		HttpSession session = request.getSession();
		int member_id = (int) session.getAttribute("memberId");
    	ReviewDAO reviewDAO = new ReviewDAO();
		List<Review> reviewlist = null;
		try {
			Member member = dao.getUser(member_id);
			request.setAttribute("member", member);
			
			reviewlist = reviewDAO.getReview(member_id);
			request.setAttribute("reviewlist", reviewlist);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
    
    public void addUser(HttpServletRequest request) {
    	Member n = new Member();
		try {
			
            String username = request.getParameter("member_name");
            String password = request.getParameter("member_password");
            String nickname = request.getParameter("member_nickname");
            
            n.setMember_name(username);
            n.setMember_password(password);
            n.setMember_nickname(nickname);
			
			dao.addUser(n);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
    
    public void login(HttpServletRequest request, HttpServletResponse response) {
    	Member n = new Member();
        String view = null;
        String errorMessage = null;
        int memberId;
		
        try {
        	String MemberName = request.getParameter("member_name");
            String MemberPassword = request.getParameter("member_password");
            
            n.setMember_name(MemberName);
            n.setMember_password(MemberPassword);

            boolean loginSuccess = dao.login(n);
            if (loginSuccess) {
            	memberId = n.getMember_id();
            	
            	HttpSession session = request.getSession();
    		    session.setAttribute("memberId", memberId);
    		    
            	response.sendRedirect(request.getContextPath() + "/movies");
                
    			RequestDispatcher dispatcher = request.getRequestDispatcher(view);
    			dispatcher.forward(request, response);	
            } else {
            	errorMessage = "Invalid username or password. Please try again.";
                request.setAttribute("errorMessage", errorMessage);
                
            	view = "login/login.jsp";
    			RequestDispatcher dispatcher = request.getRequestDispatcher(view);
    			dispatcher.forward(request, response);	
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}