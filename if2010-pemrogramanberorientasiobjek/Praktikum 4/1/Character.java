class Character extends Unit implements Damageable {
    private int score;

    public Character() {
        super("Player1", 100);
        this.score = 0;
    }

    public Character(String name, int health, int score) {
        super(name, health);
        this.score = score;
    }

    public int getScore() {
        return this.score;
    }

    public void setScore(int score) {
        this.score = score;
    }

    @Override
    public void takeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            System.out.printf("%s has been defeated%n", this.name);
        }
    }

    public void increaseScore(int points) {
        this.score += points;
    }

    @Override
    public String toString() {
        String res = getName() + " [Health: " + getHealth() + ", Score: " + getScore() + "]";
        return res;
    }

}