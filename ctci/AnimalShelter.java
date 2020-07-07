import java.util.Queue;

public class AnimalShelter {

    public static class Animal {
        // type = 1 CAT
        // type = 2 DOG
        static int type;
        static int id;
        public Animal(int type, int id) {
            this.type = type;
            this.id = id;
        }
    }

    Queue<Animal> cat, dog;
    int currentId;

    public AnimalShelter() {
        cat = new Queue<>();
        dog = new Queue<>();
        currentId = -1;
    }

    public int enqueue(int type) {
        if(type == 1) {
            cat.add(new Animal(type, ++currentId));
        } else if(type == 2) {
            dog.add(new Animal(type, ++currentId));
        } else {
            return -1;
        }
        return currentId;
    }

    public Animal dequeueAny() {
        if(cat.isEmpty() && dog.isEmpty()) return null;
        if(cat.isEmpty()) return dog.poll();
        if(dog.isEmpty()) return cat.poll();
        if(cat.peek().id < dog.peek().id) return cat.poll();
        
        return dog.poll();
    }

    public Animal dequeueCat() {
        return cat.poll();
    }

    public Animal dequeueDog() {
        return dog.poll();
    }
    
}