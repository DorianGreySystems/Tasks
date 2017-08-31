package Task.Books.repo;

import java.util.Map;
import java.util.Set;

import org.bson.BSONObject;

import com.google.gson.Gson;
import com.mongodb.BasicDBObject;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.DBObject;
import com.mongodb.Mongo;

import Task.Books.entity.Book;

public class BookRepo {
	
	private static final Mongo mongo = new Mongo("localhost", 27017);
	private static final DB db = mongo.getDB("books");
	private static final DBCollection collection = db.getCollection("books");
	
	public void save(Book book) {
		Gson gson = new Gson();
		collection.save(new BasicDBObject(String.valueOf(book.getId()), gson.toJson(book)));
		
	}
	
	public void delete(Book book){
		Gson gson = new Gson();
		collection.remove(new BasicDBObject(String.valueOf(book.getId()),gson.toJson(book)));
	}
}
