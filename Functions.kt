import java.util.Scanner
fun sum(a : Int, b: Int): Int{print("The sum is ")return a+b    }
fun multiply(a:Int,b:Int): Int
{
    print("Product of a and b is ")
    return a*b
}
fun div(a:Int, b:Int)
{
    if(b==0 || b<0)
    {
        println("Cannot divide by a 0 or less than 0 (Negitive Number)");
    }
    else
    {
     println("The division of a and b is: "+ (a/b))
    }
}
fun main()
{
    val s = Scanner(System.`in`)
    println("Enter number 1: ")
   val a = s.nextInt()
   println("Enter the number 2: ")
   val b  = s.nextInt()
   var exit = false
   while(!exit)
   {
        println("Press 1 to Add")
        println("Press 2 to Multiply")
        println("Press 3 to divide")
        println("Press 4 to Exit")   
    val choice  = s.nextInt()
    when(choice)
     {
        1-> println("${sum(a,b)}")
        2-> println("${multiply(a, b)}")
        3-> println("${div(a,b)}")
        4-> 
        {
            println("Exiting")
            exit = true
        }
        else-> println("Fuck you! You bitch Enter between 1 and 4 you MotherFAther ")
     }
    }
}