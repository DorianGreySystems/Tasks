package controllers;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import Task.Books.entity.Author;

@RestController
public class AuthorsController {
	
	private List<Author> authors = null;
	 
	public AuthorsController()
	{
		authors = new ArrayList<Author>();
	}
	 
	@RequestMapping(value = "/authors", method = RequestMethod.GET)
	@ResponseBody 
	public List<Author> authors() {
	       return authors;
	}
	 
	// Get book by id
	@RequestMapping(value = "/authors/{id}", method = RequestMethod.PUT)
	@ResponseBody 
	public List<Author> getAuthor(@PathVariable String id) {
		int tempId = Integer.parseInt(id);
		List<Author> result = authors.stream()
			     .filter(item -> item.getId() == tempId)
			     .collect(Collectors.toList());
		return result;
	}

}
