import java.util.Random;

public class DataElement {

    public int id;
    public int key;



    public DataElement(int idNext) {
        Random rand = new Random();

        this.id = idNext;
        this.key =rand.nextInt(Main.M);
    }
}
