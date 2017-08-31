package controllers;

import java.util.ArrayList;
import java.util.List;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import Task.Books.entity.Book;
import Task.Books.repo.BookRepo;

@RestController
public class BooksController {

	List<Book> books = null;
	
	BooksController()
	{
		List<Book> books = new  ArrayList<Book>();
    	
    	Book b1 = new Book(101,"book_title_1","1796",300,800);
        Book b2 = new Book(102,"book_title_2","1796",300,800);
        Book b3 = new Book(103,"book_title_3","1796",300,800);
        
        books.add(b1);
        books.add(b2);
        books.add(b3);
	}
	
	 @RequestMapping("/books")
	 @ResponseBody 
	 public List<Book> books() {
	        return books;
	 }
}
