import java.util.Scanner;
Int fun add(num1: Int, num2: Int): Int
{
    return a+b
}
Int fun sub(num1: Int, num2: Int): Int
{
    return a-b
}
fun mian()
{
    val Scanner s = new Scanner(System.`in`);
    println("Welcome to a calculator");
    
    println("Enter num1");
    var num1 = s.nextInt()
    
    println("Enter num2")
    var num2 = s.nextInt()

    println("What operation do you want to perform");
    println("Press 1 to Add");
    println("Press 2 to subtract");
    var choice = s.nextInt()
    when(choice)
    {
        1-> println("${add(num1,num2)}");
        2-> println("${sub(num1,num2)}");
        
    }
}