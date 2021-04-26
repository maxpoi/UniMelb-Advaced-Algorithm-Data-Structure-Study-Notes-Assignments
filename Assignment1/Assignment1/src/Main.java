import java.util.ArrayList;
import java.util.Random;

public class Main {
    public static final double[] Mlen = {0.1, 0.2, 0.5, 0.8, 1.0};
    public static final double[] prob = {0.001, 0.005, 0.01, 0.05, 0.1};
    public static final int numSequences = 5;
    public static final double fixedProb = 0.05;
    public static final int M = 1000000;


    public static void main(String[] args) {
//        ex1();
//        ex2();
//        ex3();
        ex4();
    }

    public static void ex1() {
        for (int i = 0; i < numSequences; i++) {
            int numTrails = (int) (Mlen[i] * M);
            long start, end;

            ArrayList<Operation> operations = new ArrayList<>();
            for (int j = 0; j < numTrails; j++) {
                operations.add(DataGenerator.genInsertion(j + 1));
            }

            start = System.nanoTime();
            Treap treap = new Treap();
            for (Operation o : operations) {
                treap = Treap.insert(o.data, treap);
            }
            end = System.nanoTime();
            System.out.println("Total running time for the Treap on " + numTrails + " sequences is: " + (end - start) / (double)1000000000);

            start = System.nanoTime();
            DynamicArray dynamicArray = new DynamicArray();
            for (Operation o : operations) {
                dynamicArray.insert(o.data);
            }
            end = System.nanoTime();
            System.out.println("Total running time for the Dynamic Array on " + numTrails + " sequences is: " + (end - start) / (double)1000000000);
        }
    }

    public static void ex2() {
        for(int i=0; i<numSequences; i++) {
            Random rand = new Random();

            int idNext = 1;
            long start, end;

            int numDeletions = 0;
            ArrayList<Operation> operations = new ArrayList<>();

            operations.add(DataGenerator.genInsertion(idNext));
            idNext++;

            for (int j = 1; j < M; j++) {
                if (rand.nextDouble() < prob[i]) {
                    operations.add(DataGenerator.genDeletion(idNext, operations));
                    numDeletions++;
                }
                else {
                    operations.add(DataGenerator.genInsertion(idNext));
                    idNext++;
                }
            }
            System.out.println(numDeletions + " deletions. " + "About " + ((double)numDeletions / M)*100 + "% deletions");

            start = System.nanoTime();
            Treap treap = new Treap();
            for (Operation o : operations) {
                if (o.type == Operation.INSERT)
                    treap = Treap.insert(o.data, treap);
                else
                    treap = Treap.delete(o.data.key, treap);
            }
            end = System.nanoTime();
            System.out.println("Total running time for the Treap is: " + (end - start) / (double)1000000000);

            start = System.nanoTime();
            DynamicArray dynamicArray = new DynamicArray();
            for (Operation o : operations) {
                if (o.type == Operation.DELETE)
                    dynamicArray.delete(o.data.key);
                else
                    dynamicArray.insert(o.data);
            }
            end = System.nanoTime();
            System.out.println("Total running time for the Dynamic Array is: " + (end - start) / (double)1000000000);
        }
    }

    public static void ex3() {
        for(int i=0; i<numSequences; i++) {
            Random rand = new Random();

            int idNext = 1;
            long start, end;

            int numSearch = 0;
            ArrayList<Operation> operations = new ArrayList<>();

            operations.add(DataGenerator.genInsertion(idNext));
            idNext++;

            for (int j = 1; j < M; j++) {
                if (rand.nextDouble() < prob[i]) {
                    operations.add(DataGenerator.genSearch());
                    numSearch++;
                }
                else {
                    operations.add(DataGenerator.genInsertion(idNext));
                    idNext++;
                }
            }
            System.out.println(numSearch + " searches. " + "About " + ((double)numSearch / M)*100 + "% searches");

            start = System.nanoTime();
            Treap treap = new Treap();
            for (Operation o : operations) {
                if (o.type == Operation.INSERT)
                    treap = Treap.insert(o.data, treap);
                else
                    Treap.search(o.data.key, treap);
            }
            end = System.nanoTime();
            System.out.println("Total running time for the Treap is: " + (end - start) / (double)1000000000);

            start = System.nanoTime();
            DynamicArray dynamicArray = new DynamicArray();
            for (Operation o : operations) {
                if (o.type == Operation.SEARCH)
                    dynamicArray.search(o.data.key);
                else
                    dynamicArray.insert(o.data);
            }
            end = System.nanoTime();
            System.out.println("Total running time for the Dynamic Array is: " + (end - start) / (double)1000000000);
        }
    }

    public static void ex4() {
        for (int i = 0; i < numSequences; i++) {
            Random rand = new Random();

            int idNext = 1;
            int numTrails = (int) (Mlen[i] * M);
            long start, end;
            int numDeletions = 0, numSearch = 0;

            ArrayList<Operation> operations = new ArrayList<>();
            for (int j = 0; j < numTrails; j++) {
                if (rand.nextDouble() < fixedProb*2) {
                    if (rand.nextDouble() < 0.5) {
                        operations.add(DataGenerator.genSearch());
                        numSearch++;
                    }
                    else {
                        operations.add(DataGenerator.genDeletion(idNext, operations));
                        numDeletions++;
                    }
                } else {
                    operations.add(DataGenerator.genInsertion(idNext));
                    idNext++;
                }
            }
            System.out.println(numDeletions + " deletions. " + "About " + ((double)numDeletions / numTrails)*100 + "% deletions");
            System.out.println(numSearch + " search. " + "About " + ((double)numSearch / numTrails)*100 + "% search");

            start = System.nanoTime();
            Treap treap = new Treap();
            for (Operation o : operations) {
                if (o.type == Operation.INSERT)
                    treap = Treap.insert(o.data, treap);
                else if (o.type == Operation.DELETE)
                    treap = Treap.delete(o.data.key, treap);
                else
                    Treap.search(o.data.key, treap);
            }
            end = System.nanoTime();
            System.out.println("Total running time for the Treap on " + numTrails + " sequences is: " + (end - start) / (double)1000000000);

            start = System.nanoTime();
            DynamicArray dynamicArray = new DynamicArray();
            for (Operation o : operations) {
                if (o.type == Operation.INSERT)
                    dynamicArray.insert(o.data);
                else if (o.type == Operation.DELETE)
                    dynamicArray.delete(o.data.key);
                else
                    dynamicArray.search(o.data.key);
            }
            end = System.nanoTime();
            System.out.println("Total running time for the Dynamic Array on " + numTrails + " sequences is: " + (end - start) / (double)1000000000);
        }
    }
}
