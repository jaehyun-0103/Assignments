package DO;

import java.math.BigDecimal;

public class Review {
	
	private int review_id;
	private String review_title;
	private String review_content;
	private int review_rate;
	private String review_created_at;
	private int movie_id;
	private int member_id;
	private String movie_title;
	private String member_nickname;
	
	
	public Review() {
		
	}
 	
	
	public int getReview_id() {
		return review_id;
	}


	public void setReview_id(int review_id) {
		this.review_id = review_id;
	}



	public String getReview_title() {
		return review_title;
	}



	public void setReview_title(String review_title) {
		this.review_title = review_title;
	}



	public String getReview_content() {
		return review_content;
	}



	public void setReview_content(String review_content) {
		this.review_content = review_content;
	}


	public int getReview_rate() {
		return review_rate;
	}


	public void setReview_rate(int review_rate) {
		this.review_rate = review_rate;
	}


	public String getReview_created_at() {
		return review_created_at;
	}



	public void setReview_created_at(String review_created_at) {
		this.review_created_at = review_created_at;
	}



	public int getMovie_id() {
		return movie_id;
	}



	public void setMovie_id(int movie_id) {
		this.movie_id = movie_id;
	}



	public int getMember_id() {
		return member_id;
	}



	public void setMember_id(int member_id) {
		this.member_id = member_id;
	}


	public String getMovie_title() {
		return movie_title;
	}


	public void setMovie_title(String movie_title) {
		this.movie_title = movie_title;
	}


	public String getMember_nickname() {
		return member_nickname;
	}


	public void setMember_nickname(String member_nickname) {
		this.member_nickname = member_nickname;
	}

	

} 
