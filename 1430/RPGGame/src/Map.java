import java.util.Random;

public class Map {
    private final int SIZE;
    private final int PLAYER_LOCATION;
    private char[][] map;
    private final Player player;
    private final Monster monster;
    private final Combat combat;

    public Map() {
        player = new Player("Link", 50, 'P', 4, 4);
        combat = new Combat();
        SIZE = 9;
        map = new char[SIZE][SIZE];
        PLAYER_LOCATION = 4;
        initializeMap();
        int monsterX = generateRandomLocation();
        int monsterY = generateRandomLocation();
        monster = new Monster("Ganon", 50, 'M', monsterX, monsterY);
    }

    private int generateRandomLocation() {
        Random random = new Random();
        return random.nextInt(SIZE-1);
    }

    private void initializeMap() {
        for (int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                map[i][j] = '-';
            }
        }
    }

    public void drawMap() {
        initializeMap();
        assignActorLocation(player);
        assignActorLocation(monster);
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
    }

    private void assignActorLocation(Actor actor) {
        int x = actor.getX();
        int y = actor.getY();
        char symbol = actor.getSymbol();

        map[y][x] = symbol;
    }

    public void movePlayer(char move) {
        int x = player.getX();
        int y = player.getY();

        switch (move) {
            case 'a': {
                if (player.getX() > 0) {
                    player.setX(player.getX() - 1);
                }
                break;
            }

            case 'd': {
                if (player.getX() < 8) {
                    player.setX(player.getX() + 1);
                }
                break;
            }

            case 'w': {
                if (player.getY() > 0) {
                    player.setY(player.getY() - 1);
                }
                break;
            }

            case 's': {
                if (player.getY() < 8) {
                    player.setY(player.getY() + 1);
                }
                break;
            }

            case 'q': {
                System.out.println("Good buy!!!");
                System.exit(0);
            }
        }

        if (encounters(player, monster)) combat.initCombat(player, monster);
    }

    private boolean encounters(Player player, Monster monster) {
        return player.getY() == monster.getY() && player.getX() == monster.getX();
    }


}
