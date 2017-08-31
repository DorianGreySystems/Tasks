package Task.Books.entity;

import java.io.Serializable;

public class Book implements Serializable{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Integer id;
    private String title;
    private String publishDate;
    private Integer pageSize;
    private Integer price;
    
    public Book() {
    	
    }
    
    public Book(int id,String title,String publishDate,int pageSize,int price) {
        this.id = id;
        this.title = title;
        this.publishDate = publishDate;
        this.pageSize = pageSize;
        this.price = price;
    }

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getPublishDate() {
		return publishDate;
	}

	public void setPublishDate(String publishDate) {
		this.publishDate = publishDate;
	}

	public Integer getPageSize() {
		return pageSize;
	}

	public void setPageSize(Integer pageSize) {
		this.pageSize = pageSize;
	}

	public Integer getPrice() {
		return price;
	}

	public void setPrice(Integer price) {
		this.price = price;
	}

    
}
