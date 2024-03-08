package DAO;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.http.HttpServletRequest;

import DO.Movie;

public class MoviesDAO {
	final String JDBC_DRIVER = "org.h2.Driver";
	final String JDBC_URL = "jdbc:h2:tcp://localhost/~/movie_review";
	
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
	
	public List<Movie> getAll() throws Exception {
		Connection conn = open();
		List<Movie> moviesList = new ArrayList<>();
		
		String sql = "select movie_id, movie_poster, movie_title, movie_release_date from movie";
		PreparedStatement pstmt = conn.prepareStatement(sql);
		ResultSet rs = pstmt.executeQuery();
		
		try(conn; pstmt; rs) {
			while(rs.next()) {
				Movie n = new Movie();
				n.setMovie_id(rs.getInt("movie_id"));
				n.setMovie_poster(rs.getString("movie_poster"));
				n.setMovie_title(rs.getString("movie_title"));
				n.setMovie_release_date(rs.getString("movie_release_date")); 
				
				moviesList.add(n);
			}
			return moviesList;			
		}
	}
	
	public List<Movie> searchMovies(String searchTerm) throws SQLException {
        Connection conn = open();
        List<Movie> searchResults = new ArrayList<>();

        String sql = "SELECT movie_id, movie_poster, movie_title, movie_release_date FROM movie WHERE movie_title LIKE ?";
        try (PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setString(1, "%" + searchTerm + "%");
            try (ResultSet rs = pstmt.executeQuery()) {
                while (rs.next()) {
                    Movie movie = new Movie();
                    movie.setMovie_id(rs.getInt("movie_id"));
                    movie.setMovie_poster(rs.getString("movie_poster"));
                    movie.setMovie_title(rs.getString("movie_title"));
                    movie.setMovie_release_date(rs.getString("movie_release_date"));
                    
                    searchResults.add(movie);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return searchResults;
    }

	public Movie getMovie(int movie_id) throws SQLException {
		Connection conn = open();
		Movie m = new Movie();
		String sql = "SELECT m.movie_id, m.movie_title, m.movie_release_date, m.movie_overview, m.movie_director, m.movie_genre, m.movie_poster, AVG(r.review_rate) as avgRate " +
         		"from movie m " +
         		"join review r on r.movie_id = m.movie_id where m.movie_id=?";
		PreparedStatement pstmt = conn.prepareStatement(sql);
		pstmt.setInt(1,  movie_id);
		ResultSet rs = pstmt.executeQuery();
		rs.next();
		
		try(conn; pstmt; rs) {
			m.setMovie_id(rs.getInt("movie_id"));
			m.setMovie_title(rs.getString("movie_title"));
			m.setMovie_release_date(rs.getString("movie_release_date"));
			m.setMovie_overview(rs.getString("movie_overview"));
			m.setMovie_director(rs.getString("movie_director"));
			m.setMovie_rate(rs.getFloat("avgRate"));
			m.setMovie_genre(rs.getString("movie_genre"));
			m.setMovie_poster(rs.getString("movie_poster"));
			pstmt.executeQuery();
			return m;
		}
	}
	
}
