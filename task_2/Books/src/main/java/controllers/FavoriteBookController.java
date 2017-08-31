package controllers;

import java.util.ArrayList;
import java.util.List;

import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import Task.Books.entity.Book;

@RestController
public class FavoriteBookController {
	
	private List<Book> favoriteBooks = null;
	
	public FavoriteBookController()
	{
		favoriteBooks = new ArrayList<Book>();
	}

	// Return all favorite books
    @RequestMapping(value = "/favoritebook", method = RequestMethod.GET)
    @ResponseBody 
    public List<Book> favoritebook() {
        return favoriteBooks;
    }
    
    // Add book to favorite books
    @RequestMapping(value = "/favoritebook", method = RequestMethod.PUT) 
	public void updateBookList(@RequestBody Book book) {
    	favoriteBooks.add(book);
	}
}
