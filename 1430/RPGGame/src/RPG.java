
public class RPG {
    public static void main(String[] args) {
        Map map = new Map();
        Input input = new Input();
        map.drawMap();

        while (true) {
            map.drawMap();
            System.out.println("up: w | down: s | left: a | right: d | quit: q");
            System.out.print("move: ");
            map.movePlayer(input.readInput());
        }
    }
}
