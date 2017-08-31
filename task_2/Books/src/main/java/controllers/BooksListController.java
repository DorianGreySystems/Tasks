package controllers;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import Task.Books.entity.Book;

@RestController
public class BooksListController {
	
	List<Book> books = null;
	
    BooksListController()
    {
    	books = new  ArrayList<Book>();
    	
    	// Test data
    	Book b1 = new Book(101,"book_title_1","1796",300,800);
        Book b2 = new Book(102,"book_title_2","1796",300,800);
        Book b3 = new Book(103,"book_title_3","1796",300,800);
        
        books.add(b1);
        books.add(b2);
        books.add(b3);
    }
    
    
    // Get books by id
    @RequestMapping(value = "/booklist/{id}", method = RequestMethod.GET)
    @ResponseBody
    public List<Book> getBook(@PathVariable String id) {
    	int tempId = Integer.parseInt(id);
		List<Book> result = books.stream()
			     .filter(item -> item.getId() == tempId)
			     .collect(Collectors.toList());
		return result;
	}
	
    // Get all book list
	@RequestMapping(value = "/booklist", method = RequestMethod.GET)
	@ResponseBody 
	public List<Book> getBooklist() {
	    return books;
	}
	
	// Add book to book list
	@RequestMapping(value = "/booklist", method = RequestMethod.PUT) 
	public void updateBookList(@RequestBody Book book) {
		books.add(book);
	}
	
	// Remove book from list
	@RequestMapping(value = "/booklist/{id}", method = RequestMethod.DELETE) 
	public void deleteBook(@PathVariable String id) {
	 	int tempId = Integer.parseInt(id);
			List<Book> result = books.stream()
				     .filter(item -> item.getId() != tempId)
				     .collect(Collectors.toList());
    	books = result;   
	}
}
