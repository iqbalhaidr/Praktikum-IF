public abstract class SecurityDevice extends SmartDevice implements SecureDevice {
    protected boolean locked;
    protected String password;
    protected int failedAttempts;
    protected boolean permanentlyLocked;

    public SecurityDevice(String deviceName, String password) {
        super(deviceName, "Security");
        this.password = password;
        this.locked = true;
        this.failedAttempts = 0;
        this.permanentlyLocked = false;
    }

    @Override
    public boolean authenticate(String password) {
        if (permanentlyLocked) {
            System.out.println("Device is permanently locked due to too many failed attempts");
            return false;
        }

        if (this.password.equals(password)) {
            failedAttempts = 0;
            System.out.println("Authentication successful");
            return true;
        } else {
            failedAttempts++;
            if (failedAttempts >= 3) {
                permanentlyLocked = true;
                System.out.println("Too many failed attempts. Device permanently locked");
            } else {
                System.out.println("Authentication failed. " + (3 - failedAttempts) + " attempts remaining");
            }
            return false;
        }
    }

    @Override
    public void lock() {
        locked = true;
        System.out.println(deviceName + " locked");
    }

    @Override
    public void unlock(String password) {
        if (authenticate(password)) {
            locked = false;
            System.out.println(deviceName + " unlocked");
        }
    }

    @Override
    public boolean isLocked() {
        return locked;
    }

    // Override turnOn to check if device is locked
    @Override
    public void turnOn() {
        if (locked) {
            System.out.println("Cannot turn on " + deviceName + ": Device is locked");
        } else {
            super.turnOn();
        }
    }
}