public class Box<T> {
    private T inside;

    public Box(T inside){
        this.inside = inside;
    }

    public void open(){
        System.out.println("Box opened, and it contains: " + inside);
    }
}