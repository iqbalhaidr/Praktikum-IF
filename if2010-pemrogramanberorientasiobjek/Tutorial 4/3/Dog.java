public class Dog implements CanBark, CanWalk {
    public void walk() {
        System.out.println("Dog is walking");
    }

    public void bark() {
        System.out.println("Dog is barking");
    }
}