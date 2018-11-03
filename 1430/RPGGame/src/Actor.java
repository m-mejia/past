public abstract class Actor {
    
    // character statistics
    private String name = "";
    private int hp = 0;
    private char symbol = ' ';
    
    // map coordinates
    private int x;
    private int y;
    
    Actor(String name, int hp, char symbol, int x, int y)
    {
        this.name = name;
        this.hp = hp;
        this.symbol = symbol;
        this.x = x;
        this.y = y;
    }
    
    public String getName() {
        return this.name;
    }
    
    public int getHP() {
        return this.hp;
    }
    
    public void setHP(int hp) {
        this.hp = hp;
    }
    
    public int getX()
    {
        return this.x;
    }
    
    public int getY()
    {
        return this.y;
    }
    
    public void setX(int x)
    {
        this.x = x;
    }
    
    public void setY(int y)
    {
        this.y = y;
    }
    
    public char getSymbol()
    {
        return this.symbol;
    }
    
    abstract int generateRandomAttack();
}
