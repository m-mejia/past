import java.util.Random;

public class Monster extends Actor{
    Monster(String name, int hp, char symbol, int x, int y) {
        super(name, hp, symbol, x, y);
    }

    @Override
    int generateRandomAttack() {
        Random random = new Random();

        return 1 + random.nextInt(50);
    }
}
