import java.util.Random;

public class Treap {

    public Treap left, right;
    public int priority;
    public DataElement data;

    public Treap() {
        left = null;
        right = null;
        data = null;

        Random rand = new Random();
        priority = rand.nextInt(Main.M);
    }

    public static Treap rotateLeft(Treap treap) {
        Treap right = treap.right;
        Treap rightLeft = right.left;

        right.left = treap;
        treap.right = rightLeft;

        return right;
    }

    public static Treap rotateRight(Treap treap) {
        Treap left = treap.left;
        Treap leftRight = left.right;

        left.right = treap;
        treap.left = leftRight;

        return left;
    }

    public static Treap insert(DataElement data, Treap treap) {
        if (treap == null || treap.data == null) {
            Treap leaf = new Treap();
            leaf.data = data;

            return leaf;
        } else {
            if (data.key > treap.data.key ||
                    ((data.key == treap.data.key) && data.id > treap.data.id)) {
                treap.right  = insert(data, treap.right);

                if (treap.priority > treap.right.priority)
                    treap = rotateLeft(treap);
            }
            else if(data.key < treap.data.key ||
                    ((data.key == treap.data.key) && data.id < treap.data.id)) {
                treap.left  = insert(data, treap.left);

                if (treap.priority > treap.left.priority)
                    treap = rotateRight(treap);
            }

            return treap;
        }
    }

    public static Treap delete(int key, Treap treap) {
//        if (treap == null)
//            return null;

        // search through the treap
        if (key > treap.data.key) {
            if (treap.right == null)
                return treap;
            treap.right = delete(key, treap.right);
        }
        else if (key < treap.data.key) {
            if (treap.left == null)
                return treap;
            treap.left = delete(key, treap.left);
        }
        else {
            // found it, rotate to leaf
            if (treap.left != null && treap.right != null) {
                if (treap.left.priority < treap.right.priority) {
                    treap = rotateRight(treap);
                    treap.right = delete(key, treap.right);
                } else {
                    treap = rotateLeft(treap);
                    treap.left = delete(key, treap.left);
                }
            } else if (treap.left == null && treap.right != null) {
                treap = rotateLeft(treap);
                treap.left = delete(key, treap.left);
            } else if (treap.right == null && treap.left != null) {
                treap = rotateRight(treap);
                treap.right = delete(key, treap.right);
            } else
                // now at the leaf, delete it
                treap = null;
        }

        return treap;

    }

    public static DataElement search(int key, Treap treap) {
        if (treap == null)
            return null;

        if (key > treap.data.key)
            return search(key, treap.right);
        else if (key < treap.data.key)
            return search(key, treap.left);
        else
            return treap.data;
    }

    public static int treapSize(Treap treap, int size) {
        if (treap == null) return 0;

        size += treapSize(treap.left, 0);
        size += 1;
        size += treapSize(treap.right, 0);

        return size;
    }
}
