package Task.Books.entity;

import java.util.List;

public class Author {
	
	private final int id;
	private final String name;
	private final List<Integer> booksIds; 
	
	Author(int id,String name,List<Integer> booksIds){
		this.id = id;
		this.name = name;
		this.booksIds = booksIds;
	}
	
	public int getId() {
		return id;
	}
	
	public String getName() {
		return name;
	}
	
	public List<Integer> getBooks(){
		return booksIds;
	}

}