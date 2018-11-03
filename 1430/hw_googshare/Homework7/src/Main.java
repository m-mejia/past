import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		try (Scanner scReadUserInput = new Scanner (System.in)) { // Create Scanner object
			// to read user's input.

			System.out.print("Welcome to the Asset Management System"
					+ "\nInput the number of GOOG shares: ");

			int numberOfShares = scReadUserInput.nextInt(); // Get the number of shares form the user.
			
			System.out.println("Your GOOG assets:\n");
			System.out.printf("%-10s %25s %15s \n", "Date", "Number of Shares", "Total Value");
			
			// Create Scanner object to read the file line by line.
			try (Scanner scReadFile = new Scanner (new File ("GOOGprices.csv"))) {
				
				boolean firstLine = true; // Indicates the first line in file to skip it.
				
				while (scReadFile.hasNextLine()) { // Loop through the all lines in the file.
					
					String line = scReadFile.nextLine().trim(); // Retrieve the current line.
					
					if (firstLine) { // If current line is the first one.
						
						firstLine = false; // Because all the next lines will not be the first.
						
						continue; // Just go to the next line (skip the first line with column headers).
					}
					
					// Retrieve comma separated items from file.
					String [] items = line.split(",");
					
					String date = items[0]; // Retrieve date.
	
					double adjClose = Double.parseDouble(items[6]); // Retrieve 'Adj Close' value.
					
					double totalValue = numberOfShares * adjClose; // Calculate total value.
					
					System.out.printf("%-10s %10d %26.2f \n", date, numberOfShares, totalValue);
					
				} // end of while
				
				System.out.println("\nGoodbye!");
				
			} catch (IOException exc) {
				exc.printStackTrace();
			}
		} // end of try-with-resources block

	} // end of main method

} // end of class
