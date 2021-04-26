public class DynamicArray {
    public DataElement[] arr;
    public int num;

    public DynamicArray() {
        num = 0;
        arr = new DataElement[1];
    }

    void insert(DataElement data) {
        this.arr[this.num] = data;

        this.num++;
        if (this.num == this.arr.length) {
            int size = this.arr.length * 2;

            DataElement[] temp = new DataElement[size];
            System.arraycopy(this.arr, 0, temp, 0, num);
            this.arr = new DataElement[size];

            if (num >= 0) System.arraycopy(temp, 0, this.arr, 0, num);
        }
    }

    void delete(int key) {
        int tempNum = this.num;
        for (int i = 0; i < tempNum; i++) {
            if (this.arr[i].key == key) {
                this.arr[i] = this.arr[num-1];
                this.arr[num-1] = null;
                num--;

                break;
            }
        }

        if (this.num < this.arr.length / 4) {
            int size = this.arr.length / 2;

            DataElement[] temp = new DataElement[size];
            System.arraycopy(this.arr, 0, temp, 0, num);
            this.arr = new DataElement[size];

            if (num >= 0) System.arraycopy(temp, 0, this.arr, 0, num);
        }
    }

    DataElement search(int key) {
        for (int i = 0; i < this.num; i++) {
            if (this.arr[i].key == key) {
                return this.arr[i];
            }
        }

        return null;
    }
}
