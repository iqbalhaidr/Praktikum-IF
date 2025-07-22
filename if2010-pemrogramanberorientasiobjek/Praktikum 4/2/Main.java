class Main {
    public static void main(String[] args) {
        IPhone iphone = new IPhone();
        iphone.locate(); // Should print "IPhone is not connected"
        iphone.makeSound(); // Should print "IPhone is not connected"
        iphone.charge(); // Should print "IPhone charged to 100%"
        iphone.connect(); // Connect the device
        iphone.locate(); // Should print "IPhone is nearby! Distance: 100 meters away"
        iphone.makeSound(); // Should print "IPhone: *LOUD BEEPING*";
    }
}