public class SortStack {
    public static Stack<Integer> solve(Stack<Integer> stack) {
        Stack<Integer> t = new Stack<>();
        while(!stack.isEmpty()) {
            int num = stack.pop();
            while(!t.isEmpty() && t.peek() > num) stack.push(t.pop());
            t.push(num);
        }
        while(!t.isEmpty()) stack.push(t.pop());

        return stack;
    }   
}