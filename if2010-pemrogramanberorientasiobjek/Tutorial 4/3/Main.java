import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tc = scanner.nextInt();

        Object[] things = new Object[] {};

        switch (tc) {
            case 1:
                things = new Object[] { new Human() };
                break;
            case 2:
                things = new Object[] { new Robot() };
                break;
            case 3:
                things = new Object[] { new Dog() };
                break;
            case 4:
                things = new Object[] { new Human(), new Robot(), new Dog() };
                break;
            default:
                break;
        }

        for (Object obj : things) {
            if (obj instanceof CanWalk) {
                ((CanWalk) obj).walk();
            }
            if (obj instanceof CanTalk) {
                ((CanTalk) obj).talk();
            }
            if (obj instanceof CanBark) {
                ((CanBark) obj).bark();
            }
        }

        scanner.close();
    }
}
