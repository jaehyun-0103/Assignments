package DAO;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import DO.Member;
import DO.Movie;
import DO.Review;

public class MemberDAO {
	final String JDBC_DRIVER = "org.h2.Driver";
	final String JDBC_URL = "jdbc:h2:tcp://localhost/~/movie_review";
	
	// DB 연결을 가져오는 메서드, DBCP를 사용하는 것이 좋음
	public Connection open() {
		Connection conn = null;
		try {
			Class.forName(JDBC_DRIVER);
			conn = DriverManager.getConnection(JDBC_URL,"m","1");
		} catch (Exception e) {
			e.printStackTrace();
		}
		return conn;
	}
	
	public void updateUser(Member n) throws Exception {
		Connection conn = open();
		
		String sql = "UPDATE member SET member_name=?, member_nickname=?, member_password=? WHERE member_id=?";
		PreparedStatement pstmt = conn.prepareStatement(sql);
		
		try(conn; pstmt) {
			pstmt.setString(1, n.getMember_name());
			pstmt.setString(2, n.getMember_nickname());
			pstmt.setString(3, n.getMember_password());
			pstmt.setInt(4, n.getMember_id());
			pstmt.executeUpdate();
		}
	}
	
	public void addUser(Member n) throws Exception {
		Connection conn = open();
		
		String sql = "insert into member(member_name, member_password, member_nickname) values(?,?,?)";
		PreparedStatement pstmt = conn.prepareStatement(sql);
		
		try(conn; pstmt) {
			pstmt.setString(1, n.getMember_name());
			pstmt.setString(2, n.getMember_password());
			pstmt.setString(3, n.getMember_nickname());
			pstmt.executeUpdate();
		}
	}

	public boolean login(Member user) throws SQLException {
	    Connection conn = open();

	    String sql = "SELECT * FROM member WHERE member_name = ? AND member_password = ?";
	    try (PreparedStatement pstmt = conn.prepareStatement(sql)) {
	        pstmt.setString(1, user.getMember_name());
	        pstmt.setString(2, user.getMember_password());
	        try (ResultSet rs = pstmt.executeQuery()) {
	            if (rs.next()) {
	                // 로그인 성공
	            	int memberId = rs.getInt("member_id");
                    user.setMember_id(memberId);
	                return true;
	            } else {
	                // 로그인 실패
	                return false;
	            }
	        }
	    }
	}
	public Member getUser(int member_id) throws SQLException {
		Connection conn = open();
		Member m = new Member();
		String sql = "select * from member where member_id=?";
		PreparedStatement pstmt = conn.prepareStatement(sql);
		pstmt.setInt(1,  member_id);
		ResultSet rs = pstmt.executeQuery();
		rs.next();
		
		try(conn; pstmt; rs) {
			m.setMember_name(rs.getString("member_name"));
			m.setMember_password(rs.getString("member_password"));
			m.setMember_nickname(rs.getString("member_nickname"));
			pstmt.executeQuery();
			return m;
		}
	}
	
}