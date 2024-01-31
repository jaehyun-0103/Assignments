package DAO;

import DO.Movie;
import DO.Review;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ReviewDAO {
	final String JDBC_DRIVER = "org.h2.Driver";
	final String JDBC_URL = "jdbc:h2:tcp://localhost/~/movie_review";
	
	public Connection open(){
		Connection conn = null;
		try {
			Class.forName(JDBC_DRIVER);
			conn = DriverManager.getConnection(JDBC_URL, "m", "1");
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return conn;
	}
	
	public List<Review> getAll(int movie_id) throws Exception {
		Connection conn = open();
		List<Review> ReviewList = new ArrayList<>();
		
		String sql ="select r.review_id, r.review_title, r.review_content, m.member_nickname, PARSEDATETIME(r.review_created_at, 'yyyy-MM-dd HH:mm:ss') as cdate, r.review_rate, mv.movie_title " +
             		"from review r " +
             		"join member m on r.member_id = m.member_id " +
             		"join movie mv on r.movie_id = mv.movie_id " +
	                "WHERE mv.movie_id = ?";

		PreparedStatement pstmt = conn.prepareStatement(sql);
		pstmt.setInt(1, movie_id);
		ResultSet rs = pstmt.executeQuery();
		
		try(conn; pstmt; rs) {
			while(rs.next()) {
				Review r = new Review();
				
				r.setReview_id(rs.getInt("review_id"));
				r.setReview_title(rs.getString("review_title"));
				r.setReview_content(rs.getString("review_content"));
				r.setMember_nickname(rs.getString("member_nickname"));
				r.setReview_created_at(rs.getString("cdate"));
				r.setReview_rate(rs.getInt("review_rate"));
				r.setMovie_title(rs.getString("movie_title"));
				
				ReviewList.add(r);
				
			}
		}

		return ReviewList;
	}
	
	public List<Review> getAllSortedByDate(int movie_id) throws Exception {
	    Connection conn = open();
	    List<Review> ReviewList = new ArrayList<>();
	    
		String sql ="select r.review_id, r.review_title, r.review_content, m.member_nickname, PARSEDATETIME(r.review_created_at, 'yyyy-MM-dd HH:mm:ss') as cdate, r.review_rate, mv.movie_title " +
             		"from review r " +
             		"join member m on r.member_id = m.member_id " +
             		"join movie mv on r.movie_id = mv.movie_id " +
	                "WHERE mv.movie_id = ? " +
             		"order by cdate desc";

	    PreparedStatement pstmt = conn.prepareStatement(sql);
	    pstmt.setInt(1, movie_id);
	    ResultSet rs = pstmt.executeQuery();
	    
	    try (conn; pstmt; rs) {
	        while (rs.next()) {
	            Review r = new Review();

				r.setReview_id(rs.getInt("review_id"));
				r.setReview_title(rs.getString("review_title"));
				r.setReview_content(rs.getString("review_content"));
				r.setMember_nickname(rs.getString("member_nickname"));
				r.setReview_created_at(rs.getString("cdate"));
				r.setReview_rate(rs.getInt("review_rate"));
				r.setMovie_title(rs.getString("movie_title"));
				
				ReviewList.add(r);
	        }
	    }

	    return ReviewList;
	}

	public List<Review> getAllSortedByRating(int movie_id) throws Exception {
	    Connection conn = open();
	    List<Review> ReviewList = new ArrayList<>();
	    
		String sql ="select r.review_id, r.review_title, r.review_content, m.member_nickname, PARSEDATETIME(r.review_created_at, 'yyyy-MM-dd HH:mm:ss') as cdate, r.review_rate, mv.movie_title " +
             		"from review r " +
             		"join member m on r.member_id = m.member_id " +
             		"join movie mv on r.movie_id = mv.movie_id " +
	                "WHERE mv.movie_id = ? " +
             		"order by review_rate desc";

	    PreparedStatement pstmt = conn.prepareStatement(sql);
	    pstmt.setInt(1, movie_id);
	    ResultSet rs = pstmt.executeQuery();
	    
	    try (conn; pstmt; rs) {
	        while (rs.next()) {
	            Review r = new Review();
	            
				r.setReview_id(rs.getInt("review_id"));
				r.setReview_title(rs.getString("review_title"));
				r.setReview_content(rs.getString("review_content"));
				r.setMember_nickname(rs.getString("member_nickname"));
				r.setReview_created_at(rs.getString("cdate"));
				r.setReview_rate(rs.getInt("review_rate"));
				r.setMovie_title(rs.getString("movie_title"));
				
				ReviewList.add(r);          
	        }
	    }

	    return ReviewList;
	}

	public void addReview(Review r) throws Exception {
		Connection conn = open();
		String sql = "insert into REVIEW(review_title,review_content,review_rate,member_id,movie_id) values(?,?,?,?,?)";
		PreparedStatement pstmt = conn.prepareStatement(sql);
		
		try(conn; pstmt) {
			pstmt.setString(1, r.getReview_title());
			pstmt.setString(2, r.getReview_content());
			pstmt.setInt(3, r.getReview_rate());
			pstmt.setInt(4, r.getMember_id());
			pstmt.setInt(5, r.getMovie_id());
			pstmt.executeUpdate();
			
		}
	}
	
	public List<Review> getReview(int member_id) throws Exception {
		Connection conn = open();
		List<Review> ReviewList = new ArrayList<>();
		
		String sql ="SELECT r.review_id, r.review_title, r.review_content, m.member_nickname, PARSEDATETIME(r.review_created_at, 'yyyy-MM-dd HH:mm:ss') as cdate, r.review_rate, mv.movie_title " +
	             "FROM review r " +
	             "JOIN member m ON r.member_id = m.member_id " +
	             "JOIN movie mv ON r.movie_id = mv.movie_id " +
	             "WHERE m.member_id = ?";

		PreparedStatement pstmt = conn.prepareStatement(sql);
		pstmt.setInt(1,  member_id);
		ResultSet rs = pstmt.executeQuery();
		
		try(conn; pstmt; rs) {
			while(rs.next()) {
				Review r = new Review();
				
				r.setReview_id(rs.getInt("review_id"));
				r.setReview_title(rs.getString("review_title"));
				r.setReview_content(rs.getString("review_content"));
				r.setMember_nickname(rs.getString("member_nickname"));
				r.setReview_created_at(rs.getString("cdate"));
				r.setReview_rate(rs.getInt("review_rate"));
				r.setMovie_title(rs.getString("movie_title"));
				
				ReviewList.add(r);
				
			}
		}

		return ReviewList;
	}
}


