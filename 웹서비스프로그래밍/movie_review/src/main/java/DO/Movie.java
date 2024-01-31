package DO;

public class Movie {
	private int movie_id;
	private String movie_title;
	private String movie_release_date;
	private String movie_director;
	private String movie_overview;
	private float movie_rate;
	private String movie_genre;
	private String movie_poster;
	
	public Movie() {
		
	}

	
	public String getMovie_director() {
		return movie_director;
	}


	public void setMovie_director(String movie_director) {
		this.movie_director = movie_director;
	}


	public int getMovie_id() {
		return movie_id;
	}

	public void setMovie_id(int movie_id) {
		this.movie_id = movie_id;
	}
	

	public String getMovie_title() {
		return movie_title;
	}


	public void setMovie_title(String movie_title) {
		this.movie_title = movie_title;
	}


	public String getMovie_release_date() {
		return movie_release_date;
	}

	public void setMovie_release_date(String movie_release_date) {
		this.movie_release_date = movie_release_date;
	}

	public String getMovie_overview() {
		return movie_overview;
	}

	public void setMovie_overview(String movie_overview) {
		this.movie_overview = movie_overview;
	}

	public float getMovie_rate() {
		return movie_rate;
	}

	public void setMovie_rate(float movie_rate) {
		this.movie_rate = movie_rate;
	}

	public String getMovie_genre() {
		return movie_genre;
	}

	public void setMovie_genre(String movie_genre) {
		this.movie_genre = movie_genre;
	}

	public String getMovie_poster() {
		return movie_poster;
	}

	public void setMovie_poster(String movie_poster) {
		this.movie_poster = movie_poster;
	}

}
