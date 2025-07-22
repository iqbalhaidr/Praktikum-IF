public abstract class Device implements Trackable {
    protected boolean connected;
    protected String name;

    public Device(String name) {
        this.name = name;
        this.connected = false;
    }

    @Override
    public void connect() {
        connected = true;
        System.out.println(name + " connected");
    }

    @Override
    public boolean isConnected() {
        return connected;
    }

    @Override
    public abstract void locate();

    @Override
    public abstract void makeSound();
}