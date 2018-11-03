import java.util.Scanner;

public class Input {
    private Scanner scanner;

    public Input() {
        scanner = new Scanner(System.in);
    }

    public char readInput() {
        char[] c;

        do {
            String line = scanner.nextLine();
            if (line.isEmpty()) line = "empty";
            c = line.toCharArray();
        } while (!validInput(c));
        return c[0];
    }

    private boolean validInput(char[] c) {
        if(c[0] == 'a' || c[0] == 'w' || c[0] == 's' || c[0] == 'd' || c[0] == 'q') return true;
        return false;
    }
}
