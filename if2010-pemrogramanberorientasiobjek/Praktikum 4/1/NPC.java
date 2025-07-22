class NPC extends Unit implements Interactable {
    String dialogue = "Hello there!";

    public NPC() {
        super("NPC1", 100);
    }

    public NPC(String name, int health, String dialogue) {
        super(name, health);
        this.dialogue = dialogue;
    }

    public String getDialogue() {
        return this.dialogue;
    }

    public void setDialogue(String dialogue) {
        this.dialogue = dialogue;
    }

    @Override
    public void interact() {
        System.out.println(this.dialogue);
    }

    @Override
    public String toString() {
        String res = getName() + " [Health: " + getHealth() + ", Dialogue: " + getDialogue() + "]";
        return res;
    }

}