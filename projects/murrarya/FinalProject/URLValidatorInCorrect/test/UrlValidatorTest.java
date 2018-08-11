

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   
	   UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   assertFalse(urlValidator.isValid("htt.google"));
	   assertFalse(urlValidator.isValid("ftp.google"));
	   assertTrue(urlValidator.isValid("http://www.google.com/"));
	   assertFalse(urlValidator.isValid("www.turtle.com/"));
	   assertTrue(urlValidator.isValid("http://www.dog.com/"));
	   //assertTrue(urlValidator.isValid("https://www.dog.com/")); //Does not like https, causes program to crash
	   //assertTrue(urlValidator.isValid("ftp://ftp.dog.com"));Does not like format, causes program to crash
	   //assertTrue(urlValidator.isValid("http://www.dog.com:98"));Does not like format with port number, causes program to crash
	   assertFalse(urlValidator.isValid("ftp.kibble.com"));
	  //assertTrue(urlValidator.isValid(  "https://www.facebook.com/"));//Does not like https, causes program to crash
	   assertFalse(urlValidator.isValid(""));
	   assertTrue(urlValidator.isValid("http://www.dog.com/test"));
	   assertTrue(urlValidator.isValid("http://www.dog.com/test?a=bee"));
	  //assertTrue(urlValidator.isValid("http://www.example.com:8080/path/"));Does not like format, causes program to crash

   }
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   
	   UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String []valid = {"http://www.dog.com/", "http://www.cat.com/", "http://www.cowsonfarm.com", "http://www.chipmunks.com"
	   };
	   boolean result; 
	   for (int i =0; i< valid.length; i++) 
	   {
		   result = urlValidator.isValid(valid[i]);
		   System.out.println("Valid" + " " + valid[i] + " " + result);
		   //assertTrue(urlValidator.isValid(valid[i]));
	   }
	   
   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   
	  // UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String []invalid = { "http://www.cat.com/path/path2?a=bee", "http://www.tiger.com/tigerlives/tigerhunts/", 
			   "http://www.cat.com/path/",  "http://www.cat.com:80", " ", " efsfs"
	   };
	   boolean result; 
	   for (int i =0; i< invalid.length; i++) 
	   {
		   result = urlValidator.isValid(invalid[i]);
		   System.out.println("Invalid" + " " +invalid[i] + " " + result);
		   //assertTrue(urlValidator.isValid(valid[i]));
	   }
   }
   
   
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}



