/* Sam (Sean) van den Eijnden
 * Capitalize the first letter of every word in a string of words
 * Java version "1.8.0_201"
 * Java(TM) SE Runtime Environment (build 1.8.0_201-b09)
 * Java HotSpot(TM) 64-Bit Server VM (build 25.201-b09, mixed mode)
 * February 18th, 2019
 * */
import java.util.Scanner;

public class capitalize {
	
	public static void main(String[] args){
		//variables needed
		String input;
		String[] words;
		String output = "";
		
		//scanner for user input
		Scanner sc = new Scanner(System.in);
		
		//prompt user and store result in words
		System.out.println("Enter a string of words: ");
		input = sc.nextLine();
		
		//split the input and seperate at the spaces, could add other delimiters.
		words = input.split("\\s+");
		
		for(int i = 0; i < words.length; ++i){
			//replace the first character with a capital, keep the rest intact
			words[i] = words[i].substring(0,1).toUpperCase() + words[i].substring(1);
			//
			output += words[i] + " ";
		}
		
		//print output
		System.out.println(output);
	}
}
