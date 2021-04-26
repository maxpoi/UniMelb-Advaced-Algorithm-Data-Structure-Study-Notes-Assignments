import java.util.ArrayList;
import java.util.Random;

public class DataGenerator {

    public static Operation genInsertion(int idNext) {
        return new Operation(Operation.INSERT, new DataElement(idNext));
    }

    public static Operation genDeletion(int idNext, ArrayList<Operation> arr) {
        Random rand = new Random();
        int id = rand.nextInt(idNext);

        DataElement temp = new DataElement(id);
        for(Operation o : arr) {
            if (o.data.id == id) {
                if (o.type == Operation.DELETE) {
                    break;
                } else if (o.type == Operation.INSERT) {
                    temp.key = o.data.key;
                }
            }
        }

        return new Operation(Operation.DELETE, temp);
    }

    public static Operation genSearch() {
        return new Operation(Operation.SEARCH, new DataElement(-1));
    }

}
