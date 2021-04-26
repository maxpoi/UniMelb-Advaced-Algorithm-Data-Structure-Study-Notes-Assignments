public class Operation {
    public static final int INSERT = 1, DELETE = -1, SEARCH = 0;
    DataElement data;
    int type;

    public Operation(int type, DataElement data) {
        this.type = type;
        this.data = data;
    }
}
