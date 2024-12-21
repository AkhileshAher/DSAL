import java.util.*;

// Define the first interface
interface First {
    void add();
}

// Define the second interface extending the first
interface Second extends First {
    void multi();
}

// Define the third interface extending the second
interface Third extends Second {
    void sub();
}

// Implementing class
class MyClass implements Third {
    Scanner sc = new Scanner(System.in);
    int a, b, c;

    // Implementation of the add method
    public void add() {
        System.out.println("Enter two numbers:");
        a = sc.nextInt();
        b = sc.nextInt();
        System.out.println("Addition:");
        c = a + b;
        System.out.println(c);
    }

    // Implementation of the sub method
    public void sub() {
        System.out.println("Enter two numbers:");
        a = sc.nextInt();
        b = sc.nextInt();
        System.out.println("Subtraction:");
        c = a - b;
        System.out.println(c);
    }

    // Implementation of the multi method
    public void multi() {
        System.out.println("Enter two numbers:");
        a = sc.nextInt();
        b = sc.nextInt();
        System.out.println("Multiplication:");
        c = a * b;
        System.out.println(c);
    }
}

// Main class
public class Main {
    public static void main(String[] args) {
        MyClass ob = new MyClass();
        ob.add();
        ob.sub();
        ob.multi();
    }
}
