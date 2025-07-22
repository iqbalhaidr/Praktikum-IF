public interface SecureDevice {
    boolean authenticate(String password);

    void lock();

    void unlock(String password);

    boolean isLocked();
}