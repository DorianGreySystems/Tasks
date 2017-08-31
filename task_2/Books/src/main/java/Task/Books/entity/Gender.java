package Task.Books.entity;

import java.util.List;

public class Gender {
	
	private final int id;
	private final String title;
	private final List<Integer> authorsIds;
	
	public Gender(int id,String title,List<Integer> authorsIds) {
		this.id = id;
		this.title = title;
		this.authorsIds = authorsIds;
	}
	
	public int getId() {
		return id;
	}
	
	public String getTitle() {
		return title;
	}

	public List<Integer> getAuthors(){
		return authorsIds;
	}
}
