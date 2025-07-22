public abstract class SmartDevice implements Controllable {
    protected String deviceName;
    protected boolean active;
    protected String deviceType;

    public SmartDevice(String deviceName, String deviceType) {
        this.deviceName = deviceName;
        this.deviceType = deviceType;
        this.active = false;
    }

    @Override
    public void turnOn() {
        active = true;
        System.out.println(deviceName + " turned ON");
    }

    @Override
    public void turnOff() {
        active = false;
        System.out.println(deviceName + " turned OFF");
    }

    @Override
    public boolean isActive() {
        return active;
    }

    public String getDeviceName() {
        return deviceName;
    }

    public String getDeviceType() {
        return deviceType;
    }

    // Setiap smart device harus memiliki metode untuk melaporkan statusnya
    public abstract void reportStatus();
}